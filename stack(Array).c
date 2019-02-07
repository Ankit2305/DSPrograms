#include<stdio.h>

void view(int array[], int tos){
    int i;
    if(tos==-1)
        printf("\nStack is empty...\n");
    else{
        printf("Stack : ");
        for(i=0;i<=tos;i++)
            printf("%d ", array[i]);
    }
}

int push(int array[], int tos){
    int element, i;
    if(tos == 4)
        printf("Overflow");
    else{
        printf("Enter element : ");
        scanf("%d", &element);
        array[++tos] = element;
    }
    return tos;
}

int pop(int array[], int tos){
    int i;
    if(tos==-1)
        printf("Underflow");
    else{
        printf("%d has been popped out of stack\n", array[tos]);
        tos--;
    }
    return tos;
}

int main(){
    int array[5], choice, tos = -1, i, updated;
    while(choice!=0){
        system("cls");
        printf("STACK OPERATIONS:\n1> Push\n2> Pop\n3> Display\n0> Exit\n\nOption : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            updated = tos;
            tos = push(array, tos);
            if(tos>updated){
                printf("Stack updated...\n");
                view(array, tos);
            }
            break;
        case 2 :
            updated = tos;
            tos = pop(array, tos);
            if(tos<updated){
                printf("Stack updated...\n");
                view(array, tos);
            }
            break;
        case 3:
            view(array, tos);
            break;
        case 0:
            break;
        default:
            printf("No option selected, please try again...");
        }
        printf("\n");
        system("pause");
    }
    return 0;
}
