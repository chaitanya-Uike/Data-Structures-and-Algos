//Assignment 9


#include<iostream>

using namespace std;

int leftChild(int A[], int i, int n)
{
    if(2*i<=n)
        return 2*i;
    else
        return NULL;
}

int rightChild(int A[], int i, int n)
{
    if(2*i+1<=n)
        return 2*i+1;
    else
        return NULL;
}

void maxHeapify(int A[], int n)
{
    int j, temp, parent;
    int l, r;
    for(int i=n; i>0; i--)
    {
        parent = i;
        while(leftChild(A, parent, n) != NULL)
        {
            l = leftChild(A,parent,n);
            r = rightChild(A, parent, n);
            if(l!=NULL && r==NULL)
            {
                j = l;
            }
            else if(r!=NULL)
            {
                if(A[l]>A[r]) j = l;
                else j = r;
            }
            if(A[parent]<A[j])
            {
                temp = A[parent];
                A[parent] = A[j];
                A[j] = temp;
            }
            parent = j;
        }
    }
}

void minHeapify(int A[], int n)
{
    int j, temp, parent;
    int l, r;
    for(int i=n; i>0; i--)
    {
        parent = i;
        while(leftChild(A, parent, n) != NULL)
        {
            l = leftChild(A,parent,n);
            r = rightChild(A, parent, n);
            if(l!=NULL && r==NULL)
            {
                j = l;
            }
            else if(r!=NULL)
            {
                if(A[l]>A[r]) j = r;
                else j = l;
            }
            if(A[parent]>A[j])
            {
                temp = A[parent];
                A[parent] = A[j];
                A[j] = temp;
            }
            parent = j;
        }
    }
}

void maxHeapSort(int A[], int n)
{
    int temp;
    while(n>1)
    {
        maxHeapify(A, n);
        temp = A[1];
        A[1] = A[n];
        A[n] = temp;

        n--;
    }
}

void minHeapSort(int A[], int n)
{
    int temp;
    while(n>1)
    {
        minHeapify(A, n);
        temp = A[1];
        A[1] = A[n];
        A[n] = temp;

        n--;
    }
}

void display(int A[], int n)
{
    for(int i=1; i<=n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


void acceptArray(int A[], int n)
{
    for(int i=1; i<=n ;i++)
    {
        cout<<"enter value:";
        cin>>A[i];
    }
}


int main()
{
    int A[20];
    int n, ch;
    cout<<"enter size of heap:";
    cin>>n;
    acceptArray(A, n);

    do
    {
        cout<<"MENU\n";
        cout<<"1. heap sort using max heap\n";
        cout<<"2. heap sort using min heap\n";
        cout<<"3. exit\n";
        cout<<"enter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1: maxHeapSort(A, n);
                    cout<<"heap after max heap sort: ";
                    display(A,n);
                    break;
            case 2: minHeapSort(A, n);
                    cout<<"Array after min heap sort: ";
                    display(A, n);
                    break;
            case 3: cout<<"exiting....";
                    break;
            default:cout<<"invalid choice!!\n";
        }
    }while(ch!=3);
    return 0;
}
