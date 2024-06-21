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
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = num;
    for(int i = 0; i < n_th; i++){
	head = head->next;
    }
    new_node->next = head->next;
    head->next = new_node;
}

void delete(struct node* head, int n_th){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    for(int i = 0; i < n_th - 1; i++){
	if(i == n_th - 2){
	    temp = head;
	}
	head = head->next;
    }
    //printf("%d\n", head->num);
    //printf("%d\n", temp->num);

}

void insert_head(struct node** head, int num){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = num;

    if(*head != NULL){
	new_node->next = *head;
    }
    *head = new_node;
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
    //delete(head, 3);
    
    return 0;
}
