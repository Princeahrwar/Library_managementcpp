#include<bits/stdc++.h>
#include <string>
#include <ctime>
#include<cstdio>
#include<stdlib.h>
#include "user_database.h"
using namespace std;
user_database USER_DATABASE;
book_database BOOK_DATABASE;
void login_as_student(){
    cout<<"\n Enter student ID\n";
    string id;
    cin>>id;
    if(List_of_students.count(id)==0){
        cout<<"\n No such student found..\n";
        return;
    }
    cout<<"\nEnter User password\n";
    string pass;
    cin>>pass;
    if(List_of_students[id].password!=pass){
        cout<<"\ninvalid Password\n";
        return;
    }
    
    cout<<"\n Welcome to your page...\n";
    int ch2;
    do{
    cout<<"\n \t1.Display all books issued by user\n";
    cout<<"\n \t2.Display all books in library\n";
    cout<<"\n \t3.Display Student info\n";
    cout<<"\n \t4.Search for the Book\n";
    cout<<"\n \t5.Return\n";
    cout<<"\n\t Enter the digit from (1-5)";
    cin>>ch2;
    switch (ch2)
    {
    case 1:
        List_of_students[id].show_student_books();
        break;
    case 2:
        BOOK_DATABASE.show_books();
        break;
    case 3:
        List_of_students[id].user_details();
        break;
    case 4:
        BOOK_DATABASE.search();
        break;
    case 5:
        return;
    }
    }while(0<ch2 and ch2<6);
    return;
}
void login_as_prof(){
    cout<<"\n Enter prof ID\n";
    string id;
    cin>>id;
    if(List_of_professors.count(id)==0){
        cout<<"\n No such student found..\n";
        return;
    }
    cout<<"\nEnter User password\n";
    string pass;
    cin>>pass;
    if(List_of_professors[id].password!=pass){
        cout<<"\ninvalid Password\n";
        return;
    }
    cout<<"\n Welcome to your page...\n";
    int ch2;
    do{
    cout<<"\n \t1.Display all books issued by user\n";
    cout<<"\n \t2.Display all books in library\n";
    cout<<"\n \t3.Display Professor info\n";
    cout<<"\n \t4.Search for the Book\n";
    cout<<"\n \t5.Return\n";

    cout<<"\n\t Enter the digit from (1-5)";
    cin>>ch2;
    switch (ch2)
    {
    case 1:
        List_of_professors[id].show_prof_books();
        break;
    case 2:
        BOOK_DATABASE.show_books();
        break;
    case 3:
        List_of_professors[id].user_details();
        break;
    case 4:
        BOOK_DATABASE.search();
        break;
    case 5:
        return;
    }
    }while(0<ch2 and ch2<6);
    return;
}
// Here we have a fixed Admin menu. From here books and all the users can be viewed and modified.

void admin_menu()
    {
    int ch;
    do{
    cout<<"\n\tADMINISTRATOR MENU";
    cout<<"\n\t1.REGISTER NEW STUDENT/PROFESSOR RECORD";
    cout<<"\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\t3.DISPLAY ALL PROFESSOR RECORD ";
    cout<<"\n\t4.MODIFY STUDENT/PROF RECORD";
    cout<<"\n\t5.DELETE STUDENT/PROF RECORD";
    cout<<"\n\t6.CREATE NEW BOOK ";
    cout<<"\n\t7.DISPLAY ALL BOOKS ";
    cout<<"\n\t8.MODIFY BOOK ";
    cout<<"\n\t9.DELETE BOOK ";
    cout<<"\n\t10.SEARCH BOOK";
    cout<<"\n\t11.LOGIN AS A STUDENT ";
    cout<<"\n\t12.LOGIN AS A Prof ";
    cout<<"\n\t13.BACK TO MAIN MENU";
    cout<<"\n\tPlease Enter Your Choice (1-13) ";
    cin>>ch;

    switch (ch)
    {
    case 1:
        USER_DATABASE.Add_user();
        break;
    case 2:
        USER_DATABASE.show_all_students();
        break;
    case 3:
        USER_DATABASE.show_all_profs();
        break;
    case 4:
        USER_DATABASE.update_user();
        break;
    case 5:
        USER_DATABASE.delete_user();
        break;
    case 6:
        BOOK_DATABASE.add_new_book();
        break;
    case 7:
        BOOK_DATABASE.show_books();
        break;
    case 8:
        BOOK_DATABASE.update_book();
        break;
    case 9:
        BOOK_DATABASE.delete_book();
        break;
    case 10:
        BOOK_DATABASE.search();
        break;
    case 11:
    sleep(2);
        login_as_student();
    
        break;
    case 12:
    sleep(2);
        login_as_prof();
        break;
    case 13:
        return;
    }
    }while(ch>0 and ch<14);
}
int main()
{
    int n;
    cout<<"\n\n....WELCOME TO THE LIBRARY MANAGEMENT PORTAL...\n\n";
    cout<<"\n\t01. ADMINISTRATOR MENU";
    cout<<"\n\t02. EXIT";
    cout<<"\n\tPlease Select Your Option (1-2) ";
    cin>>n;
    switch(n)
    {
    case 1:clrscr();
        sleep(2);
        admin_menu();
        break;
    case 2:
        cout<<"\n ...EXITING...\n";
        sleep(2);
        clrscr();
        break;
    default:
        break;
    }
    return 0;
} 


