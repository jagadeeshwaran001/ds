#include<iostream>
using namespace std;

class stack
{
    public:
    int data;
    stack* next;
};
void push(stack **top_ref,int new_data)
{
    if((*top_ref) == NULL)
    {
        stack *newnode = new stack();
        newnode->data = new_data;
        newnode->next = NULL;
        cout<<"item pushed"<<endl;
    }
    stack *newnode = new stack();
    newnode->data = new_data;
    newnode->next = (*top_ref);
    cout<<"item pushed"<<endl;

    (*top_ref) = newnode;
}
void pop(stack **top_ref)
{
    if((*top_ref) == NULL)
    {
        return;
    }
    stack *temp = (*top_ref);
    (*top_ref) = temp->next;
    delete temp;
    cout<<"item poped"<<endl;
}
void display(stack *top_ref)
{
    stack *temp = new stack();
    temp = top_ref;
    cout<<"stack : "<<endl;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
int main()
{
    stack *top = NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    push(&top,5);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
}