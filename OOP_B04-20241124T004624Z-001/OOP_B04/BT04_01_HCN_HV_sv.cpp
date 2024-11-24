//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <iostream>
using namespace  std;

//Class Hinh chu nhat
class HinhCN 
{
	private:
		float dai;
		float rong;
		float dt;  
		float cv;
	public:
		HinhCN();
		HinhCN(float d, float r);
		void Nhap();
		void Xuat();
		void TinhDT();
		void TinhCV();
		float getCV();
		float getDT();
		float setdt(float dt);
		float setcv(float cv);
		//float getDai();
		//float getRong();
		//..cac phuong thuc khac
};


//Hinh vuong
class HinhVuong:public HinhCN
{
	private: 
		float canh;
		//ke thua dt, cv tu HCN

	public:
		HinhVuong();
		HinhVuong(float c);
		void Nhap();
		void Xuat();
		void TinhDT();
		void TinhCV();
		//float getCV();
		//float getDT();
		float getCanh();
};

int main()
{
	HinhCN	hcn[50];
	HinhVuong hv[50];
	int n,m;
	cout<<"So luong Hinh CN: "; cin>>n;
	for(int i=0; i<n;i++)
		hcn[i].Nhap();
		
	cout<<"Thong tin cac  Hinh CN: "<<endl;
	for(int i=0; i<n;i++)
		hcn[i].Xuat();
	
	//..Them code
	cout<<"So luong Hinh Vuong: "; cin>>m;
	for(int i=0; i<m;i++)
		hv[i].Nhap();
		
	cout<<"Thong tin cac  Hinh Vuong: "<<endl;
	for(int i=0; i<m;i++)
		hv[i].Xuat();
	
	float tongcv_HCN = 0;	
	float tongdt_HCN = 0;
	float tongcv_HV = 0;
	float tongdt_HV = 0;
	for(int i = 0; i<n; i++){
		tongcv_HCN += hcn[i].getCV();
		tongdt_HCN +=hcn[i].getDT();
	}
	
	for(int i = 0; i<m; i++){
		tongcv_HV += hv[i].getCV();
		tongdt_HV +=hv[i].getDT();
	}
	
	cout<<"Tong chu vi HCN= "<<tongcv_HCN<<", Tong dien tich HCN= "<<tongdt_HCN<<endl;
	cout<<"Tong chu vi HV= "<<tongcv_HV<<", Tong dien tich HV= "<<tongdt_HV<<endl;
	getch();
	return 1;
}

//Cac phuong thuc Hinh CN
HinhCN::HinhCN()
{
	dai = rong = dt=cv=0;
}
HinhCN::HinhCN(float d,float r)
{
	dai=d; rong=r;
}

void HinhCN::Nhap()
{
	cout<<"nhap do dai canh dai: "; cin>>dai;
	cout<<"nhap do dai canh rong: "; cin>>rong;
	//..Them code
	TinhCV();
	TinhDT();
}
void HinhCN::Xuat()
{
	cout<<"canh dai: "<<dai<<" canh rong: "<<rong;
	cout<<" Chu vi: "<<cv<<" Dien tich: "<<dt<<endl;
}

void HinhCN::TinhDT()
{
	dt=(dai*rong);
}

void HinhCN::TinhCV()
{
	cv= (dai+rong)*2;
}

float HinhCN::getCV(){
	return cv;
}

float HinhCN::getDT(){
	return dt;
}

float HinhCN::setcv(float cv){
	this->cv = cv;
}

float HinhCN::setdt(float dt){
	this->dt = dt;
}

//Cac phuong thuc cua Hinh Vuong
HinhVuong::HinhVuong()
{
	canh=0;
}
HinhVuong::HinhVuong(float c)
{
	canh=c;
}
void HinhVuong::Nhap(){
	cout<<"Nhap do dai canh: ";
	cin>>canh;
	TinhCV();
	TinhDT();
}

void HinhVuong::Xuat(){
	cout<<"Canh: "<<canh;
	cout<<" Chu vi: "<<getCV()<<" Dien tich: "<<getDT()<<endl;
}


void HinhVuong::TinhDT()
{
	
	float dtv = canh * canh;
	setdt(dtv);
}

void HinhVuong::TinhCV()
{
	
	float  cvv = canh*4;
	setcv(cvv);
}

