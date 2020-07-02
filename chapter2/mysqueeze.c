#include<stdio.h>

/*
This program implements squeeze(s1, s2) : it 
deletes any character in s1 that also occurs in s2
*/

void mysqueeze(char s1[], char s2[]);
int presentin(char s[], char a);

int main(){
    char s1[] = "my name is muthukrishna\n";
    char s2[] = " ";
    mysqueeze(s1, s2);
    printf("Printing string 1 after executing the squeeze function\n");
    printf("%s", s1);
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

void mysqueeze(char s1[], char s2[]){
    int i, j;
    for(i = j = 0; s1[i] != '\0'; ++i){
        if(!presentin(s2, s1[i])){
            /* a character in s1 is present in s2 */
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}