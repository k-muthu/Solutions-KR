#include<stdio.h>

#define MAXLINE 1000

/*
This program implements escapetoreal and
realtoescape functions i.e. replacing escape 
sequence characters to their representation
like \n for newline etc and vice versa
*/

void escapetoreal(char s[], char t[]);
void realtoescape(char s[], char t[]);
int mygetline(char line[], int max);

int main(){
    char line[MAXLINE];
    char output[MAXLINE];
    int length;
    while( (length = mygetline(line, MAXLINE)) > 0 ){
        realtoescape(line, output);
        printf("%s\n", output);
        escapetoreal(line, output);
        printf("%s", output);
    }
    return 0;
}

int mygetline(char line[], int max){
    int c, i;
    for(i = 0; (i < max - 1) && (c = getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }
    if(c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}

/* Converts escape sequence notation to acutal character display on output */
void escapetoreal(char s[], char t[]){
    int i, j, c;
    i = j = 0;
    while(s[i] != '\0'){
        if(s[i] == '\\'){
            switch(s[i+1]){
                case '\\' : t[j++] = '\\';
                            break;

                case 't' : t[j++] = '\t';
                            break;

                case 'n' : t[j++] = '\n';
                            break;
                
                default : t[j++] = '\\';
                            t[j++] = s[i+1];
            }
            i = i + 2;
        }
        else{
            t[j++] = s[i++];
        }
    }
    t[j] = '\0';
}

/* Converts actual display on output to escae sequence notation */
void realtoescape(char s[], char t[]){
    int i, j;
    for(i = j = 0; s[i] != '\0'; ++i){
        switch(s[i]){
            case '\t' : t[j++] = '\\';
                        t[j++] = 't';   
                        break;
            
            case '\n' : t[j++] = '\\';
                        t[j++] = 'n';   
                        break;
            
            case '\\' : t[j++] = '\\';
                        t[j++] = '\\';   
                        break;
            
            default :   t[j++] = s[i];
                        break;
        }
    }
    t[j++] = '\\';
    t[j++] = '0';
    t[j] = '\0';
}
