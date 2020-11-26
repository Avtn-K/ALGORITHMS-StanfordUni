#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Number transformation from one Number System to another.
// Systems included: Decimal, Binary, Octal, Hexadecimal.



vector<int>DecBin(int x)
{
   vector<int>Bin;

   do{
       Bin.push_back(x%2); 
       x=x/2;    
     }	   
   while(x>0);
   
   int q=int(Bin.size()); 	   
   vector<int>BinR(q);
   for(int i=0;i<q;i++)
       BinR[i]=Bin[q-i-1];	   
 
 return BinR;
}

/////////////////////////////////////////////////

vector<int>DecOct(int x)
{
   vector<int>Oct;

   do{
       Oct.push_back(x%8);  
       x=x/8;     
     }	   
   while(x>0);
   
   int q=int(Oct.size()); 	   
   vector<int>OctR(q);
   for(int i=0;i<q;i++)
       OctR[i]=Oct[q-i-1];
   
 return OctR;
}

/////////////////////////////////////////////////

vector<int>DecHex(int x)
{
   vector<int>Hex;

   do{
       Hex.push_back(x%16); 
       x=x/16;      
     }	   
   while(x>0);
   
   int q=int(Hex.size()); 	   
   vector<int>HexR(q);
   for(int i=0;i<q;i++)
       HexR[i]=Hex[q-i-1];
   
 return HexR;
}

/////////////////////////////////////////////////////// 

int BinDec(vector<int>XY)
{
   int x=0;
   int q=int(XY.size());
   
   for(int i=0;i<q;i++)
      {
        x += XY[i]*(pow(2,q-i-1)); 	      
      }	   
 return x;  
}

/////////////////////////////////////////////////////////

int OctDec(vector<int>XY)
{
  int x=0;

  int q=int(XY.size());

  for(int i=0;i<(q-1);i++)
     {
       x += XY[i];
       x *= 8;       
     }	   
   x += XY[q-1];

 return x;   
}

///////////////////////////////////////////////////////////

vector<int>StrNum(vector<string>Hex)
{
   int q=int(Hex.size());	
   vector<int>XY(q);
   for(int i=0;i<q;i++)
      {
	 if(Hex[i] == "1")     
      	    XY.push_back(1);
         
	 else if(Hex[i] == "2")     
      	    XY.push_back(2);
          
	 else if(Hex[i] == "3")     
      	    XY.push_back(3);
         
	 else if(Hex[i] == "4")     
      	    XY.push_back(4);

	 else if(Hex[i] == "5")     
      	    XY.push_back(5);

	 else if(Hex[i] == "6")     
      	    XY.push_back(6);

	 else if(Hex[i] == "7")     
      	    XY.push_back(7);

	 else if(Hex[i] == "8")     
      	    XY.push_back(8);

	 else if(Hex[i] == "9")     
      	    XY.push_back(9);

	 else if(Hex[i] == "A")     
      	    XY.push_back(10);

	 else if(Hex[i] == "B")     
      	    XY.push_back(11);

	 else if(Hex[i] == "C")     
      	    XY.push_back(12);

	 else if(Hex[i] == "D")     
      	    XY.push_back(13);

	 else if(Hex[i] == "E")     
      	    XY.push_back(14);

	 else if(Hex[i] == "F")     
      	    XY.push_back(15);
      }

 return XY;
}

//////////////////////////////////////////////////////////

int HexDec(vector<int>XY)
{
  int x=0;
  
  int q=int(XY.size());
  
  for(int i=0;i<(q-1);i++)
     {
       x += XY[i];
       x *= 16;       
     }	   
   x += XY[q-1];
   
 return x;   
}



int main()
{
   int p;	
   int n;
   int m;
   int x;
   vector<int>XY;
   int q;

   cout<<"Please choose what operation do you want to do: "<<endl;
   cout<<"1. Transformation from one base to another. "<<endl;
   cout<<"2. Addition of numbers. "<<endl;
   cout<<"3. Subtraction of numbers. "<<endl;
   cin>>p;  
   
   if(p == 1)
     { 	     
       cout<<"You chose transformation of numbers. "<<endl;
       cout<<"Please choose in what base do you want to input your number. "<<endl;
       cout<<"1. Decimal"<<endl;
       cout<<"2. Binary"<<endl;
       cout<<"3. Octal"<<endl;
       cout<<"4. Hexadecimal"<<endl;
       cin>>n;
         
       cout<<"Now choose in what base do you want to your number to be. "<<endl;
       cout<<"1. Decimal"<<endl;
       cout<<"2. Binary"<<endl;
       cout<<"3. Octal"<<endl;
       cout<<"4. Hexadecimal"<<endl;
       cin>>m;
       

       if(n == m)
	 {
	   cout<<"Are you stupid?"<<endl;	 
	 }
       
       else if(n == 1 && m ==2)
              {
		 cout<<"Insert your number: ";
	         cin>>x;
                 
		 XY=DecBin(x);
		 q=int(XY.size());
		 cout<<"Your number is: ";
		 for(int i=0;i<q;i++)
		     cout<<XY[i];
                 cout<<endl;		 
	      }
        
       else if(n == 1 && m ==3)
              {	      
		 cout<<"Insert your number: ";
	         cin>>x;

		 XY=DecOct(x);
		 q=int(XY.size());
		 cout<<"Your number is: ";
		 for(int i=0;i<q;i++)
		     cout<<XY[i];
                 cout<<endl;		 
	      }

       else if(n == 1 && m ==4)
              {     
		 cout<<"Insert your number: ";
	         cin>>x;

		 XY=DecHex(x);
		 q=int(XY.size());
		 cout<<"Your number is: ";
		 for(int i=0;i<q;i++)
		    { 
		      if(XY[i] == 10)
			cout<<"A";      
                      
		      else if(XY[i] == 11)
			cout<<"B";      
		       
		      else if(XY[i] == 12)
			cout<<"C";      
		   
		      else if(XY[i] == 13)
			cout<<"D";      
		   
		      else if(XY[i] == 14)
			cout<<"E";      
		   
		      else if(XY[i] == 15)
			cout<<"F";      
		   
		      else
			cout<<XY[i];  
		      
		      cout<<endl;    
		    }		     
	      }

       else if(n == 2 && m == 1)
              {
		 cout<<"Insert the length of your number: ";
	         cin>>q;
	         vector<int>Q(q);	 
		 cout<<"Insert your number: "; 
		 for(int i=0;i<q;i++)
		     cin>>Q[i];
                 
		 x=BinDec(Q);
                 cout<<"Your number is: "<< x <<endl;
	      }

       else if(n == 3 && m == 1)
              {
		 cout<<"Insert the length of your number: ";
	         cin>>q;
	         vector<int>Q(q);	 
		 cout<<"Insert your number: "; 
		 for(int i=0;i<q;i++)
		     cin>>Q[i];
                 
		 x=OctDec(Q);
                 cout<<"Your number is: "<< x <<endl;
	      }

       else if(n == 4 && m == 1)
              {
		 cout<<"Insert the length of your number: ";
	         cin>>q;
	         vector<string>Q(q);	 
		 vector<int>XY(q);

		 cout<<"Insert your number (in CAPITAL letters): "; 
		 for(int i=0;i<q;i++)
		     getline(cin,Q[i]);
		 	
                 XY=StrNum(Q);
		 x=HexDec(XY);
                 cout<<"Your number is: "<< x <<endl;
	      }
     }

   else if(p == 2)
     {

     }	   

   else if(p == 3)
     {

     }	   
   
   else
     {
      cout<<"Are you stupid?"<<endl;	     
     }








}
