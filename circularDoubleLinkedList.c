#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int info;
    struct node *next, *prev;
};

void display(struct node *head){
    struct node *ptr = head;
    int count = 0, i;
    char arrow[4];
    strcpy(arrow, "<->");
    if(head == NULL)
        printf("\nCircular Double Linked List is empty...");
    else{
        printf("\nCircular Double Linked List : \n");
        if(ptr->next==head)
            strcpy(arrow, "->");
        printf("\n\n %p | %d [ %p ]| %p %s\n",ptr->prev, ptr->info, ptr, ptr->next, arrow);
        ptr = ptr->next;
        while(ptr!=head){
            if(ptr->next==head)
                strcpy(arrow, "->");
            printf(" %p | %d [ %p ]| %p %s\n",ptr->prev, ptr->info, ptr, ptr->next, arrow);
            ptr = ptr->next;
            count++;
        }
    }
}

struct node *insertion(struct node *head, int location, int search, int *updated){
    int element;
    printf("Enter element : ");
    scanf("%d", &element);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = element;
    if(head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else{
        if(location == 0){
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        else if(location == 1){
            if(head->info == search){
                newNode->next = head->next;
                newNode->prev = head;
                head->next->prev = newNode;
                head->next = newNode;
            }
            else{
                struct node *ptr = head->next;
                while(ptr!=head && ptr->info!=search)
                        ptr = ptr->next;
                if(ptr==head){
                    printf("%d is not found in the Circular Double Linked List", search);
                    *updated = 0;
                }
                else{
                    newNode->next = ptr->next;
                    newNode->prev = ptr;
                    ptr->next->prev = newNode;
                    ptr->next = newNode;
                }
            }
        }
        else{
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }
    return head;
}

struct node *deletion(struct node *head, int location, int search, int* updated){
    if(head == head->next){
        printf("\n%d deleted from the Circular Double Linked List", head->info);
        free(head);
        head = NULL;
    }
    else{
        struct node *ptr = head;
        if(location == 0){
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            head = ptr->next;
            printf("\n%d deleted from the Circular Double Linked List", ptr->info);
            free(ptr);
        }
        else if(location == 1){
            if(ptr->info == search){
                ptr->next->prev = ptr->prev;
                ptr->prev->next = ptr->next;
                head = ptr->next;
                printf("\n%d deleted from the Circular Double Linked List", ptr->info);
                free(ptr);
            }
            else{
                ptr = ptr->next;
                while(ptr!=head && ptr->info!=search){
                    ptr = ptr->next;
                }
                if(ptr == head){
                    printf("%d is not found in the Circular Double Linked List", search);
                    *updated = 0;
                }
                else{
                    ptr->next->prev = ptr->prev;
                    ptr->prev->next = ptr->next;
                    printf("\n%d deleted from the Circular Double Linked List", ptr->info);
                    free(ptr);
                }
            }
        }
        else{
            ptr = ptr->prev;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            printf("\n%d deleted from the Circular Double Linked List", ptr->info);
            free(ptr);
        }
    }
    return head;
}

int main(){
    int choice = 1, updated, choice2, location;
    struct node *head = NULL;
    while(choice!=0){
        system("cls");
        printf("CIRCULAR DOUBLE LINKED LIST :\n1> Insertion\n2> Deletion\n3> Display\n0> Exit\n\nOption: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Insertion :\t1> Beginning\t2> Location\t3> End\nAny other key to abort insertion\nOption: ");
            scanf("%d", &choice2);
            switch(choice2){
            case 1:
                head = insertion(head, 0, 0, &updated);
                printf("\nCircular Doubly Linked List updated...");
                display(head);
                break;
            case 2:
                updated = 1;
                printf("Enter Location : ");
                scanf("%d", &location);
                head = insertion(head, 1, location, &updated);
                if(updated){
                    printf("\nCircular Doubly Linked List updated...");
                    display(head);
                }
                break;
            case 3:
                head = insertion(head, 2, 0, &updated);
                printf("\nCircular Doubly Linked List updated...");
                display(head);
                break;
            }
            break;
        case 2:
            if(head == NULL){
                printf("\nUnderflow");
                break;
            }
            printf("Deletion :\t1> Beginning\t2> Location\t3> End\nAny other key to abort insertion\nOption: ");
            scanf("%d", &choice2);
            switch(choice2){
            case 1:
                head = deletion(head, 0, 0, &updated);
                printf("\nCircular Doubly Linked List updated...");
                display(head);
                break;
            case 2:
                updated = 1;
                printf("Enter Location : ");
                scanf("%d", &location);
                head = deletion(head, 1, location, &updated);
                if(updated){
                    printf("\nCircular Doubly Linked List updated...");
                    display(head);
                }
                break;
            case 3:
                head = deletion(head, 2, 0, &updated);
                printf("\nCircular Doubly Linked List updated...");
                display(head);
                break;
            }
            break;
        case 3:
            display(head);
            break;
        case 0:
            printf("\nProgram is requested to quit...");
            break;
        default:
            printf("\nNo option selected, please try again...");
        }
        printf("\n");
        system("pause");
    }
    return 0;
}
