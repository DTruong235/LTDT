#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;
class MON_HOC
{
private:
char *monhoc;
int st;
public:
MON_HOC()
{
monhoc=NULL;
st=0;
}
MON_HOC(char *monhoc1, int st1)
{
int n = strlen(monhoc1);
monhoc = new char[n+1];
strcpy(monhoc,monhoc1);
st=st1;
}
~ MON_HOC()
{
if (monhoc!=NULL)
{
delete monhoc;
st=0;
}
}
void in()
{
cout << "\nTen mon: " << monhoc << " so tiet: " << st;
}
} ;
class NGUOI
{
private:
char *ht;
int ns;
public:
NGUOI()
{
ht=NULL;
ns=0;
}
NGUOI(char *ht1, int ns1)
{
int n = strlen(ht1);
ht = new char[n+1];
strcpy(ht,ht1);
ns=ns1;
}
~NGUOI()
{
if (ht!=NULL)
{
delete ht;
ns=0;
}
}
void in()
{
cout << "\nHo ten : " << ht << " nam sinh: " << ns;
}
} ;
class GIAO_VIEN : public NGUOI
{
private:
char *bomon;
MON_HOC mh;
public:
GIAO_VIEN():mh(),NGUOI()//Su dung ham tao khong doi
{
bomon=NULL;
}
GIAO_VIEN(char *ht1, int ns1, char *monhoc1,int st1, char *bomon1 ):
NGUOI(ht1,ns1),mh(monhoc1, st1)
{
int n = strlen(bomon1);
bomon = new char[n+1];
strcpy(bomon,bomon1);
}
~GIAO_VIEN()
{
if (bomon!=NULL)
delete bomon;
}
void in()
{
// Su dung phuong thuc in
NGUOI::in();
cout << "\n Cong tac tai bo mon: " << bomon;
mh.in();
}
};
int main()
{

GIAO_VIEN g1; // Goi toi cac ham tao khong doi
GIAO_VIEN *g2;
//Goi toi cac ham tao co doi
g2 = new GIAO_VIEN("PHAM VAN AT", 1945, "CNPM", 
60, "TIN HOC");
g2->in();
/*
co the viet
g2->GIAO_VIEN::in();
*/
g2->NGUOI::in();
getch();
delete g2; // Goi toi cac ham huy
getch();
}
