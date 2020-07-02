#include<stdio.h>
#define MAXLINE 1000

/*
This program reverses a given line
*/

int revs(char line[]);
int len(char line[]);
int mygetline(char line[], int max);

int main(){
    int len;
    char line[MAXLINE];
    while( (len = mygetline(line, MAXLINE) ) > 0){
        revs(line);
        printf("%s", line);
    }
    return 0;
}

/* getline: this function return a character string */
int mygetline(char s[], int max){
    int len;
    int c;
    for(len = 0; (len < (max -1)) && ( (c = getchar()) != EOF) && c != '\n'; ++len){
        s[len] = c;
    }
    if(c == '\n'){
        s[len] = '\n';
        ++len;
    }
    s[len] = '\0';
    return len;
}

/* len: This function return the length of a given string */
int len(char s[]){
    int length = 0;
    for(length = 0; s[length] != '\0'; length++)
        ;
    return length;
}

/* revs: This function reverses a given string */
int revs(char s[]){
    int length = len(s);
    int c;
    int i;
    int last;
    length = length - 1;
    last = length - 1;
    for(i = 0; i < length/2; i++){
        c = s[i];
        s[i] = s[last];
        s[last] = c;
        --last;
    }
    return 0;
}




