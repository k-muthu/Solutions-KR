#include <stdio.h>

#define SIZE 1000

static char allocbuf[SIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if(allocbuf + SIZE - allocp>= n){
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}

void afree(char *p){
    if(p >= allocbuf && p < allocp)
        allocp = p;
}

/* Testing functions alloc and afree */
int main(){
    int i;
    int n = 10;
    char *p;
    p = alloc(n);
    printf("index of element pointed by allocp after calling alloc(n), n = 10: %ld\n", allocp - allocbuf);
    for(i = 0; i < n - 1; ++i)
        *(p + i) = getchar();
    *(p + n - 1) = '\0';
    printf("%s\n", p);
    afree(p);
    printf("index of element pointed by allocp after calling afree(n), n = 10: %ld\n", allocp - allocbuf);
    return 0;
}