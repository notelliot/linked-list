//singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* next;
};

void print(struct node* head){
    while(head != NULL){
	printf("%d\n", head->num);
	head = head->next;
    }
}


void insert(struct node* head, int num, int n_th,int size){
    //create new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = num;
    for(int i = 0; i < n_th - 1; i++){
	//go through head til find nth node
	head = head->next;
    }
    //next of new node is previous next node of head
    new_node->next = head->next;
    //next node of head is new node
    head->next = new_node;
}

void insert_head(struct node** head, int num){
    //create new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = num;

    if(*head != NULL){
	new_node->next = *head;
    }
    //head is new node
    *head = new_node;
}


void delete(struct node* head, int n_th){
    struct node* temp1 = head;
    for(int i = 0; i < n_th - 2; i++){
	temp1 = temp1->next;
    }
    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);   
}

int main(){
    struct node* head = NULL;


    int size;
    int num;
    printf("how many numbers: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
	printf("enter number: ");
	scanf("%d", &num);
	insert_head(&head, num);
    }
    insert(head, 8, 2, size);
    print(head);
    printf("\n\n");
    delete(head, 3);
    print(head);
    return 0;
}
