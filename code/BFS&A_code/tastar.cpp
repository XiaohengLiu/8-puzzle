#define Num 9 
#include <iostream>
#include <iomanip>
#include <fstream>
#include "tastar.h"
#include "xb.h"
using namespace std;
int TAstar::s[Num],TAstar::e[Num*Num];  
  
TAstar::TAstar(char *fname1,char *fname2):TEight(fname1)  
{   
    for(int i=0;i<Num;)  
    {  
        r[p[i]]=i;   //存储初始状态个个数字的位置   
        s[q[i]]=i++; //存储目标状态个个数字的位置   
    }  
    ifstream fin;                       
    fin.open(fname2,ios::in | ios::in);//打开数据文件   
    if(!fin)  
    {  
        cout<<"不能打开数据文件!"<<endl;  
        return;  
    }  
	int i;
    for(i=0;i<Num*Num;i++)   //读入各个数字相对距离值     
        fin>>e[i];  
    fin.close();  
    f=g=h=0;       //估价函数初始值     
}  
  
void TAstar::Printl(TList<TAstar> L)   
{  
    TAstar T=*this;  
    if(T.last==-1)  
        return;  
    else  
    {  
        T=L.GetData(T.last);  
        T.Printl(L);  
        T.Printf();  
    }  
}  
  
int TAstar::Expend(int i)                        
{  
    if(Extend(i))   //结点可扩展   
    {  
        int temp=r[p[r[0]]];   //改变状态后数字位置变化，存储改变后的位置    
        r[p[r[0]]]=r[0];  
        r[0]=temp;  
        return 1;  
    }  
    return 0;  
}  
  
int TAstar::Calcuf()  
{  
    h=0;  
    for(int i=0;i<Num;i++)  //计算估价函数的h   
        h+=e[Num*r[i]+s[i]];  
    return ++g+h;                                       
}  
  
void TAstar::Sort(TList<TAstar>& L,int k)  
{  
    int n=L.Getlen();
	int i;  
    for( i=k+1;i<n;i++)  
    {  
        TAstar T=L.GetData(i);  
        if(this->f<=T.f)  
            break;  
    }  
    L.Insert(*this,i);  
}  
  
int TAstar::Repeat(TList<TAstar> &L)  
{  
    int n=L.Getlen(); 
	int i; 
    for( i=0;i<n;i++)  
        if(L.GetData(i)==*this)  
            break;  
    return i;  
}  
  
void TAstar::Search()  
{  
	total = 0;
    TAstar T=*this;              //初始结点   
    T.f=T.Calcuf();               //初始结点的估价函数   
    TList<TAstar> L;           //建立队列   
    L.Append(T);                 //初始结点入队   
    int head=0,tail=0;           //队列头和尾指针   
    while(head<=tail)           //队列不空则循环   
    {  
        for(int i=0;i<4;i++)            //空格可能移动方向   
        {  
            T=L.GetData(head);   //去队列头结点   
            if(T.h==0)                   //是目标结点   
            {     
                T.Printl(L);//输出搜索路径   
                T.Printf();    //输出目标状态   
                return;        //结束   
            }  
            if(T.Expend(i))          //若结点可扩展   
            {  
                int k=T.Repeat(L); //返回与已扩展结点重复的序号        
                if(k<head)               //如果是不能扩展的结点   
                    continue; //丢弃   
                T.last=head;      //不是不能扩展的结点，记录父结点   
                T.f=T.Calcuf(); //计算f   
                if(k<=tail)         //新结点与可扩展结点重复   
                {  
                    TAstar Temp=L.GetData(k);   
                    if(Temp.g>T.g)         //比较两结点g值   
                        L.SetData(T,k); //保留g值小的   
                    continue;  
                }      
                T.Sort(L,head) ;            //新结点插入可扩展结点队列        
                tail++;        //队列尾指针后移    
            }  
        }  
        head++; //一个结点不能再扩展，队列头指针指向下一结点   
    }  
}


