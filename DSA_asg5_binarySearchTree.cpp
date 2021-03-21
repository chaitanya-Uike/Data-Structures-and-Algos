#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


Node* root = NULL;

Node* getNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* findMin(Node* root)
{
    if(root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

Node* insert(Node* root, int data)
{
    if(root == NULL)
        root = getNewNode(data);
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

bool Search(Node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

Node* Delete(Node* root, int key)
{
    if(root == NULL) return root;
    else if(key < root->data) root->left = Delete(root->left, key);
    else if(key > root->data) root->right = Delete(root->right, key);
    else
    {
        if(root->left==NULL && root->right==NULL)       // for leaf nodes
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)                   // for nodes with single child
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)                // for nodes with single child
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        return root;
    }

}

void preOrderDisplay(Node* root)
{
    if(root == NULL)    return;
    cout<<root->data<<" ";
    preOrderDisplay(root->left);
    preOrderDisplay(root->right);
}

int depth(Node* root)
{
    if(root == NULL)    return -1;
    return max(depth(root->left), depth(root->right)) + 1;

}

Node* Copy(Node* root)
{
    if(root == NULL) return NULL;
    else
    {
        Node* newNode = getNewNode(root->data);
        newNode->left = Copy(root->left);
        newNode->right = Copy(root->right);
        root = newNode;
        return root;
    }
}

void invert(Node* root)
{
    if(root==NULL) return;
    else
    {
        Node* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }
}

void displayLeaf(Node* root)
{
    if(root==NULL)
        return;
    else if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    else
    {
        displayLeaf(root->left);
        displayLeaf(root->right);
    }
}

void displayParentChild(Node* root)
{
    if(root==NULL)  return;

    cout<<"Parent: "<<root->data<<" child: ";

    if(root->left!=NULL && root->right==NULL)
        cout<<root->left->data;
    if(root->left==NULL && root->right!=NULL)
        cout<<root->right->data;
    if(root->left != NULL && root->right!= NULL)
        cout<<root->left->data<<" "<<root->right->data;
    cout<<endl;
    displayParentChild(root->left);
    displayParentChild(root->right);
}

void levelOrderDisplay(Node* root)
{
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* current = Q.front();
        cout<<current->data<<" ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}

int main()
{
    int ch, data;
    Node* rootCopy;
    do
    {
    cout<<" \n Main menu ";
    cout<<"\n 1.Insert ";
    cout<<"\n 2.Display ";
    cout<<"\n 3.Search ";
    cout<<"\n 4.Delete ";
    cout<<"\n 5.Mirror image ";
    cout<<"\n 6.create copy ";
    cout<<"\n 7.Find Depth ";
    cout<<"\n 8.Display Tree Level-wise ";
    cout<<"\n 9.Display Leaf nodes ";
    cout<<"\n 10.Display parent node with child nodes ";
    cout<<"\n 11.Exit \n Enter your choice - ";
    cin>>ch;

    switch(ch)
    {
        case 1: cout<<"Enter data:";
                cin>>data;
                root = insert(root, data);
                break;
        case 2: preOrderDisplay(root);
                cout<<endl;
                break;
        case 3: cout<<"Enter Key:";
                cin>>data;
                if(Search(root, data)== false) cout<<"Not found\n";
                else cout<<"found\n";
                break;
        case 4: cout<<"Enter Key:";
                cin>>data;
                root = Delete(root, data);
                cout<<"Item deleted successfully\n";
                break;
        case 5: invert(root);
                cout<<"tree has been Inverted\n";
                break;
        case 6: rootCopy = Copy(root);
                cout<<"The copied tree is : ";
                preOrderDisplay(rootCopy);
                cout<<endl;
                break;
        case 7: cout<<"depth of tree: "<<depth(root)<<endl;
                break;
        case 8: levelOrderDisplay(root);
                cout<<endl;
                break;
        case 9: displayLeaf(root);
                cout<<endl;
                break;
        case 10:displayParentChild(root);
                break;
        case 11:cout<<"Exiting....\n";
                break;
        default:cout<<"Invalid choice!!\n";
    }
    }while(ch!=11);


    return 0;
}
