#include <iostream>
#include <iomanip>
#include <fstream>
#include "bfs.h"
#include "xb.h"
 
//TBFS(char *fname):TEight(fname){} 

void TBFS::Printl(TList<TBFS> &L)  
{  
    TBFS T=*this;  
    if(T.last==-1)  
        return;  
    else  
    {  
        T=L.GetData(T.last);  
        T.Printl(L);  
        T.Printf();  
    }  
}  
  
int TBFS::Repeat(TList<TBFS> &L)  
{  
    int n=L.Getlen();  
    int i;  
    for(i=0;i<n;i++)  
        if(L.GetData(i)==*this)  
            break;  
    return i;  
}  
  
int TBFS::Find()  
{  
    for(int i=0;i<Num;)  
        if(p[i]!=q[i++])  
            return 0;  
    return 1;  
}  
  
void TBFS::Search()  
{  
	total = 0;
    TBFS T=*this;  
    TList<TBFS> L;  
    L.Append(T);  
    int head=0,tail=0;  
    while(head<=tail)  
    {  
        for(int i=0;i<4;i++)  
        {  
            T=L.GetData(head);  
            if(T.Extend(i) && T.Repeat(L)>tail)  
            {  
                T.last=head;  
                L.Append(T);  
                tail++;  
            }  
            if(T.Find())  
            {  
                T.Printl(L);  
                T.Printf();  
                return;  
            }  
        }  
        head++;  
    }  
}
