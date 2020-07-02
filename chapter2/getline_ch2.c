#include<stdio.h>

#define MAXLINE 1000

/*
This program implements get line 
without using any logical operators
*/

int mygetline(char line[], int max);

int main(){
    char line[MAXLINE];
    int len;
    while( (len = mygetline(line, MAXLINE)) > 0){
        printf("%s", line);
    }
    return 0;
}

int mygetline(char line[], int max){
    int len, i;
    int c;
    for(i = 0; i < max - 1; ++i){
        c = getchar();
        line[i] = c;
        if(c == '\n'){
            len = i + 1;
            line[i + 1] = '\0';
            i = max - 1;
        }
        else if(c == EOF){
            line[i] = '\0';
            len = i;
            i = max -1;
        }
    }
    // for(len = 0; ((len < max - 1) * ((c = getchar()) != EOF) * (c != '\n')) > 0; ++len){
    //     line[len] = c;
    // }
    if(c == '\n'){
        line[len] = '\n';
        ++len;
    }
    line[len] = '\0';
    return len;
}