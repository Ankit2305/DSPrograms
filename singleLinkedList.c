#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* next;
};

int count(struct node* head){
    struct node* ptr = head;
    int counter = 0;
    while(ptr!=NULL){
        counter++;
        ptr=ptr->next;
    }
    return counter;
}

display(struct node* head){
    struct node* ptr = head;
    if(ptr==NULL)
        printf("\nLinked List is empty...");
    else{
        printf("\nLinked List : HEAD ->");
        while(ptr!=NULL){
            printf(" %d ->", ptr->info);
            ptr = ptr->next;
        }
        printf(" NULL");
    }
}

struct node* insertion(struct node* head, int element, int location){
    int i;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = element;
    if(head==NULL){
        head = newNode;
        head->next=NULL;
    }
    else{
        if(location==1){
            newNode->next=head;
            head=newNode;
        }
        else{
            struct node* ptr = head;
            for(i=1;i<location-1;i++){
                    ptr=ptr->next;
            }
            struct node* temp = ptr->next;
            ptr->next = newNode;
            newNode->next = temp;
        }

    }
    return head;
}

struct node* deletion(struct node* head, int location){
    int i;
    struct node* ptr = head;
    if(location==1){
        printf("\nDeleted %d from Linked List", head->info);
        head = head->next;
    }
    else{
        for(i=1;i<location-1;i++)
            ptr=ptr->next;
        struct node* newptr = ptr->next;
        printf("\nDeleted %d from Linked List", newptr->info);
        ptr->next = newptr->next;
    }
    return head;
}

int main(){
    struct node* head = NULL;
    int choice = 1, choice2, element, location;
    while(choice!=0){
        system("cls");
        printf("SINGLE LINKED LIST OPERATIONS:\n1> Insertion\n2> Deletion\n3> Display\n0> Exit\nChoice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nInsertion:\t1> Beginning\t2> Location\t3> End\nAny other key to abort insertion...\nChoice : ");
                scanf("%d", &choice2);
                switch(choice2){
                    case 1:
                        printf("\nEnter element : ");
                        scanf("%d", &element);
                        head = insertion(head, element, 1);
                        printf("\nLinked-List updated...");
                        display(head);
                        break;
                    case 2:
                        printf("Enter location : ");
                        scanf("%d", &location);
                        if(location>count(head)+1 || location<1)
                            printf("\nUnable to insert element here...\n");
                        else{
                            printf("Enter element : ");
                            scanf("%d", &element);
                            head = insertion(head, element, location);
                            printf("\nLinked-List updated...");
                            display(head);
                        }
                        break;
                    case 3:
                        printf("\nEnter element : ");
                        scanf("%d", &element);
                        head = insertion(head, element, count(head)+1);
                        printf("\nLinked-List updated...");
                        display(head);
                        break;
                }
                break;
            case 2:
                if(head==NULL){
                    printf("\nUnderflow\n");
                    break;
                }
                printf("\nDeletion:\t1> Beginning\t2> Location\t3> End\nAny other key to abort insertion...\nChoice : ");
                scanf("%d", &choice2);
                switch(choice2){
                    case 1:
                        head = deletion(head, 1);
                        printf("\nLinked-List updated...");
                        display(head);
                        break;
                    case 2:
                        printf("Enter location : ");
                        scanf("%d", &location);
                        if(location>count(head) && location<1)
                            printf("\nNo element at this position...\n");
                        else{
                            head = deletion(head, location);
                            printf("\nLinked-List updated...");
                            display(head);
                        }
                        break;
                    case 3:
                        head = deletion(head, count(head));
                        printf("\nLinked-List updated...");
                        display(head);
                        break;
                }
                break;
            case 3:
                display(head);
                break;
            case 0:
                printf("\nProgram is requested to quit...\n");
                break;
            default:
                printf("No option selected, please try again...");
        }
        printf("\n");
        system("pause");
    }
}
