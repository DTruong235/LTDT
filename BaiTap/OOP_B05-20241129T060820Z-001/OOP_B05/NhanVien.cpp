#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>

using namespace std;

class NhanVien{
	private:
		char MSNV [6], HoTen [50], NgaySinh[10];
		float TienLuong;
	
	public:
		NhanVien();
		NhanVien(char* msnv, char* hoten, char* ngaysinh, float tienluong);
		virtual void Nhap();
		virtual void Xuat();
		virtual void TinhLuong()=0;
		char* getMSNV();
		char* getHoTen();
		float setTienLuong(float tienluong);
		float getTienLuong();
		virtual float getSl()=0;
		virtual float getTienThuong()=0;
};

class NVQL:public NhanVien{
	private:
		float TienThuong,HsLuong;
		float LuongCB ;
	public:
		NVQL();
		NVQL(char* msnv, char* hoten, char* ngaysinh, float tienluong, float tienthuong,float hsluong,float luongcb);
		void Nhap();
		void Xuat();
		void TinhLuong();
		float getSl();
		float getTienThuong();
};

class NVSX:public NhanVien{
	private:
		float TienCong, LuongCB , SLSp;
	public:
		NVSX();
		NVSX(char* msnv, char* hoten, char* ngaysinh, float tienluong, float tiencong,float slsp,float luongcb);
		void Nhap();
		void Xuat();
		void TinhLuong();
		float getSl();
		float getTienThuong();
};


int main(){
	int n = 0;
	float sumsl = 0, sumLuongNV = 0, avgLuongNV = 0,sumTienThuongNVQL = 0;
	NhanVien *nv[100];
	
	char Loai,Chon;
	cout<<endl<<"Nhap Thong Tin Nhan Vien"<<endl;
	cout<<setiosflags (ios::fixed)<<setprecision(3);
	
	do{
		cout<<"Chon Nhan Vien Quan Li hay Nhan Vien San Xuar (Q/S): ";
		cin>>Loai;
		Loai = toupper(Loai);
		if(Loai == 'Q')
		{
			nv[n] = new NVQL;
			nv[n]->Nhap();
			sumTienThuongNVQL += nv[n]->getTienThuong();
		}
			
		else
		{
			nv[n] = new NVSX;
			nv[n]->Nhap();
		
			sumsl+= nv[n]->getSl();
			
		}
			
		n++;
		
		cout<<"Tiep tuc? (C/K)";
		cin>>Chon;
		Chon = toupper(Chon);
		
		if((n>100) || Chon == 'K')
			break;
		
	}while(1);
	
	cout<<endl<<"Danh sach Nhan Vien"<<endl;
	for(int i = 0; i<n; i++)
		nv[i]->Xuat();
	//may le
	cout<<endl<<"May le"<<endl<<"Tong so san pham ma cac nhan vien san xuat da thuc hien: "<<sumsl;
	for(int i = 0; i<n; i++)
		sumLuongNV+= nv[i]->getTienLuong();
	avgLuongNV = sumLuongNV/n;
	cout<<endl<<"Trung binh luong cua cac nhan vien trong doanhh nghiep: "<<avgLuongNV;
	for(int i = 0; i<n-1; i++)
		for(int j = i; j<n; j++)
			if(strcmp(nv[i]->getHoTen(),nv[j]->getHoTen())>0){
			NhanVien *tmp = nv[i];
			nv[i]=nv[j];
			nv[j]=tmp;
		}
	cout<<endl<<endl;
	cout<<"Danh sach sap xep tang dan theo Ho & Ten"<<endl;
	for(int i = 0; i<n; i++)
		nv[i]->Xuat();
		
	//may chan
	cout<<endl<<"May Chan"<<endl<<"Tong tien thuong cac nhan vien quan li: "<<sumTienThuongNVQL;
	float maxluong = nv[0]->getTienLuong();
	for(int i = 0; i<n;i++)
		if(maxluong<nv[i]->getTienLuong())
			maxluong = nv[i]->getTienLuong();
	cout<<endl<<"Tien luong cao nhat cua cac nhan vien: "<<maxluong;
	
	char msnvct[50];
	int flag = 0;
	fflush(stdin);
	cout<<endl<<"Nhap Ma so nhan vien can tim: "; gets(msnvct);
	for(int i = 0; i<n;i++)
		if(stricmp(nv[i]->getMSNV(),msnvct)==0){
			nv[i]->Xuat();
			flag++;
		}
	if(flag==0) cout<<endl<<"Khong tim thay Ma so nhan vien can tim!";
		
}		


// Class NhanVien
NhanVien::NhanVien(){
	strcpy(this->MSNV,"");
	strcpy(this->HoTen,"");
	strcpy(this->NgaySinh,"");
	this->TienLuong = 0;
}

NhanVien::NhanVien(char* msnv, char* hoten, char* ngaysinh, float tienluong){
	strcpy(this->MSNV,msnv);
	strcpy(this->HoTen,hoten);
	strcpy(this->NgaySinh,ngaysinh);
	this->TienLuong = tienluong;
}

float NhanVien::setTienLuong(float tienluong){
	this->TienLuong = tienluong;
}

char* NhanVien::getMSNV(){
	return this->MSNV;
}

char* NhanVien::getHoTen(){
	return this->HoTen;
}

float NhanVien::getTienLuong(){
	return this->TienLuong;
}

void NhanVien::Nhap(){
	fflush(stdin);
	cout<<"Ma so Nhan Vien: "; cin>>this->MSNV;
	cin.ignore();
	fflush(stdin);
	cout<<"Ho va Ten: "; gets(this->HoTen);
	cout<<"Ngay sinh: "; cin>>this->NgaySinh;
	
}

void NhanVien::Xuat(){
	cout<<"MSNV: "<<this->MSNV<<", H&T: "<<this->HoTen<<", NGS: "<<this->NgaySinh<<", Luong: "<<this->TienLuong;
}

// Class NVQL

NVQL::NVQL():NhanVien(){
	this->TienThuong = 0;
	this->HsLuong = 0;
	this->LuongCB = 3000;
}
NVQL::NVQL(char* msnv, char* hoten, char* ngaysinh, float tienluong, float tienthuong,float hsluong,float luongcb):NhanVien(msnv,hoten,ngaysinh,tienluong){
	this->TienThuong = tienthuong;
	this->HsLuong = hsluong;
	this->LuongCB=luongcb;
}

void NVQL::Nhap(){
	NhanVien:: Nhap();
	do{
		cout<<"Tien Thuong (Khong lon hon luong CB (LCB = 3000)): "; cin>>this->TienThuong;
		if(this->TienThuong>this->LuongCB)
			cout<<"Tien thuong khong hop le!"<<endl<<"Vui long nhap lai!"<<endl;
	}while((this->TienThuong<0) || (this->TienThuong>this->LuongCB));
	
	do{
		cout<<"He so Luong (2.0-5.0): "; cin>>this->HsLuong;
			if((this->HsLuong<2.0) || (this->HsLuong>5.0))
			cout<<"He so luong khong hop le!"<<endl<<"Vui long nhap lai!"<<endl;
	}while((this->HsLuong<2.0) || (this->HsLuong>5.0));
	TinhLuong();
}

void NVQL::Xuat(){
	NhanVien::Xuat();
	cout<<", Tien Thuong: "<<this->TienThuong<<", Hs Luong: "<<this->HsLuong<<", Luong CB: "<<this->LuongCB<<endl;
}

void NVQL::TinhLuong(){
	float tienluong = this->LuongCB * this->HsLuong + this->TienThuong;
	setTienLuong(tienluong);
}

float NVQL::getSl(){	
}

float NVQL::getTienThuong(){
	return this->TienThuong;
}
//class NVSX
NVSX::NVSX():NhanVien(){
	this->TienCong = 10;
	this->SLSp = 0;
	this->LuongCB = 2400;
}

NVSX::NVSX(char* msnv, char* hoten, char* ngaysinh, float tienluong, float tiencong,float slsp,float luongcb):NhanVien(msnv,hoten,ngaysinh,tienluong){
	this->TienCong = tiencong;
	this->SLSp = slsp;
	this->LuongCB=luongcb;
}

void NVSX::Nhap(){
	NhanVien::Nhap();
	do{
		cout<<"So luong san pham (khong lon hon 400/thang): "; cin>>this->SLSp;
		if((this->SLSp<0) ||(this->SLSp>400.0))
			cout<<"So luong khong hop le!"<<endl<<"Vui long nhap lai!"<<endl;
	}while ((this->SLSp<0) ||(this->SLSp>400.0));
	
	TinhLuong();
}

void NVSX::Xuat(){
	NhanVien::Xuat();
	cout<<", Tien cong: "<<this->TienCong<<", SLSP: "<<this->SLSp<<", Luong CB: "<<this->LuongCB<<endl;
}

void NVSX::TinhLuong(){
	float tienluong = this->LuongCB + (this->SLSp * this->TienCong);
	setTienLuong(tienluong);
}

float NVSX::getSl(){
	return this->SLSp;
}

float NVSX::getTienThuong(){
}

