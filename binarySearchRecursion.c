#include<stdio.h>

int binarySearch(int array[], int search, int beg, int end){
    int mid = (beg+end)/2;
    if(beg>end)
        return -1;
    else if(array[mid]==search)
        return mid;
    else if(array[mid]>search)
        return binarySearch(array, search, beg, mid-1);
    else
        return binarySearch(array, search, mid+1, end);
}

int main(){
    int array[10], size, i, search;
    printf("How many elements do you want to enter? ");
    scanf("%d", &size);
    printf("Enter sorted array : \n");
    for(i=0;i<size;i++)
        scanf("%d", &array[i]);
    printf("Enter element to be searched : ");
    scanf("%d", &search);
    i = binarySearch(array, search, 0, size-1);
    if(i==-1)
        printf("%d is not found in the array.\n", search);
    else
        printf("%d is found at index : %d\n", search, i);
    return 0;
}
