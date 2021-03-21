#include<iostream>
#include<fstream>

using namespace std;

struct student
{
    int roll;
    char a,name[20],add[30];
};

void create();
void display();
void insert();
void search(int key);
void Delete(int key);
void modify(int key);

int main()
{
    int ch,x;
    do
    {
        cout<<"\n\t*****MENU*****\n1.Accept\n2.Display\n3.Insert\n4.Search\n5.Delete\n6.Modify\n7.Exit\n\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert();
                    break;
            case 4: cout<<"Enter roll no. to search:";
                    cin>>x;
                    search(x);
                    break;
            case 5: cout<<"Enter roll no. to delete:";
                    cin>>x;
                    Delete(x);
                    break;
            case 6: cout<<"Enter roll no. to modify:";
                    cin>>x;
                    modify(x);
                    break;
        }
    }while(ch!=7);
    return 0;
}

ifstream fin;
ofstream fout;
fstream fm;
int n;
char fname[20];

void create()
{
    int i;
    student s;
    cout<<"\nEnter name of the file:";
    cin>>fname;
    fm.open(fname,ios::out);
    cout<<"\nEnter no. of records:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter roll no.=";
        cin>>s.roll;
        cout<<"Enter name=";
        cin>>s.name;
        cout<<"Enter division=";
        cin>>s.a;
        cout<<"Enter address=";
        cin>>s.add;
        fm.write((char*) & s,sizeof(s));
    }
    fm.close();
}
void display()
{
    int i;
    student s;
    fin.open(fname);
    cout<<"\nROLL NO.\tNAME\tDIVISION\tADDRESS";
    for(i=0;i<n;i++)
    {
        fin.read((char*) & s, sizeof(s));
        printf("\n%-10d%-15s%-10c%s",s.roll,s.name,s.a,s.add);

    }
    fin.close();
}
void insert()
{
    student s;
    fout.open(fname,ios::app);
    cout<<"Enter roll no.=";
    cin>>s.roll;
    cout<<"Enter name=";
    cin>>s.name;
    cout<<"Enter division=";
    cin>>s.a;
    cout<<"Enter address=";
    cin>>s.add;
    fout.write((char*) & s, sizeof(s));
    n++;
    fout.close();
}
void search(int key)
{
    student s;
    int flag=0,i;
    fin.open(fname);
    for(i=0;i<n;i++)
    {
        fin.read((char*) & s, sizeof(s));
        if(s.roll==key)
        {
        cout<<"\nRecord is present their corressponding details are:\nRoll no.=";
        cout<<s.roll<<"\nName="<<s.name<<"\nDivision="<<s.a<<"\nAddress="
        <<s.add;
        flag=1;
        }
    }
    if(flag==0)
    cout<<"\nRoll no.="<<key<<"is not present in the record";
    fin.close();
}

void Delete(int key)
{
    student s;
    int flag=0,i;
    fin.open(fname);
    fout.open("temp.txt",ios::out);
    for(i=0;i<n;i++)
    {
        fin.read((char*) & s, sizeof(s));
        if(s.roll==key)

        {
            cout<<"\nRecord deleted successfully";
            flag=1;
        }
        else
        {
            fout.write((char*) & s, sizeof(s));
        }
    }
    if(flag==0)
        cout<<"\nRoll no.="<<key<<"is not present in the record";
    else
        n--;
    fin.close();
    fout.close();
    remove(fname);
    rename("temp.txt",fname);
}
void modify(int key)
{
    student s;
    int flag=0,i;
    fin.open(fname);
    fout.open("temp.txt",ios::out);
    for(i=0;i<n;i++)
    {
        fin.read((char*) & s, sizeof(s));
        if(s.roll==key)
        {
            cout<<"Enter roll no.=";
            cin>>s.roll;
            cout<<"Enter name=";
            cin>>s.name;
            cout<<"Enter division=";
            cin>>s.a;
            cout<<"Enter address=";
            cin>>s.add;
            fout.write((char*) & s, sizeof(s));
            flag=1;
        }
        else
        {
            fout.write((char*) & s, sizeof(s));
        }
    }
    if(flag==0)
        cout<<"\nRoll no.="<<key<<"is not present in the record";
    fin.close();
    fout.close();

    remove(fname);
    rename("temp.txt",fname);
}
