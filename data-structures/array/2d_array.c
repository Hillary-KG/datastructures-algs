#include <stdio.h>

int main()
{
    int a[3][3] = {6,2,5,0,1,3,4,9,8};
    // mem structure = [100, 104, 108, 112, 116, 120, 124, 128, 132]
    int *p;
    p = &a[0][0];
    int diff;
    diff = (&a[1] + 1) - (&a[1]);

    printf("%p\n", p);
    printf("%d\n", **a);
    printf("%p\n", &a[1]+1);
    printf("%d\n", diff);

    // printf("%u\n", **p); *p = value stored at address 100=6, **p value stored at address 6 whci is not a pointer hence an error

     
    return 0;
}
