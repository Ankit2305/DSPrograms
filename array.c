#include<stdio.h>
int main(){
    int arr[10], size, choice, choice2, i, j, data, loc, updated, found;
    printf("How many elements do yo want to enter? ");
    scanf("%d", &size);
    printf("Enter %d elements : \n", size);
    for(i=0;i<size;i++)
        scanf("%d", &arr[i]);
    while(choice!=0){
        system("cls");
        printf("ARRAY OPERATIONS : \n1> Traverse\n2> Insertion \n3> Deletion \n4> Linear Search \n5> Selection Sort\n0> Exit\n\nOption : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            if(size==0){
                printf("Array is empty.");
                break;
            }
            printf("Array : ");
            for(i=0;i<size;i++)
                printf("%d ", arr[i]);
            break;
        case 2:
            if(size==10)
                printf("\nOverflow\n");
            else{
                updated = 1;
                printf("INSERTION : \t1>Beginning\t2>Location\t3>End\nAny other key to abort insertion...\nOption : ");
                scanf("%d", &choice2);
                switch(choice2){
                case 1:
                    for(i=size-1;i>=0;i--){
                        arr[i+1] = arr[i];
                    }
                    printf("Enter Number : ");
                    scanf("%d", &data);
                    arr[0] = data;
                    size++;
                    break;
                case 2:
                    printf("\nLocation : ");
                    scanf("%d", &loc);
                    if(loc>size){
                        printf("\nCannot insert element here...\n");
                        updated = 0;
                        break;
                    }
                    for(i=size-1;i>=loc;i--){
                        arr[i+1] = arr[i];
                    }
                    printf("Enter Number : ");
                    scanf("%d", &data);
                    arr[loc] = data;
                    size++;
                    break;
                case 3:
                    printf("Enter Number : ");
                    scanf("%d", &data);
                    arr[size] = data;
                    size++;
                    break;
                default:
                    updated = 0;
                }
                if(updated){
                    printf("Updated Array : ");
                    for(i=0;i<size;i++)
                        printf("%d ", arr[i]);
                }
            }
            break;
        case 3:
            if(size==0)
                printf("\nUnderflow\n");
            else{
                updated = 1;
                printf("DELETION : \t1>Beginning\t2>Location\t3>End\nAny other key to abort deletion...\nOption : ");
                scanf("%d", &choice2);
                switch(choice2){
                case 1:
                    printf("Deleted %d from the array.\n", arr[0]);
                    for(i=0;i<size;i++){
                        arr[i] = arr[i+1];
                    }
                    size--;
                    break;
                case 2:
                    printf("\nLocation : ");
                    scanf("%d", &loc);
                    if(loc>=size){
                        printf("\nNo element at this location...\n");
                        updated = 0;
                        break;
                    }
                    printf("Deleted %d from the array.\n", arr[loc]);
                    for(i=loc;i<size;i++){
                        arr[i] = arr[i+1];
                    }
                    size--;
                    break;
                case 3:
                    printf("Deleted %d from array.\n", arr[size-1]);
                    size--;
                    break;
                default:
                    updated = 0;
                }

                if(updated){
                    printf("Updated Array : ");
                    for(i=0;i<size;i++)
                        printf("%d ", arr[i]);
                }
            }
            break;
        case 4:
            if(size==0){
                printf("Array is empty.");
                break;
            }
            printf("Enter element to be searched : ");
            scanf("%d", &data);
            found = 0;
            printf("Element found at index : ");
            for(i=0;i<size;i++){
                if(data == arr[i]){
                    printf(" %d", i);
                    found = 1;
                }
            }
            if(!found)
                printf(" Not found");
            break;
        case 5:
                if(size==0){
                    printf("Array is empty.");
                    break;
                }
                updated = 1;
                printf("SELECTION SORT : \t1>Increasing Order\t2>Decreasing Order\nAny other key to abort sorting...\nOption : ");
                scanf("%d", &choice2);
                switch(choice2){
                case 1:
                    printf("Performing Selection sort in increasing order...\n");
                    for(i=0;i<size;i++){
                        int min = i;
                        for(j=i+1;j<size;j++){
                                if(arr[min]>arr[j])
                                min = j;
                        }
                        if(min!=i){
                            int temp;
                            temp = arr[i];
                            arr[i] = arr[min];
                            arr[min] = temp;
                        }
                    }
                    break;
                case 2:
                    printf("Performing Selection sort in decreasing order...\n");
                    for(i=0;i<size;i++){
                        int max = i;
                        for(j=i+1;j<size;j++){
                                if(arr[max]<arr[j])
                                max = j;
                        }
                        if(max!=i){
                            int temp;
                            temp = arr[i];
                            arr[i] = arr[max];
                            arr[max] = temp;
                        }
                    }
                    break;
                default:
                    updated = 0;
                }

                if(updated){
                    printf("Updated Array : ");
                    for(i=0;i<size;i++)
                        printf("%d ", arr[i]);
                }
            break;
        case 0:
            printf("Program is requested to quit...");
            break;
        default:
            printf("\nNo option selected try again...\n");
        }
        printf("\n");
        system("pause");
    }
    return 0;
}
