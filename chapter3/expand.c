#include<stdio.h>

#define MAXLINE 1000
#define FOUND 1
#define NOTFOUND 0

/*
This program implements expand(s1, s2) function.
Takes the string s1 and expands all shorthand notations
and copies it to s2.
For example a-z will be converted to abc...z
*/

int mygetline(char line[], int max);
int expand(char s1[], char s2[]);

int main(){
    char s1[MAXLINE];
    char s2[MAXLINE];
    mygetline(s1, MAXLINE);
    expand(s1, s2);
    printf("%s", s2);
    return 0;
}

int mygetline(char line[], int max){
    int length = 0;
    int c, i;
    for(i = 0; i < max && (c = getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }
    if(c == '\n'){
        line[i++] = '\n';
    }
    line[i] = '\0';
    return i;
}

int expand(char s1[], char s2[]){
    int i, j, c, state = NOTFOUND, k;
    for(i = j = 0; (c = s1[i]) != '\0';){
        if(c == '-'){
            if(i == 0 || s1[i+1] == '\n'){
                s2[j++] = '-';
            }
            else{
                for(k = s1[i-1] + 1; k <= s1[i+1]; ++k){
                    s2[j] = k;
                    ++j;
                }
                ++i;
            }
        }
        else{
            s2[j++] = c;
        }
        ++i;
    }
    s2[j] = c;
    return j;
}