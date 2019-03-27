#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *left, *right;
};

struct node* insert(struct node *root){
    int element;
    printf("Enter element : ");
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

int minimum(struct node *current){
    while(1){
        if(current->left == NULL)
            return current->info;
        current = current->left;
    }
}

struct node* delete(struct node *root, int element, int *updated){
    if(root == NULL) return root;
    else if(root->info > element) root->left = delete(root->left, element, updated);
    else if(root->info < element) root->right = delete(root->right, element, updated);
    else{
        *updated = 1;
        if(root->left==NULL && root->right==NULL){
            free(root);
            root = NULL;
        }
        else if(root->left==NULL){
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right==NULL){
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else{
            int temp = minimum(root->right);        //Using minimum of Right
            root->info = temp;
            root->right = delete(root->right, temp, updated);
        }
        return root;
    }

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

void preDisplay(struct node *root){
    if(root==NULL)
        printf("\nBST is empty...");
    else{
        printf("\nBST : \n");
        display(root);
    }
}

void preorder(struct node *leaf){
    if(leaf!=NULL){
        printf(" %d", leaf->info);
        preorder(leaf->left);
        preorder(leaf->right);
    }
}

void inorder(struct node *leaf){
    if(leaf!=NULL){
        inorder(leaf->left);
        printf(" %d", leaf->info);
        inorder(leaf->right);
    }
}

void postorder(struct node *leaf){
    if(leaf!=NULL){
        postorder(leaf->left);
        postorder(leaf->right);
        printf(" %d", leaf->info);
    }
}

void search(struct node *root){
    int element, found = 0;
    printf("Enter element to be searched : ");
    scanf("%d", &element);
    while(root!=NULL){
        if(root->info == element){
            printf("\n%d found at address %p", element, root);
            found = 1;
            break;
        }
        else if(root->info > element)
            root = root->left;
        else
            root = root->right;
    }
    if(!found)
        printf("\n%d is not found in BST", element);
}

int main(){
    struct node *root = NULL;
    int choice = 1, element, updated;
    while(choice != 0){
        system("cls");
        printf("Binary Search Tree:\n1> Insert\n2> Delete\n3> Traversal\n4> Display\n5> Search\n0> Exit\n\nOption : ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            root = insert(root);
            preDisplay(root);
            break;
        case 2:
            printf("Enter element to be deleted : ");
            scanf("%d", &element);
            updated = 0;
            root = delete(root, element, &updated);
            if(updated){
                printf("\n%d deleted from the BST\n", element);
                preDisplay(root);
            }
            else
                printf("\n%d is not found in the BST", element);
            break;
        case 3:
            preDisplay(root);
            printf("\n\nPre order\t:");
            preorder(root);
            printf("\n\nIn order\t:");
            inorder(root);
            printf("\n\nPost order\t:");
            postorder(root);
            printf("\n");
            break;
        case 4:
            preDisplay(root);
            break;
        case 5:
            search(root);
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
