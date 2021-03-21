#include<iostream>

using namespace std;

class Graph
{
private:
    int G[20][20], n;

public:
    void accept()
    {
        int e, src, dest, cost;
        cout<<"Enter number of vertices:";
        cin>>n;
        cout<<"Enter number of edges:";
        cin>>e;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                G[i][j] = 0;
            }
        }

        for(int i=0; i<e; i++)
        {
            cout<<"Enter source and destination:";
            cin>>src>>dest;
            cout<<"Enter cost:";
            cin>>cost;

            G[src][dest] = cost;
            G[dest][src] = cost;
        }
    }

    void display()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void Prims()
    {
        int R[20][20], V[20];
        int count = 0, total = 0;
        int src, dest;
        int min;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(G[i][j]==0)
                    R[i][j] = 999;
                else
                    R[i][j] = G[i][j];
            }
        }

        for(int i=0; i<n ;i++)
            V[i] = 0;

        cout<<"Enter source Vertex:";
        cin>>src;

        V[src] = 1;

        while(count < n-1)
        {
            min = 999;
            for(int i=0; i<n; i++)
            {
                if(V[i]==1)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(V[j] != 1)
                        {
                            if(min>R[i][j])
                            {
                                min = R[i][j];
                                src = i;
                                dest = j;
                            }
                        }
                    }
                }
            }

            cout<<"Edge from "<<src<<" to "<<dest<<" with cost "<<R[src][dest]<<endl;
            total += R[src][dest];
            V[dest] = 1;
            count++;
        }

        cout<<"Total cost:"<<total<<endl;
    }
};

int main()
{
    Graph g1;
    g1.accept();
    g1.display();
    g1.Prims();

    return 0;

}
