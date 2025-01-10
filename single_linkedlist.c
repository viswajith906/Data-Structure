#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Node *header=NULL,*newnode,*ptr,*ptr1;
void insert_at_front(int key){
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data=key;
    if(header==NULL){
        newnode->link=NULL;
        header = newnode;
    }
    else{
        newnode->link=header;
        header=newnode;
    }
}
void insert_at_end(int key){
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data=key;
    if(header==NULL){
        newnode->link=NULL;
        header = newnode;
    }
    else{
        ptr=header;
        while(ptr->link != NULL){
            ptr=ptr->link;
        }
        newnode->link=NULL;
        ptr->link=newnode;
    }
}
void insert_at_anypart(int key, int pos) {
    int i;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = key;
    if (pos == 1) {
        newnode->link = header;
        header = newnode;
        return;
    }
    ptr = header;
    for (i = 1; i < pos - 1; i++) {
        if (ptr == NULL) {
            printf("Position out of range\n");
            free(newnode);
            return;
        }
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Position out of range\n");
        free(newnode);
    } else {
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}

void delete_at_front(){
    ptr=header;
    if(ptr==NULL){
        printf("Linked List is empty");
    }
    else{
        header=ptr->link;
        free(ptr);
    }
}
void delete_at_end(){
    ptr=header->link;
    if(ptr==NULL){
        printf("Linked LIst is empty");
    } 
    else{
        while(ptr->link != NULL){
            ptr1=ptr;
            ptr=ptr->link;
        }
        ptr1->link=NULL;
        free(ptr);
    }
}
void delete_at_any(int key) {
    if (header == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    if (header->data == key) {
        struct Node *temp = header;
        header = header->link;
        free(temp);
        printf("Key %d deleted\n", key);
        return;
    }
    ptr = header;
    while (ptr != NULL && ptr->data != key) {
        ptr1 = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key %d not found\n", key);
    } else {
        ptr1->link = ptr->link;
        free(ptr);
        printf("Key %d deleted\n", key);
    }
}

int search(int key){
    int location=1;
    ptr=header;
    while(ptr!=NULL){
        if(ptr->data==key){
            printf("Location:%d",location);
            return 0;
        }
        else{
            ptr=ptr->link;
            location=location+1;
        }
    }
    if(ptr==NULL){
        printf("Key is not found");
        return 0;
    }
}
void display(){
    ptr=header;
    if(ptr==NULL){
        printf("Lined List is empty");
    }
    else{
        printf("Elements in the list:");
        while(ptr!=NULL){
            printf("%d->",ptr->data);
            ptr=ptr->link;
        }
        printf("NULL");
    }
}
void main(){
    int choice,key,pos;
    do{
    printf("\n 1. Insert_front \n 2. Insert_end \n 3. Insert_anypart \n 4. Delete_front \n 5. Delete_end \n 6. Delete_anypart \n 7. Display \n 8. Search \n 9. Exit \n"); 
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the item: ");
        scanf("%d",&key);
        insert_at_front(key);
        break;
        case 2:
        printf("Enter the item: ");
        scanf("%d",&key);
        insert_at_end(key);
        break;
        case 3:
        printf("Enter the key: ");
        scanf("%d",&key);
        printf("Enter the position: ");
        scanf("%d",&pos);
        insert_at_anypart(key,pos);
        break;
        case 4:
        delete_at_front();
        break;
        case 5:
        delete_at_end(key);
        break;
        case 6:
        printf("Enter the key: ");
        scanf("%d",&key);
        delete_at_any(key);
        break;
        case 7:
        display();
        break;
        case 8:
        printf("Enter the item: ");
        scanf("%d",&key);
        search(key);
        break;
        case 9:
        printf("\n Exit \n");
        break;
        default:printf("Invalid ");
    }
    }
    while(choice != 9);
}