#include <iostream>
#include <string.h>


using namespace std;
class SEIT{
public:
    float SGPA;
    int rollNo;
    char name[20];
    SEIT(){
    SGPA = 0;
    rollNo = 0;
    strcpy(name,"");

    }
    SEIT(int r, const char* n, float s){
        SGPA = s;
        rollNo = r;
        strcpy(name,n);
    }
};


void bubbleSort(SEIT *A, int n)
{
    bool xchanges;
    SEIT temp;
    for(int i = 1; i < n; i++)
    {
        xchanges = false;
        for (int j = 0; j < n - i; j++)
        {
            if(A[j].rollNo > A[j+1].rollNo)
            {
                temp = A[j];
                A[j] = A[j+1];

                A[j+1] = temp;
                xchanges = true;
            }
        }
        if(xchanges==false){
            break;
        }
    }
}
void insertionSort(SEIT *A, int n)
{
    SEIT value;
    int hole;
    for(int i=1; i<n; i++)
    {
        value = A[i];
        hole = i;
        while(hole>0 && strcmp(A[hole-1].name,value.name)>0)
        {

            A[hole] = A[hole-1];
            hole--;
        }
        A[hole] = value;
    }
}

void showData(SEIT s)
{
    cout<<"Roll No:"<<s.rollNo<<" Name:"<<s.name<<" SGPA:"<<s.SGPA<<"\n";
}

void swap(SEIT *A, int a, int b)
{
    SEIT temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition (SEIT *A, int L, int U)
{
    SEIT pivot = A[L];
    int i = L-1;
    for (int j = L; j <= U; j++)
    {
        if (A[j].SGPA <= pivot.SGPA)
        {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i, L);
    return i;
}


void quickSort(SEIT *A, int l, int u)
{
    if(l>u)
    return;
    int pIndex = partition(A,l,u);

    quickSort(A,l,pIndex-1);
    quickSort(A,pIndex+1,u);
}

void linearSearch(SEIT *A, int n, float item)
{
    bool found = false;
    for(int i=0; i<n; i++)
    {

        if(A[i].SGPA == item)
        {
            showData(A[i]);
            found = true;
        }
    }
    if(found == false)
    cout<<"Not Found\n";
}
int binarySearch(SEIT *A, int n, char *name)
{
    int L = 0;

    int U = n-1;
    while(L<=U)
    {
        int mid = (L + U) / 2;
        if(strcmp(A[mid].name,name)==0)
        return mid;
        else if(strcmp(A[mid].name,name) > 0)
        U = mid - 1;
        else
        L = mid + 1;
    }
    return -1;
}
void showArray(SEIT *A, int n)
{
    for (int i=0; i<n; i++){
        showData(A[i]);
    }

    cout<<endl;
}
void showArrayReversed(SEIT *A, int n, int limit)
{
    for (int i=n-1; i>=n-limit; i--){
    showData(A[i]);
    }
    cout<<endl;
}


int main()
{
    SEIT database[15] = {
    SEIT(15,"Kyle",7.2),
    SEIT(14,"kenny",7.9),
    SEIT(13,"Eric",8.2),
    SEIT(12,"Butters",8.8),
    SEIT(11,"Stan",7.5),
    SEIT(10,"Token",8.2),
    SEIT(9,"Randy",9.0),
    SEIT(8,"Jimmy",8.6),
    SEIT(7,"Tweek",9.7),
    SEIT(6,"Craig",7.1),
    SEIT(5,"Clyde",7.2),
    SEIT(4,"Scott",8.5),
    SEIT(3,"Timmy",7.0),
    SEIT(2,"wendy",8.1),
    SEIT(1,"Nicole",9.8),
    };
    int index;
    float sgpa;
    char name[20];
    int limit;
    int choice = 0;
    while(choice!=6){
        cout<<"\n1.arrange list of students according to roll numbers (Bubble sort)\n";
        cout<<"2.arrange list of students alphabetically (insertion sort)\n";
        cout<<"3.arrange list of students to find out first 10 toppers (quick sort)\n";
        cout<<"4.search students according to SGPA (linear search)\n";
        cout<<"5.search a particular student according to name (binary search)\n";
        cout<<"6.exit\n";

        cout<<"\nenter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                bubbleSort(database, 15);
                cout<<"List of students arranged according to roll number:\n";
                showArray(database, 15);
                break;
            case 2:
                insertionSort(database, 15);
                cout<<"List of students arranged alphabetically:\n";
                showArray(database, 15);
                break;
            case 3:
                quickSort(database,0,14);
                cout<<"Enter number of students to be displayed (at most 15):";
                cin>>limit;
                cout<<"List of top "<<limit<<" toppers:\n";
                showArrayReversed(database,15,limit);
                break;

            case 4:
                cout<<"Enter SGPA to be searched:";
                cin>>sgpa;
                linearSearch(database, 15, sgpa);
                break;
            case 5:

                cout<<"Enter name to be searched:";
                cin>>name;
                insertionSort(database, 15);
                index = binarySearch(database,15,name);
                if(index==-1)
                cout<<"Data unavailable\n";
                else
                showData(database[index]);
                break;
            case 6:
                cout<<"Exiting...";
                break;
            default :
                cout<<"invalid!\n";
        }
    }
    return 0;
}
