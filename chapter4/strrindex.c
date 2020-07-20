#include<stdio.h>

#define MAXLINE 1000

/*
this program implements strrindex(s1, s2)
that is given input(s1) it prints the position of 
rightmost occurence of s2 in s1.
Note : Excericise 4-1
*/

int mygetline(char s1[], int max);
int strrindex(char s1[], char s2[]);

char pattern[] = "grasp";

int main(){
    char input[MAXLINE];
    int len;
    while(mygetline(input, MAXLINE) > 0){
        printf("%d\n", strrindex(input, pattern));
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

int strrindex(char s1[], char s2[]){
    int i, j, k;
    int index = -1;
    for(i = 0; s1[i] != '\0'; ++i){
        for(j = i, k = 0; s1[j] == s2[k] && s2[k] != '\0'; ++k, ++j);

        if(k > 0 && s2[k] == '\0')
            index = i;
    }
    return index;
}