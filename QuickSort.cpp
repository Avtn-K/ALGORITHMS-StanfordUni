#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<int> Merge(vector<int>L,int p,vector<int>R)
{
 	L.push_back(p);
	for(int i=0;i<(int(R.size()));i++)
	    L.push_back(R[i]);	
    return L;
}

vector<int> Pivot(vector<int>XY)
{
	int q=int(XY.size());

if(q <= 1)
   return XY;
      
        vector<int>L;
	vector<int>R;
	int p=XY[0];

	for(int i=1;i<q;i++)
	   { 
	     if(XY[i]<p)
	       L.push_back(XY[i]);	     
	     else
               R.push_back(XY[i]);	     
	   }

   return Merge(Pivot(L),p,Pivot(R));	 
}

/////////////////////////////////////////////////////

int main()
{ 
  int q;	

  cout<<"Number of elements in the array: ";
  cin>>q;
  vector<int> XYZ(q);
  for(int i=0;i<q;i++)
     {
	cin>>XYZ[i];
     }	  
  
  cout<<"Array: ";
  for(int i=0;i<q;i++)
     {
	cout<<XYZ[i]<<" ";
     }	  
  cout<<endl;

////////////////////////////////////////////////////
  
  vector<int>XY=Pivot(XYZ);
  q=int(XY.size());
  cout<<"Quick-Sorted array: ";
  for(int i=0;i<q;i++)
	 cout<<XY[i]<<" ";  
}
