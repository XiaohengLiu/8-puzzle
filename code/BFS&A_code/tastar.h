#ifndef TASTAR_H
#define TASTAR_H
#include "teight.h"
#include "xb.h"
#define Num 9 
class TAstar:public TEight  
{  
public:  
    TAstar(){}                           //构造函数   
    TAstar(char *fname1,char *fname2);   //带参数构造函数    
    virtual void Search();               //A*搜索法   
private:  
    int f,g,h;                               //估价函数     
    int r[Num];                              //存储状态中各个数字位置的辅助数组   
    static int s[Num];                       //存储目标状态中各个数字位置的辅助数组   
    static int e[];
    void Printl(TList<TAstar> L);       //成员函数，输出搜索路径    
    int Expend(int i);                        //成员函数，A*算法的状态扩展函数    
    int Calcuf();                             //成员函数，计算估价函数   
    void Sort(TList<TAstar>& L,int k);  //成员函数，将新扩展结点按f从小到大顺序插入待扩展结点队列   
    int Repeat(TList<TAstar> &L);       //成员函数，检查结点是否重复   
};  

#endif
