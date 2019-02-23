#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* next;
};

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

struct node* insertion(struct node* head, int element, int location, int search, int *updated){
    int i;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = element;
    if(head==NULL){
        if(location==1){
            printf("No element found with value %d", search);
            return head;
        }
        head = newNode;
        head->next=NULL;
    }
    else{
        if(location==0){
            newNode->next=head;
            head=newNode;
        }
        else if(location==1){
            struct node* ptr = head;
            while(ptr!=NULL && ptr->info!=search){
                ptr=ptr->next;
            }
            if(ptr==NULL){
                printf("No element found with value %d", search);
                *updated = 0;
            }
            else{
                newNode->next = ptr->next;
                ptr->next = newNode;
            }
        }
        else{
            struct node* ptr = head;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
        }
    }
    return head;
}

struct node* deletion(struct node* head, int location, int search, int *updated){
    int i;
    if(location==0){
        struct node* head2 = head;
        printf("\nDeleted %d from Linked List", head->info);
        head = head->next;
        free(head2);
    }
    else if(location==1){
        struct node *head1 = head, *head2 = NULL;
        while(head1!=NULL && head1->info!=search){
            head2 = head1;
            head1 = head1->next;
        }
        if(head1==NULL){
            printf("\nNo element found with value %d", search);
            *updated = 0;
        }
        else{
            printf("\nDeleted %d from Linked List", head1->info);
            if(head2==NULL)
                head = head1->next;
            else
                head2->next = head1->next;
            free(head1);
        }
    }
    else{
        struct node* head1 = head;
        struct node* head2 = NULL;
        while(head1->next!=NULL){
            head2 = head1;
            head1 = head1->next;
        }
        printf("\nDeleted %d from Linked List", head1->info);
        free(head1);
        if(head2==NULL)
            head = NULL;
        else
            head2->next = NULL;
    }
    return head;
}

int main(){
    struct node* head = NULL;
    int choice = 1, choice2, element, location, updated = 1;
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
                        head = insertion(head, element, 0, 0, &updated);
                        printf("\nLinked-List updated...");
                        display(head);
                        break;
                    case 2:
                        printf("Enter location : ");
                        scanf("%d", &location);
                        printf("Enter element : ");
                        scanf("%d", &element);
                        head = insertion(head, element,1 , location, &updated);
                        if(updated){
                            printf("\nLinked-List updated...");
                            display(head);
                        }
                        break;
                    case 3:
                        printf("\nEnter element : ");
                        scanf("%d", &element);
                        head = insertion(head, element, 2, 0, &updated);
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
                        head = deletion(head, 0, 0, &updated);
                        printf("\nLinked-List updated...");
                        display(head);
                        break;
                    case 2:
                        printf("Enter location : ");
                        scanf("%d", &location);
                        head = deletion(head, 1, location, &updated);
                        if(updated){
                            printf("\nLinked-List updated...");
                            display(head);
                        }
                        break;
                    case 3:
                        head = deletion(head, 2, 0, &updated);
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
        updated = 1;
        printf("\n");
        system("pause");
    }
}
