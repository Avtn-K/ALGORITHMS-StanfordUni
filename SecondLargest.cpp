#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

double s=0;

/*
You are given as input an unsorted array of n distinct numbers, where n is a power of 2. 
Give an algorithm that identifies the second-largest number in the array, and that uses at most n+log⁡2n− comparisons.
*/

bool PowerOfTwo(int n)
{
  int i=1;	
  int p=(n/2)+1;
  
  while(i<=p)
       { 
	 if(n%i!=0)
           return false;
	 i=i*2;
       }	  
 return true;
}

int Comparison(vector<int>XY, int n)
{
   int x=0;
   int y=0;

   for(int i=0;i<n;i++)
    {
       if(XY[i]>x) 
         {
	  y=x;	 
     	  x=XY[i];
	  s++;
	 } 
       else if(XY[i]>y);
         {
	   y=XY[i];
	   s++; 
         }
    }   
 return y;
}



int main()
{ 
  int n;

  cout<<"Input number n, where n is a power of 2. "<<endl;
  
  cin>>n;
  if(PowerOfTwo(n)==false)
    {	    
      do{
	  cout<<"Number is not power of 2."<<endl;    
	  cin>>n;
        }	      
      while(PowerOfTwo(n)==false);
    }	  
  
  cout<<endl<<"Input a list of natural numbers of size n. "<<endl;   
  
  vector<int>XY(n);
  for(int i=0;i<n;i++)
     { 
       cout<< i+1 <<".  ";	     
       cin>>XY[i];	     
     }	  
  
  cout<<endl<<"Second largest number: "<< Comparison(XY,n) <<endl;
  cout<<endl;

  if(s<=(n*log2(n)))
  cout<<"s = "<< s <<", "<<"n*log2(n) = "<< n*log2(n) <<" || "<<"Number of allowed comparisons is OK!"<<endl;
  else
  cout<<"s = "<< s <<", "<<"n*log2(n) = "<< n*log2(n) <<" || "<<"Number of allowed comparisons exceeded!"<<endl;   
return 0;
}
