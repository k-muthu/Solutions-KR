#include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];

int mygetline(char *line, int max);

int main(){
    while(mygetline(line, MAXLINE) > 0){
        printf("%s", line);
    }
    return 0;
}

int mygetline(char *line, int max){
    int i, c;
    for(i = 0, c = 0; (c < (max - 1) && (c = getchar()) != EOF && c != '\n'); ++i){
        *(line + i) = c;
    }
    if(c == '\n'){
        *(line + i) = '\n';
        ++i;
    }
    *(line + i) = '\0';
    return i;
}