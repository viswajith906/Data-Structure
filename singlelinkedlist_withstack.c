#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Node *top=NULL,*newnode,*ptr;
int choice,key;
void push(int key){
    newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=key;
    newnode->link=top;
    top=newnode;
    printf("\n%d pushed onto the stack", key);
}
void pop(){
    if(top==NULL){
        printf("Stack is empty");
    }
    else{
        ptr=top;
        top=top->link;
        printf("\n Popped element: %d", ptr->data);
        free(ptr);
    }
}
void search(int key){
    int loc=1;
    ptr=top;
    while(ptr != NULL){
        if(ptr->data==key){
        printf("\n The key %d is found at location %d", key, loc);
        return;
    }
    ptr=ptr->link;
    loc++;
    }
    printf("\n Key %d not found in the stack", key);
}
void display() {
    ptr = top;
    if (ptr == NULL) {
        printf("\n Stack is empty");
        return;
    }

    printf("\n Stack elements are:");
    while (ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
int main() {
    do {
        printf("\n1. Push \n2. Pop \n3. Search \n4. Display \n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n Enter the element to push: ");
                scanf("%d", &key);
                push(key);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("\n Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\n Exiting...\n");
                break;
            default:
                printf("\n Invalid choice");
        }
    } while (choice != 5);

    return 0;
}