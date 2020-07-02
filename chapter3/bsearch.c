#include<stdio.h>
#define MAXLENGTH 10;
/*
This program implements binary search 
with the required lesses if conditions
*/

int binarysearch(int numbers[], int n, int element);

int main(){
    int numbers[10];
    int i;
    for(i = 0; i < 10; ++i){
        numbers[i] = 20 * i;
    } 
    int element = 100;
    printf("%d\n", binarysearch(numbers, 10, element));
}

int binarysearch(int numbers[], int n, int element){
    int index = -1;
    int low, mid, high;
    low = 0;
    high = n - 1;
    while( (low <= high) && (numbers[mid = (low + high) / 2] != element)){
        if(numbers[mid] > element){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if(low <= high)
        index = mid;
    return index;
}