#include<stdio.h>

#define BREAKAT 20
#define INS 1
#define OOS 0

/*
This program folds long input lines
into two or more shorter lines
*/

int main(){
    int count = 0;
    int c, state = OOS;
    int nws = 0;
    while( (c = getchar()) != EOF){
        if(count == BREAKAT){
            if(c == '.'){
                putchar(c);
                putchar('\n');
            }
            else if((nws == 0) && (c != ' ' || c != '\t')){
                putchar('-');
                putchar('\n');
            }
            else{
                putchar('\n');
            }
            count = 0;
            state = OOS;
            nws = 0;
        }
        if(c != ' ' && c != '\t'){
            while(nws > 0){
                putchar(' ');
                --nws;
            }
            ++count;
            putchar(c);
            state = OOS;
            nws = 0;
        }
        else if((c == ' ' || c == '\t') && state == OOS){
            state = INS;
            ++nws;
            ++count;
        }
        else{
            ++nws;
            ++count;
        }
    }
    return 0;
}
