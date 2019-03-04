#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int info;
    struct node *next;
};

display(struct node *head, char type[]){
    struct node *ptr=head;
    if(head==NULL){
        printf("\n%s is empty...", type);
    }
    else{
        printf("\n%s : HEAD ->", type);
        while(ptr!=NULL){
            printf(" %d ->", ptr->info);
            ptr = ptr->next;
        }
        printf(" NULL");
    }
}

struct node* insertEnd(struct node *head){
    int element;
    printf("\nEnter element : ");
    scanf("%d", &element);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info=element;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
    }
    else{
        struct node *head1 = head;
        while(head1->next!=NULL)
            head1 = head1->next;
        head1->next=newNode;
    }
    return head;
}

struct node* deleteEnd(struct node *head, int *updated){
    struct node *ptr = head, *preptr=NULL;
    if(head==NULL){
        printf("\nUnderflow");
        *updated = 0;
        return head;
    }
    while(ptr->next!=NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    if(preptr == NULL)
        head = NULL;
    else
        preptr->next = NULL;
    printf("\nPopped %d from the stack...", ptr->info);
    free(ptr);
    return head;
}

struct node* deleteBeg(struct node *head, int *updated){
    struct node *ptr = head;
    if(head==NULL){
        printf("\nUnderflow");
        *updated = 0;
        return head;
    }
    head = head->next;
    printf("\nDequeued %d from the queue...", ptr->info);
    free(ptr);
    return head;
}

int peek(struct node *head){
    if(head==NULL)
        return -1000;
    while(head->next!=NULL)
        head = head->next;
    return head->info;
}

stack(){
    char type[10];
    int updated, tos;
    strcpy(type, "Stack");
    struct node *head=NULL;
    int choice = 1;
    while(choice!=0){
        system("cls");
        printf("LINKED LIST > STACK >\n1> Push\n2> Pop\n3> Peek\n4> Display\n0> Back\nOption: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            head = insertEnd(head);
            printf("\nStack updated...");
            display(head, type);
            printf("\n");
            system("pause");
            break;
        case 2:
            updated = 1;
            head = deleteEnd(head, &updated);
            if(updated){
                printf("\nStack updated...");
                display(head, type);
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            tos = peek(head);
            if(tos==-1000)
                printf("\nStack is empty...");
            else
                printf("\nElement at the top of the stack is %d", tos);
            printf("\n");
            system("pause");
            break;
        case 4:
            display(head, type);
            printf("\n");
            system("pause");
            break;
        case 0:
            break;
        default:
            printf("\nNo option selected, please try again...");
            printf("\n");
            system("pause");
        }
    }
}

queue(){
    char type[10];
    int updated;
    strcpy(type, "Queue");
    struct node *head=NULL;
    int choice = 1;
    while(choice!=0){
        system("cls");
        printf("LINKED LIST > QUEUE >\n1> Enqueue\n2> Dequeue\n3> Display\n0> Back\nOption: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            head = insertEnd(head);
            printf("Queue updated...");
            display(head, type);
            printf("\n");
            system("pause");
            break;
        case 2:
            updated = 1;
            head = deleteBeg(head, &updated);
            if(updated){
                printf("\nQueue updated...");
                display(head, type);
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            display(head, type);
            printf("\n");
            system("pause");
            break;
        case 0:
            break;
        default:
            printf("\nNo option selected, please try again...");
            printf("\n");
            system("pause");

        }
    }
}

int main(){
    int choice=1;
    while(choice!=0){
        system("cls");
        printf("LINKED LIST >\n1> Stack\n2> Queue\n0> Exit\n\nOption : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            stack();
            break;
        case 2:
            queue();
            break;
        case 0:
            printf("\nProgram is requested to quit...");
            break;
        default:
            printf("\nNo option selected, please try again...");
            printf("\n");
            system("pause");
        }
    }
}
