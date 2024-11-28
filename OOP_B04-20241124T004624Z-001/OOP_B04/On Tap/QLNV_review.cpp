#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#define LCB  18000

using namespace std;
class NhanVien{
	private:
		char Maso[25];
		char Hoten[50];
		float Luong;
	public:
		NhanVien();
		NhanVien(char* Maso1,char* Hoten1,float Luong1);
		virtual void Nhap();
		virtual void Xuat();
		float virtual TinhLuong()=0;
		float setLuong(float Luong1);
		float getLuong();
};

class BienChe:public NhanVien{
	private:
		float hsLuong;
		float hsPhucap;
	public:
		BienChe();
		BienChe(char* Maso1,char* Hoten1,float Luong1,float hsLuong1,float hsPhucap1);
		void Nhap();
		void Xuat();
		float TinhLuong();
};

class HopDong: public NhanVien{
	private:
		float TienCong;
		float SoNgayLamViec;
	public:
		HopDong();
		HopDong(char* Maso1,char* Hoten1,float Luong1,float TienCong1,float SoNgayLamViec1);
        void Nhap();
		void Xuat();
		float TinhLuong(); 
};

int main(){
	int n = 0;
	NhanVien *Nv[100];
	
	char Chon,Loai;
	cout<<"\nNhap thong tin cho cac doi tuong: \n"<<endl;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	do{
		cout<<"Nhap loai B hay H (B/H)";
		cin>>Loai;   Loai=toupper(Loai);
		if(Loai == 'B')
		{
			Nv[n] = new BienChe;
			Nv[n]->Nhap();
		}
		else{
			Nv[n] = new HopDong;
			Nv[n]->Nhap();
		}
		
		n++;
		cout<<"Tiep tuc (C/K)?";  cin>>Chon;
		Chon = toupper(Chon);
		if((n==100) || (Chon == 'K'))
			break;
	}while (1);
	
	for(int i = 0; i<n; i++)
		Nv[i]->Xuat();
		
	float tongluong = 0;
	for(int i = 0; i<n ; i++)
		tongluong+=Nv[i]->getLuong();
	cout<<"\nTong luong nhan vien: "<<tongluong;
	float avgluong = tongluong/n;
	cout<<"\nTrung binh cong luong nhan vien: "<<avgluong;
}

NhanVien::NhanVien(){
	strcpy(Maso," ");
	strcpy(Hoten," ");
	Luong = 0; 
}

NhanVien::NhanVien(char* Maso1,char* Hoten1,float Luong1){
	strcpy(this->Maso,Maso1);
	strcpy(this->Hoten,Hoten1);
	this->Luong=Luong1;
}

void NhanVien::Nhap(){
	
	cout<<"Ma so: "; cin>>Maso;
	fflush(stdin);
	cout<<"Ho ten: "; gets(Hoten);
	//cin.ignore();
}

void NhanVien::Xuat(){
	cout<<"Ma so: "<<Maso<<", Ho ten: "<<Hoten<<", Luong: "<<Luong;
}
float NhanVien::setLuong(float Luong1){
	this->Luong=Luong1;
}
float NhanVien::getLuong(){
	return Luong;
}

//Bien Che

BienChe::BienChe():NhanVien(){
	hsLuong = 0;
	hsPhucap = 0;
}

BienChe::BienChe(char* Maso1,char* Hoten1,float Luong1,float hsLuong1,float hsPhucap1): NhanVien( Maso1,Hoten1, Luong1){
	this->hsLuong = hsLuong1;
	this->hsPhucap=hsPhucap1;
}

void BienChe::Nhap(){
	NhanVien::Nhap();
	do{
		cout<<"He so luong: ";
		cin>>hsLuong;
	}while((hsLuong<3.0) || (hsLuong>14.0));
	
	do{
		cout<<"He so phu cap: ";
		cin>>hsPhucap;
	}while((hsPhucap<0.0) || (hsPhucap>2.0));
	TinhLuong();
}

float BienChe::TinhLuong(){
	float Luong1=LCB*(hsLuong+hsPhucap);
	setLuong(Luong1);
}

void BienChe::Xuat(){
	NhanVien::Xuat();
	cout<<", He so luong: "<<hsLuong<<", He so phu cap: "<<hsPhucap<<endl;
}


HopDong::HopDong():NhanVien(){
	TienCong = 0;
	SoNgayLamViec = 0;
}

HopDong::HopDong(char* Maso1,char* Hoten1,float Luong1,float TienCong1,float SoNgayLamViec1):NhanVien( Maso1,Hoten1, Luong1){
	this->TienCong=TienCong1;
	this->SoNgayLamViec=SoNgayLamViec1;
}	

void HopDong::Nhap(){
	NhanVien::Nhap();
	do{
		cout<<"Tien ngay cong 1 ngay: ";
		cin>>TienCong;
	}while((TienCong<100) || (TienCong>200));
	
	cout<<"Nhap so ngay lam viec: ";
	cin>>SoNgayLamViec;
	
	if(SoNgayLamViec > 24)
	{
		float SoNgayHon24 = (SoNgayLamViec - 24)*1.2;
		SoNgayLamViec = 24+SoNgayHon24;
	}
	
	TinhLuong();

}	

float HopDong::TinhLuong(){
	float Luong1= TienCong*SoNgayLamViec;
	setLuong(Luong1);
}

void HopDong::Xuat(){
	NhanVien::Xuat();
	cout<<", Tien cong 1 ngay: "<<TienCong<<", So ngay cong: "<<SoNgayLamViec<<endl;
}
