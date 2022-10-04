#include <iostream>
#include "EFT.h"
int main() {
    int a[]={1,2,3,4,6,9,22,33,55,66};
    int b[]={0,3,6,7,11,22};
    LNode *A,*B;
    createListR(A,a,10);
    createListR(B,b,7);
    diff(A,B);
    return 0;
}
1,2,3,4,5,6,7,8,9
1 2 3 10