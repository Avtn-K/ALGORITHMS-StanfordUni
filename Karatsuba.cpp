#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Multiplication of integers using Karatsuba method.

vector<double> Addition(vector<double>X,vector<double>Y)
{  
       
   	int p=int(X.size());
   	int q=int(Y.size());
	vector<double> XY(q);
	
	for(int i=0;i<q;i++)
     	    XY[i]=0;

      	    for(int i=1;i<=q;i++)
               {
	         if(XY[q-i]+X[q-i]+Y[q-i]<10)	   
	     	   {
	             XY[q-i]+=(X[q-i]+Y[q-i]);
	     	   }
                 else if(XY[q-i]+X[q-i]+Y[q-i]>=10)
		        {  	
	                  XY[q-i]=(fmod((XY[q-i]+X[q-i]+Y[q-i]),10));
			  XY[q-i-1]+=1;
			} 
	       }
	return XY;    
}

vector<double>EqualRevert(vector<double>X,int r,int q,int j)
{
   int p=int(X.size());
   
   vector<double>Y(r);
   for(int i=0;i<r;i++)
       Y[i]=0;       

   for(int i=0;i<p;i++)
      {
	Y[i+(q-1-j)]+=X[i]; 
      }

   vector<double>XY(r);

   for(int i=1;i<=r;i++)
       XY[r-i]=Y[i-1];	  

return XY;   
}

vector<double> Subtraction(vector<double>X,vector<double>Y)
{  
        int q=int(X.size());
	int p=int(Y.size());
        vector<double> XY;

	for(int i=1;i<=q;i++)
	   {
	     if(X[q-i]-Y[p-i]>=0)	   
	           XY.push_back(X[q-i]-Y[p-i]);
	     else if((X[q-i]-Y[p-i])<0 && i<q) 		     
	        {     
	          XY.push_back((X[q-i]+10-Y[p-i]));
	          X[q-i-1]--; 
	   //     X[q-i-1]+(((X[q-i]+Y[q-i])/10.0)-(fmod(X[q-i]+Y[q-i],10.0)/10.0));
	     	}
	     else if(p<q && i==q)
                {
		  XY.push_back(X[q-i]);	
	   //	  XY.push_back(X[q-i-1]+(((X[q-i]+Y[q-i])/10.0)-(fmod(X[q-i]+Y[q-i],10.0)/10.0)));
                }
	   }
      return XY;	
}

vector<double> Multiplication(vector<double>X,vector<double>Y)
{
   int p=int(X.size());
   int q=int(Y.size());

   int r=p+q;
   vector<double>XYR(r); 
   vector<double>M(r);

   for(int i=0;i<r;i++)
       M[i]=0;	   

   vector<double> XY(p+1);

   for(int j=0;j<q;j++)
    { 
       for(int i=0;i<(p+1);i++)
           XY[i]=0;

      for(int i=1;i<=p;i++)
         {
	   if((XY[i-1]+Y[j]*X[p-i])<10)
	     {
	      XY[i-1]=(XY[i-1]+Y[j]*X[p-i]);
	      XY[i]+=0;
	     }
           else if(10<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<20 && i<p)
	          {
	          XY[i-1]=(fmod((XY[i-1]+Y[j]*X[p-i]),10));	
		  XY[i]+=1;
		  }	
           else if(20<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<30 && i<p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),20));
		  XY[i]+=2;
                  }
           else if(30<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<40 && i<p) 
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),30));
		  XY[i]+=3;
                  }
           else if(40<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<50 && i<p)
                  { 
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),40));
		  XY[i]+=4;
                  }
           else if(50<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<60 && i<p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),50));
		  XY[i]+=5;
                  }
           else if(60<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<70 && i<p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),60));
		  XY[i]+=6;
                  }
           else if(70<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<80 && i<p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),70));
		  XY[i]+=7;
                  }
           else if(80<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<90 && i<p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),80));
		  XY[i]+=8;
                  } 
           else if(90<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<100 && i<p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),90));
		  XY[i]+=9;
                  } 
           else if(10<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<20 && i==p)
	          {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),10));	
		  XY[i]+=1;
		  }	
           else if(20<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<30 && i==p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),20));
		  XY[i]+=2;
                  }
           else if(30<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<40 && i==p) 
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),30));
		  XY[i]+=3;
                  }
           else if(40<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<50 && i==p)
                  { 
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),40));
		  XY[i]+=4;
                  }
           else if(50<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<60 && i==p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),50));
		  XY[i]+=5;
                  }
           else if(60<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<70 && i==p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),60));
		  XY[i]+=6;
                  }
           else if(70<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<80 && i==p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),70));
		  XY[i]+=7;
                  }
           else if(80<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<90 && i==p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),80));
		  XY[i]+=8;
                  } 
           else if(90<=(XY[i-1]+Y[j]*X[p-i]) && (XY[i-1]+Y[j]*X[p-i])<100 && i==p)
                  {
	          XY[i-1]=(fmod(( XY[i-1]+Y[j]*X[p-i]),90));
		  XY[i]+=9;
                  } 
	 }
	
	XYR=EqualRevert(XY,r,q,j);
        
	M=Addition(XYR,M);

    }
      return M;    
}

/*
vector<double> Karatsuba(vector<double>X,vector<double>Y)
{
	int q=int(X.size());
	int q1=(q/2);
	int q2=(q-(q/2));

	vector<double>a(q1);
	vector<double>c(q1);
	vector<double>b(q2);
	vector<double>d(q2);


	vector<double>S(1);
 	if(q<=1)
	  {
	    S[0]=X[0]*Y[0];	  
	    return S; 	
          }


	for(int i=0;i<(q1);i++)
           {
              a[i]=X[i];
	      c[i]=Y[i];
	   }
   	for(int i=0;i<(q2);i++)
	   {
	      b[i]=X[q1+i];
   	      d[i]=Y[q1+i];	      
	   }

  return (Subtraction(Subtraction(Karatsuba(Addition(a,b),Addition(c,d)),Addition(b,d)),Addition(a,c)));	
}
*/

////////////////////////////////////////////////////////////////////////////////

int main()
{
  int q;	
  cout<<"Numbers size (numbers are equal size): ";
  cin>>q;
  cout<<endl;

  cout<<"First number digits: ";
  vector<double>X(q);
  vector<double>Y(q);
  for(int i=0;i<q;i++)
     {
       cin>>X[i];
     }

  cout<<"Second number digits: ";
  for(int j=0;j<q;j++)
     {
       cin>>Y[j];
     }

  cout<<endl;
  cout<<"Numbers are: "<<endl;
  cout<<"X= ";
  for(int i=0;i<q;i++)
     {
       cout<<X[i];
     }
  cout<<endl;
  cout<<"Y= ";
  for(int j=0;j<q;j++)
     {
       cout<<Y[j];
     }
  cout<<endl;

//////////////////////////////////////////////////////////////// 
  
  vector<double>M;
  M=Multiplication(X,Y); 
  int qK=int(M.size());

  cout<<"Multiplication of those 2 integers is: ";
  for(int i=0;i<(qK);i++)
     {
       cout<<M[i]; 	     
     }
}
