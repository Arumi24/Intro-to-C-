//
//  main.cpp
//  Comp322_A1
//
//  Created by Aymen on 2/10/19.
//  Copyright © 2019 Aymen. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>


using namespace std;

void countLetter()
{
    string sentence;
    char lowerCase;
    char upperCase;
    int count=0;
    
    cout <<"Please enter a sentence: ";
    getline(cin,sentence);
    cout <<""<<endl;
    cout <<"Please enter a letter: ";
    cin>>lowerCase;
    upperCase=char(toupper(lowerCase));

    

    for(int i=0;i<sizeof(sentence);i++)
    {
        if(sentence[i]==lowerCase || sentence[i]==upperCase)
        {
            count++;
        }
    }
    
    cout<<"The letter "<<lowerCase<<" is repeated "<<count<<" times in your sentence"<<endl;

}

void convertPhonetic()
{
    int numOfLetters=26;
    string word;
    string phoneticAlphabet[26]={ "Alfa","Bravo" ,"Charlie" ,"Delta" ,"Echo" ,"Foxtrot" ,"Golf" ,"Hotel" ,"India" ,"Juliett" ,"Kilo" , "Lima" ,"Mike" ,"November" ,"Oscar" ,"Papa" ,"Quebec" ,"Romeo" ,"Sierra" ,"Tango" ,"Uniform" ,"Victor" , "Whiskey" , "Xray" , "Yankee" ,"Zulu" };
    
    
    cout<<"Please enter a word: ";
    cin>>word;
    cout <<""<<endl;
    
    
    
    
    
    
    for(int i=0;i<sizeof(word);i++)
    {
        for(int j=0;j<numOfLetters;j++)
        {
            if(isalpha(word[i]))
            {
                if(word[i]==phoneticAlphabet[j][0] || char(toupper(word[i]))==phoneticAlphabet[j][0])
                {
                    cout<<phoneticAlphabet[j]<<" ";
                }
            }
           
            
        }
    }
    cout<<endl;
    
}

int factorialHelper(int number)
{
    if(number==1)
    {
        return 1;
    }
    else
    {
        return number*factorialHelper(number-1);
    }
}



void factorial()
{
    int number;
    cout<<"Please enter a number: ";
    cin>>number;
    if(number>0)
    {
        cout<<"The factorial of "<<number<<" is "<<factorialHelper(number)<<endl;
    }
    
    

}

int enhancedFactorialHelper(int number,int array[])
{
    if(number==1)
    {
        return array[sizeof(array)-1];
    }
    else
    {
        return number*factorialHelper(number-1);
    }
}

void enhancedFactorial()
{
    int number;
    int array[6]={1,2,6,24,120,720};
    cout<<"Please enter a number: ";
    cin>>number;
    if(number>0)
    {
        if(number>7)
        {
            cout<<"The factorial of "<<number<<" is "<<array[number-1]<<endl;
        }
        else
        {
            cout<<"The factorial of "<<number<<" is "<<enhancedFactorialHelper(number,array)<<endl;
            
        }
    }
   

}


int main() {
    countLetter();
    convertPhonetic();
    factorial();
    enhancedFactorial();
    return 0;
}
