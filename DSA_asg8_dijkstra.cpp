#include <iostream>

using namespace std;

class graph
{
int g[20][20];
int e,n;
public:

    void accept()
    {
          int src,dest,cost,i,j;
          cout<<"\n Enter no. of vertices and edges : ";
          cin>>n>>e;
        
          for(i=0;i<n;i++)
          {
             for(j=0;j<n;j++)
             {
               g[i][j]=0;
             }
          }

          for(i=0;i<e;i++)
          {
             cout<<"\n Enter source, destination and cost: ";
             cin>>src>>dest>>cost;
             g[src][dest]=cost;

        }
    }

    void dijkstra(int src)
    {
        int R[20][20], D[20], ST[20], from[20];
        int min, u, v, i, j;

        //******************** Initializing R*******************************************

        /*
            Create a temporary matrix (R) and copy all the contents of the adjacency matrix (G)
            except replace all the 0’s with infinity
        */

        for(i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(g[i][j]==0)
                    R[i][j] = 999;    //999 in place of infinity
                else
                    R[i][j] = g[i][j];
            }
        }

        //******************************************************************************


        //******************** Initializing D, ST and from******************************

        /*  1.  Create a array (D) to store the distance of the all the vertices from the source.
                Initially set the distance of all the vertices from source as infinity
                (but keep distance of source vertex as 0).

            2.  Create a array (ST) to keep track of all the vertices included in the shortest path tree.
                    value = 0  if the vertex has not yet been included in the shortest path tree.
                    value = 1 if the vertex has been included in the shortest path tree.

                (initially set all the values to 0)

            3.  Create a array (from) to keep track of the path required to reach a vertex.
                Initially keep all the values as source.

        */
        for(i=0; i<n; i++)
        {
            D[i] = 999;          //999 in place of infinity
            ST[i] = 0;
            from[i] = src;
        }

        D[src] = 0;          //distance of source is kept as "0"
        //*****************************************************************************


        //************************************* Step 4 *******************************

        //Repeat steps 1-3 " n-1 " times

        for(i=0; i<n-1; i++)
        {


            //********************************* Step 1 *******************************

            /*
                Select a vertex "u" with minimum distance and which is not yet included in the
                shortest path tree (ST) i.e. ST[j] == 0
            */

            min = 999;
            for(j=0; j<n; j++)
            {
                if(D[j]<min && ST[j]==0)
                {
                    min = D[j];
                    u = j;
                }
            }
            //************************************************************************


            //********************************* Step 2 *******************************

            //  include the vertex u from step 1 in the shortest path tree (ST).

            ST[u] = 1;

            //************************************************************************


            //********************************* Step 3 *******************************

            /*
                Iterate through all the adjacent vertices of u and update their distances
                using the update rule.

                update rule:
                                if( D[u] + R[u][v] < D[v])
                                {
                                    D[v] = D[u] + R[u][v];
                                }

            */

            for(v=0; v<n; v++)
            {
                if(D[u] + R[u][v] < D[v])
                {
                    D[v] = D[u] + R[u][v];
                    from[v] = u;
                }

            }

            //************************************************************************
        }

        //*****************************************************************************


        //******************** Code to print the output *******************************

        for(i=0; i<n; i++)
        {
            cout<<"shortest path from "<<src<<" to "<<i<<" : ";
            j = i;
            while(j!=src)
            {
                cout<<j<<"<-";
                j = from[j];
            }
            cout<<src<<" with cost "<<D[i]<<endl;
        }

        //*****************************************************************************

    }
};


int main()
{
    graph g;
    g.accept();
    g.dijkstra(0);

    return 0;
}
