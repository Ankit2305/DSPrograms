#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int info;
    struct node *next;
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

numPrefix(int num, char prefix[]){
    switch(num){
        case 1:
            strcpy(prefix, "st");
            break;
        case 2:
            strcpy(prefix, "nd");
            break;
        case 3:
            strcpy(prefix, "rd");
            break;
        default:
            strcpy(prefix, "th");
    }
}

linearSearch(struct node *head){
    int element, nodeNum = 1;
    char prefix[3];
    printf("Enter element to be searched : ");
    scanf("%d", &element);
    struct node *ptr = head;
    while(ptr!=NULL){
        if(ptr->info==element){
            numPrefix(nodeNum, prefix);
            printf("\n%d found at the %d%s node [ ADDRESS : %p ]", element, nodeNum, prefix, ptr);
            break;
        }
        ptr=ptr->next;
        nodeNum++;
    }
    if(ptr==NULL)
        printf("%d is not found in the Linked List", element);
}

struct node* selectionSort(struct node *head){
    struct node *min, *current, *precurrent, *preptr=NULL, *postmin, *premin, *ptr=head;
    if(head==NULL)
        printf("\nLinked List is empty...");
    else{
        while(ptr->next!=NULL){
            premin=NULL;
            precurrent = ptr;
            current = ptr->next;
            min = ptr;
            while(current!=NULL){
                if(current->info < min->info){
                    premin = precurrent;
                    min = current;
                }
                precurrent = current;
                current = current->next;
            }
            if(premin!=NULL){
                postmin = min->next;
                if(ptr->next==min){
                    min->next=ptr;
                }
                else{
                    min->next = ptr->next;
                    premin->next = ptr;
                }
                ptr->next = postmin;
                if(preptr==NULL)
                    head=min;
                else
                    preptr->next = min;
            }
            preptr = min;
            ptr=min->next;
        }
    }
    return head;
}

int main(){
    int choice=1;
    struct node *head = NULL;
    printf("Creating Linked List :\n");
    head = createLinkedList();
    display(head);
    printf("\n");
    system("pause");
    while(choice!=0){
        system("cls");
        printf("LINKED LIST OPERATIONS : \n1> Linear Search\n2> Selection Sort\n3> Display\n0> Exit\n\nOption : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            linearSearch(head);
            break;
        case 2:
            printf("\nSorting Linked List...");
            head = selectionSort(head);
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
