#include <iostream>
#include"route.h"
#include "food.h"
#include "bus_details.h"
#include "payment.h"
#include "login.h"
#include <iomanip>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

#define TRUE 1
int main()
{
    login l;
    while(TRUE)
    {
        int x=0;
        cout<<"------------------------bus reservation system-------------------------------"<<endl;
        cout<<"\n\n\n\n1)login\t\t\t2)register\t\t3)exit"<<endl;
        cout<<"\n\nenter option :";
        cin>>x;
        if(x==0)
        {
            bus b;
            int z;
            cout<<"enter number of entries :"<<endl;
            cin>>z;
            for (int i=0;i<z;i++)
            {
                b.get_data();
            }
        }
        else if(x==3)
        {
            break;
        }
        else if(x==2)
        {
            l.get_details();
            cout<<"please login now "<<endl;
            cout<<"\n\n\n\n"<<endl;
            system("pause");
            system("cls");
        }
        else if(x==1)
        {
            int z=0;
            int j=l.authenticate();
            while(j!=1)
            {
                z++;
                cout<<"invalid user please try again "<<endl;
                j=l.authenticate();
                if(z>2)
                {
                    cout<<"too many attempts "<<endl;
                    break;
                }
            }
            if(z>2)
            {
                break;
            }
            system("cls");
            cout<<"welcome"<<l.name<<endl;

            cout<<"booking details :"<<endl;
            bus b;
            z=b.search_data();

            if(z==1)
            {
                payment *p;
                card ca;
                check ch;
                system("cls");
                cout<<"--------------redirecting you to payment gateway----------------"<<endl;
                Sleep(5);
                system("cls");
                cout<<"select mode of payment \n1)cash\n2)card\n3)check"<<endl;
                cin>>z;
                if(z==1)
                {
                    cout<<"please pay the required amount to the bus conductor"<<endl;
                }
                else if(z==2)
                {
                    p=&ca;
                    p->pay();
                }
                else
                {
                    p=&ch;
                    p->pay();
                }
                cout<<"----------------ticket confirmed----------------"<<endl;
                cout<<"\n\n\n"<<endl;
                cout<<setw(25)<<"passenger name:"<<l.name<<endl;
                cout<<setw(25)<<"departure :"<<b.r.to<<endl;
                cout<<setw(25)<<"arrival :"<<b.r.from<<endl;
                cout<<setw(25)<<"booking id:"<<rand()%10000<<endl;
                cout<<setw(25)<<"price :"<<b.price<<endl;
                system("pause");
                system("cls");
            }
        }
        system("cls");

    }
    return 0;
}
