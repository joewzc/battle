
#include<stdio.h>

void test(int a[]) {
    a[0] = 1;
    return;
}
int main(){
    int a[3] = {2,3,4};
    test(a);
    printf("%d\n",a[0]);
    return 0;
}

