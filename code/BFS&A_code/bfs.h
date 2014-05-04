#ifndef BFS_H
#define BFS_H
#include "teight.h"
#include "xb.h"

class TBFS:public TEight  
{  
public:  
    TBFS(){}  
    TBFS(char *fname):TEight(fname){}  
    virtual void Search();  
private:  
    void Printl(TList<TBFS> &L);  
    int Repeat(TList<TBFS> &L);  
    int Find();  
}; 
#endif
