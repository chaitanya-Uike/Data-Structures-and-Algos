#include<iostream>

using namespace std;



class Edge
{
public:
    int src, dest, cost;
};


int Find(int parent[], int vertex)
    {
        if(parent[vertex]==-1)
            return vertex;
        else
            Find(parent, parent[vertex]);
    }

int Union(int parent[], int src, int dest)
    {
        int x = Find(parent,src);
        int y = Find(parent,dest);

        if(x!=y)
        {
            parent[y] = x;
            return 1;
        }

        return 0;
    }

void Sort(Edge arr[], int n)
{
    // bubble sort to sort the edges

    bool xchanges;
    Edge temp;
    for(int i = 1; i < n; i++){
        xchanges = false;
        for (int j = 0; j < n - i; j++){
            if(arr[j].cost > arr[j+1].cost){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                xchanges = true;
            }
        }
        if(xchanges==false){
            break;
        }
    }
}

void printMST(Edge input[], int n, int e)
{
    int src, dest;
    int total = 0;
    int* parent = new int[n];

    Sort(input, e);

    for(int i=0; i<n; i++)
        parent[i] = -1;

    for(int i=0; i<e; i++)
    {
        src = input[i].src;
        dest = input[i].dest;

        if(Union(parent, src, dest)!=0)
        {
            cout<<"Edge "<<input[i].src<<"-"<<input[i].dest<<" cost:"<<input[i].cost<<endl;
            total += input[i].cost;
        }
    }

    cout<<"Total cost:"<<total<<endl;

}

int main()
{
    int src, dst, cost;
    int n, e;
    cout<<"Enter number of vertices:";
    cin>>n;
    cout<<"Enter number of edges:";
    cin>>e;

    Edge *input = new Edge[e];

    cout<<"Enter source, destination and weight:";
    for(int i=0; i<e; i++)
    {
        cin>>src>>dst>>cost;
        input[i].src = src;
        input[i].dest = dst;
        input[i].cost = cost;

    }

    Sort(input, e);
    printMST(input, n, e);

    return 0;
}
