#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* create(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
node* find(node* root,int x)
{
    while(root!=NULL)
    {
        if(x==root->data)
        return root;
    
    else
    {
        if(x>root->data)
        {
        root=root->right;
        }
        else
        root=root->left;

        
    }
    return NULL;
    }
}
node* insert(node* T,int x)
{
    node* p,*q,*r;
    r=(node*)malloc(sizeof(node));
    r->data=x;
    r->left=NULL;
    r->right=NULL;
    if(T==NULL)
    return r;
    p=T;
    while(p!=NULL)
    {
        q=p;
        if(x>p->data)
        p=p->right;
        else
        p=p->left;
    }
    if(x>q->data)
    q->right=r;
    else
    q->left=r;
    return T;

}
node* delete(node* root, int x) {
    if (root == NULL) {
        return root;
    }

    if (x < root->data) {
        root->left = delete(root->left, x);
    } else if (x > root->data) {
        root->right = delete(root->right, x);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = find(root->right,x);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}
void inOrderTraversal(node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
void post(node* root)
{
    if(root!=NULL)
    {
        post(root->left);
        post(root->right);
        printf("%d",root->data);
    }
}
int main() {
    node* root = NULL;
    int choice, data, x;

    while (1) {
        printf("Binary Search Tree Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. In-order Traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &x);
                node* result = find(root, x);
                if (result != NULL) {
                    printf("%d found in the BST.\n", x);
                } else {
                    printf("%d not found in the BST.\n", x);
                }
                break;
            case 4:
                printf("In-order traversal of the BST: ");
                inOrderTraversal(root);
                printf("\n");
                break;
                case 5:
                printf("postorder traversal:");
                post(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}