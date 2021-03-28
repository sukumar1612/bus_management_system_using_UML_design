#include<iostream>
#include "route.h"
#include<stdio.h>

using namespace std;


void route::get_data()
{
    cout<<"enter source :"<<endl;
    fflush(stdin);
    gets(from);
    cout<<"enter destination :"<<endl;
    fflush(stdin);
    gets(to);
    cout<<"enter distance (in km):"<<endl;
    cin>>distance;
    if(distance<0)
    {
        cout<<"invalid input\nenter distance (in km):"<<endl;
        cin>>distance;
    }

}
void route::display()
{
    cout<<"destination :"<<to<<endl;
    cout<<"source :"<<from<<endl;
    cout<<"distance :"<<distance<<"km"<<endl;
}
