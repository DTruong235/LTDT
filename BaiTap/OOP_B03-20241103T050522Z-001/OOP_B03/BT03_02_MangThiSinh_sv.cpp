//Mang cac doi tuong 
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class Thisinh
{
	private:
		char Maso[12];
		char Hoten[40];
		float Diemlt, Diemth, Dtb;
		char Ketqua[12];
	public:
		Thisinh(); 
		void Nhap();
		void TinhDTB();
		void Xuat();
		//.. bo sung code
		void XepLoaiTSinh();
		
		char* getMs();
		char* getHoten();
		float getDiemlt();
		float getDiemth();
		float getDtb();
		
};

class MangThisinh
{
	private:
		Thisinh mts[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		
		//..cac phuong thuc con lai
		int Lk_TS_co_DTHvaDLT_LonHon7();
		float AVG_diemThsinh();
		void TimMsTS();
		void SX_TStangdan_theoHoten();
		
};


int main()
{
	MangThisinh mThisinh;
	
	//Nhap danh sach
	cout<<"Nhap thong tin cac Thi sinh: ";
	mThisinh.Nhap();
	
	cout<<"Thong tin cac Thi sinh: ";
	mThisinh.Xuat();
	
	//..Them code 
	cout<<endl<<"KQ nhung thi sinh co dth va dlt lon hon 7:";
	int tam = mThisinh.Lk_TS_co_DTHvaDLT_LonHon7();
	if(tam == 0) cout<<endl<<"Khong co thi sinh co dth va dlt deu lon hon 7!";
	
	float Kq_avgdiemTS = mThisinh.AVG_diemThsinh();
	cout<<endl<<"AVG diem cua tat ca thi sinh trong mang thi sinh: "<<Kq_avgdiemTS;
	
	cout<<endl<<"Tim MSTS: ";
	mThisinh.TimMsTS();
	
	cout<<endl<<"KQ Sx tang dan: ";
	mThisinh.SX_TStangdan_theoHoten();
	mThisinh.Xuat();
	
	getch();
	return 1;

}

//Cac phuong thuc lop Thisinh
Thisinh::Thisinh()
{
	strcpy(Maso,"");
	strcpy(Hoten,"");
	Diemlt=Diemth=Dtb=0;
	
}

void Thisinh::Nhap()
{
	cout<<"Ma so thi sinh: "; gets(Maso);
	cout<<"Ho ten thi sinh: "; gets(Hoten);
	cout<<"Diem ly thuyet: "; cin>>Diemlt;
	cout<<"Diem thuc hanh: "; cin>>Diemth;
	cin.ignore();
	TinhDTB();
	XepLoaiTSinh();
}

void Thisinh::Xuat()
{
	cout<<endl<<"Ma so: "<<Maso;
	cout<<" - Ho ten: "<<Hoten; 
	cout<<" - Diem LT : "<<Diemlt;
	cout<<" - Diem TH: "<<Diemth;
	cout<<" - DTB = "<<Dtb;
	cout<<" - Ket qua = "<<Ketqua;
}

void Thisinh::TinhDTB()
{
	Dtb= (Diemlt + Diemth*2)/3;
}


//Cac phuong thuc Lop MangThisinh
void MangThisinh::Nhap()
{
	cout <<"\nSo luong Thi sinh : "; cin >> n;
	cin.ignore();
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap Thi sinh thu "<<i+1<<" : "<<endl;
		mts[i].Nhap();
	}
}

void MangThisinh::Xuat()
{
	for (int i=0;i<n;i++)
	{
		mts[i].Xuat();
		cout << " ";
	}
}

void Thisinh::XepLoaiTSinh(){
	if(Dtb >= 5) strcpy(Ketqua,"Dat");
	else strcpy(Ketqua,"Khong dat");
}

char* Thisinh::getMs(){
	return Maso;
}

char* Thisinh::getHoten(){
	return Hoten;
}

float Thisinh::getDiemlt(){
	return Diemlt;
}

float Thisinh::getDiemth(){
	return Diemth;
}

float Thisinh::getDtb(){
	return Dtb;
}
int MangThisinh::Lk_TS_co_DTHvaDLT_LonHon7(){
	int ktr = 0;
	for(int i = 0; i<n; i++){
		if(mts[i].getDiemlt()>7 && mts[i].getDiemth()>7){
			ktr ++;
			mts[i].Xuat();
		}		
	}
	return ktr;
}

float MangThisinh::AVG_diemThsinh(){
	float sum=0;
	for(int i = 0; i<n; i++){
		sum += mts[i].getDiemlt() + mts[i].getDiemth() + mts[i].getDtb();
	}
	return sum/n;
}

void MangThisinh::TimMsTS(){
	char tms [25];
	int ktra = 0;
	cout<<endl<<"	>>Nhap MSTS can tim: ";
	gets(tms);
	for(int i = 0; i<n; i++){
		if(strcmp(tms,mts[i].getMs())==0){
			mts[i].Xuat();
			ktra++;
			break;
		}
	}
	if(ktra == 0) cout<<"	>>Khong tim thay msts can tim!";
}

void MangThisinh::SX_TStangdan_theoHoten(){
	for(int i = 0; i<n-1;i++)
		for(int j = i+1; j<n;j++)
			if(strcmp(mts[i].getHoten(),mts[j].getHoten())>0){
				Thisinh tam = mts[i];
				mts[i]=mts[j];
				mts[j] = tam;
			}
}


		
