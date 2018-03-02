#include "memoryPool.h"


int check_align_addr(void* &pBuf) {
    int align = 0;
    int addr = int(pBuf);
    align = (ADDR_ALIGN - addr % ADDR_ALIGN) % ADDR_ALIGN;
    pBuf = (char*)pBuf + align;
    return align;
}

MemoryChunk* create_list(memoryChunk* pool, int count) 
{
    if (!pool) 
    {
        return NULL;
    }

    MemoryChunk* head = NULL;
    for (int i=0; i<count; i++)
    {
        pool->pre = NULL;
        pool->next = head;

        if (head != NULL) {
            head->pre = pool;
        }

        head = pool;
        pool++;
    }
    
    return head;
}

void delete_chunk (MemoryChunk* &head, MemoryChunk* element)
{
    if (element == NULL)
    {
        return;
    }

    else if (element == head) 
    {
        if (head->pre == head) 
        {
            head = NULL;
        }
        else 
        {
            head = head->next;
            head->pre = element->pre;
            head->pre->next = head;
        }
    }
    
    else 
    {
        element->next->pre = element->pre;
        element->pre->next = element->next;
    }

    element->next = NULL;
    element->pre = NULL;
}

void push_back(MemoryChunk* &head, MemoryChunk* element) 
{
    if (head == NULL) {
        head = element;
        head->pre = element;
        head->next = element;
    }

    head->pre->next = element;
    element->pre = head->pre;
    head->pre = element;
    element->next = head;
}

MemoryPool::MemoryPool(int length) 
{
    memoryPool = (void*) malloc (length);
    memset(memorypool, 0, length);

    int memPoolStructSize = sizeof(MemoryPool);
    memMapPoolCount = (length - memPoolStructSize + MINUNITSIZE - 1) / MINUNITSIZE;

    pmemMap = (MemoryBlock*) ((char*)memoryPool + memPoolStructSize);
    pfreeMemChunkPool = (MemoryChunk*) ((char*)pmemMap + sizeof(MemoryBlock) * memMapPoolCount);
    memoryAvaliable = (char*)pfreeMemChunkPool + sizeof(MemoryChunk) * memMapPoolCount;

    size = length - memPoolStructSize - sizeof(MemoryBlock) * memMapPoolCount + sizeof(MemoryChunk) * memMapPoolCount;
    int align = check_align_addr(memoryAvailable);
    size -= align;
    size = check_align_block (size);
    memBlockCount = size / MINUNITSIZE;

    //链表初始化
    pfreeMemChunkPool = create_list(pfreeMemChunkPool, memMapPoolCount);
    
    MemoryChunk* tmp = front_pop(pfreeMemChunkPool);
    tmp->pre = tmp;
    tmp->next = tmp;
    tmp->pfreeMemAddr = NULL;
    memMapPoolCount--;

    pmemMap[0].count = memBlockCount;
    pmemMap[0].pmemChunk = tmp;
    pmemMap[memBlockCount-1].start = 0;

    tmp->pfreeMemAddr = pmemMap;
    push_back(pfreeMemChunk, tmp);

    freeMemChunkCount = 1;
    memUsedSize = 0;
}

void* MemoryPool::getMemory(int length)
{
    length = check_align_size(length);
    int index = 0;
    MemoryChunk* tmp = pfreeMemChunk;
    for (; index<freeMemChunkCount; index++) 
    {
        if (tmp->pfreeMemAddr->count * MINUNITSIZE >= length)
        {
            break;
        }
        tmp = tmp->next;
    }

    if (index == freeMemChunkCount) 
    {
        return NULL;
    }

    memUsedSize += length;

    if (tmp->pfreeMemAddr->count * MINUNITSIZE == length)
    {
        int currentIndex = (int)(tmp->pfreeMemAddr - pmemMap);
        delete_chunk(pfreeMemChunk, tmp);
        tmp->pfreeMemAddr->pmemChunk = NULL;

        push_front(pfreeMemChunkPool, tmp);
        freeMemChunkCount--;
        memMapPoolCount++;

        return index2addr(memoryAvialable, currentIndex);
    }

    else
    {
        MemoryBlock copy;
        copy.count = tmp->pfreeMemAddr->count;
        copy.pmemChunk = tmp;


        MemoryBlock* currentBlock = tmp->pfreeMemAddr;
        currentBlock->count = length / MINUNITSIZE;      
        int currentIndex = currentBlock - pmemMap;
        pmemMap[currentIndex+currentBlock->count-1].start = currentIndex;
        currentBlock->pmemChunk = NULL;

        pmemMap[currentIndex+currentBlock->count].count = copy.count - currentBlock->count;
        pmemMap[currentIndex+currentBlock->count].pmemChunk = copy.pmemChunk;

        pmemMap[currentIndex+copy.count-1].start = currentIndex+currentBlock->count;
        tmp->pfreeMemAddr = &(pmemMap[currentIndex+currentBlock->count]);

        return index2addr(pMem, currentIndex);

    }
}

void MemoryPool::freeMemory(void* ptrMemoryBlock)
{
    int currentIndex = addr2index(pmemMap, ptrMemoryBlock);
    int size = pmemMap[currentIndex].count * MINUNITSIZE;

    MemoryBlock* preBlock = NULL;
    MemoryBlock* nextBlock = NULL;
    MemoryBlock* currentBlock = &(pmemMap[currentIndex]);


    if (currentIndex == 0) 
    {
        if (currentBlock->count < memBlockCount)
        {
            nextBlock = &(pmemMap[currentIndex+currentBlock->count]);
            if (nextBlock->pmemChunk != NULL)
            {
                nextBlock->pmemChunk->pfreeMemAddr = currentBlock;
                pmemMap[currentIndex + currentBlock->count + nextBlock->count-1].start = currentIndex;
                currentBlock->count = currentBlock->count + nextBlock->count;
                currentBlock->pmemChunk = nextBlock->pmemChunk;
                nextBlock.pmemChunk = NULL;
            } 
            else 
            {
                MemoryChunk* newChunk = front_pop(pfreeMemChunkPool);
                newChunk->pfreeMemAddr = currentBlock;
                currentBlock->pmemChunk = newChunk;
                push_back(pfreeMemChunk, newChunk);

                memMapPoolCount--;
                freeMemChunkCount++;
            }
        }
        else
        {
            MemoryChunk* newChunk = front_pop(pfreeMemChunkPool);
            newChunk->pfreeMemAddr = currentBlock;
            currentBlock->pmemChunk = newChunk;
            push_back(pfreeMemChunk, newChunk);
            memMapPoolCount--;
            freeMemChunkCount++;
        }
    }
    else if (currentIndex == memBlockCount-1)
    {
        if (currentBlock->count < memBlockCount)
        {
            preBlock = &(pmemMap[currentIndex-1]);
            int index = preBlock->start;
            preBlock = &(pmemMap[index]);
            if (preBlock->pmemChunk != NULL)
            {
                preBlock->count += currentBlock->count;
                currentBlock->pmemChunk = NULL;
                pmemMap[currentIndex+currentBlock->count-1].start = index;
            }
            else
            {
                MemoryChunk* newChunk = front_pop(pfreeMemChunkPool);
                newChunk->pfreeMemAddr = currentBlock;
                push_back(pfreeMemChunk, newChunk);
                currentBlock->pmemChunk = newChunk;
                memMapPoolCount--;
                freeMemChunkCount++;
            }
        }
        else
        {
            MemoryChunk* newChunk = front_pop(pfreeMemChunkPool);
            newChunk->pfreeMemAddr = currentBlock;
            push_back(pfreeMemChunk, newChunk);
            currentBlock->pmemChunk = newChunk;
            memMapPoolCount--;
            freeMemChunkCount++;

        }
    }
    else
    {
        nextBlock = &(pmemMap[currentIndex+currentBlock->count]);
        preBlock = &(pmemMap[currentIndex-1]);
        int index = preBlock->start;
        preBlock = &(pmemMap[index]);
        bool isBackMerge = false;

        if (nextBlock->pmemChunk == NULL && preBlock->pmemChunk == NULL) 
        {
            MemoryChunk* newChunk = front_pop(pfreeMemChunkPool);
            newChunk->pfreeMemAddr = currentBlock;
            push_back(pfreeMemChunk, newChunk);
            currentBlock->pmemChunk = newChunk;
            memMapPoolCount--;
            freeMemChunkCount++;
        }

        if (nextBlock->pmemChunk != NULL)
        {
            nextBlock->pmemChunk->pfreeMemAddr = currentBlock;
            pmemMap[currentIndex+currentBlock->count + nextBlock->count - 1].start = currentIndex;
            currentBlock->count += nextBlock->count;
            currentBlock->pmemChunk = nextBlock->pmemChunk;
            nextBlock->pmemChunk = NULL;
            isBackMerge = true;
        }

        if (preBlock->pmemBlock != NULL) 
        {
            pmemMap[currentIndex+currentBlock->count-1].start = currentIndex - preBlock->count;
            preBlock->count += currentCount->count;
            if (isBackMerge)
            {
                delete_chunk(pfreeMemChunk, currentBlock->pmemChunk);
                push_front(pfreeMemChunkPool, currentBlock->pmemChunk);
                freeMemChunkCount--;
                memMapPoolCount++;
            }
            currentBlock->pmemChunk = NULL;
        }
    }

    memUsedSize -= size;
}

void* sf_realloc()
{
   int memPoolStructSize = sizeof(MemoryPool);
   void* newMemoryPool = (void*) malloc (size * 2 - memPoolStructSize);
   int newMemPoolCount = (size * 2 - memPoolStructSize + MINUNITSIZE - 1) / MINUNITSIZE;
   MemoryBlock* newPmemMap = (MemoryBlock*) ((char*)newMemoryPool + memPoolStructSize);
   memset(newMemoryPool, 0, size*2 - memPoolStructSize);
   void* newMemory = (char*) newMemoryPool + sizeof(MemoryBlock) * newMemPoolCount + sizeof(MemoryChunk) * newMemPoolCount;
   memcpy(newMemory, memoryAvialable, size);
}
