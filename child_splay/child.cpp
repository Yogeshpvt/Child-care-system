#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include "child.h"
using namespace std;
int main()
{  
    SplayTree k;
    splay *root;
    root = NULL;
    char ch;
    const int length = 10;
    int i, option;
    kid h;
    cout<< endl <<"\t\t\t\t CHILD CARE CENTRE\n\n\n";
    cout<<endl;
    cout<<"Enter Y to Continue: ";
    cin>>ch;
    if(ch == 'Y' || ch == 'y')
    {
	do
    {  
        cout<<"\n";
        cout<<"1. INSERT CHILD'S DETAILS"<<endl; 
        cout<<"2. DELETE CHILD'S DETAILS"<<endl;
        cout<<"3. SEARCH FOR CHILD'S DETAILS"<<endl;
        cout<<"4. DISPLAY MOST RECENTLY SEARCHED CHILD'S DETAILS"<<endl;
        cout<<"5. DISPLAY ALL THE CHILDREN'S DETAILS STORED IN THE SYSTEM"<<endl;
        cout<<"6. EXIT PROGRAM"<<endl;
        cout<<"\nENTER YOUR OPTION : ";
        cin>>option;
        switch(option)
        {
        case 1:
            line();
            cout<<"\n";
            cout<<"\n\t\t\t\tCHILD DETAILS INPUT PAGE\n";
            cout<<"\nENTER CHILD'S NAME : ";
            cin>>h.kname;
            cout<<"\nENTER CHILD'S AGE : ";
            cin>>h.age;
            cout<<"\nENTER CHILDCARE ID : ";
            cin>>h.k_id;
            cout<<"\nENTER CHILD'S GENDER (M/F) : ";
            cin>>h.gender;
            cout<<"\nENTER PARENT'S EMAIL ID : ";
            cin>>h.email;
            cout<<"\nENTER PARENT'S PHONE NUMBER : ";
            cin>>h.phone;
            root = k.Insert(h.k_id,h,root);
            line();
			cout<<"\n";
			cout<<"\nAFTER INSERT : "<<h.k_id<<endl;
            k.InOrder(root);
            line();
            getchar();
            break;

        case 2:
            line();
            cout<<"\n";
            cout<<"\n\t\t\t\tCHILD DETAILS REMOVAL PAGE\n";
            cout<<"\nENTER CHILD'S ID TO BE REMOVED : ";
            cin>>h.k_id;
            root = k.Delete(h.k_id, root);
            cout<<"\nAFTER DELETE : "<<h.k_id<<endl;
            k.InOrder(root);
            cout<<"\n";
            line();
            getchar();
            break;
           
        case 3:
            line();
            cout<<"\n";
            cout<<"\n\t\t\t\tCHILD DETAILS SEARCH PAGE\n";
            cout<<"\nENTER CHILD'S ID TO BE SEARCHED : ";
            cin>>h.k_id;
            root = k.Search(h.k_id, root);
            if(root->key == h.k_id){
                cout<<"\nCHILD FOUND!";
                cout<<"\nAFTER SEARCH : "<<h.k_id<<endl;
                k.InOrder(root);
            }
            else{
                cout<<"ELEMENT NOT FOUND";
            }
            cout<<"\n";
            line();
            getchar();
            break;
 
        case 4:
            line();
            cout<<"\n";
            cout<<"\nRECENTLY SEARCHED CHILD : \n";
            cout<<"\nCHILDCARE ID : ";
            cout<<root->key;
            cout<<"\nNAME : ";
            cout<<root->val.kname;
            cout<<"\nPHONE : ";
            cout<<root->val.phone;
            cout<<"\nEMAIL : ";
            cout<<root->val.email;
            cout<<"\nGENDER : ";
            cout<<root->val.gender;
            cout<<"\n";
            cout<<"\n";
            line();
            getchar();
            break;
           
        case 5:
            line();
            cout<<"\n";
            cout<<setw(49)<<"CHILD'S DETAILS\n";
            cout<<"\n";
            cout<<setw(15)<<"CHILDCARE ID"<<setw(15)<<"NAME"<<setw(15)<<"PHONE"<<setw(30)<<"EMAIL"<<setw(15)<<"GENDER";
            cout<<"\n";
            k.PreOrder(root);
            cout<<"\n";
            line();
            getchar();
            break;
           
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nINVALID CHOICE! \n";
            break;
        }
    }
while(option!=6);
} 
else
{
    cout<<"\nTHANK YOU! VISIT LATER TO CHECK OUR CHILD CARE FACILITY :)";
} 
    cout<<"\n";
    return 0;
} 
