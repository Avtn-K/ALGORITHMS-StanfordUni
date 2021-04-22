#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;



unsigned kiss_z     = 123456789; 
unsigned kiss_w     = 378295763;  
unsigned kiss_jsr   = 294827495;  
unsigned kiss_jcong = 495749385; 

unsigned SlucajniUns()
{
	kiss_z=36969*(kiss_z&65535)+(kiss_z>>16);
	kiss_w=18000*(kiss_w&65535)+(kiss_w>>16);

	kiss_jsr^=(kiss_jsr<<13); 
	kiss_jsr^=(kiss_jsr>>17); 
	kiss_jsr^=(kiss_jsr<<5);

	kiss_jcong=69069*kiss_jcong+1234567;

	return (((kiss_z<<16)+kiss_w)^kiss_jcong)+kiss_jsr;
}

const unsigned RNG_MAX = 4294967295; 

void OdvrtiGenerator()
{
	for (int i=0; i<300; i++)
		SlucajniUns();
}

int Slucajni(int granica)
{
	unsigned velicinaIntervala = RNG_MAX / granica;
	unsigned granicaIzbora= velicinaIntervala*granica;
	unsigned slucajniBroj = SlucajniUns();
	while(slucajniBroj>=granicaIzbora)
		slucajniBroj = SlucajniUns();
	return slucajniBroj/velicinaIntervala;
}



int main()
{

string s;
int v;
vector<string>S;
vector<string>SS;
int stupac;
int redak;
int stupacvr;
int redakvr;
int redakswap;
int redakswapvr;
int q;
int p;
int brojilo=0;

for(int brojilo=0;brojilo<100;brojilo++)
{
vector<vector<int>> tbl(200, vector<int>());

  ifstream List("graph.txt");
    if(List.is_open())
      {
        while(getline(List,s))
             {
	       S.push_back(s);	     
             }
          List.close();
      }

    for(int i=0;i<200;i++)
     {
        stringstream sTok(S[i]);
        string word;
        while(sTok >> word)
	     {
              SS.push_back(word);      
	     }

	int q=int(SS.size());

	for(int j=0;j<q;j++)
	   {
	     v=std::stoi(SS[j]);
	     tbl[i].push_back(v);	
	   }

	for(int j=0;j<q;j++)
	    SS.pop_back();	
      }
/*       
    for(int i=0;i<200;i++)
      {
	int q=int(tbl[i].size());
        for(int j=0;j<q;j++)
	   {
             cout<<tbl[i][j]<<" ";		   
	   }	
         cout<<endl;
      }
*/   
/////////////////////////////////////////////////////////////////
//for(int brojilo=0;brojilo<3;brojilo++)
//{	
/*
vector<vector<int>>tbl
{

        {1,2,3,4},
	{2,1,4},
	{3,1,4},
	{4,1,2,3}
	
	{1,2,3,4,7},
	{2,1,3,4},
	{3,1,2,4},
	{4,1,2,3,5},
	{5,4,6,7,8},
	{6,5,7,8},
	{7,1,5,6,8},
	{8,5,6,7}

};

for(int i=0;i<(int(tbl.size()));i++)
   { 
     for(int j=0;j<(int(tbl[i].size()));j++)
        {
	  cout<<tbl[i][j]<<" ";	
	}	     
     cout<<endl;
   }
*/
/////////////////////////////////////////////////////////////////

do{

redak=Slucajni(int(tbl.size()));
redakvr=tbl[redak][0];

do{
   stupac=Slucajni(int(tbl[redak].size()));
   stupacvr=tbl[redak][stupac];
  }
while(redakvr==stupacvr);

for(int i=0;i<int(tbl.size());i++)
   {
     if(tbl[i][0]==stupacvr)
       {
	 redakswap=i;      
	 redakswapvr=tbl[i][0];
         break;	 
       }	     
   }
/*
cout<<endl;
cout<<"----------------------------"<<endl;
cout<<"Redak: "<< redakvr <<endl;
cout<<"Stupac: "<< stupacvr <<endl;
cout<<"Novi Redak po stupcu: "<< redakswapvr <<endl;
cout<<"----------------------------"<<endl;
cout<<endl;
*/
for(int i=0;i<(int(tbl[redak].size()));i++)
   {
     if(tbl[redak][i]==redakswapvr)
       {
	 tbl[redak][i]=tbl[redak][int(tbl[redak].size())-1];
         tbl[redak].pop_back(); 	 
         break;
       }     
   }

for(int i=0;i<(int(tbl[redakswap].size()));i++)
   {
     if(tbl[redakswap][i]==redakvr)
       {
	 tbl[redakswap][i]=tbl[redakswap][int(tbl[redakswap].size())-1];
         tbl[redakswap].pop_back(); 	 
         break;
       } 
   }

for(int i=1;i<(int(tbl[redakswap].size()));i++)
   {
     tbl[redak].push_back(tbl[redakswap][i]); 	   
   }

tbl.erase(tbl.begin() + (redakswap));

for(int i=0;i<(int(tbl.size()));i++)
   { 
     for(int j=0;j<(int(tbl[i].size()));j++)
        {
	  if(tbl[i][j]==redakswapvr)
	    {
	      tbl[i][j]=redakvr;	    
	    }	  
	}	     
   }
/*
for(int i=0;i<(int(tbl.size()));i++)
   { 
     for(int j=0;j<(int(tbl[i].size()));j++)
        {
	  cout<<tbl[i][j]<<" ";	
	}	     
     cout<<endl;
   }
*/
}
while(int(tbl.size())>2);

p=0;
q=0;
for(int i=0;i<(int(tbl[0].size()));i++)
   {
     if(tbl[0][i]==tbl[1][0])
        p++;	     
   }

for(int i=0;i<(int(tbl[1].size()));i++)
   {
     if(tbl[1][i]==tbl[0][0])
        q++;	     
   }
cout<<endl;
cout<<"Najmanji: "<< p <<" , "<< q <<endl;
cout<<endl;
}

//////////////////////////////////////////////////////////////////


	
/*
cout<<endl;
cout<<"----------------------------"<<endl;
cout<<"----------------------------"<<endl;
cout<<"End of DO-WHILE: Final Field"<<endl;
cout<<endl;

for(int i=0;i<(int(tbl.size()));i++)
   { 
     for(int j=0;j<(int(tbl[i].size()));j++)
        {
	  cout<<tbl[i][j]<<" ";	
	}	     
     cout<<endl;
     cout<<endl;
   }
*/

return 0;
}
