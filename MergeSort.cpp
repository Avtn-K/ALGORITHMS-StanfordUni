#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

long double inv=0;

void Merge(int XY[], int l, int m, int h)
{
  int x=m-l+1;
  int y=h-m;

  int X[x];
  int Y[y];

  for(int i=0;i<x;i++)
     {
       X[i]=XY[l+i];	     
     }	  

  for(int j=0;j<y;j++)
     {
       Y[j]=XY[m+1+j];	     
     }	  

  int i=0;
  int j=0;
  int k=l;
   
  while(i<x && j<y)
       {
       	if(X[i]<=Y[j])
	  { 
            XY[k]=X[i];
            i++;	    
	  }	
        else
          {
	    XY[k]=Y[j];
            j++;
            inv+=(x-i);
	  }
        k++;
       }
    
   while(i<x)
        {
	  XY[k]=X[i];
          i++;
          k++;	  
        }   
   while(j<y)
        {
	  XY[k]=Y[j];
          j++;
          k++;	  
	}   
}



void MergeSort(int XY[], int l, int h)
{
  if(l>=h)
    {	  
     return;	  
    }
      int m=l+(h-l)/2;
      MergeSort(XY,l,m);
      MergeSort(XY,m+1,h);
      Merge(XY,l,m,h);         	  
}




int main()
{	
   ifstream List("Mnum.txt");
   if(!List)
     {
       cout<< "File error!" <<endl;
       return 1;       
     }  
   string s;
   int v;
   vector<int>V;
   while(getline(List,s))
        { 
          v = std::stoi(s); 
	  V.push_back(v);	  
	}    
    	
   int q=int(V.size());
   int XY[q];
   for(int i=0;i<q;i++)
      {
        XY[i]=V[i];	      
      }        
   
   cout<<"Given list: ";
   for(int i=0;i<q;i++)
      cout<< XY[i] <<" ";	   

   MergeSort(XY,0,q-1);

   cout<<endl<<"Sorted list: ";
   for(int i=0;i<q;i++)
      cout<< XY[i] <<" ";	   
   
   cout<<endl;
   cout<<fixed;
   cout<<"Number of inversions: ";
   cout<<setprecision(3)<<inv;

return 0;
}
