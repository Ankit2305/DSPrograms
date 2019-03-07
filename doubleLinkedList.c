#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int info;
    struct node *next, *prev;
};

void display(struct node *head){
    char arrow[4];
    strcpy(arrow, "<->");
    if(head==NULL)
        printf("\nDoubly Linked List is empty...");
    else{
        struct node *ptr = head;
        printf("\nDoubly Linked List:\n");
        while(ptr!=NULL){
            if(ptr->next == NULL)
                strcpy(arrow, "");
            printf(" %p | %d [ %p ]| %p %s\n",ptr->prev, ptr->info, ptr, ptr->next, arrow);
            ptr = ptr->next;
        }
    }
    printf("\n");
    system("pause");
}

struct node* insertion(struct node *head, int location, int search, int *updated){
    int element;
    printf("\nEnter element : ");
    scanf("%d", &element);
    struct node *newNode = (struct node*)malloc(sizeof(struct node)), *ptr;
    newNode->info = element;
    if(head==NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else{
        if(location == 0){
            newNode->next = head;
            newNode->prev = NULL;
            head->prev = newNode;
            head = newNode;
        }
        else if(location == 1){
            ptr  = head;
            while(ptr!=NULL && ptr->info!=search)
                ptr = ptr->next;
            if(ptr==NULL){
                printf("\n%d not found in the Doubly Linked List", search);
                *updated = 0;
            }
            else{
                newNode->next = ptr->next;
                newNode->prev = ptr;
                ptr->next = newNode;
                if(newNode->next!=NULL)
                    newNode->next->prev = newNode;
            }
        }
        else{
            ptr = head;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->prev = ptr;
            newNode->next = NULL;
        }
    }
    return head;
}

struct node *deletion(struct node* head, int location, int search, int *updated){
    struct node *head1 = head;
    if(location == 0){
        head = head->next;
        if(head!=NULL)
            head->prev = NULL;
        printf("\nDeleted %d from the Doubly Linked List...", head1->info);
        free(head1);
    }
    else if(location ==1){
        while(head1!=NULL && head1->info!=search)
            head1 = head1->next;
        if(head1==NULL){
            printf("%d is not found in the Doubly Linked List", search);
            *updated = 0;
        }
        else{
            if(head1->prev==NULL)
                head = head1->next;
            else
                head1->prev->next = head1->next;
            if(head1->next != NULL)
                head1->next->prev = head1->prev;
            printf("\nDeleted %d from the Doubly Linked List...", head1->info);
            free(head1);
        }
    }
    else{
        while(head1->next!=NULL)
            head1 = head1->next;
        if(head1->prev == NULL)
            head = NULL;
        else
            head1->prev->next = NULL;
        printf("\nDeleted %d from the Doubly Linked List...", head1->info);
        free(head1);
    }
    return head;
}

int main(){
    int choice = 1, choice2, updated, location;
    struct node *head = NULL;
    while(choice != 0){
        system("cls");
        printf("DOUBLY LINKED LIST :\n1> Insertion\n2> Deletion\n3> Display\n0> Exit\n\nOption: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("\nInsertion:\t1> Beginning\t2> Location\t3> End\nAny other key to abort insertion...\nOption: ");
            scanf("%d", &choice2);
            switch(choice2){
            case 1:
                head = insertion(head, 0, 0, &updated);
                printf("\nDoubly Linked List updated...");
                display(head);
                break;
            case 2:
                updated = 1;
                printf("Enter location : ");
                scanf("%d", &location);
                head = insertion(head, 1, location, &updated);
                if(updated){
                    printf("\nDoubly Linked List updated...");
                    display(head);
                }
                break;
            case 3:
                head = insertion(head, 2, 0, &updated);
                printf("\nDoubly Linked List updated...");
                display(head);
                break;
            }
            break;
        case 2:
            if(head==NULL)
                printf("\nUnderflow");
            else{
                printf("\nDeletion:\t1> Beginning\t2> Location\t3> End\nAny other key to abort insertion...\nOption: ");
                scanf("%d", &choice2);
                switch(choice2){
                case 1:
                    head = deletion(head, 0, 0, &updated);
                    printf("\nDoubly Linked List updated...");
                    display(head);
                    break;
                case 2:
                    updated = 1;
                    printf("Enter location : ");
                    scanf("%d", &location);
                    head = deletion(head, 1, location, &updated);
                    if(updated){
                        printf("\nDoubly Linked List updated...");
                        display(head);
                    }
                    break;
                case 3:
                    head = deletion(head, 2, 0, &updated);
                    printf("\nDoubly Linked List updated...");
                    display(head);
                    break;
                }
            }
            break;
        case 3:
            display(head);
            break;
        case 0:
            break;
        default:
            printf("\nNo option selected, please try again...");
            printf("\n");
            system("pause");
        }
    }
    return 0;
}
