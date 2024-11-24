#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class SoPhuc
{
	private:
		float Thuc, Ao;
	public:
		SoPhuc(); // Constructor mac dinh
		SoPhuc(float R,float I);
		SoPhuc (const SoPhuc & Z); // Constructor sao chep
		SoPhuc (float R); // Constructor chuyen doi
		void Nhap();  //Nhap so phuc
		void Xuat(); // Hien thi so phuc

		
		// Cac tinh toan 
		SoPhuc operator + (SoPhuc Z);
		//SoPhuc operator - (SoPhuc Z);
		//SoPhuc operator * (SoPhuc Z);
		//SoPhuc operator / (SoPhuc Z);
		
		//Ham tinh toan 
		SoPhuc Cong(SoPhuc Z);
		//SoPhuc Tru(SoPhuc Z);
		//SoPhuc Nhan(SoPhuc Z);
		//SoPhuc Chia(SoPhuc Z);
		
		//int LonHon(SoPhuc Z);  
    	//int NhoHon(SoPhuc Z);  
	   	//int Bang(SoPhuc Z);  
		
		// Cac tinh toan so sanh
		////int operator == (SoPhuc Z);
		//int operator != (SoPhuc Z);
		//int operator > (SoPhuc Z);
		//int operator >= (SoPhuc Z);
		//int operator < (SoPhuc Z);
		//int operator <= (SoPhuc Z);
	
		float Module(); // Giá tri tuyet doi cua so phuc
		
		//Cac ham kiem tra
		//int ThuanAo();
		//int ThuanThuc();
		float getReal();
		
		
};

class MangSoPhuc
{
	private:
		SoPhuc a[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		
		//..cac phuong thuc cn lai
		void Lk_Module_Nho_Hon_1();
		bool Ktr_Real_lonhon_10();
		SoPhuc Sum_MangSoPhuc();
		float AVG_MangSoPhuc();
		void SX_Tangdan_MangSoPhuc_theo_Module();
		
};


int main()
{
	MangSoPhuc x;
	
	//Nhap danh sach
	cout<<"Nhap thong tin cac So phuc trong Mang: ";
	x.Nhap();
	cout<<"Thong tin cac So phuc trong Mang: ";
	x.Xuat();
	
	x.Lk_Module_Nho_Hon_1();
	bool kq_ktr_real_lonhon_10 = x.Ktr_Real_lonhon_10();
	if(kq_ktr_real_lonhon_10 == true) 
		cout<<endl<<">>Voi moi doi tuong trong mang ton tai phan thuc lon hon 10!";
	else cout<<endl<<">>Ton tai 1 hoac nhieu doi tuong trong mang ton tai phan thuc nho hon 10!";
	
	
	SoPhuc Sum_MangSP= x.Sum_MangSoPhuc();
	cout<<endl<<">>KQ tong cac so phuc trong mang: ",Sum_MangSP.Xuat();
	
	float KQ_AVGModule = x.AVG_MangSoPhuc();
	cout<<endl<<">>KQ trung binh cong module cac so phuc trong mang so phuc: "<<KQ_AVGModule;
	
	cout<<endl<<">>KQ sap xep cac so phuc tang dan theo module: "<<endl;
	x.SX_Tangdan_MangSoPhuc_theo_Module();
	x.Xuat();
	getch();
	return 1;

}


SoPhuc::SoPhuc()
{
	Thuc = 0.0;
	Ao = 0.0;
}

SoPhuc::SoPhuc(float R,float I)
{
	Thuc = R;
	Ao = I;
}

SoPhuc::SoPhuc(const SoPhuc & Z)  //Ham dung sao chep
{
	Thuc = Z.Thuc;
	Ao = Z.Ao;
}

SoPhuc::SoPhuc(float R) 
{
	Thuc = R;
	Ao = 0.0;
}

void SoPhuc::Nhap()
{
	cout<<"\n Nhap phan thuc "; cin>>Thuc;
	cout<<"\n Nhap phan ao "; cin>>Ao;

}


void SoPhuc::Xuat()
{
	cout<<"(" << Thuc << " + " << Ao << "i)";
}



/*
Cho hai so phuc z = a + bi và w = c + di.
Phep Cong:  z+w  = (a +c) + (b+d)i
Phep Tru:  z-w  = (a +c) - (b+d)i
Phep Nhan:  z.w  = (a * c - b * d) + (a * d + b * c)i
Phep Chia:  z/w   = [(a * c + b * d) / (c * c + d * d)] + (b * c - a * d)i
*/

SoPhuc SoPhuc::Cong(SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = Thuc + Z.Thuc;
	Tmp.Ao = Ao + Z.Ao;
	return Tmp;
}


float SoPhuc::Module()
{
	return sqrt(Thuc*Thuc+Ao*Ao);
}



//CAC PHUONG THUC THUOC LOP MangSoPhuc
void MangSoPhuc::Nhap()
{
	cout <<"\n Nhap n : "; cin >> n;
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"]: ";
		a[i].Nhap();
	}
}

void MangSoPhuc::Xuat()
{
	for (int i=0;i<n;i++)
	{
		a[i].Xuat();
		cout << " ";
	}
}

void MangSoPhuc::Lk_Module_Nho_Hon_1(){
	int count = 0;
	for (int i = 0; i<n; i++){
		if(a[i].Module()<1){
			cout<<endl<<">>Cac so phuc co module<1: ";
			a[i].Xuat();
			count ++;
		}
			
	}
	if(count == 0) cout<<"\n>>Khong ton tai so phuc co module<1!";
}

float SoPhuc::getReal(){
	return Thuc;
}
bool MangSoPhuc::Ktr_Real_lonhon_10(){
	int i;
	int count = 0;
	for(i = 0; i<n; i++){
		if(a[i].getReal() < 10)
			break;
		else count++;
	}
	if(count == n) return true;
	else return false;

}

SoPhuc MangSoPhuc::Sum_MangSoPhuc(){
	SoPhuc Sum = 0;
	for(int i = 0; i<n ; i++){
		Sum= Sum.Cong(a[i]);	
	}
	return Sum;
}

float MangSoPhuc::AVG_MangSoPhuc(){
	float SumModule = 0;
	float AVGModule;
	for(int i = 0; i<n; i++){
		SumModule += a[i].Module();
	}
	return  AVGModule = SumModule/n;
}

void MangSoPhuc::SX_Tangdan_MangSoPhuc_theo_Module(){
	SoPhuc tam;
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++)
			if(a[i].Module()>a[j].Module()){
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
	}
}


		
