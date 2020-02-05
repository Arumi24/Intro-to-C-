//
//  main.cpp
//  Comp322_A3
//
//  Created by Aymen on 4/3/19.
//  Copyright © 2019 Aymen. All rights reserved.
//

#include <iostream>
using namespace std;

//smart pointer implementation with only integer
class SmartPointer
{
    int *ptr=(int *)malloc(sizeof(int));
   
public:
    SmartPointer();
    SmartPointer(int number);
    ~SmartPointer();
    void setValue(int number);
    int getValue();
    friend SmartPointer operator+(const SmartPointer &c1, const SmartPointer &c2);
    friend SmartPointer operator-(const SmartPointer &c1, const SmartPointer &c2);
    friend SmartPointer operator*(const SmartPointer &c1, const SmartPointer &c2);

    
   
};


SmartPointer::SmartPointer()
{
    
     ptr = new int(0);
}

SmartPointer::SmartPointer(int number)
{
    if(number<0)
    {
        string msg="Negative Number Not Allowed";
        throw msg;
    }
    ptr=new int(number);
}


SmartPointer::~SmartPointer()
{
   
    delete(ptr);
}

void SmartPointer::setValue(int number)
{
    if(number<0)
    {
        string msg="Negative Number Not Allowed";
        throw msg;
    }
    ptr=new int(number);
}

int  SmartPointer::getValue()
{
    return *ptr;
}


SmartPointer operator+(const SmartPointer &c1, const SmartPointer &c2)
{
 
    return SmartPointer(*c1.ptr + *c2.ptr);
}

SmartPointer operator-(const SmartPointer &c1, const SmartPointer &c2)
{
    
    return SmartPointer(*c1.ptr - *c2.ptr);
}

SmartPointer operator*(const SmartPointer &c1, const SmartPointer &c2)
{
    
    return SmartPointer(*c1.ptr * *c2.ptr);
}


//smart pointer representation with template class

template <class T>
class SmartPtr
{
    T *ptr;
public:
    SmartPtr()
    {
        ptr = new T(0);
    }
    
    SmartPtr(T data)
    {
        if(data<0)
        {
            string msg="Negative Number Not Allowed";
            throw msg;
        }

        ptr=new T(data);
        
    }
    
    //question 6 implementation
    
    SmartPtr(T* array, int size)
    {
   
        for(int i=0;i<size;i++)
        {
            if(*(array+i)<0)
            {
                
                string msg="Negative Number Not Allowed In Array";
                throw msg;
            }
        }
        
        ptr= new T[size];
    }
    
    
   
    
    ~SmartPtr()
    {
        delete(ptr);
    }
    
    void setValue(T data)
    {
        if(data<0)
        {
            string msg="Negative Number Not Allowed";
            throw msg;
        }

        ptr= new T(data);
    }
    
    T getValue()
    {
       
        return *ptr;
    }
    friend SmartPtr operator+(const SmartPtr &c1, const SmartPtr &c2)
    {
        return SmartPtr(*c1.ptr + *c2.ptr);
    }
    
    friend SmartPtr operator-(const SmartPtr &c1, const SmartPtr &c2)
    {
        return SmartPtr(*c1.ptr - *c2.ptr);
    }
    
    friend SmartPtr operator*(const SmartPtr &c1, const SmartPtr &c2)
    {
        return SmartPtr(*c1.ptr * *c2.ptr);
    }
};







int main() {
    
    //Question 2
    cout<<"Testing Question 2 & 3 & 5"<<endl<<endl;
    //testing constructor, setter, getter, operation overloading for *,-,+ and try catch
    
    try
    {
        SmartPointer sPointer;
        cout<<sPointer.getValue()<<endl;  //constructing with no input so it's 0
        
        SmartPointer sPointer1(11);
        cout<<sPointer1.getValue()<<endl;  //constructing with input 11
        
        sPointer1.setValue(30);           //setting value to 30
        cout<<sPointer1.getValue()<<endl;
        
        SmartPointer sPointer2(15);
        
        SmartPointer sPointer3=sPointer1*sPointer2; //operation overload for *
        cout<<sPointer3.getValue()<<endl;
        
        SmartPointer sPointer4=sPointer1-sPointer2; //operation overload for -
        cout<<sPointer4.getValue()<<endl;
        
        SmartPointer sPointer5=sPointer1+sPointer2; //operation overload for +
        cout<<sPointer5.getValue()<<endl;
        
        SmartPointer sPointer6(-5);  //catch exception for negative number
        
        
        
        
    }
    catch(string& message)
    {
        cout<<message<<endl;
    }
    catch(bad_alloc& ptr)
    {
        cout<<"Variable Could Not Be Allocated; System Is Out Of Memory"<<endl;
    }
    
    
    cout<<"Testing Question 4 & 3 & 5 & 6"<<endl<<endl;
    
    try
    {
        SmartPtr<double> genericPointer1(10.31);
        cout << genericPointer1.getValue()<<endl;
    
        genericPointer1.setValue(18.71);
        cout << genericPointer1.getValue()<<endl;
        
        SmartPtr<double> genericPointer2(16.31);
        
        SmartPtr<double> genericPointer3=genericPointer1*genericPointer2; //operation overload for *
        cout << genericPointer3.getValue()<<endl;
        
        SmartPtr<double> genericPointer4=genericPointer1-genericPointer2; //operation overload for -
        cout << genericPointer4.getValue()<<endl;
        
        SmartPtr<double> genericPointer5=genericPointer1+genericPointer2; //operation overload for +
        cout << genericPointer5.getValue()<<endl;
        
        
        double array[5]= {1.1,2.2,3.3,4.4,5.5};    //array declaration
        
        SmartPtr<double> arrayPointer(array,5);
        
        double array2[5]= {1.1,2.2,-3.3,4.4,5.5};   //array declaration with negative numer, will throw exception
        
        SmartPtr<double> arrayPointer2(array2,5);
        
        
        
        

        
        
    }
    catch(string& message)
    {
        cout<<message<<endl;
    }
    catch(bad_alloc& ptr)
    {
        cout<<"Variable Could Not Be Allocated; System Is Out Of Memory"<<endl;
    }
   
    
    
    
    
}
