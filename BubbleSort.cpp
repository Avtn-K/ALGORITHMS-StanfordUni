#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int x;
  int p;
  int k;
  int q;

  cout<<"Number of elements in the array: "<<endl;
  cin>>q;
  vector<int> XYZ(q);

  cout<<"Insert elements of the array: "<<endl;
  for(int i=0;i<q;i++)
     cin>>XYZ[i];

  for(int i=0;i<q;i++)
     cout<<XYZ[i]<<" ";	  
  cout<<endl; 

//////////////////////////////////////////////

  do
   {
    k=0;	   
    for(int i=0;i<(q-1);i++)
       {   
         if(XYZ[i]>XYZ[i+1])
           { 
             p=XYZ[i];
             XYZ[i]=XYZ[i+1];
	     XYZ[i+1]=p;
	     k++;
           }	     
       }
   }
  while(k!=0);

//////////////////////////////////////////////

  cout<<"Bubble-sorted array: ";
  for(int i=0;i<q;i++)
     cout<<XYZ[i]<<" ";  
  cout<<endl;
  
}
