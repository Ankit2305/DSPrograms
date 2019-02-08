#include<stdio.h>

AscendingSort(int SortArray[], int ArraySize){
    int i,j,temp;
    for(i = 0;i < ArraySize;i++){
        for(j = i;j < ArraySize;j++){
            if(SortArray[i] > SortArray[j]){
                temp = SortArray[i];
                SortArray[i] = SortArray[j];
                SortArray[j] = temp;
            }
        }
    }
    printf("Sorted Array is \n");
    for(i = 0;i < ArraySize ; i++){
        printf("%d ", SortArray[i]);
    }
}

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
    printf("Enter array : \n");
    for(i=0;i<size;i++)
        scanf("%d", &array[i]);
    AscendingSort(array,size);
    printf("\nEnter element to be searched : ");
    scanf("%d", &search);
    i = binarySearch(array, search, 0, size-1);
    if(i==-1)
        printf("%d is not found in the array.\n", search);
    else
        printf("%d is found at index : %d\n", search, i);
    return 0;
}
