#include<stdio.h>

#define MAXLENGTH 1000
#define RETAIN 1
#define NORETAIN 0

int lineno;     /*This variable checks for '{}' while in other line */

int mygetline(char line[], int max);
int balancer(char line[], int len, int linenum);

int main(){
    int len;
    char line[MAXLENGTH];
    int number = 0;
    while( (len = mygetline(line, MAXLENGTH)) > 0){
        ++number;
        balancer(line, len, number);
    }
    return 0;
}

int mygetline(char line[], int max){
    int c, i;
    for(i = 0; (i < (max - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++i){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

int balancer(char line[], int length, int linenumber){
    int flag[8];
    /* Flag[0] : for {}, Flag[1] : for (), Flag[2] : for [] */
    /* Flag[3] : for '', Flag[4] : for "", Flag[5] : for comment */
    /* Flag[6] : for escape sequences */
    extern int lineno = NORETAIN;
    int c, i;
    for(i = 0; i < 8; ++i)
        flag[i] = 0;
    i = 0;
    while(i < length){
        flag[7] = 0;
        c = line[i];
        if(c == '{' && flag[0] == 0){    
            ++flag[0];
            ++i;
        }
        else if(c == '}'){
            --flag[0];
            ++i;
        }
        else{
            ++flag[7];
        }
        if(c == '(' && flag[1] == 0){
            ++flag[1];
            ++i;
        }
        else if(c == ')'){
            --flag[1];
            ++i;
        }
        else{
            ++flag[7];
        }
        if(c == '[' && flag[2] == 0){
            ++flag[2];
            ++i;
        }
        else if(c == ']'){
            --flag[2];
            ++i;
        }
        else{
            ++flag[7];
        }
        if(c == '\'' && flag[3] == 0){
            ++flag[3];
            ++i;
        }
        else if(c == '\''){
            --flag[3];
            ++i;
        }
        else{
            ++flag[7];
        }
        if(c == '"' && flag[4] == 0){
            ++flag[4];
            ++i;
        }
        else if(c == '"'){
            --flag[4];
            ++i;
        }
        else{
            ++flag[7];
        }
        if(c == '\\' && (line[i+1] == ' ' || line[i+1] == '\t')){
            ++flag[6];
            ++i;
        }
        else{
            ++flag[7];
        }
        if(c == '/' && line[i+1] == '*'){
            ++flag[5];
            i = i + 2;
        }
        else if(c == '*' && line[i+1] == '/'){
            --flag[5];
            i = i + 2;
        }
        else{
            ++flag[7];
        }
        if(flag[7] == 7){
            ++i;
        }
    }
    for(i = 0; i < 7; ++i){
        if(flag[i] != 0){
            printf("There is an unbalanced character at line number : %d\n", linenumber);
        }
    }
    return 0;
}