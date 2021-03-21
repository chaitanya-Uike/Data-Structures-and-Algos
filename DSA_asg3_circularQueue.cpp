#include<iostream>

using namespace std;

class Queue
{
    int rear, front;
    int size;
    int *arr;

public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }
    void enQueue(int value)
    {
        if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
        {
            cout<<"\nQueue is Full\n";
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    int deQueue()
    {

        if (front == -1)
        {
            cout<<"\nQueue is Empty\n";
            return INT_MIN;
        }
        int data = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size-1)
            front = 0;
        else
            front++;
        return data;
    }

    void displayQueue()
    {
        if (front == -1)
        {

            cout<<"\nQueue is Empty\n";
            return;
        }
        cout<<"\nElements in Circular Queue are: ";
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout<<arr[i]<<" ";
        }
        else
        {
            for (int i = front; i < size; i++)
                cout<<arr[i]<<" ";
            for (int i = 0; i <= rear; i++)
                cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


int main()
{
    Queue q(5);
    int ch, data;
    do
    {
        cout<<"Menu\n";
        cout<<"1.Insertion\n";
        cout<<"2.deletion\n";
        cout<<"3.Display\n";
        cout<<"4.Exit\n";
        cout<<"enter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"enter value:";
                    cin>>data;
                    q.enQueue(data);
                    break;
            case 2: cout<<q.deQueue()<<" successfully deleted!\n";
                    break;
            case 3: q.displayQueue();
                    break;
            case 4: cout<<"Exiting...";
                    break;
            default:cout<<"Invalid choice!!\n";
        }
    }while(ch!=4);

    return 0;
}
