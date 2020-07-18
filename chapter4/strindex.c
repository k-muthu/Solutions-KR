#include<stdio.h>

#define MAXLINE 1000

/*
this program implements a basic version of grep
that is given input(s1) it prints all the lines 
consisting of a given pattern(s2).
Note : This program is not a part of any excercise.
*/

int mygetline(char s1[], int max);
int strindex(char s1[], char s2[]);

char pattern[] = "ould";

int main(){
    char input[MAXLINE];
    int len;
    while(mygetline(input, MAXLINE) > 0){
        if(strindex(input, pattern) > -1)
            printf("%s", input);
    }
    return 0;
}

int mygetline(char s1[], int max){
    int c, j;
    j = 0;
    while(--max > 0 && (c = getchar()) != EOF && c != '\n'){
        s1[j++] = c;
    }
    if(c == '\n'){
        s1[j++] = c;
    }
    s1[j] = '\0';
    return j;
}

int strindex(char s1[], char s2[]){
    int i, j, k;
    for(i = 0; s1[i] != '\0'; ++i){
        for(j = i, k = 0; s1[j] == s2[k] && s2[k] != '\0'; ++k, ++j);

        if(k > 0 && s2[k] == '\0')
            return i;
    }
    return -1;
}
