//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

#define MAX_TEN		50
#define MAX_MASO	10
#define LCB     1800000 

//Class Nhanvien
class NhanVien
{	protected: //private:
		char HoTen[MAX_TEN];
		char MaSo[MAX_MASO];
		float Luong;
	public:
		NhanVien();
		virtual void TinhLuong()=0; 
		virtual void Xuat(); 
		virtual void Nhap();
		float getluong();
		//...bo sung code
};

	
//Class Bien che
class BienChe: public NhanVien
{	protected: //private:
		float HeSoLuong;
		float HeSoPhuCap;
	public:
		BienChe();
		void TinhLuong();
		void Nhap();
		void Xuat();
		//...bo sung code
};

//Dinh nghia lop HopDong
class HopDong : public NhanVien
{	protected: //private:
		float TienCong; // 1 ngay
		float NgayCong; // lon hon 24 ngay thi tinh 1.2
	public:
		HopDong();
		void TinhLuong();
		void Nhap();
		void Xuat();
		//...bo sung code
};

int main()
{
	NhanVien *Nv[100];	int N=0;
	char Chon,Loai;
	cout<<"Nhap thong tin cho cac Nhan vien"<<endl;
	do
	{	cout<<"Bien che hay Hop dong (B/H)? ";
		cin>>Loai; 	Loai=toupper(Loai);
		if (Loai=='B')
			Nv[N]=new BienChe;
		else
			Nv[N]=new HopDong;
		Nv[N++]->Nhap();
		cout<<"Tiep tuc (C/K)? ";	cin>>Chon;
		Chon=toupper(Chon);
		if ((N==100)||(Chon=='K'))
			break;
	}
	while (1);
	cout<<"Thong tin cua cac nhan vien vua nhap"<<endl;
	
	//...bo sung code
	for(int i = 0 ; i<N; i++){
		Nv[i]->Xuat();
	}
	float sumluong=0;
	for(int i = 0 ; i<N; i++){
		sumluong+=Nv[i]->getluong();
	}
	cout<<endl<<"-Tong luong nhan vien= "<<sumluong;
	cout<<endl<<"-Trung binh cong luong nhan vien= "<<sumluong/N;
	cout<<endl<<"-Nhan vien co luong luong lon hon 5tr "<<endl;
	for(int i = 0 ; i<N; i++){
		if(Nv[i]->getluong()>5000)
			Nv[i]->Xuat();
	}
	getch();
	return 1;
}


//Dinh nghia ham thanh vien cho lop NhanVien
NhanVien::NhanVien()
{
	strcpy(HoTen,""); 
	strcpy(MaSo,"");
	Luong=0;
}

void NhanVien::Nhap()
{
	cout<<"Ma so:";	cin>>MaSo;
	cin.ignore(); //xoa dau Enter trong buffer
	cout<<"Ho va ten:"; 
	cin.getline(HoTen,MAX_TEN);
	//cin>>HoTen;
}

void NhanVien::Xuat() 
{	//setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Ma so:"<<MaSo<<",Ho va ten:"<<HoTen
		 <<",Luong:"<<Luong<<endl;
}
	
float NhanVien::getluong(){
	return Luong;
}
//Dinh nghia ham thanh vien cho lop BienChe
BienChe::BienChe()
{
	HeSoLuong=HeSoPhuCap=0;
}

void BienChe::Nhap()
{	
//...bo sung code
	NhanVien::Nhap();
	do{
		cout<<"Nhap he so luong: ";
		cin>>HeSoLuong;
	}while(HeSoLuong<3.0||HeSoLuong>14);
	
	do{
		cout<<"Nhap phu cap chuc vu: ";
		cin>>HeSoPhuCap;
	}while(HeSoPhuCap<0.0||HeSoPhuCap>2.0);
	TinhLuong();
}

void BienChe::Xuat(){
	NhanVien::Xuat();
	cout<<",He so luong= "<<HeSoLuong;
	cout<<",He so phu cap= "<<HeSoPhuCap<<endl;
}

void BienChe::TinhLuong()
{
	Luong=LCB*(HeSoLuong+HeSoPhuCap);
}

//Cac ham thanh vien trong lop HopDong
HopDong::HopDong()
{
	TienCong=NgayCong=0;
}

void HopDong::Nhap()
{
	
	//...bo sung code
	NhanVien::Nhap();
	do{
		cout<<"Nhap tien cong mot ngay: ";
		cin>>TienCong;
	}while(TienCong<100||TienCong>20000);
	
	cout<<"Nhap so ngay lam viec: ";
	cin>>NgayCong;
	TinhLuong();
}

void HopDong::Xuat(){
	NhanVien::Xuat();
	cout<<",Tien cong= "<<TienCong;
	cout<<",Ngay cong= "<<NgayCong<<endl;
}

void HopDong::TinhLuong()
{
	//...bo sung code
	if(NgayCong>24.0){
		float ncongcophucap = NgayCong - 24.0 * 1.2;
		Luong = (TienCong * ncongcophucap)+(TienCong)*24.0;
	}
	else Luong = TienCong * NgayCong;	
}

