#include <stdio.h>

int main() {
    int a[50]= {2,4,6,7,9}, size, i, pos, num, *q;

    printf("%p\n", a);
    q = a;
 
    printf("%d\n", q[1]);
    printf("%p\n", &q);

    printf("%d\n", *a); //prints the oth element
    printf("%d\n", *(a+1)); //prints the second element
    printf("%d\n", *a+1); // first element + 1
    
    // for (i=0; i<5; i++){
    //     scanf("%d", &q[i]);
    // }

    for (i=0; i<5; i++){
        printf("Val %d: %d\n", i, i[q]);
    }

    return 0;
}

