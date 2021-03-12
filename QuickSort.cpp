 #include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

double n=0;

int MedianPivot(int XY[], int l, int r)
{
  int k=(r+l)/2;
  int x=XY[l];
  int y=XY[k];
  int z=XY[r];

  if(x<=y && y<=z)
    {	  
       return k;
    }
  else if(x<=z && z<=y)
    { 
       return r;   
    }     
  else if(y<=x && x<=z)
    {
       return l;
    }
  else if(y<=z && z<=x)
    {
       return r;
    }     
  else if(z<=x && x<=y)
    {
       return l;
    }
  else if(z<=y && y<=x);
    { 
       return k;
    }
}

void swap(int XY[], int i, int j)
{
  int sw=0;
  
  sw=XY[i];
  XY[i]=XY[j];
  XY[j]=sw;  
}

int FirstPartition(int XY[], int l, int r)    //162085
{
  int p=XY[l];
  int i=l+1;
  for(int j=l+1;j<=r;j++)
     {
       if(XY[j]<p)
         {    
           swap(XY,i,j);
	   i++;
         }
       n++;
     }
   
  swap(XY,l,i-1);
  return (i-1);
}

int LastPartition(int XY[], int l, int r)  //164123 
{
  swap(XY,l,r);  

  int p=XY[l];
  int i=l+1;
  for(int j=l+1;j<=r;j++)
     {
       if(XY[j]<p)
         {    
           swap(XY,i,j);
	   i++;
         }
       n++;
     }
   
  swap(XY,l,i-1);
  return (i-1);
}

int MedianPartition(int XY[], int l, int r)  
{
  int m=MedianPivot(XY,l,r);
  swap(XY,l,m);  

  int p=XY[l];
  int i=l+1;
  for(int j=l+1;j<=r;j++)
     {
       if(XY[j]<p)
         {    
           swap(XY,i,j);
	   i++;
         }
       n++; 
     }
   
  swap(XY,l,i-1);
  return (i-1);
}

void QuickSort(int XY[], int l, int r)
{
  if(l<r)
    {
      int p=MedianPartition(XY,l,r);  
      
      QuickSort(XY,l,p-1);
      QuickSort(XY,p+1,r);    
    }    
}



int main()
{ 
   ifstream List("Qnum.txt");
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
 
 QuickSort(XY,0,q-1);

   cout<<endl<<"Sorted list: ";
   for(int i=0;i<q;i++)
       cout<< XY[i] <<" ";   

cout<<endl<<"Number of comparisons: "<< n <<endl;
return 0;	
}
