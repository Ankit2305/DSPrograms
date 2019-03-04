#include<stdio.h>
#include<stdlib.h>

struct node{
    int coefficient, order;
    struct node *next;
};

struct node* createLinkedList(){
    struct node *head;
    int coeff, ord;
    char ch = 'y';
    struct node *last;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter Order of x : ");
    scanf("%d", &ord);
    printf("Enter coefficient of x^%d : ", ord);
    scanf("%d", &coeff);
    ptr->order = ord;
    ptr->coefficient = coeff;
    ptr->next = NULL;
    head = ptr;
    last = ptr;
    printf("Enter more elements(y/n) : ");
    scanf(" %c", &ch);
    while(ch=='y'||ch=='Y'){
        printf("Enter Order of x : ");
        scanf("%d", &ord);
        printf("Enter coefficient of x^%d : ", ord);
        scanf("%d", &coeff);
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->order = ord;
        newNode->coefficient = coeff;
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
    while(ptr->next!=NULL){
        printf(" %d x^%d +", ptr->coefficient, ptr->order);
        ptr = ptr->next;
    }
    printf(" %d x^%d", ptr->coefficient, ptr->order);
}

struct node* selectionSort(struct node *head){
    struct node *max, *current, *precurrent, *preptr=NULL, *postmax, *premax, *ptr=head;
    if(head==NULL)
        printf("\nLinked List is empty...");
    else{
        while(ptr->next!=NULL){
            premax=NULL;
            precurrent = ptr;
            current = ptr->next;
            max = ptr;
            while(current!=NULL){
                if(current->order > max->order){
                    premax = precurrent;
                    max = current;
                }
                precurrent = current;
                current = current->next;
            }
            if(premax!=NULL){
                postmax = max->next;
                if(ptr->next==max){
                    max->next=ptr;
                }
                else{
                    max->next = ptr->next;
                    premax->next = ptr;
                }
                ptr->next = postmax;
                if(preptr==NULL)
                    head=max;
                else
                    preptr->next = max;
            }
            preptr = max;
            ptr=max->next;
        }
    }
    return head;
}

struct node *addPolynomials(struct node *first, struct node *second){
    struct node *third, *last;

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(first->order == second->order){
        newNode->order = first->order;
        newNode->coefficient = first->coefficient + second->coefficient;
        newNode->next = NULL;
        third = newNode;
        last = newNode;
        first = first->next;
        second = second->next;
    }
    else if(first->order > second->order){
        newNode->order = first->order;
        newNode->coefficient = first->coefficient;
        newNode->next = NULL;
        third = newNode;
        last = newNode;
        first = first->next;
    }
    else{
        newNode->order = second->order;
        newNode->coefficient = second->coefficient;
        newNode->next = NULL;
        third = newNode;
        last = newNode;
        second = second->next;
    }

    while(first!=NULL || second!=NULL){
        if(first == NULL){
            last->next = second;
            second = NULL;
        }
        else if(second == NULL){
            last->next = first;
            first = NULL;
        }
        else{
            if(first->order == second->order){
                newNode = (struct node*)malloc(sizeof(struct node));
                newNode->order = first->order;
                newNode->coefficient = first->coefficient + second->coefficient;
                newNode->next = NULL;
                last->next = newNode;
                last = newNode;
                first = first->next;
                second = second->next;
            }
            else if(first->order > second->order){
                newNode = (struct node*)malloc(sizeof(struct node));
                newNode->order = first->order;
                newNode->coefficient = first->coefficient;
                newNode->next = NULL;
                last->next = newNode;
                last = newNode;
                first = first->next;
            }
            else{
                newNode = (struct node*)malloc(sizeof(struct node));
                newNode->order = second->order;
                newNode->coefficient = second->coefficient;
                newNode->next = NULL;
                last->next = newNode;
                last = newNode;
                second = second->next;
            }
        }
    }
    return third;
}


int main(){
    struct node *first, *second, *sum;

    printf("Enter first polynomial expression : \n");
    first = createLinkedList();
    first = selectionSort(first);
    printf("\nFirst expression : ");
    display(first);
    printf("\n");
    system("pause");

    system("cls");
    printf("Enter second polynomial expression : \n");
    second = createLinkedList();
    second = selectionSort(second);
    printf("\nSecond expression : ");
    display(second);
    printf("\n");
    system("pause");

    system("cls");
    printf("\nFirst expression : ");
    display(first);
    printf("\nSecond expression : ");
    display(second);
    printf("\n\nAddition of expressions : ");
    sum = addPolynomials(first, second);
    display(sum);
    printf("\n");

    return 0;
}
