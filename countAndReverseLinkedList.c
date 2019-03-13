#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* next;
};

struct node* createLinkedList(){
    struct node *head;
    int element;
    char ch = 'y';
    struct node *last;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d", &element);
    ptr->info = element;
    ptr->next = NULL;
    head = ptr;
    last = ptr;
    printf("Enter more elements(y/n) : ");
    scanf(" %c", &ch);
    while(ch=='y'||ch=='Y'){
        printf("Enter element : ");
        scanf("%d", &element);
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = element;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
        printf("Enter more elements(y/n) : ");
        scanf(" %c", &ch);
    }
    return head;
}

display(struct node *head){
    struct node *ptr = head;
    printf("\nLinked List : \nHEAD ->\n");
    while(ptr!=NULL){
        printf("ADDRESS : %p | INFO : %d | NEXT : %p ->\n",ptr, ptr->info, ptr->next);
        ptr = ptr->next;
    }
    printf("NULL");
}

int countNodes(struct node *head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

struct node *reverse(struct node *head){
    struct node *ptr = head, *ptrnext, *ptrprev = NULL;
    while(ptr!=NULL){
        ptrnext = ptr->next;
        ptr->next = ptrprev;
        ptrprev = ptr;
        ptr = ptrnext;
    }
    head = ptrprev;
    return head;
}

int main(){
    printf("Creating Linked List:\n");
    struct node *head = createLinkedList();
    display(head);
    printf("\n");
    system("pause");
    int choice = 1;
    while(choice!=0){
        system("cls");
        printf("LINKED LIST:\n1> Count Nodes\n2> Reverse Linked List\n3> Display\n0> Exit\n\nOption: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("\nNumber of nodes in the Linked List : %d",countNodes(head));
            break;
        case 2:
            head = reverse(head);
            printf("\nReversing Linked List...\nLinked List updated...");
            display(head);
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
