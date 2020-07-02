#include<stdio.h>
#define MAXLINE 1000   /* The maximum size of line allowed for the input*/

/*
This function prints the longest line
in a given list of lines
*/

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
    int len; /* Current line length*/
    int max; /*maximum length seen so far*/
    char line[MAXLINE]; /*Current input line*/
    char longest[MAXLINE]; /*Contains the longest line so far*/
    max = 0;
    while((len = mygetline(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0) {
        printf("%s", longest);
    }
    return 0;
}

/* getline: read a line into the array, return its length */
int mygetline(char s[], int lim){
    int c, i;
    for(i = 0; (i < (lim - 1)) && ((c = getchar()) != EOF) && c != '\n'; i++)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copies a line from the 'from' array to the 'to' array */
void copy(char to[], char from[]){
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}