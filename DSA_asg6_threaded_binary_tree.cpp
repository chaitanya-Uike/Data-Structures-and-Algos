#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    int leftThread;
    int rightThread;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class DTBT
{
    Node* root;
public:
    DTBT()
    {
        root = new Node(INT_MAX);
        root->left = root->right = root;
        root->leftThread = root->rightThread = 0;
    }

    void Insert(int data)
    {
        Node* newNode = new Node(data);
        if(root->left == root && root->right == root)
        {
            root->left = newNode;
            root->leftThread = 1;
            newNode->left = newNode->right = root;
            newNode->leftThread = newNode->rightThread = 0;
        }
        else
        {
            Node* temp = root;
            while(true)
            {
                while(temp->data > data && temp->leftThread==1)
                {
                    temp=temp->left;
                }
                if(temp->data > data && temp->leftThread==0)
                {
                    newNode->left = temp->left;
                    temp->left = newNode;
                    temp->leftThread = 1;
                    newNode -> right = temp;
                    newNode->leftThread = newNode->rightThread = 0;
                    return;
                }
                while(temp->data < data && temp->rightThread==1)
                {
                    temp=temp->right;
                }
                if(temp->data < data && temp->rightThread==0)
                {
                    newNode->right = temp->right;
                    temp->right = newNode;
                    temp->rightThread = 1;
                    newNode->left = temp;
                    newNode->leftThread = newNode->rightThread = 0;
                    return;
                }
            }
        }

    }

    void inorder()
    {
        Node* temp = root;
        do
        {
            while(temp->leftThread!=0)
            {
                temp=temp->left;
            }
            cout<<temp->data<<" ";
            while(temp->rightThread==0)
            {
                temp=temp->right;
                cout<<temp->data<<" ";
            }
            temp=temp->right;

        }while(temp->right!=root);
        cout<<temp->data<<" ";
    }

    void preorder()
    {
        Node* temp = root;
        do
        {
            while(temp->leftThread!=0)
            {
                temp=temp->left;
                cout<<temp->data<<" ";
            }
            while(temp->rightThread==0)
            {
                temp=temp->right;
            }
            temp=temp->right;
            cout<<temp->data<<" ";

        }while(temp->right!=root);
    }
};
int main()
{
    DTBT t;
    int ch, data;
    do
    {
        cout<<"\nMenu\n";
        cout<<"1.Insert\n";
        cout<<"2.InOrder traversal\n";
        cout<<"3.PreOrder traversal\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"enter data:";
                    cin>>data;
                    t.Insert(data);
                    break;
            case 2: t.inorder();
                    cout<<endl;
                    break;
            case 3: t.preorder();
                    cout<<endl;
                    break;
            case 4: cout<<"Exiting....";
                    break;
            default:cout<<"Invalid choice!!!\n";
        }
    }while(ch!=4);

    return 0;
}
