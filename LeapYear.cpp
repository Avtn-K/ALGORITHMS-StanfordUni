#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Decide if the given year is Leap Year.

/*
   Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100, 
   but these centurial years are leap years if they are exactly divisible by 400. For example, the years 1700, 1800, and 1900 are not leap years, but the years 1600 and 2000 are.
*/



int main()
{
   int y;
   
   cout<<"Insert a year you want to check for leapiness: ";
   cin>>y;
	
   if(y%4==0 && y%100!=0)	   
	cout<< y <<" is a Leap Year."<<endl;

   else if(y%4==0 && y%400==0)
	cout<< y <<" is a Leap Year."<<endl;
    
   else	   
   	cout<< y <<" is NOT a Leap Year."<<endl;
	          
}
