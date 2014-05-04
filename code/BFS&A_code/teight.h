#ifndef TEIGHT_H
#define TEIGHT_H
#define Num 9 
class TEight  
{  
public:  
    TEight(){}  
    TEight(char *fname);  
    virtual void Search()=0;  
protected:  
    int p[Num];  
    int last,spac;  
    static int q[Num],d[],total;  
    void Printf();  
    bool operator==(const TEight &T);  
    bool Extend(int i);  
};  
#endif
