#include<stdio.h>

#define MAXLINE 100

/*
This program implements strcat(s, t)
with the assumption that s has enough
space to hold t
*/

void mystrcat(char input[], char tobeadded[]);

int main(){
    char input[MAXLINE];
    char original[] = "support is";
    char tobeadded[] = " so slow in replying to mails\n";
    int i;
    for(i = 0; original[i] != '\0'; ++i){
        input[i] = original[i];
    }
    input[i] = '\0';
    mystrcat(input, tobeadded);
    printf("Printing the resultant string\n");
    printf("%s", input);
    return 0;
}

void mystrcat(char input[], char tobeadded[]){
    int i,j;
    for(i = 0; input[i] != '\0'; ++i);
    for(j = 0; tobeadded[j] != '\0'; ++j){
        input[i++] = tobeadded[j];
    }
    input[i] = '\0';
}