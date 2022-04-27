#include<bits/stdc++.h>
#include <string>
#include <ctime>
#include<cstdio>
#include<stdlib.h>
using namespace std;
class book
{
public:
    string title;
    string author;
    string ISBN;
    int number;
    void book_details()
    {
        cout<<"\n Book name : "<<title;
        cout<<"\n Author's name : "<<author;
        cout<<"\n ISBN code: "<<ISBN;
        cout<<"\n Number of books: "<< number<<"\n";
    }
};
