#include<iostream>
using namespace std;

class queue
{
    public:
        int data;
        queue* next;
};
void enqueue(queue** front,queue** rear,int element)
{
    if((*rear) == NULL)
    {
        (*rear)->data = element;
        (*rear)->next = NULL;
        (*front) = (*rear);
    }
    else
    {
        queue *temp = new queue();
        temp->next = NULL;
        temp->data = element;
        (*rear)->next = temp;
        (*rear) = temp;
    }
}
void dequeue(queue** front,queue** rear)
{
    
    if((*front) == NULL)
    {
        cout<<"queue is empty...."<<endl;
        return;
    }
    else if ((*front) != NULL)
    {
        queue* temp = new queue();
        temp = (*front);
        (*front) = temp->next;
        delete temp;
    }
    else
    {
        delete (*front);
        (*rear) = NULL;
        (*front) = NULL;
    }
}
void display(queue* front , queue* rear)
{
    queue* temp = new queue;
    temp = front;
    if(rear == NULL && front == NULL)
    {
        cout<<"queue is empty..."<<endl;
        return;
    }
    cout<<"queue is : "<<endl;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
int main()
{
    queue* front = new queue();
    queue* rear = new queue();
    enqueue(&front,&rear,1);
    enqueue(&front,&rear,2);
    //for(int i = 1 ; i < 11 ; i++)
    //{
    //    enqueue(&front,&rear,i);
    //}
    display(rear,front);
    //for(int i = 0 ; i < 3 ; i++)
    //{
    //    dequeue(&front,&rear);
    //}
    //display(rear,front);
}