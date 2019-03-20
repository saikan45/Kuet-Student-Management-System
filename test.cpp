#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class base
{
    char* university;


public:
    void set()
    {
        university=new char [200];
        cout<<"Enter name of the university: ";
        cin>>university;

    }
};
class student:virtual public base
{
    char name[100];
    int roll;
    int year;
    int semester;
    int t_s;
    float gpa[8];
    float cgpa;
    string department;
    string email;
    string phone_num;
    string current_address;
public:
    void set()
    {
        cout<<"Enter name of the student: "<<endl;
        cin>>name;
        cout<<"Enter roll no. :"<<endl;
        cin>>roll;
        cout<<"Enter year:"<<endl;
        cin>>year;
        cout<<"Enter semester:"<<endl;
        cin>>semester;
        t_s=(year-1)*2+semester;
        cout<<"Enter department name:"<<endl;
        cin>>department;
        cout<<"-----gpa-----"<<endl;
        for(int i=0; i<t_s; i++)
        {
            cout<<"Enter gpa of "<<i+1<<"st semester:"<<endl;
            cin>>gpa[i];
        }
        cout<<"Enter e-mail address:"<<endl;
        cin>>email;
        cout<<"Enter phone number:"<<endl;
        cin>>phone_num;
        cout<<"Enter current address:"<<endl;
        cin>>current_address;
    }
    template <class t>
    t cgpa_count(t q)
    {
        float sum=0;
        for(int i=0; i<t_s; i++)
        {
            sum+=gpa[i];
        }
        cgpa=sum/t_s;
    }
    string fun_n()
    {
        return name;
    }
    int fun_r()
    {
        return roll;
    }
    float fun_c()
    {
        return cgpa;
    }
    string fun_d()
    {
        return department;
    }
    string fun_e()
    {
        return email;
    }
    student()
    {
        cgpa=0.0;
    }
    void get()
    {
        cout<<"Name: "<<name<<" "<<endl<<"Roll: "<<roll<<endl<<"Year: "<<year<<" Semester: "<<semester<<endl<<"CGPA: "<<cgpa<<endl;
        cout<<"Department: "<<department<<endl<<"E-mail: "<<email<<endl<<"Current Address: "<<current_address<<endl;
    }
    void up()
    {
        int ice,j;
        cout<<"1. Press 1 to update name"<<endl;
        cout<<"2. Press 2 to update roll"<<endl;
        cout<<"3. Press 3 to update gpa"<<endl;
        cin>>ice;
        if(ice==1)
        {
            cout<<"Enter name to update:"<<endl;
            cin>>name;
        }
        else if(ice==2)
        {
            cout<<"Enter roll to update:"<<endl;
            cin>>roll;
        }
        else if(ice==3)
        {
            int y,s,t;
            float u_gpa;
            cout<<"Enter year and semester gpa to update:"<<endl;
            cin>>y>>s;
            t=(y-1)*2+s;
            cout<<"Enter updated cgpa:"<<endl;
            cin>>u_gpa;
            gpa[t]=u_gpa;
            cgpa_count(0.0);
        }
        else
        {
            cout<<"Invalid input"<<endl;
        }
    }
};

vector<student> vec;


void sorting()
{
    student l;
    int ice;
    cout<<"1. Press 1 to sort by CGPA."<<endl;
    cout<<"2. Press 2 to sort by roll."<<endl;
    cin>>ice;
    if(ice==1)
    {
        for(int i=0; i<(vec.size()-1); i++)
        {
            for(int j=i+1; j<vec.size(); j++)
            {
                if(vec[i].fun_c()<vec[i+1].fun_c())
                {
                    l=vec[i];
                    vec[i]=vec[i+1];
                    vec[i+1]=l;
                }
            }
        }
    }
    else if(ice==2)
    {

        for(int i=0; i<(vec.size()-1); i++)
        {
            for(int j=i+1; j<vec.size(); j++)
            {
                if(vec[i].fun_r()>vec[i+1].fun_r())
                {
                    l=vec[i];
                    vec[i]=vec[i+1];
                    vec[i+1]=l;
                }
            }
        }
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
}

void add()
{
    int n;
    cout<<"Enter number of students:"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        student x;
        x.set();
        x.cgpa_count(0.0);
        vec.push_back(x);
    }
}
int sarch()
{
    string n;
    int ro,ice,i;
    cout<<"1. Enter 1 to search by name"<<endl;
    cout<<"2. Enter 2 to search by roll"<<endl;
    cin>>ice;
    if(ice==1)
    {
        cout<<"Enter student name to search:"<<endl;
        cin>>n;
        for(i=0; i<vec.size(); i++)
        {
            if(n== vec[i].fun_n())

            {
                vec[i].get();
                break;
            }
        }
    }
    else if(ice==2)
    {
        cout<<"Enter student roll:"<<endl;
        cin>>ro;
        for(i=0; i<vec.size(); i++)
        {
            if(ro== vec[i].fun_r())
            {
                vec[i].get();
                break;
            }
        }
    }
    else
    {
        cout<<"Invalid input"<<endl;
        return 10000;
    }
    return i;
}

void deletion()
{
    int i;
    i=sarch();
    if(i==10000)
    {
        cout<<"No match found to delete"<<endl;
        return;
    }
    else
    {
        vec.erase(vec.begin()+i);
    }
}

void update()
{
    int j;
    j=sarch();
    vec[j].up();
}


void display()
{
    ofstream out("Text.txt");
    if(!out)
    {
        cout<<"Not Found!!"<<endl;
        return;
    }
    for(int i=0; i<vec.size(); i++)
    {
        out<<"Name: "<<vec[i].fun_n()<<" Roll: "<<vec[i].fun_r()<<" CGPA: "<<vec[i].fun_c()<<" E-mail: "<<vec[i].fun_e()<<" Department: "<<vec[i].fun_d()<<endl;
    }
}

int main()
{
    base b;
    b.set();
    int choice;
    while(1)
    {
        cout<<vec.size()<<endl;
        cout<<"1. Press 1 for adding student information"<<endl;
        cout<<"2. Press 2 for searching student information"<<endl;
        cout<<"3. Press 3 for deleting student information"<<endl;
        cout<<"4. Press 4 for sorting student information"<<endl;
        cout<<"5. Press 5 for updating student result"<<endl;
        cout<<"6. Press 6 for displaying student personal information"<<endl;
        cout<<"7. Press 7 to exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            sarch();
            break;
        case 3:
            deletion();
            break;
        case 4:
            sorting();
            break;
        case 5:
            update();
            break;
        case 6:
            display();
            break;
        case 7:
            return 0;
            break;
        }
    }
}

