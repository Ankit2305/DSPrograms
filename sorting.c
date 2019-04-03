#include<stdio.h>

void display(int array[], int n)
{
    int i;
    printf("Array :");
    for(i=0; i<n; i++)
    {
        printf(" %d", array[i]);
    }
}

//Bubble Sort
void bubbleSort(int a[], int order, int n)
{
    int i, j, swapped;
    for(i=0; i<n-1; i++)
    {
        swapped = 0;
        for(j=0; j<n-i-1; j++)
        {
            if(order == 1 && a[j] > a[j+1])
            {
                swapped = 1;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            if(order == 2 && a[j] < a[j+1])
            {
                swapped = 1;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(!swapped)
            break;
    }
}

//Indertion Sort
void insertionSort(int a[], int order, int n)
{
    int i, j, temp;
    for(i=1; i<n; i++)
    {
        temp = a[i];
        j = i;
        if(order==1)
            while(j>0 && a[j-1] > temp)
            {
                a[j] = a[j-1];
                j--;
            }
        else
            while(j>0 && a[j-1] < temp)
            {
                a[j] = a[j-1];
                j--;
            }
        a[j] = temp;
    }
}


//Merge Sort
void Merge(int a[], int left[], int right[], int order, int aL, int lL, int rL)
{
    int i=0, j=0, k=0;
    if(order == 1)
    {
        while(i<lL && j<rL)
        {
            if(left[i] < right[j])
            {
                a[k] = left[i];
                k++;
                i++;
            }
            else
            {
                a[k] = right[j];
                k++;
                j++;
            }
        }
        while(i<lL)
        {
            a[k] = left[i];
            k++;
            i++;
        }
        while(j<rL)
        {
            a[k] = right[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i<lL && j<rL)
        {
            if(left[i] > right[j])
            {
                a[k] = left[i];
                k++;
                i++;
            }
            else
            {
                a[k] = right[j];
                k++;
                j++;
            }
        }
        while(i<lL)
        {
            a[k] = left[i];
            k++;
            i++;
        }
        while(j<rL)
        {
            a[k] = right[j];
            k++;
            j++;
        }
    }
}

void mergeSort(int a[], int order, int n)
{
    if(n>1)
    {
        int mid = n/2, i;
        int left[mid], right[n-mid];
        for(i=0; i<mid; i++)
            left[i] = a[i];
        for(i=0; i<n-mid; i++)
            right[i] = a[mid+i];
        mergeSort(left, order, mid);
        mergeSort(right, order, n-mid);
        Merge(a, left, right, order, n, mid, n-mid);
    }
}

//Quick Sort
int partition(int a[], int start, int end, int order)
{
    int pivot = a[end];
    int partitionIndex = 0, i;
    for(i=0; i<=end; i++)
    {
        if(order==1 && a[i] < pivot)
        {
            int temp = a[i];
            a[i] = a[partitionIndex];
            a[partitionIndex] = temp;
            partitionIndex++;
        }
        if(order==2 &&a[i] > pivot)
        {
            int temp = a[i];
            a[i] = a[partitionIndex];
            a[partitionIndex] = temp;
            partitionIndex++;
        }
    }
    int temp = a[partitionIndex];
    a[partitionIndex] = a[end];
    a[end] = temp;
    return partitionIndex;
}

void quickSort(int a[], int start, int end, int order)
{
    if(start<end)
    {
        int partitionIndex = partition(a, start, end, order);
        quickSort(a, start, partitionIndex-1, order);
        quickSort(a, partitionIndex+1, end, order);
    }
}

//Shell Sort
void shellSort(int a[], int n, int order)
{
    int gap = n/2, i, j, temp;
    while(gap!=0)
    {
        for(i=gap; i<n; i++)
        {
            temp = a[i];
            j = i;
            if(order == 1)
                while(j>=gap && a[j-gap] > temp)
                {
                    a[j] = a[j-gap];
                    j -= gap;
                }
            else
                while(j>=gap && a[j-gap] < temp)
                {
                    a[j] = a[j-gap];
                    j -= gap;
                }
            a[j] = temp;
        }
        gap = gap/2;
    }
}

//Heap Sort
void heapify(int a[], int n, int i, int order)
{
    int root, l, r;
    root = i;
    l = 2*i + 1;
    r = 2*i + 2;

    if(order == 1)
    {
        if(l<n && a[l] > a[root])
            root = l;

        if(r<n && a[r] > a[root])
            root = r;
    }
    else
    {
        if(l<n && a[l] < a[root])
            root = l;

        if(r<n && a[r] < a[root])
            root = r;
    }
    if(root != i)
    {
        int temp = a[i];
        a[i] = a[root];
        a[root] = temp;

        heapify(a, n, root, order);
    }
}

void heapSort(int a[], int n, int order)
{
    int i;
    for(i=n-1;i>=0;i--){
        heapify(a, n, i, order);
    }
    for(i=n-1;i>=0;i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0, order);
    }
}

int main()
{
    int n, i, choice, choice2;
    printf("How many elements do you want to insert in array? ");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d elements :\n", n);
    for(i=0; i<n; i++)
        scanf("%d", &array[i]);
    display(array, n);
    printf("\n");
    system("pause");
    while(choice!=0)
    {
        system("cls");
        printf("Sorting Techniques : \n1> Bubble Sort\n2> Insertion Sort\n3> Merge Sort\n4> Shell Sort\n5> Quick Sort\n6> Heap Sort\n0> Exit\n\nOption : ");
        scanf("%d", &choice);
        if(choice == 0)
            break;
        printf("Select Order : \n1> Increasing\n2> Decreasing\n\nOption : ");
        scanf("%d", &choice2);
        switch(choice)
        {
        case 1:
            bubbleSort(array, choice2, n);
            display(array, n);
            break;
        case 2:
            insertionSort(array, choice2, n);
            display(array, n);
            break;
        case 3:
            mergeSort(array, choice2, n);
            display(array, n);
            break;
        case 4:
            shellSort(array, n, choice2);
            display(array, n);
            break;
        case 5:
            quickSort(array, 0, n-1, choice2);
            display(array, n);
            break;
        case 6:
            heapSort(array, n, choice2);
            display(array, n);
            break;
        default:
            printf("\nNo option selected, please try again...");
        }
        printf("\n");
        system("pause");
    }
}


