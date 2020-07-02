#include<stdio.h>
#define MAXLINE 1000
#define INWS 1
#define NINWS 0
/*
This program removes trailling tabs, blanks
*/

int mygetline(char line[], int max);
int rmtrail(char line[]);
int rmexcess(char line[]);

int main(){
    char line[MAXLINE];
    while(mygetline(line, MAXLINE) > 0){
        rmexcess(line);
        rmtrail(line);
        printf("-----------------------------------\n");
        printf("%s", line);
    }
}

/* mgetline : returns the length of the line and stores the line in the array */
int mygetline(char s[], int max){
    int len;
    int c;
    for(len = 0; (len < (max - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++len){
        s[len] = c;
    }
    if(c == '\n'){
        s[len] = c;
        ++len;
    }
    s[len] = '\0';
    return len;
}

/* rmtrail : removes trailing whitespaces in a given line of input */
int rmtrail(char s[]){
    int index = 0;
    int temp;
    for(temp = 0; s[temp] != '\n'; ++temp){
        if(s[temp] != ' ' || s[temp] != '\t')
            index = temp;
    }
    if((temp - index) != temp){
        s[index + 1] = '\n';
        s[index + 2] = '\0';
    }
    else{
        s[0] = '\0';
    }
    return 0;
}   

/* rmexcess: removes extra whitespaces anywhere in the input */
int rmexcess(char s[]){
    int state = NINWS;
    int i;
    int c;
    if(s[0] == '\n')
        return 0;
    for(i = 0; s[i] != '\0'; ++i){
        c = s[i];
        if( c != ' ' && c != '\t'){
            putchar(c);
            state = NINWS;
        }
        else if(state == NINWS){
            putchar(c);
            state = INWS;
        }
    }
    return 0;
}