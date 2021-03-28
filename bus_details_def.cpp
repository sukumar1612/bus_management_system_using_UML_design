#include<iostream>
#include<stdio.h>
#include"bus_details.h"
#include<ctype.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<cstdio>

#define width 40
using namespace std;

void timings::get_data()
{
    cout<<"enter hours :"<<endl;
    cin>>hours;
    cout<<"enter minutes :"<<endl;
    cin>>minutes;
    cout<<"enter am or pm :"<<endl;
    fflush(stdin);
    gets(am_pm);
    for (int i=0;am_pm[i]!='\0';i++)
    {
        am_pm[i]=tolower(am_pm[i]);
    }
    while(strcmp(am_pm,"am")!=0 && strcmp(am_pm,"pm")!=0)
    {
        cout<<" wrong input\nenter am or pm :"<<endl;
        fflush(stdin);
        gets(am_pm);
        for (int i=0;am_pm[i]!='\0';i++)
        {
            am_pm[i]=tolower(am_pm[i]);
        }
    }
    cout<<"enter date :"<<endl;
    cin>>date;
    cout<<"enter month :"<<endl;
    cin>>month;
    cout<<"enter year :"<<endl;
    cin>>year;
}
void timings::display()
{
    cout<<"time :"<<hours<<":"<<minutes<<am_pm<<endl;
    cout<<"date :"<<date<<"/"<<month<<"/"<<year<<endl;
}
void timings::display_time()
{
    cout<<hours<<":"<<minutes<<am_pm;
}
void timings::display_date()
{
    cout<<date<<"/"<<month<<"/"<<year;
}
void bus::get_data()
{
    ofstream fout;
    bus b;
    fout.open("bus_timetable.txt",ios::app);
    b.r.get_data();
    b.f.get_data();
    b.t.get_data();
    strcpy(b.model,"TATA G3 AMT");
    cout<<"enter number of seats :"<<endl;
    cin>>b.number_of_seats_left;
    cout<<"enter price :"<<endl;
    cin>>b.price;

    fout.write((char*)&b,sizeof(b));
    fout.close();

}

void bus::display()
{
    bus b;
    ifstream fin;
    fin.open("bus_timetable.txt",ios::in);
    int j=1;
    while(!fin.eof())
    {
        fin.read((char*)&b,sizeof(b));
        cout<<"bus model"<<setw(56)<<"departure time"<<setw(50)<<"departure date"<<endl;
        cout<<j<<") "<<b.model;
        cout<<setw(width);
        b.t.display_time();
        cout<<setw(45);
        b.t.display_date();
        cout<<endl;
        cout<<"\nnumber of seats left : "<<b.number_of_seats_left<<endl;
        cout<<endl;
        cout<<"\n----route details----\n"<<endl;
        b.r.display();
        cout<<"\n----food details-----\n"<<endl;
        b.f.display();
        cout<<"||||||| price :"<<b.price<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
        j++;
    }
    fin.close();
}
int bus::search_data()
{
    system("cls");
    char source[50];
    char dest[50];
    cout<<"enter source :"<<endl;
    fflush(stdin);
    gets(source);
    cout<<"enter destination :"<<endl;
    fflush(stdin);
    gets(dest);

    bus b;
    int x=0;
    ifstream fin;
    fin.open("bus_timetable.txt",ios::in);
    while(!fin.eof())
    {
        fin.read((char*)&b,sizeof(b));
        if(strcmp(b.r.from,source)==0 && strcmp(b.r.to,dest)==0)
        {
            cout<<"bus model"<<setw(56)<<"departure time"<<setw(50)<<"departure date"<<endl;
            cout<<x+1<<") "<<b.model;
            cout<<setw(width);
            b.t.display_time();
            cout<<setw(45);
            b.t.display_date();
            cout<<endl;
            cout<<"\nnumber of seats left : "<<b.number_of_seats_left<<endl;
            cout<<endl;
            cout<<"\n----route details----\n"<<endl;
            b.r.display();
            cout<<"\n----food details-----\n"<<endl;
            b.f.display();
            cout<<"||||||| price :"<<b.price<<endl;
            cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
            x++;
        }
    }
    if(x==0)
    {
        cout<<"---------------------no buses available---------------------"<<endl;
    }
    fin.close();
    char op;
    cout<<"do you want to book ticket (y/n) "<<endl;
    cin>>op;
    if(op=='n')
    {
        return 0;
    }
    else if(op=='y')
    {
        int a;
        fin.open("bus_timetable.txt",ios::in);
        ofstream fout;
        fout.open("bus_time.txt",ios::out);
        cout<<"enter booking option number :"<<endl;
        cin>>a;
        x=0;
        while(!fin.eof())
        {
            fin.read((char*)&b,sizeof(b));
            if(strcmp(b.r.from,source)==0 && strcmp(b.r.to,dest)==0)
            {
                x++;
                if(x==a)
                {
                    b.number_of_seats_left=b.number_of_seats_left-1;
                    fout.write((char*)&b,sizeof(b));
                }
                else
                {
                    fout.write((char*)&b,sizeof(b));
                }
            }
            else
            {
                fout.write((char*)&b,sizeof(b));
            }
        }
        fout.close();
        fin.close();
        remove("bus_timetable.txt");
        rename("bus_time.txt","bus_timetable.txt");
        system("cls");
        cout<<"----ticket booked----"<<endl;
        strcpy(this->r.to,b.r.to);
        strcpy(this->r.from,b.r.from);
        strcpy(this->model,b.model);
        this->price=b.price;
        return 1;
    }
    else
    {
        cout<<"no valid option entered "<<endl;
        return 0;
    }
}
