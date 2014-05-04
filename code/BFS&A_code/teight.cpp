#define Num 9 
#include <iostream>
#include <iomanip>
#include <fstream>
#include "teight.h"
#include "xb.h"
using namespace std;
int TEight::q[Num];  
int TEight::d[]={1,3,-1,-3};  
int TEight::total=0;  
  
TEight::TEight(char *fname)  
{  
    ifstream fin;  
    fin.open(fname,ios::in | ios::in);  
    if(!fin)  
    {  
        cout<<"cannot open the file!"<<endl;  
        return;  
    }  
    int i;  
    for(i=0;i<Num;)  
        fin>>p[i++];  
    fin>>spac;  
    for(i=0;i<Num;)  
        fin>>q[i++];  
    fin.close();  
    last=-1;  
    total=0;  
}  
  
void TEight::Printf()  
{  
	
    ofstream fout;  
    fout.open("Eight_result.txt",ios::ate|ios::app);  
    cout<<total++<<"t";  
    for(int i=0;i<Num;) {
	cout<<"  "<<p[i]; 
       	fout<<"  "<<p[i++]; 
	}
    cout<<endl; 
  	fout<<endl;  
  	 fout.close();  
}  
  
bool TEight::operator==(const TEight &T)  
{  
    for(int i=0;i<Num;)  
        if(T.p[i]!=p[i++])  
            return 0;  
    return 1;  
}  
  
bool TEight::Extend(int i)  
{  
    if(i==0 && spac%3==2 || i==1 && spac>5   
        || i==2 && spac%3==0 || i==3 && spac<3)  
        return 0;  
    int temp=spac;  
    spac+=d[i];  
    p[temp]=p[spac];  
    p[spac]=0;  
    return 1;  
}

