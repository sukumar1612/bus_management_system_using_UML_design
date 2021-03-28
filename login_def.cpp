#include<iostream>
#include<stdio.h>
#include "login.h"
#include<ctype.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<cstdio>

using namespace std;

void login::get_details()
{
    login l;
    cout<<"enter username :"<<endl;
    fflush(stdin);
    gets(l.user_name);
    cout<<"enter password :"<<endl;
    fflush(stdin);
    gets(l.password);
    cout<<"enter name :"<<endl;
    fflush(stdin);
    gets(l.name);
    cout<<"enter age :"<<endl;
    fflush(stdin);
    cin>>l.age;
    while(l.age<0)
    {
        cout<<"enter age :"<<endl;
        cin>>l.age;
    }
    cout<<"enter gender (m/f):"<<endl;
    cin>>l.gender;
    while(l.gender!='m' && l.gender!='f')
    {
        cout<<"invalid input\nenter gender (m/f):"<<endl;
        cin>>l.gender;
    }
    cout<<"enter special needs : "<<endl;
    fflush(stdin);
    gets(l.special_needs);
    cout<<"enter adhar number :"<<endl;
    cin>>l.adhar_number;

    ofstream fout;
    fout.open("login_details.txt",ios::app);
    fout.write((char*)&l,sizeof(l));
    fout.close();

}

int login::authenticate()
{
    char user[50];
    char pass[50];

    login l;

    cout<<"enter username :"<<endl;
    fflush(stdin);
    gets(user);
    cout<<"enter password :"<<endl;
    fflush(stdin);
    gets(pass);

    ifstream fin;
    fin.open("login_details.txt",ios::in);
    while(!fin.eof())
    {
        fin.read((char*)&l,sizeof(l));
        if(strcmp(l.user_name,user)==0 && strcmp(l.password,pass)==0)
        {
            strcpy(this->password,pass);
            strcpy(this->user_name,user);
            strcpy(this->name,l.name);
            return 1;
        }
    }

    return 0;
}

void login::display_details()
{
    cout<<"welcome "<<name<<endl;
}
