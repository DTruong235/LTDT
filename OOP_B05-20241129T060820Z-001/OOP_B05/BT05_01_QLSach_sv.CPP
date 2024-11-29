#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

#define MAX_NXB		50
//Class Nhanvien
class QLSach
{	protected:
		char MaSach[12];
		char NgayNhap[12];
		float DonGia;
		int SoLuong;
		char NXB[50];
		float ThanhTien;
	public:
		QLSach();
		virtual void Nhap();
		virtual void Xuat(); 
		virtual void TinhTien()=0; //Ham thuan ao
		//...bo sung code
		float getThanhTien();
		char* getNXB();
		float getDonGia();
		virtual int Ktra()=0;
};

	
//Class Bien che
class SachGK: public QLSach
{
	protected:
		int TinhTrang; //1-Moi; 0-Cu
	public:
		SachGK();
		void TinhTien();
		void Nhap();
		//...bo sung code
		void Xuat();
		int Ktra();
};

//Dinh nghia lop SachTK

class SachTK : public QLSach
{
	protected:
		float Thue; 
	public:
		SachTK();
		void Nhap();
		void TinhTien();
		//...bo sung code
			void Xuat();
		int Ktra();
};


int main()
{
	QLSach *MSach[100];
	int i=0,n=0,m=0,c=0;
	float ttsachGK=0,ttsachTK=0,tdg=0;
	char Chon,Loai, nxb_ct[50];
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Nhap thong tin cho cac loai sach"<<endl;
	do
	{
		cout<<"Sack Giao khoa hay Sach Tham khao (G/T)? ";
		cin>>Loai;
		Loai=toupper(Loai);
		if (Loai=='G')
			{
				//...bo sung code
				MSach[n]=new SachGK;
				MSach[n]->Nhap();
				MSach[n]->TinhTien();
				ttsachGK = ttsachGK+MSach[n]->getThanhTien();
			}
			
		else
			{
			//...bo sung code
				MSach[n]=new SachTK;
				MSach[n]->Nhap();
				MSach[n]->TinhTien();
				ttsachTK = ttsachTK+MSach[n]->getThanhTien();
				tdg=tdg+MSach[n]->getDonGia();
				m++;
			}
		MSach[n]->TinhTien();
		n++; //tang len so luong sach
		cout<<"Tiep tuc (C/K)? ";
		cin>>Chon;
		Chon=toupper(Chon);
		if ((n==100)||(Chon=='K'))
			break;
	}
	while (1);
	
	//...bo sung code
	
	cout<<endl<<"Thong tin vua nhap"<<endl;
	for(i= 0; i<n;i++)
		MSach[i]->Xuat();
	
	cout<<"Tong tien sach GK: "<<ttsachGK<<endl;
	cout<<"Tong tien sach TK: "<<ttsachTK<<endl;	
	float tbcts = tdg/m;
	cout<<"Trung binh cong don gia: "<<tbcts<<endl;	
	cout<<"Nhap nxb can tim: ";
	cin.ignore();
	gets(nxb_ct);
	for(i = 0; i<n; i++)
		if(MSach[i]->Ktra()==1)
			if(stricmp(MSach[i]->getNXB(),nxb_ct)==0)
			{
				MSach[i]->Xuat();
				c++;
			}
	if (c == 0) cout<<"Khong tim thay nxb can tim!"	;		
	getch();
	return 1;
}


//Dinh nghia ham thanh vien cho lop QLSach
QLSach::QLSach()
{
	strcpy(MaSach,"");
	strcpy(NgayNhap,"");
	strcpy(NXB,"");
	ThanhTien=DonGia=SoLuong=0;
}

void QLSach::Nhap()
{
	//bo sung code
	cout<<"Ma sach: "; cin>>MaSach;
	cin.ignore();
	cout<<"Ngay nhap: "; cin>>NgayNhap;
	cin.ignore();
	cout<<"Ngay don gia: "; cin>>DonGia;
	cout<<"Ngay So luong: "; cin>>SoLuong;
	cin.ignore();
	cout<<"Nha xuat ban: "; gets(NXB);
	
}

float QLSach::getThanhTien(){
	return ThanhTien;
}

float QLSach::getDonGia(){
	return DonGia;
}

char* QLSach::getNXB(){
	return NXB;
}

void QLSach::Xuat() 
{
	cout<<"MS: "<<MaSach<<",NG: "<<NgayNhap;
	cout<<",DG: "<<DonGia<<",SL: "<<SoLuong;
	cout<<",TT: "<<ThanhTien<<",NXB: "<<NXB;
}


//Dinh nghia ham thanh vien cho lop SachGK
SachGK::SachGK(): QLSach() 
{
	//QLSach::QLSach();
	TinhTrang=1; //mac nhien la Sach moi
}
void SachGK::TinhTien()
{
	if (TinhTrang==1)
		ThanhTien=SoLuong*DonGia;
	else
		ThanhTien=SoLuong*DonGia*0.5;
}

void SachGK::Nhap()
{
	//...bo sung code
	char tt;
	QLSach::Nhap();
	cout<<"Tinh trang sach Moi-Cu (M/C): ";
	cin>>tt;
	if ((tt='M') || (tt='m'))
		TinhTrang = 1;
	else 	TinhTrang = 0;
	
	TinhTien();
}

void SachGK::Xuat()
{	cout<<"Ds sach Gk";
	QLSach::Xuat();
	cout<<",Tinh trang: "<<TinhTrang<<endl;
}
//Cac ham thanh vien trong lop SachTK
SachTK::SachTK(): QLSach() 
{
	Thue=0;
}

void SachTK::Nhap()
{
	//...bo sung code
	QLSach::Nhap();	
	float t;
	do{
		cout<<"Thue: ";
		cin>>t;
	}while ((t<5) ||(t>20));
	
	t= t/100;
	Thue=DonGia*t;
	TinhTien();
	
}

void SachTK::Xuat()
{   
    cout<<"Ds sach Tk";
	QLSach::Xuat();
	cout<<",Thue: "<<Thue<<endl;
}

void SachTK::TinhTien()
{
	ThanhTien= SoLuong*DonGia + Thue;
}
int SachTK::Ktra(){
	return 0;
}
int SachGK::Ktra(){
	return 1;
}
