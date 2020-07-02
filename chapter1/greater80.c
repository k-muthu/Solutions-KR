#include<stdio.h>
#define MAXLINE 1000
#define LINELENGTH 40
/*
This program prints all the lines 
whose length is greater than 80
*/

int mygetline(char line[], int maxlength);

int main(){
    int len, i;
    char line[MAXLINE];
    while( (len = mygetline(line, MAXLINE) ) > 0){
        if (len > LINELENGTH){
            printf("%s", line);
            printf("The line length is %d \n", len);
        }
    }
    return 0;
}

/* mygetline: takes a line from input and returns its length */
int mygetline(char s[], int max){
    int len, c;
    for(len = 0; (len < max - 1) && ((c = getchar()) != EOF) && c != '\n'; ++len){
        s[len] = c;
    }
    if(c == '\n'){
        s[len] = c;
        ++len;
    }
    s[len] = '\0';
    return len;
}