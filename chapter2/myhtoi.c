#include<stdio.h>

/* 
This program converts a string of hexadecimal 
digits to its decimal equivalent
*/

int myhtoi(char input[]);
int returnint(char s);

int main(){
    char input[] = "0x11F";
    int output;
    output = myhtoi(input);
    printf("The decimal equivalent of %s is %d\n", input, output);
    return 0;
}

int returnint(char s){
    int output = -1;
    if(s >= 'a' && s <= 'f'){
        output = 9 + (s - 'a') + 1;
    }
    else if(s >= 'A' && s<= 'F'){
        output = 9 + (s - 'A') + 1;
    }
    else if(s >= '0' && s<= '9'){
        output = s - '0';
    }
    return output;
}

int myhtoi(char input[]){
    int output = 0;
    int length = 0;
    int pow = 1;
    int index_to_stop = 0;
    while(input[length] != '\0')
        ++length;
    if(input[0] == '0' && (input[1] == 'x' || input[1] == 'X'))
        index_to_stop = 2;
    while(length > index_to_stop){
        output += returnint(input[length - 1]) * pow;
        pow = pow * 16;
        length = length - 1;
    }
    return output;
}