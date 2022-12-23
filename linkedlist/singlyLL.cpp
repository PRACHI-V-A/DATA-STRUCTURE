#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
    public:
    int value;
    node *next;
    //INITIALISING NODE:
    node(int val ){
        value = val;
        next =NULL;
    }
};

    //Insertion at Head :
    void insertathead(node *&head, int val){
        node *n = new node(val);
    
        n->next= head;
        head = n ;
    }
    //Insertion at Tail :
    void insertattail(node *&head , int val){
        node *n = new node(val);
        if(head == NULL){
            head = n ;
            return;
        }
        node *temp = head ;
        while(temp->next  != NULL)
        {
            temp = temp->next ; 
        }
        temp->next = n;
   
    }

    //Insertion at any position :
    void insertatposition(node *&head , int val , int pos){
        node *n = new node(val);
        node *temp = head;
        for(int i = 1 ; i < pos ; i++){
            temp = temp->next;
        }
        n->next = temp->next ;
        temp->next = n ;
    }

    void display(node *&head){
        node *temp = head;
        while(temp != NULL){
            cout<<temp->value<<"->";
             temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }


int main(){
    int ipos;
    char ch;
    int c;
    int ival;
    node *head = NULL;

    do
    {
       cout<<"********Main Menu********"<<endl;
       cout<<"1.Insert at head:"<<endl;
       cout<<"2.Insert at tail:"<<endl;
       cout<<"3.insert at any position :"<<endl;
       cout<<"4.Display the linkedlist:"<<endl;
       cout<<"5.Enter the choice you want to perform:"<<endl;
       cin>>c;
       cout<<endl;

       switch (c)
       {
       case 1: cout<<"enter the data value you want to insert:"<< endl;
                cin>>ival;
                insertathead(head , ival);
        break;

       case 2: cout<<"enter the data value you want to insert:"<<endl;
                cin>>ival;
                insertattail(head , ival);
        break;

        case 3: cout<<"enter the data value you want to insert:"<< endl;
                cin>>ival;
                cout<<"enter at which position you want to insert the value:"<<endl;
                cin>>ipos;
                insertatposition(head, ival,ipos); 
        break; 
        case 4: display(head);
        break;
       default:cout<<"entered the wrong choice :"<<endl;
        break;
       }

      cout<<"Do you want to continue (y/n):"<<endl;
      cin>>ch;

    } while (ch=='y'||ch=='Y');
    

}