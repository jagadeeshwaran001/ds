#include<iostream>
#include<queue>
#include<string>

using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};
Node* CreateNode(int d)
{
    Node* NewNode = new Node();
    if(!NewNode)
    {
        cout<<"memory out of range,dangling pointer error";
        return NULL;
    }
    else{
        NewNode->data = d;
        NewNode->left = NewNode->right = NULL;
        return(NewNode);
    }
}
Node* InsertNode(Node* root,int d)
{
    if(root == NULL)
    {
        root = CreateNode(d);
        return(root);
    }
    else
    {
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            else
            {
                temp->left = CreateNode(d);
                return(root);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
            else
            {
                temp->right = CreateNode(d);
                return(root);
            }
        }
    }
}
void InOrder(Node* temp)
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
/**
int main()
{
    Node* root = new Node();
    root = NULL;
    bool n;
    string a;
    while(!n)
    {
        cout<<"enter element/enter 'print' to print/enter 'end' for end the insertion : ";
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
        else
        {
            int b = stoi(a);
            root = InsertNode(root,b);
        }
    }
}
**/
int main()
{
    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
 
    cout << "Inorder traversal before insertion: ";
    InOrder(root);
    cout << endl;
 
    int key = 12;
    root = InsertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    InOrder(root);
    cout << endl;
 
    return 0;
}