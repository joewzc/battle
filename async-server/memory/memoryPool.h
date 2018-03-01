#ifndef _MEMORY_POOL_H
#define _MEMORY_POOL_H
#include <stdlib.h>
#define MINUNITSIZE 64
#define ADDR_ALIGN 8
#define SIZE_ALIGN MINUNITSIZE

struct MemoryChunk;

struct MemoryBlock
{
    int count;
    int start;
    MemoryChunk* pmemChunk;
};

struct MemoryChunk 
{
    MemoryBlock* pfreeMemAddr;
    MemoryChunk* pre;
    MemoryChunk* next;
};

class MemoryPool
{
    void* memoryPool;
    void* memoryAvailable;
    int size;
    MemoryBlock* pmemMap;
    MemoryChunk* pfreeMemChunk;
    MemoryChunk* pfreeMemChunkPool;
    int memUsedSize;            //记录内存池中已经分配给用户的内存大小
    int memMapPoolCount;        //记录链表单元缓冲池中剩余单元的个数，个数不为0时不能分配
    int freeMemChunkCount;      //记录pfreeMemChunk链表中单元的个数
    int memMapUnitCount;
    int memBlockCount;          //一个memUnit大小为MINUNITSIZE
    MemoryPool(){}
    public:
    MemoryPool(int length);
    ~MemoryPool();
    
    void* getMemory(int length);

    void releaseMemoryPool();

    void* freeMemory(void* ptrMemoryBlock);

};

inline int check_align_block(int size) {
    int align = size % MINUNITSIZE;
    return size - align;
}

inline MemoryChunk* front_pop(MemoryChunk* &pool) 
{
    if (!pool) 
    {
        return NULL;
    }

    MemoryChunk* tmp = pool;
    pool = tmp->next;
    pool->pre = NULL;
    return tmp;
}

inline int check_align_size(int length)
{
    length = (length + SIZE_ALIGN - 1) / SIZE_ALIGN * SIZE_ALIGN;
    return length;
}

inline void push_front(MemoryChunk* &head, memoryChunk* element)
{
    element->pre = NULL;
    element->next = head;

    if(head != NULL)
    {
        head->pre = element;
    }

    head = element;
}

inline void* index2addr(MemoryPool* memory, int index)
{
    char* p = (char*) (memory);
    void* ret = (void*) (p + index * MINUNITSIZE);

    return ret;
}

inline void* addr2index(MemoryPool* memory, void* addr)
{
    char* start = (char*) memory;
    char* p = (char*)addr;

    int index = (p - start) / MINUNITSIZE;
    return index;
}

#endif
