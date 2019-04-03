#include<stdio.h>
#include<stdlib.h>



struct edge{
    int info;
    struct edge* next;
};

struct vertex{
    int info;
    struct vertex* nextvertex;
    struct edge* next;
};

struct node{
    struct vertex* info;
    struct node* next;
};

//Stack and Queue Operations
struct node* insertEnd(struct node *head, struct vertex* element){
    struct node *ptr = head, *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = element;
    newNode->next = NULL;
    if(ptr == NULL)
        head = newNode;
    else{
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    return head;
}

struct node* deleteEnd(struct node *head){
    struct node *head1 = head, *head2 = NULL;
    while(head1->next!=NULL){
        head2 = head1;
        head1 = head1->next;
    }
    if(head2 == NULL)
        head = NULL;
    else
        head2->next = NULL;
    free(head1);
    return head;
}

struct node* deleteBeg(struct node *head){
    struct node* head1 = head;
    head = head->next;
    free(head1);
    return head;
}

struct vertex* peekStack(struct node *head){
    if(head == NULL)
        return NULL;
    while(head->next!=NULL){
        head = head->next;
    }
    return head->info;
}

struct vertex* peekQueue(struct node *head){
    if(head == NULL)
        return NULL;
    return head->info;
}
//Stack and Queue Operations ends


//Graph Operations
int found(struct vertex *start, int element){
    while(start!=NULL){
        if(start->info == element)
            return 1;
        start = start->nextvertex;
    }
    return 0;
}

void display(struct vertex *start){
    printf("\nAdjacent List : \n");
    struct vertex *ptr = start;
    while(ptr!=NULL){
        struct edge *ptredge = ptr->next;
        printf("%d -> ", ptr->info);
        while(ptredge!=NULL){
            printf(" %d", ptredge->info);
            ptredge = ptredge->next;
        }
        printf("\n");
        ptr = ptr->nextvertex;
    }
}

struct vertex *insertvertex(struct vertex *start, int element){
    struct vertex *ptr = start;
    struct vertex *newvertex = (struct vertex*)malloc(sizeof(struct vertex));
    newvertex->info = element;
    newvertex->next = NULL;
    newvertex->nextvertex = NULL;
    if(start == NULL)
        start = newvertex;
    else{
        while(ptr->nextvertex != NULL)
            ptr = ptr->nextvertex;
        ptr->nextvertex = newvertex;
    }
    return start;
}

struct vertex *insertEdge(struct vertex *start, int firstvertex, int secondvertex){
    struct vertex *ptr = start;
    while(ptr!=NULL){
        if(ptr->info == firstvertex){
            struct edge *newvertex = (struct edge*)malloc(sizeof(struct edge));
            newvertex->info = secondvertex;
            newvertex->next = NULL;
            if(ptr->next == NULL){
                ptr->next = newvertex;
            }
            else{
                struct edge *ptredge = ptr->next, *preedge = NULL;
                while(ptredge!=NULL){
                    preedge = ptredge;
                    if(ptredge->info == secondvertex){
                        printf("\nEdge already exists between %d and %d", firstvertex, secondvertex);
                        free(newvertex);
                        break;
                    }
                    ptredge = ptredge->next;
                }
                if(ptredge!=NULL)
                    break;
                else{
                    preedge->next = newvertex;
                }
            }
        }
        else if(ptr->info == secondvertex){
            struct edge *newvertex = (struct edge*)malloc(sizeof(struct edge));
            newvertex->info = firstvertex;
            newvertex->next = NULL;
            if(ptr->next == NULL){
                ptr->next = newvertex;
            }
            else{
                struct edge *ptredge = ptr->next, *preedge = NULL;
                while(ptredge!=NULL){
                    preedge = ptredge;
                    if(ptredge->info == firstvertex){
                        printf("\nEdge already exists between %d and %d", firstvertex, secondvertex);
                        free(newvertex);
                        break;
                    }
                    ptredge = ptredge->next;
                }
                if(ptredge!=NULL)
                    break;
                else{
                    preedge->next = newvertex;
                }
            }
        }
        ptr = ptr->nextvertex;
    }
    return start;
}
//Graph operation ends

int search(int visited[], int size, int element){
    int i;
    for(i=0;i<size;i++){
        if(visited[i] == element)
            return 1;
    }
    return 0;
}

struct vertex *findVertex(struct vertex *start, int element){
    while(start!=NULL){
        if(start->info == element)
            return start;
        start  = start->nextvertex;
    }
}

void bft(struct vertex *start){
    struct node *queue = NULL;
    int visited[20], size=0;
    printf(" %d", start->info);
    visited[size++] = start->info;
    queue = insertEnd(queue, start);
    while(peekQueue(queue)!=NULL){
        struct vertex* input = peekQueue(queue);
        queue = deleteBeg(queue);
        struct edge* currentEdge = input->next;
        while(currentEdge != NULL){
            if(search(visited, size, currentEdge->info)){
                currentEdge = currentEdge->next;
                continue;
            }
            printf(" %d", currentEdge->info);
            visited[size++] = currentEdge->info;
            queue = insertEnd(queue, findVertex(start, currentEdge->info));
            currentEdge = currentEdge->next;
        }
    }
}

void dft(struct vertex* start){
    struct node *stack = NULL;
    int visited[20], size=0;
    stack = insertEnd(stack, start);
    printf(" %d", start->info);
    visited[size++] = start->info;
    while(peekStack(stack)!=NULL){
        struct vertex *input = peekStack(stack);
        struct edge* currentEdge = input->next;
        while(currentEdge != NULL){
            if(search(visited, size, currentEdge->info)){
                currentEdge = currentEdge->next;
                continue;
            }
            printf(" %d", currentEdge->info);
            visited[size++] = currentEdge->info;
            stack = insertEnd(stack, findVertex(start, currentEdge->info));
            break;
        }
        if(currentEdge == NULL)
            stack = deleteEnd(stack);
    }
}

int main(){
    int choice=1, element, firstvertex, secondvertex;
    struct vertex *start = NULL, *ptr;
    while(choice!=0){
        system("cls");
        printf("Creating graph : \n1> Insert Vertex\n2> Insert Edge\n3> Display\n0> Continue\n\nOption : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter element : ");
            scanf("%d", &element);
            start = insertvertex(start, element);
            break;
        case 2:
            ptr = start;
            printf("Select First vertex : \n");
            while(ptr!=NULL){
                printf(" %d", ptr->info);
                ptr = ptr->nextvertex;
            }
            printf("\nEnter vertex : ");
            scanf("%d", &firstvertex);
            if(found(start, firstvertex)){
                ptr = start;
                printf("Select Second vertex : \n");
                while(ptr!=NULL){
                    printf(" %d", ptr->info);
                    ptr = ptr->nextvertex;
                }
                printf("\nEnter vertex : ");
                scanf("%d", &secondvertex);
                if(found(start, secondvertex)){
                    start = insertEdge(start, firstvertex, secondvertex);
                }
                else{
                    printf("\n%d is not found in graph, cannot create an edge...\nAborting edge insertion...", secondvertex);
                }
            }
            else{
                printf("\n%d is not found in graph, cannot create an edge...\nAborting edge insertion...", firstvertex);
            }
            break;
        case 3:
            display(start);
            break;
        case 0:
            printf("Graph created successfully\n");
            display(start);
            break;
        default:
            printf("\nNo option selected, please try again...");
        }
        printf("\n");
        system("pause");
    }
    system("cls");
    display(start);
    printf("\nTraversals : \n\nBFT : ");
    bft(start);
    printf("\n\nDFT : ");
    dft(start);
    printf("\n");

    return 0;
}
