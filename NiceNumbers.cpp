#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



//Find the sum of all the Nice Digits in the number.
//Number is Nice if at least one digit is equal its position.


//////////////////////////////////////////////


int main()
{
   int x;
   vector<int>YX;
   cout<<"Insert the number: ";
   cin>>x;
   
   do{
         YX.push_back(x%10);
         x=x/10;	 
     }
   while(x>=1);

   int q=int(YX.size());
   vector<int>XY(q);
   for(int i=0;i<q;i++)
      {
         XY[i]=YX[q-1-i];
      }	   
    
   cout<<endl<<"Your number is: ";
   for(int i=0;i<q;i++)
       cout<< XY[i]<< " ";
 
////////////////////////////////////////////////
   
   x=0; 
   for(int i=0;i<q;i++)
      {
         if(XY[i]==i+1)
	   x+=(i+1); 
      }

   if(x!=0)
     cout<<endl<<"Sum of all Nice Digits in the number is: "<< x  <<endl;
   
   else
     cout<<"Number is not Nice!"<<endl;   
}
