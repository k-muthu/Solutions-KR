#include <stdio.h>

#define swap(t, x, y) do {\
t x##y = x; \
x = y;\
y = x##y;\
}while(0);

int main(){
    int a = 5;
    int b = 6;
    swap(int, a, b)
    printf("a : %d\n", a);
    printf("b : %d\n", b);
    return 0;
}