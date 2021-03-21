#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

struct StackNode
{
    Node* node;
    StackNode* next;
};

class Stack
{
    StackNode* head;
public:
    Stack()
    {
        head = NULL;
    }

    void push(Node* newNode)
    {
        StackNode* newStackNode = new StackNode();
        newStackNode->node = newNode;
        newStackNode->next = head;
        head = newStackNode;
    }

    StackNode* pop()
    {
        if(head==NULL) return NULL;
        else
        {
            StackNode* temp = head;
            head = head->next;
            return temp;
        }

    }

    bool empty()
    {
        if(head == NULL)
            return true;
        return false;
    }
};


Node* getNewNode(char data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* create_post(char postfix[])
{
    Stack s;
    for(int i=0; postfix[i] != '\0'; i++)
    {
        char token = postfix[i];
        if(isalnum(token))
        {
            Node* p = getNewNode(token);
            s.push(p);
        }
        else
        {
            Node* p = getNewNode(token);
            p->right = s.pop()->node;
            p->left = s.pop()->node;
            s.push(p);
        }
    }

    return s.pop()->node;
}

void preOrderDisplay(Node* root)
{
    if(root == NULL)    return;
    cout<<root->data<<" ";
    preOrderDisplay(root->left);
    preOrderDisplay(root->right);
}

void inOrderDisplay(Node* root)
{
    if(root == NULL)    return;
    inOrderDisplay(root->left);
    cout<<root->data<<" ";
    inOrderDisplay(root->right);
}

void postOrderDisplay(Node* root)
{
    if(root == NULL)    return;
    postOrderDisplay(root->left);
    postOrderDisplay(root->right);
    cout<<root->data<<" ";
}

void Non_recursive_inOrderDisplay(Node* root)
{
    Stack s;
    while(root!=NULL)
    {
        s.push(root);
        root = root->left;
    }
    while(!s.empty())
    {
        root = s.pop()->node;
        cout<<root->data<<" ";
        root = root->right;
        while(root!=NULL)
        {
            s.push(root);
            root = root->left;
        }
    }
}

void Non_recursive_preOrderDisplay(Node* root)
{
    Stack s;
    while(root != NULL)
    {
        s.push(root);
        cout<<root->data<<" ";
        root=root->left;
    }
    while(!s.empty())
    {
        root = s.pop()->node;
        root = root->right;
        while(root!=NULL)
        {
            s.push(root);
            cout<<root->data<<" ";
            root=root->left;
        }
    }
}

void Non_recursive_postOrderDisplay(Node* root)
{
    Stack s,s1;
    Node* t1;
    while(root!=NULL)
    {
        s.push(root);
        s1.push(NULL);
        root=root->left;
    }
    while(!s.empty())
    {
        root=s.pop()->node;
        t1=s1.pop()->node;
        if(t1==NULL)
        {
            s.push(root);
            s1.push((Node*)1);
            root=root->right;
            while(root!=NULL)
            {
                s.push(root);

                s1.push(NULL);
                root=root->left;
            }
        }
        else
        cout<<root->data<<" ";
    }
}

int main()
{
    Node* root;
    int ch;
    char postfix[40];
    do
    {
        cout<<"Menu\n";
        cout<<"1.Create tree from postfix\n";
        cout<<"2.PreOrder traversal\n";
        cout<<"3.InOrder traversal\n";
        cout<<"4.PostOrder traversal\n";
        cout<<"5.Non recursive PreOrder traversal\n";
        cout<<"6.Non recursive InOrder traversal\n";
        cout<<"7.Non recursive PostOrder traversal\n";
        cout<<"8.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"Enter postfix Expression:";
                    cin>>postfix;
                    root = create_post(postfix);
                    break;
            case 2: preOrderDisplay(root);
                    cout<<endl;
                    break;
            case 3: inOrderDisplay(root);
                    cout<<endl;
                    break;
            case 4: postOrderDisplay(root);
                    cout<<endl;
                    break;
            case 5: Non_recursive_preOrderDisplay(root);
                    cout<<endl;
                    break;
            case 6: Non_recursive_inOrderDisplay(root);
                    cout<<endl;
                    break;
            case 7: Non_recursive_postOrderDisplay(root);
                    cout<<endl;
                    break;
            case 8: cout<<"Exiting...";
                    break;
            default:cout<<"Invalid choice!!\n";
        }
    }while(ch!=8);


    return 0;
}


