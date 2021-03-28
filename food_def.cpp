#include<iostream>
#include"food.h"
#include<stdio.h>
#include<ctype.h>
#include<string.h>
using namespace std;

void food::get_data()
{
    cout<<"enter food name :"<<endl;
    fflush(stdin);
    gets(food_name);
    cout<<"enter food type (veg/non_veg) :"<<endl;
    fflush(stdin);
    gets(food_type);
    for (int i=0;food_type[i]!='\0';i++)
    {
        food_type[i]=tolower(food_type[i]);
    }
    while(strcmp(food_type,"veg")!=0 && strcmp(food_type,"non_veg")!=0)
    {
        cout<<"enter food type (veg/non_veg) :"<<endl;
        fflush(stdin);
        gets(food_type);
        for (int i=0;food_type[i]!='\0';i++)
        {
            food_type[i]=tolower(food_type[i]);
        }
    }
}

void food::display()
{
    cout<<"food name :"<<food_name<<endl;
    cout<<"food type :"<<food_type<<endl;
}
