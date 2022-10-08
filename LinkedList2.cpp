/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
};

void insert(Node*& node,int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(node==NULL){
        node = newNode;
        return;
    }
    Node* temp = node;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return ;
    
}

void display(Node* node){
    if(node==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = node;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
    return;
}

void deleteNode(Node** node, int key)
{
 
    // Store head node
    Node* temp = *node;
    Node* prev = NULL;
 
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key) {
       
      // Changed head
        *node = temp->next;
        // *node->prev = NULL;
      // free old head
        delete temp;
        return;
    }
 
    // Else Search for the key to be
    // deleted, keep track of the
    // previous node as we need to
    // change 'prev->next'
    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
 
        // If key was not present in linked list
        if (temp == NULL){
            cout<<"Value is not present"<<endl;
            return;
        }
            
 
        // Unlink the node from linked list
        prev->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = prev;
        }
        
        // Free memory
        delete temp;
    }
}
void insertAfter(Node*& node,int prev,int val){
    Node* temp = node;
    bool ispresent = false;
    while(temp!=NULL){
        if(temp->data == prev){
            ispresent  = true;
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if(temp->next != NULL){
                temp->next->prev = newNode;
            }
            return; 
        }
        temp = temp->next;
    }
    if(!ispresent){
        cout<<prev<<" is not present"<<endl;
    }
    return ;
}
void insertFront(Node*& node,int value){
    Node* newNode = new Node();
    newNode->data = value;
    
    if(node==NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        node = newNode;
        return;
    }
    newNode->next = node;
    newNode->prev = NULL;
    node= newNode;
    return;

}
int main(){
    Node* head = NULL;
    bool exit = false;
    while(!exit){
        cout<<"Choose from options: "<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Insert after a value"<<endl;
        cout<<"5. Insert in front"<<endl;
        cout<<"6. exit"<<endl;
        int x;
        cin>>x;
        if(x==1){
            cout<<"Enter the Value to add:"<<endl;
            int num;
            cin>>num;
            insert(head,num);
            
        }
        else if(x==2){
            cout<<"Enter number to delete:"<<endl;
            int number;
            cin>>number;
            deleteNode(&head,number);
        }
        else if(x==3){
            cout<<"Values in the linked list are:"<<endl;
            display(head);
        }
        else if(x==4){
            cout<<"Enter the Value after which the number should be added:"<<endl;
            int prev;
            cin>>prev;
            cout<<"Enter the Value to add:"<<endl;
            int num;
            cin>>num;
            insertAfter(head,prev,num);
        }
        else if(x==5){
            cout<<"Enter number to insert in front:"<<endl;
            int number;
            cin>>number;
            insertFront(head,number);
        }
        else{
            exit = true;
        }
    }
}