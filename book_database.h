#include<bits/stdc++.h>
#include <string>
#include <ctime>
#include<cstdio>
#include<stdlib.h>
#include "books.h"
using namespace std;
map<string,book> List_of_books;// here book->title is key of map and book is value
class book_database
{
private:
    
public:
    void delete_book(){
        if(List_of_books.empty()==true){
            cout<<"\n No books available\n";
            return;
        }
        cout<<"\n name of book to be deleted: \n";
        string b_name;
        cin>>b_name;
        if(List_of_books.count(b_name)==0){
            cout<<"\n This Book doesn't exist...\n";
            return;
        }
        List_of_books.erase(b_name);
    }
    void update_book(){
        if(List_of_books.empty()==true){
            cout<<"\n No books available\n";
            return;
        }
        cout<<"\n name of book to be updated: \n";
        string b_name;
        cin>>b_name;
        if(List_of_books.count(b_name)==0){
            cout<<"\n Book doesn't exist. Please add the book first...\n";
            return;
        }
        List_of_books.erase(b_name);
        book b2;
        cout<<"\n Enter The updated Book's title...\n";
        cin>>b2.title;
        cout<<"\nEnter The updated name of the author... ";
        cin>>b2.author;
        cout<<"\nEnter The updated 13 digit ISBN code.... ";
        cin>>b2.ISBN;
        cout<<"\n total updated books...";
        cin>>b2.number;
        List_of_books.insert(pair<string,book> (b2.title,b2));
        cout<<"\n\n book updated successfully..";

    }
    void add_new_book()// add it in librarian func
	{
        book b1;
        cout<<"\n Add a new Book...\n";
        cout<<"\n Enter The Book title...";
        cin>>b1.title;
        if(List_of_books.count(b1.title)==1){
            cout<<"\n Book already exists...";
            cout<<"\n You may update the existing book...\n";
            update_book();
            return;
        }
        cout<<"\nEnter The Name of the author... ";
        cin>>b1.author;
        cout<<"\nEnter The 13 digit ISBN code.... ";
        cin>>b1.ISBN;
        cout<<"\n Number of books...";
        cin>>b1.number;
        List_of_books.insert(pair<string,book> (b1.title,b1));
        cout<<"\n\n New book created..";
        
    }
    void show_books(){
        map<string,book>::iterator itr;
        if(List_of_books.empty()==true){
            cout<<"\n No books available\n";
            return;
        }
        for(itr=List_of_books.begin();itr!=List_of_books.end();++itr){
            itr->second.book_details();
        }

    }
    void search(){
        if(List_of_books.empty()==true){
            cout<<"\n No books available\n";
            return;
        }
        cout<<"\n Name of the book to be searched\n";
        string b_name;
        cin>>b_name;
        if(List_of_books.count(b_name)==1){
            if(List_of_books[b_name].number>0){
                cout<<"\n Info of the book"<<b_name<<"\n";
                List_of_books[b_name].book_details();
                return;
            }
            
        }
        cout<<"\n Book not Available\n";
    }
};
