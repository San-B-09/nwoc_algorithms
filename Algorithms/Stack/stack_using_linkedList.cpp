#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

int isempty(struct Node *top){
    if(top==NULL)
        return 1;
    return 0;
}

void push(struct Node **top, int data){
	struct Node *new_node = new struct Node;
	new_node->data = data;
	new_node->next = *top;

	*top = new_node;
}

void pop(struct Node **top){
    struct Node *temp = *top;
    if(isempty(*top)){
        cout<<"Stack is empty";
        return;
    }
    temp = temp->next;
    *top = temp;
}

void display(struct Node **top){
	struct Node *temp = *top;
    if(temp == NULL){
        cout<<"\nNo elements found in the stack";
        return;
    }
    cout<<temp->data;
    temp = temp->next;
	while(temp){
		cout<<"->"<<temp->data;
		temp = temp->next;
	}
	cout<<"\n";
}


int main(){

	struct Node *stack_top = NULL;
    int choice = 0, temp;
    while(choice!=4){
        cout<<"\nEnter choices \n1) Push\n2) Pop\n3) Display\n4) Exit\n";
        cin>>choice;
        switch(choice){
          case 1:
              cout<<"Enter Element: ";
              cin>>temp;
              push(&stack_top,temp);
              continue;
          case 2:
              pop(&stack_top);
              break;
          case 3:
              display(&stack_top);
              break;
          case 4:
              cout<<"Exit";
              break;
          default:
              cout<<"WRONG CHOICE";

        }
    }

    return 0;
}
