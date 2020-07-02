#include<stdio.h>

#define FOUND 1
#define NOTFOUND 0

/*
This program implements the any(str1, str2) function
This function returns the first index in string 1 where 
any of string 2s' character is found
*/

int presentin(char s1[], char a);
int any(char s1[], char s2[]);

int main(){
    char s1[] = "hi there, it looks like its going to rain today";
    char s2[] = "h";
    printf("%d\n", any(s1, s2));
    return 0;
}

int presentin(char s[], char a){
    int result = 0;
    int j = 0;
    while(s[j] != '\0'){
        if(s[j] == a)
            result = 1;
        ++j;
    }
    return result;
}

int any(char s1[], char s2[]){
    int result = -1;
    int i = 0;
    int state = NOTFOUND;
    while(!state && s1[i] != '\0'){
        if(presentin(s2, s1[i])){
            result = i;
            state = FOUND;
        }
        ++i;
    }
    return result;
}