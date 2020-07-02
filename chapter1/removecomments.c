#include<stdio.h>

#define MAXLENGTH 1000
#define Y 1
#define N 0
int flag[3];
int retain = N;

/*
This program removes comments 
from a C program
*/

int mygetline(char line[], int max);
void removecomment(char line[], int len);

int main(){
    int len;
    char line[MAXLENGTH];
    while( (len = mygetline(line, MAXLENGTH)) > 0){
        removecomment(line, len);
        /*printf("%s", line);*/
    }
    return 0;
}

/* mygetline : stores the new line in the array and return length */
int mygetline(char line[], int max){
    int c, i;
    for(i = 0; (i < max -1) && ((c = getchar()) != EOF) && (c != '\n'); ++i){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* removecomment : removes comments in a given input line */
void removecomment(char line[], int len){
    int i, c;
    extern int flag[3], retain;
    if(retain == 0){
        for(i = 0; i < 3; ++i){
            flag[i] = 0;
        }
    }   
    for(i = 0; i < len; ++i){
        c = line[i];
        if(flag[0] == 0 && flag[1] == 0){    
            if(c == '\'' || c == '"'){
                flag[0] = 1;
                putchar(c);
            }
            else if(c == '/')
                flag[1] = 1;
            else
                putchar(c);
        }
        else if(flag[0] != 0){
            if(c == '\'' || c == '"'){
                flag[0] = 0;
            }        
            putchar(c);
        }
        else if(flag[1] == 1){    
            if(c == '*'){
                flag[2] = 1;
            }                
            else if(flag[2] == 0){    
                putchar('/');
                putchar(c);
                flag[1] = 0;
            }
            else if(c == '/'){
                flag[1] = 0;
                flag[2] = 0;
            }
        }
    }
    if(flag[2] == 1)
        retain = Y;
}