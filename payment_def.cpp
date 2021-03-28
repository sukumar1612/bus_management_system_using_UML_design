#include<iostream>
#include<stdio.h>
#include"payment.h"

using namespace std;

int card::pay()
{
    cout<<"enter card number :"<<endl;
    cin>>card_number;
    cout<<"enter cvv:"<<endl;
    cin>>cvv;
}
int cash::pay()
{
    cout<<"enter amount :"<<endl;
    cin>>amount;
}
int check::pay()
{
    cout<<"enter check number :"<<endl;
    cin>>check_number;
}
