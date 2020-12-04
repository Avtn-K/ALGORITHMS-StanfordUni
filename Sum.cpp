#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


// Sum of first n numbers using recursion.


int Sum(int n)
{ 
      if(n == 1)
	 return 1; 
      else
         return Sum(n-1)+n;
}



int main()
{
   int n;

   cout<<"Insert the natural number n: ";
   cin>>n;

   cout<<endl<<"Sum of the first n numbers is: "<< Sum(n) <<endl;   

}	
