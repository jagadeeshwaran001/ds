#include<iostream>
using namespace std;

class queue
{
    public:
        int rear,front = -1;
        queue()
        {
            int n;
            cout<<"enter the size of an array : "<<endl;
            cin>>n;
            int arr[n];
        }
        void enqueue(int element)
        {
            if(rear+1 == n)
            {
                cout<<"queue overload..."<<endl;
                return;
            }
            else
            {
                if(rear == -1 && front == -1)
                {
                    front  = 0;
                    rear = 0;
                }
                else
                {
                    rear += 1;
                }
                arr[rear] = element;
            }
        }
        void dequeue()
        {
            if(front == -1 && rear < front)
            {
                cout<<"queue is underflow..."<endl;
                return;
            }
            else
            {
                if(rear == front)
                {
                    front = -1;
                    rear = -1;
                    cout<<"now queue is empty..."<<endl;
                }
                else
                {
                    front += 1;
                    cout<<"dequeued...."<<endl;
                }
            }
        }
        void display()
        {
            cout<<"queue : "<<endl;
            for(int i = front ; i < rear ;i++)
            {
                cout<<i<<endl;
            }
        }
};
int main()
{
    queue a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);
    a.enqueue(6);
    a.enqueue(7);
    a.enqueue(8);
    a.enqueue(9);
    a.enqueue(10);
    a.enqueue(11);
    a.enqueue(12);

    a.display();

    a.dequeue();
    a.dequeue();

    a.display();

}