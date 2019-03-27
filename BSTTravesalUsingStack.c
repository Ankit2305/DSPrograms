#include<stdio.h>
#include<stdlib.h>

int SENTINAL = -9999;

struct node{
    int info;
    struct node *left, *right;
};

struct stackNode{
    struct node *info;
    struct stackNode *next;
};


//Stack Operations
struct stackNode *push(struct stackNode *head, struct node *data){
    struct stackNode *newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    newNode->info = data;
    newNode->next = NULL;
    if(head == NULL)
        head = newNode;
    else{
        struct stackNode *ptr = head;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    return head;
}

struct stackNode *pop(struct stackNode *head){
    struct stackNode *head1 = head, *head2 = NULL;
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

struct node *peek(struct stackNode *head){
    if(head == NULL)
        return NULL;
    else{
        struct stackNode *ptr = head;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        return ptr->info;
    }
}


//BST Operations
struct node* insert(struct node *root){
    int element;
    printf("\nEnter element : ");
    scanf("%d", &element);
    struct node *newNode = (struct node*)malloc(sizeof(struct node)), *leaf;
    newNode->info = element;
    newNode->left = NULL;
    newNode->right = NULL;
    leaf = root;
    if(root == NULL)
        root = newNode;
    else{
        while(1){
            if(element < leaf->info){
                if(leaf->left==NULL){
                    leaf->left = newNode;
                    break;
                }
                leaf = leaf->left;
            }
            else{
                if(leaf->right==NULL){
                    leaf->right = newNode;
                    break;
                }
                leaf = leaf->right;
            }
        }
    }
    return root;
}

void display(struct node *leaf){
    if(leaf != NULL){
        printf(" %d ", leaf->info);
        if(leaf->left!=NULL || leaf->right!=NULL)
            printf("(");
        display(leaf->left);
        display(leaf->right);
        if(leaf->left!=NULL || leaf->right!=NULL)
            printf(")");
    }
}

void preorder(struct node *leaf){
    struct stackNode *head = NULL;
    while(1){
        while(leaf!=NULL){
            printf(" %d", leaf->info);
            if(leaf->right != NULL)
            head = push(head, leaf->right);
            leaf = leaf->left;
        }
        leaf = peek(head);
        if(leaf==NULL)
            break;
        else
            head = pop(head);
    }
}

void inorder(struct node *leaf){
    struct stackNode *head = NULL;
    while(1){
        while(leaf!=NULL){
            head = push(head, leaf);
            leaf = leaf->left;
        }
        leaf = peek(head);
        if(leaf==NULL)
            break;
        printf(" %d", leaf->info);
        leaf = leaf->right;
        head = pop(head);
    }
}

void postorder(struct node *leaf){
    struct stackNode *head = NULL;
    while(1){
        while(leaf!=NULL){
            head = push(head, leaf);
            if(leaf->right!=NULL){
                struct node *newNode = (struct node*)malloc(sizeof(struct node));
                newNode->info = SENTINAL;
                newNode->left = NULL;
                newNode->right = NULL;
                head = push(head, newNode);
                head = push(head, leaf->right);
            }
            leaf = leaf->left;
        }
        struct node *leaf1;
        while(1){
            leaf = peek(head);
            if(leaf==NULL)
                break;
            head = pop(head);
            leaf1 = peek(head);
            if(leaf1 != NULL && leaf1->info == SENTINAL){
                head = pop(head);
                break;
            }
            else{
                printf(" %d", leaf->info);
            }
        }
        if(leaf==NULL)
            break;
    }
}

int main(){
    struct node *root = NULL;
    char ch;
    printf("Creating BST...");
    root = insert(root);
    printf("Do you want to enter more element? (y/n) : ");
    scanf(" %c", &ch);
    while(ch == 'y' || ch == 'Y'){
        root = insert(root);
        printf("Do you want to enter more element? (y/n) : ");
        scanf(" %c", &ch);
    }
    printf("\nBST :\n");
    display(root);
    printf("\n");
    system("pause");
    system("cls");
    printf("\nBST :\n");
    display(root);
    printf("\n\nPre order\t:");
    preorder(root);
    printf("\n\nIn order\t:");
    inorder(root);
    printf("\n\nPost order\t:");
    postorder(root);
    printf("\n");
    return 0;
}
