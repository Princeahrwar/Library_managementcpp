#include<bits/stdc++.h>
#include <string>
#include <ctime>
#include<cstdio>
#include<stdlib.h>
#include<conio.h>
#include "user_class.h"
using namespace std;
// Here ID is the key of the 
map<string,student> List_of_students;
map<string,professor> List_of_professors;

class user_database
{
public:
    void Add_user(){
        cout<<"\n 1. User is a student...\n";
        cout<<"\n 2. User is a professor...\n";
        cout<<"\n ...Choose 1 or 2...\n";
        int n;
        student u1;
        professor u2;
        cin>>n;
        switch (n)
        {
        case 1:
            cout<<"\n Enter user ID...\n";
            cin>>u1.ID;
            if(List_of_students.count(u1.ID)==1){
                cout<<"\n... user Already exists...\n";
                return;
            }
            cout<<"\n Enter User_name...\n";
            cin>>u1.name;
            cout<<"\n Enter Password...\n";
            cin>>u1.password;
            List_of_students.insert( pair<string,student>(u1.ID,u1));
            cout<<"\n registration successful\n";
            sleep(2);
            break;
        case 2:
            cout<<"\n Enter user ID...\n";
            cin>>u2.ID;
            if(List_of_professors.count(u2.ID)==1){
                cout<<"\n... user Already exists...\n";
                return;
            }
            cout<<"\n Enter User_name...\n";
            cin>>u2.name;
            cout<<"\n Enter Password ...\n";
            cin>>u2.password;
            List_of_professors.insert( pair<string,professor>(u2.ID,u2));
            cout<<"\n registration successful\n";
            sleep(2);
            break;
        }
    }
    void update_user();
    void delete_user();
    void search_user();
    void show_all_students();
    void show_all_profs();
    friend class Admin;
};
void user_database:: show_all_students(){
    if(List_of_students.empty()==true){
        cout<<"\n No student registered yet\n";
        return;
    }
    map<string,student>::iterator itr;
    for(itr=List_of_students.begin();itr!=List_of_students.end();itr++){
        itr->second.user_details();
    }
}
void user_database:: show_all_profs(){
    if(List_of_professors.empty()==true){
        cout<<"\n No professor registered yet\n";
        return;
    }
    map<string,professor>::iterator itr;
    for(itr=List_of_professors.begin();itr!=List_of_professors.end();itr++){
        itr->second.user_details();
    }
}

void user_database:: update_user(){
    cout<<"\n 1. Update a student info...\n";
        cout<<"\n 2. Update a professor info...\n";
        cout<<"\n ...Choose 1 or 2...\n";
        int n;
        student u1;
        professor u2;
        string id1,id2;
        cin>>n;
        int i=0;
        switch (n)
        {
        case 1:
            cout<<"\n Enter user ID...\n";
            cin>>id1;
            if(List_of_students.count(id1)==0){
                cout<<"\n... user doesn't exist...\n";
                return;
            }
            List_of_students.erase(id1);
            cout<<"\n Enter New user ID...\n";
            cin>>u1.ID;
            cout<<"\n Enter User_name...\n";
            cin>>u1.name;
            cout<<"\n Enter Password of 8 digit length...\n";
            while(i<8){
                u1.password[i]=getch();
                if(u1.password[i]>'9' or u1.password[i]<'0'){
                    break;
                }
                cout<<"*";
                i++;
            }
            if(i!=8){
                cout<<"\n Please enter 8 digit right password...register again\n";
                return;
            }
            List_of_students.insert( pair<string,student>(u1.ID,u1));
            cout<<"\n Updated Successfully...\n";
            break;
        case 2:
            cout<<"\n Enter user ID...\n";
            cin>>id2;
            if(List_of_professors.count(id2)==0){
                cout<<"\n... user Already exists...\n";
                return;
            }
            List_of_students.erase(id2);
            cout<<"\n Enter New user ID...\n";
            cin>>u2.ID;
            cout<<"\n Enter New User_name...\n";
            cin>>u2.name;
            cout<<"\n Enter Password of 8 digit length...\n";
            while(i<8){
                u2.password[i]=getch();
                if(u2.password[i]>'9' or u2.password[i]<'0'){
                    break;
                }
                cout<<"*";
                i++;
            }
            if(i!=8){
                cout<<"\n Please enter 8 digit right password...register again\n";
                return;
            }
            List_of_professors.insert( pair<string,professor>(u2.ID,u2));
            cout<<"\n Updated Successfully...\n";
            break;
        
        default:
            break;
        }
}
void user_database:: delete_user(){
    cout<<"\n 1. delete a student ...\n";
        cout<<"\n 2. delete a professor...\n";
        cout<<"\n ...Choose 1 or 2...\n";
        int n;
        cin>>n;
        string id;
        switch (n)
        {
        case 1:
            cout<<"\n Enter student's ID...\n";
            cin>>id;
            if(List_of_students.count(id)==0){
                cout<<"\n... user doesn't exist...\n";
                return;
            }
            List_of_students.erase(id);
            break;
        case 2:
            cout<<"\n Enter professor's ID...\n";
            cin>>id;
            if(List_of_professors.count(id)==0){
                cout<<"\n... user doesn't exist...\n";
                return;
            }
            List_of_professors.erase(id);
            break;
        default:
            break;
        }
}
void user_database:: search_user(){
    
    cout<<"\n 1. search a student ...\n";
        cout<<"\n 2. search a professor...\n";
        cout<<"\n ...Choose 1 or 2...\n";
        int n;
        cin>>n;
        string id;
        switch (n)
        {
        case 1:
            if(List_of_students.empty()==true){
            cout<<"\nNo student registered yet\n";
            return;
            }
            cout<<"\n Enter student's ID...\n";
            cin>>id;
            if(List_of_students.count(id)==0){
                cout<<"\n... user doesn't exist...\n";
                return;
            }
            cout<<"\n User found\n";
            List_of_students[id].user_details();
            break;
        case 2:
            cout<<"\n Enter professor's ID...\n";
            cin>>id;
            if(List_of_professors.count(id)==0){
                cout<<"\n... user doesn't exist...\n";
                return;
            }
            cout<<"\n User found\n";
            List_of_professors[id].user_details();
            break;
        default:
            break;
        }
}
