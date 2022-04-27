#include<bits/stdc++.h>
#include <string>
#include <ctime>
#include<cstdio>
#include<stdlib.h>
#include "book_database.h"
using namespace std;
class user
{
public:
    string name;
    string ID;
    string password;
    void user_details(){
        cout<<"\n Username : "<<name<<"\t ID : "<<ID<<endl;
    }
};
class student : public user
{
public:
    map<string,book> student_issued_books;
    void show_student_books(){
        cout<<"\nstudent's book record...\n";
        map<string,book>::iterator itr;
        if(student_issued_books.empty()==true){
            cout<<"\n No book issued..\n";
        }
        for(itr=student_issued_books.begin();itr!=student_issued_books.end();++itr){
            itr->second.book_details();
        }
    }
    void book_req(){
        if(List_of_books.empty()==true){
            cout<<"\n No books available\n";
            return;
        }
        if(student_issued_books.size()==5){
            cout<<"\n Maximum limit of books reached. Please deposit your books first\n";
            return;
        }
        cout<<"\n Enter the Book name:\n";
        string b_name;
        cin>>b_name;
        if (List_of_books.count(b_name)==0){
            cout<<"\n currently this book isn't available\n";
            return;
        }
        book b1;
        b1=List_of_books[b_name];
        b1.number=1;
        student_issued_books.insert(pair<string,book>(b_name,b1));
        List_of_books[b_name].number-=1;

    }
    void book_deposit(){
        if(student_issued_books.size()==0){
            cout<<"\n No book to deposit...\n";
            return;
        }
        show_student_books();
        cout<<"\n Choose book from above listed books...\n";
        string b_name;
        cin>>b_name;
        if(student_issued_books.count(b_name)==0){
            cout<<"\n Etner right isn't is your booklist..\n ";
            return;
        }
        int day;
        cout<<"\nBook deposited in no. of days";
        cin>>day;
        if(day>30)
        {
            int fine=(day-30)*2;
            cout<<"\n Fine has to deposited Rs.\n "<<fine;
        }
        student_issued_books.erase(b_name);
        cout<<"\n Book has been deposited successfully...\n";
    }
        
};

 class professor:public user
 {
 public:
    map<string,book> prof_issued_books;
    void show_prof_books(){
        cout<<"\nProf's book record...\n";
        map<string,book>::iterator itr;
        if(prof_issued_books.empty()==true){
            cout<<"\n No book issued..\n";
        }
        for(itr=prof_issued_books.begin();itr!=prof_issued_books.end();++itr){
            itr->second.book_details();
        }
    }
    void book_req(){
        cout<<"\n Enter the Book name:\n";
        string b_name;
        cin>>b_name;
        if (List_of_books.count(b_name)==0){
            cout<<"\n currently this book isn't available\n";
            return;
        }
        book b1;
        b1=List_of_books[b_name];
        b1.number=1;
        prof_issued_books.insert(pair<string,book>(b_name,b1));
        List_of_books[b_name].number-=1;

    }
    void book_deposit(){
        if(prof_issued_books.size()==0){
            cout<<"\n No book to deposit...\n";
            return;
        }
        show_prof_books();
        cout<<"\n Choose book from above listed books...\n";
        string b_name;
        cin>>b_name;
        if(prof_issued_books.count(b_name)==0){
            cout<<"\n Etner right isn't is your booklist..\n ";
            return;
        }
        int day;
        cout<<"\nBook deposited in no. of days";
        cin>>day;
        if(day>60)
        {
            int fine=(day-60)*2;
            cout<<"\n Fine has to deposited Rs.\n "<<fine;
        }
        prof_issued_books.erase(b_name);
        cout<<"\n Book has been deposited successfully...\n";
    }
        
    
 };

 

    
 