#include<stdio.h>

display(int queue[], int front, int rear){
    int i;
    if(rear==-1)
        printf("\nQueue is empty...");
    else{
        printf("\nQueue : ");
        for(i=front;i<=rear;i++){
            printf(" %d", queue[i]);
        }
    }
}

enqueue(int queue[], int* front, int* rear, int element){
    queue[++*rear] = element;
}

int dequeue(int queue[], int* front, int* rear){
    int removed = queue[*front];
    if(*front==*rear){
        *front = -1;
        *rear = -1;
    }
    else
        ++*front;
    return removed;
}

int main(){
    int queue[5], front = -1, rear = -1, choice = 1, element;
    while(choice!=0){
        system("cls");
        printf("QUEUE OPERATION : \n1> Enqueue\n2> Dequeue\n3> Display\n0> Exit\nOption : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(rear==4)
                    printf("\nOverflow\n");
                else{
                    if(rear==-1)
                        front = 0;
                    printf("Enter element : ");
                    scanf("%d", &element);
                    enqueue(queue, &front, &rear, element);
                    printf("\nQueue updated...");
                    display(queue, front, rear);
                }
                break;
            case 2:
                if(rear==-1)
                    printf("\nUnderflow\n");
                else{
                    printf("\n%d has been removed from the queue...", dequeue(queue, &front, &rear));
                    printf("\nQueue updated...");
                    display(queue, front, rear);
                }
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 0:
                printf("\nProgram is requested to quit...");
                break;
            default:
                printf("\nNo option selected...please try again...");
        }
        printf("\n");
        system("pause");
    }
    return 0;
}
