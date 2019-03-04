#include<stdio.h>
#include<stdlib.h>
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
    printf("Linked List : HEAD ->");
    while(ptr!=NULL){
        printf(" %d ->", ptr->info);
        ptr = ptr->next;
    }
    printf(" NULL");
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

struct node* mergeLinkedLists(struct node *head1, struct node* head2){
    struct node *head, *last;
    if(head1->info<head2->info){
        last = head = head1;
        head1 = head1->next;
        last->next = NULL;
    }
    else{
        last = head = head2;
        head2 = head2->next;
        last->next = NULL;
    }
    while(head1!=NULL || head2!=NULL){
        if(head1==NULL){
            last->next = head2;
            break;
        }
        else if(head2==NULL){
            last->next = head1;
            break;
        }
        else{
            if(head1->info<head2->info){
                last->next = head1;
                head1 = head1->next;
                last = last->next;
                last->next = NULL;
            }
            else{
                last->next = head2;
                head2 = head2->next;
                last = last->next;
                last->next = NULL;
            }
        }
    }
    return head;
}

int main(){
    struct node *head1, *head2, *head3;

    printf("Creating first Linked List :\n");
    head1 = createLinkedList();
    printf("\n");
    display(head1);
    printf("\n");
    system("pause");
    system("cls");

    printf("Creating second Linked List :\n");
    head2 = createLinkedList();
    printf("\n");
    display(head2);
    printf("\n");
    system("pause");
    system("cls");

    printf("Original Linked Lists :");
    printf("\nFirst ");
    display(head1);
    printf("\nSecond ");
    display(head2);
    printf("\n\n");

    head1 = selectionSort(head1);
    head2 = selectionSort(head2);

    printf("After sorting :");
    printf("\nFirst ");
    display(head1);
    printf("\nSecond ");
    display(head2);

    head3 = mergeLinkedLists(head1, head2);

    printf("\n\nCombined ");
    display(head3);
    printf("\n");

    return 0;
}
