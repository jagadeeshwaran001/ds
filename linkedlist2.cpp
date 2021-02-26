#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;
};

void push(node **head_ref,int new_data)
{
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void insertAfter(node *prev_node,int new_data)
{
    if(prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL"; 
        return;
    }
    node *new_node = new node();
    new_node->next = prev_node->next;
    new_node->data = new_data;
    prev_node->next = new_node;
}
void append(node **head_ref,int new_data)
{
    node *new_node = new node();
    node *last = (*head_ref);  
    new_node->data = new_data;
    if((*head_ref) == NULL)
    {
        (*head_ref) = new_node;
        return;
    }
    else
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
        last = new_node;
        return;
    }
}
void delete_by_key(node **head_ref,int key)
{
    node *temp = (*head_ref);
    node *prev = NULL;

    if(temp != NULL && temp->data == key)
    {
        (*head_ref) = temp->next;
        delete temp;
        return;
    }
    while(temp != NULL && temp->data != key)
    {
         prev = temp;
         temp = temp->next;
    }
    if(temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    delete temp;
}
void delete_by_poisition(node **head_ref,int pos)
{
    node *temp = (*head_ref);
    if(temp == NULL)
    {
        cout<<"the list is empty"<<endl;
        return;
    }
    if(pos == 0)
    {
        (*head_ref) = temp->next;
        delete temp;
        return;
    }
    for(int i = 0 ; i < pos-1 ; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
    {
        return;
    }
    node *nes = temp->next->next;
    delete temp->next;
    temp->next = nes;
}
void printList(node *head)
{
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main()
{  
    node* head = NULL;  
      
    append(&head, 6);  
      
    push(&head, 7);  
      
    push(&head, 1);  
      
    append(&head, 4);  
      
    insertAfter(head->next, 8);  

    delete_by_key(&head,1);
    delete_by_poisition(&head,2);
      
    cout<<"Created Linked list is: \n";  
    printList(head);  
      
    return 0;  
}  