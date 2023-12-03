#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int value)
 {
    if (top==MAX-1){
    printf("ERROR: Stack overflow\n");
    return;
    }

stack[++top]=value;

}
int pop() 
{
    if(top==-1){
        printf("ERROR: Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
void display()
{
    if(top==-1){
        printf("stack is empty");
    }
    else
    {
        for(int i=top; i>=0; i--){
            printf("%d", stack[i]);
        }
    }
}
int main()
{
    int choice, value;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Exit\n4. Disp");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            display();
            break;
            
            case 2:
            value=pop();
            if(value!=-1){
                printf("Popped value: %d\n", value);
            }
            display();
            break;
            
            case 3:
            exit(0);
            
            case 4:
            display();
            break;
            
            default:
            printf("Invalid choice\n");
            }
        }
        return 0;
    }