#include <stdio.h>

#define MAXLINE 100

void reverse(char s[], int start, int end);
int mystrlen(char s[]);

int main(){
    char s[] = "This program reverses the input string using recursion";
    int len = mystrlen(s);
    reverse(s, 0, len - 1);
    printf("%s\n", s);
    return 0;
}

int mystrlen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i);
    return i;
}

void reverse(char s[], int start, int end){
    if(start < end){
        int c;
        c = s[start];
        s[start] = s[end];
        s[end] = c;
        ++start;
        --end;
        reverse(s, start, end);
    }
    return;
}