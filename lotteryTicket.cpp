//
//  main.cpp
//  Assignment#2
//
//  Created by Aymen on 3/9/19.
//  Copyright © 2019 Aymen. All rights reserved.
//

//
//  main.cpp
//  Assignment#2
//
//  Created by Aymen on 3/9/19.
//  Copyright © 2019 Aymen. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>

using namespace std;

struct   ticket {
    unsigned  int  numbers[6];
    ticket* next;
    int number;  //extra variable to keep track of which number ticket
};

class SuperDraw
{
    
public:
    
    SuperDraw();
    ~SuperDraw();                 //deconstructor
    SuperDraw(int number);
    SuperDraw(SuperDraw &dummy);  //copy constructor
    ticket newTicket(int verbose);
    void printAllTicketNumbers();
    void verifySequence(int array[]);
    void deleteSequence(int array[]);
    void insertTicket(int array[]); // method created to insert specific numbered sequence ticket
    
private:
    ticket* ticketListHead;
    ticket* ticketListTail;
    int tickets=0;          //total number of tickets
    int lotteryNumbers[49]; //list of lottery numbers to prevent dublicate numbers from generating
};


//method created to match 2 arrays, returns true if all 6 variables are matches, false otherwise
bool match(int arr1[],unsigned int arr2[])
{
    int count=0;
    for(int i=0;i<6;i++)
    {
        if(arr1[i]==arr2[i])
        {
            count++;
        }
    }
    
    if(count==6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//method to print array values, given the array
void print(unsigned int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//method to delete ticket from ticket list, given it's numbered index
void deleteTicket(ticket *traverse,int index)
{
    int x=0;
    
    while(x!=1)
    {
        if (traverse->next == NULL)
        {      
            break;
        }
        if(traverse->number==index-1)
        {        
            traverse->next=traverse->next->next;
            
            for(int i=0;i<6;i++)
            {
                if(traverse->next!=NULL)
                {
                    traverse->next->numbers[x]=NULL;
                }               
            }
        }
        
        if (traverse->next == NULL)
        {           
            break;
        }
        
        traverse=traverse->next;
    } 
}

//constructor
SuperDraw::SuperDraw()
{
    this->ticketListHead=NULL;
    this->ticketListTail=NULL;
}

//destructor sets tail and head to null and tickets back to 0
SuperDraw::~SuperDraw()
{
    ticket* tmp;;
    while (this->ticketListHead != NULL)
    {
        tmp = this->ticketListHead;
        this->ticketListHead = this->ticketListHead->next;
        this->tickets--;
    }

    this->ticketListTail=NULL;  
}


//constructor that generated n number of tickets
SuperDraw::SuperDraw(int number)
{
    cout<<number<<" new ticket were successfully generated"<<endl;
    cout<<"The numbers are: ";
    
    for(int i=0;i<number;i++)
    {
        print(newTicket(0).numbers,6);
        if(i!=number-1)
        {
            cout<<" and ";
        }     
    }
    
    cout<<endl;
}

//copy constructor
SuperDraw::SuperDraw(SuperDraw &dummy)
{  
    this->ticketListHead=dummy.ticketListHead;
    this->ticketListTail=dummy.ticketListTail;
    this->tickets=dummy.tickets;  
}


//object method that generates new ticket
ticket SuperDraw::newTicket(int verbose)
{
    struct ticket* lottery = (struct ticket*)malloc(sizeof(struct ticket));
    this->tickets++;
    lottery->number=this->tickets;
    if(this->ticketListHead==NULL)
    {    
        this->ticketListHead=lottery;
        this->ticketListTail=lottery;
        lottery->next=NULL;  
    }
    else
    {


        this->ticketListTail->next=lottery;
        this->ticketListTail=lottery;
        lottery->next=NULL;
        
       
        
    }
  
    int n = sizeof(lottery->numbers)/sizeof(lottery->numbers[0]);
    
    srand(time(0));
    
    for(int i=0;i<n;i++)
    {
        int x=1;
        while(x!=0)
        {
            
            int generatedNum=rand() % 48+1;
            if(this->lotteryNumbers[generatedNum]==NULL)
            {
                lottery->numbers[i]=generatedNum;
                this->lotteryNumbers[generatedNum]=generatedNum;
                break;
            }

            else
            {
                continue;
            }
        }   
    }
    
    int temp;
    for(int x=0; x<n; x++)
    {
        for(int y=x+1; y<n; y++)
        {

            if(lottery->numbers[y] < lottery->numbers[x])
            {
                temp = lottery->numbers[x];
                lottery->numbers[x] = lottery->numbers[y];
                lottery->numbers[y] = temp;
            }
        }
    }
    
    if(verbose==0)
    {
        return *lottery;
        
    }
    else if(verbose==1)
    {
        cout<<"A new ticket was successfully generated. The numbers are: ";
        for(int j=0;j<n;j++)
        {
            
            cout<<lottery->numbers[j]<<" ";
            
        }
        cout<<endl;
        
    }
    
    return *lottery;     
}


//method to print all tickets
void SuperDraw::printAllTicketNumbers()
{
    cout<<"We found "<<this->tickets<<" generated tickets:"<<endl;
    
    ticket temp=*this->ticketListHead;
    for(int i=0;i<this->tickets;i++)
        
    {
        
        print(temp.numbers,6);
        
        if(i!=(this->tickets-1))
            
        {
            cout<<endl;
            
            temp=*temp.next;
            
        }
    }
    cout<<endl;
}

//method to verify if sequence exists in ticket list
void SuperDraw::verifySequence(int array[])
{
    bool check = false;
    
    ticket temp=*this->ticketListHead;
    for(int i=0;i<this->tickets;i++)
        
    {  
        if(match(array,temp.numbers)==true)
        {
            check=true;
        }
        
        if(i!=(this->tickets-1))
            
        {
            temp=*temp.next;
            
        }
    }
    
    if(check==true)
    {
        cout<<"The provided sequence of numbers was already generated. "<<endl;
    }
    else
    {
        cout<<"The provided sequence of numbers was never generated before. "<<endl;
    }  
}




//object method that deletes a given sequence in a ticket if that ticket exists
void SuperDraw::deleteSequence(int array[])
{
    bool check = false;
    bool check2=false;
    int index=0;
    
    ticket temp=*this->ticketListHead;
    for(int i=0;i<this->tickets;i++)
        
    {    
        if(match(array,temp.numbers)==true)
        {
            check=true;
            index=temp.number;         
        }
              
        if(i!=(this->tickets-1))
            
        {
            temp=*temp.next;
            
        }
    }
    
    if(index!=0)
    {

        deleteTicket(this->ticketListHead, index);
        this->tickets--;
        check2=true;
    }
    
    if(check2==true)
    {
        cout<<"The provided sequence of numbers was successfully deleted."<<endl;
    }
    else
    {
        cout<<"The provided sequence of numbers was never generated before. "<<endl;
    } 
}

//method made by me to test verify and delete methods, this methods puts a ticket with specific values
void SuperDraw::insertTicket(int array[])
{
    struct ticket* lottery = (struct ticket*)malloc(sizeof(struct ticket));
    this->tickets++;
    lottery->number=this->tickets;
    if(this->ticketListHead==NULL)
    { 
        this->ticketListHead=lottery;
        this->ticketListTail=lottery;
        lottery->next=NULL;  
    }
    else
    {
        this->ticketListTail->next=lottery;
        this->ticketListTail=lottery;
        lottery->next=NULL;
    }
    
    for(int i=0;i<6;i++)
    {
        lottery->numbers[i]=array[i];
    }
}

int   main () {
    
    //question 2
    cout<<"Question 2:"<<endl;
    
    SuperDraw sd;
    sd.newTicket(1);
    
    cout<<endl<<endl;
    
    // question 3
     cout<<"Question 3:"<<endl;

    SuperDraw sd2(2);
    
    cout<<endl<<endl;
    
    //question 4
     cout<<"Question 4:"<<endl;
    
    SuperDraw sd3;
    sd3.newTicket(0);
    sd3.newTicket(0);
    sd3.newTicket(0);
    sd3.newTicket(0);
    sd3.printAllTicketNumbers();
    
    cout<<endl<<endl;
    
    //question 5
     cout<<"Question 5:"<<endl;
    
    SuperDraw sd4;
    sd4.newTicket(0);
    // as many sd.newTicket() as you like
    int myNumbers[6] = {2, 4, 17, 29, 31, 34};
    sd4.verifySequence(myNumbers);
    
    //made a special method to insert a specific numbered ticket, to test verify sequence
    sd4.insertTicket(myNumbers);
    sd4.verifySequence(myNumbers);
    
    cout<<endl<<endl;
    
    //question 6
     cout<<"Question 6:"<<endl;
    
    SuperDraw sd5;
    sd5.newTicket(0);
    // as many sd.newTicket() as you like
    int myNumbers2[6] = {6, 8, 18, 10, 37, 47};
    sd5.deleteSequence(myNumbers2);
    
    //testing with insert to see if it works
    sd5.insertTicket(myNumbers2);
    sd5.verifySequence(myNumbers2);
    sd5.deleteSequence(myNumbers2);
    sd5.verifySequence(myNumbers2);
      
    cout<<endl<<endl;
    
    //question 8
     cout<<"Question 8:"<<endl;
    
    SuperDraw sd6;
    sd6.newTicket(0);
    sd6.newTicket(0);
    sd6.newTicket(0);
    sd6.newTicket(0);
    SuperDraw sd7(sd6);
    sd7.printAllTicketNumbers();
}
