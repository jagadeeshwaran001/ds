#include<iostream>
using namespace std;

class stac
{
    public:
            //int n;
            //cout<<"enter the number of element : "<<endl;
            //cin>>n;
            int stack[100];
            int top = -1;
        void push(int item)
        {
            if(top >= 100)
            {
                cout<<"stack is full";
                return;
            }
            else
            {
                top++;
                stack[top] = item;
                cout<<"stack updated at "<<top<<" as : "<<item<<endl;
            }
        }
        void pop()
        {
            if(top <= -1)
            {
                cout<<"stack is empty"<<endl;
                return;
            }
            cout<<stack[top]<<" poped"<<endl;
            top--;
        }
        void display()
        {
            cout<<"stack"<<endl;
            for(int i = 0 ; i <= top ;  i++)
            {
                cout<<stack[i]<<endl;
            }
        }
};
int main()
{
    stac a;
    a.push(1);
    a.push(2);
    a.pop();
    a.display();
}

