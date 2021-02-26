#include<iostream>
#include<queue>
using namespace std;

class Leaf
{
    public:
        int data;
        Leaf* left;
        Leaf* right;
};
Leaf* CreateLeaf(int d)
{
    Leaf* NewLeaf = new Leaf();
    if(!NewLeaf)
    {
        cout<<"memory out of range,dangling pointer error";
        return NULL;
    }
    else{
        NewLeaf->data = d;
        NewLeaf->left = NewLeaf->right = NULL;
        return(NewLeaf);
    }
}
Leaf* InsertLeaf(Leaf* root,int d)
{
    if(root == NULL)
    {
        root = CreateLeaf(d);
        return(root);
    }
    else
    {
        queue<Leaf*> q;
        q.push(root);

        while(!q.empty())
        {
            Leaf* temp = q.front();
            q.pop();
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            else
            {
                temp->left = CreateLeaf(d);
                return(root);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
            else
            {
                temp->right = CreateLeaf(d);
                return(root);
            }
        }
    }
}
void InOrder(Leaf* temp)
{
    if(temp == NULL)
    {
        return;
    }
    else
    {
        InOrder(temp->left);
        cout<<temp->data<<" ";
        InOrder(temp->right);
    }   
}
Leaf* DeleteDeepest(Leaf* root,Leaf* DelLeaf)
{
    queue<Leaf*> q;
    q.push(root);
    Leaf* temp = new Leaf();
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp == DelLeaf)
        {
            temp = NULL;
            delete(DelLeaf);
            return NULL;
        }
        if(temp->left)
        {
            if(temp->left == DelLeaf)
            {
                temp->left = NULL;
                delete(DelLeaf);
                return NULL;
            }
            else{
                q.push(temp->left);
            }
        }
        if(temp->right)
        {
            if(temp->right == DelLeaf)
            {
                temp->right = NULL;
                delete(DelLeaf);
                return NULL;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
}
Leaf* Deletion(Leaf* root , int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == key)
        {
            return NULL;
        }
        else{
            return(root);
        }
    }
    queue<Leaf*> q;
    q.push(root);

    Leaf* temp = new Leaf();
    Leaf* KeyLeaf = new Leaf();
    KeyLeaf = NULL; 

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data = key)
        {
            KeyLeaf = temp;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    if(KeyLeaf != NULL)
    {
        int x = KeyLeaf->data;
        DeleteDeepest(root,temp);
        KeyLeaf->data = x;
    }
    return(root);
}
/**
int main()
{
    Leaf* root = new Leaf();
    root = NULL;
    bool n;
    string a;
    while(!n)
    {
        cout<<"enter element/enter 'print' to print/enter 'end' for end the insertion/'delete' and enter the value to delte a Leaf : ";
        cin>>a;
        if(a == "end")
        {
            cout<<"insertion completed;";
            break;
        }
        else if(a == "print")
        {
            InOrder(root);
            cout<<endl;
        }
        else if(a == "delete")
        {
            int key;
            cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
            InOrder(root);
            cout<<"\n"<<"select any one variable from above : ";
            cin>>key;
            Deletion(root,key);
            InOrder(root);
            cout<<endl;
        }
        else
        {
            int b = stoi(a);
            root = InsertLeaf(root,b);
        }
    }
}
**/
int main() 
{ 
    Leaf* root = CreateLeaf(10); 
    root->left = CreateLeaf(11); 
    root->left->left = CreateLeaf(7); 
    root->left->right = CreateLeaf(12); 
    root->right = CreateLeaf(9); 
    root->right->left = CreateLeaf(15); 
    root->right->right = CreateLeaf(8); 
  
    cout << "InOrder traversal before deletion : "; 
    InOrder(root); 
  
    int key = 11; 
    root = Deletion(root, key); 
  
    cout << endl; 
    cout << "InOrder traversal after deletion : "; 
    InOrder(root); 
  
    return 0; 
} 