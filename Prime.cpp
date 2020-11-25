#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// List of Prime Numbers.


vector<int>Sort(vector<int>XY)
{
  int q=int(XY.size());
  int w;
  int p;

  do{
      p=0;	  
      for(int i=0;i<(q-1);i++)
         {
	    if(XY[i]>XY[i+1])
	      {
	         w=XY[i+1];
                 XY[i+1]=XY[i];
                 XY[i]=w;
                 p++;		 
	      }	
	 } 
    }
  while(p>0);

 return XY;  
}

////////////////////////////////////////////////////////

vector<int>Remove(vector<int>XY)
{  
  int q=int(XY.size());
  vector<int>XYZ;
  int w;
  int p;

      for(int i=0;i<(q-1);i++)
         {
	    if(XY[i]!=XY[i+1])
	      {
                 XYZ.push_back(XY[i]);
	      }	
	 } 
      
      XYZ.push_back(XY[q-1]);

 return XYZ;  
}



int main()
{
    int x;
    vector<int>P;    
    vector<int>biP;
    vector<int>SbiP;
    int q;
    int p=0;
    double r;
    int b;
    

    cout<<"Insert a top boundary for computing: ";
    cin>>x;
   
    for(int i=2;i<=x;i++)
       {
	  p=0; 
          r=i;	  
	  q=round(sqrt(i));       
	  for(int j=1;j<=q;j++)
	     {
		if(i%j==0)
		   p++;	
	     }
	  
	  if(p<=1)
	    {	  
              P.push_back(i);
	    }
       }

    int s=int(P.size());
    cout<<"Prime Numbers are: "<<endl;
    for(int i=0;i<s;i++)
	 cout<< P[i] <<", ";

///////////////////////////////////////////////////////////////////////
  
    for(int i=0;i<s;i++)
       {
	 for(int j=0;j<s;j++)
	    {
	      b=P[i]*P[j];
              biP.push_back(b); 	      
	    }	 
       }	
     
    SbiP=Sort(biP);
    SbiP=Remove(SbiP);
    int a=int(SbiP.size());
    cout<<endl;
    cout<<"Bi-Prime Numbers are: "<<endl;
    for(int i=0;i<a;i++)
	 cout<< SbiP[i] <<", ";

}
