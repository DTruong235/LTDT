#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>

using namespace std;

class NgayGD{
	private:
		int ngay,thang,nam;
	public:
		NgayGD();
		NgayGD(int d,int m,int y);
		virtual void Nhap();
		virtual void Xuat();
		int getNgay();
		int getThang();
		int getNam();
};


class QLGiaoDich:public NgayGD{
	private:
		char MaGd [6];
		float ThanhTien;
	public:
		QLGiaoDich();
		QLGiaoDich(char* maGd, float thanhTien);
		virtual void Nhap();
		virtual void Xuat();
		virtual void TinhTien()=0;
		float setThanhTien(float thanhTien);
		float getThanhTien();
		char* getMaGD();
};

class GiaoDichVang:public QLGiaoDich{
	private:
		int SoLuong;
		char LoaiVang[10];
		float DonGia;
	public:
		GiaoDichVang();
		GiaoDichVang(char* maGd,  float thanhTien,int soLuong,char* loaiVang,float donGia);
		void Nhap();
		void Xuat();
		void TinhTien();
};

class GiaoDichTienTe:public QLGiaoDich{
	private:
		float SoTien;
		float TyGia;
		char LoaiTT [10];
	public:
		GiaoDichTienTe();
		GiaoDichTienTe(char* maGd, float thanhTien,float soTien,float tyGia,char* loaiTT);
		void Nhap();
		void Xuat();
		void TinhTien();
};



int main(){
	int n = 0;
	QLGiaoDich *gd[100];
	char Loai,Chon;
	cout<<endl<<"Nhap thong tin Giao Dich"<<endl;
	cout<<setiosflags (ios::fixed)<<setprecision(3);
	do{
		cout<<"Chon giao dich Vang hay giao dich Tien Te (V/T)";
		cin>>Loai;
		Loai = toupper(Loai);
		if(Loai == 'V')
		{
			gd[n] = new GiaoDichVang;
			gd[n]->Nhap();
		}
			
		else
		{
			gd[n] = new GiaoDichTienTe;
			gd[n]->Nhap();
		}
			
		n++;
		
		cout<<"Tiep tuc? (C/K)";
		cin>>Chon;
		Chon = toupper(Chon);
		
		if((n>100) || Chon == 'K')
			break;
		
	}while(1);
	int select;
	do{
		
	
	cout<<endl<<"Bang Chuc Nang"<<endl;
	cout<<"1. Xuat thong tin DS Ql GD"<<endl;
	cout<<"2. Nhung giao dich tu 10/09 den 20/9/2024"<<endl;
	cout<<"3. Trung binh cong thanh tien cua cac giao dich trong thang 11/2024"<<endl;
	cout<<"4. Tong so tien giao dich trong qui II nam 2024"<<endl;
	cout<<"5. Nhung giao dich co thanh tien lon so tien can  so sanh (nhap tu ban phim)"<<endl;
	cout<<"6. Sap xep danh sach tang theo ma giao dich"<<endl;
	cout<<"7. Sap xep danh sach tang theo ngay giao dich"<<endl;
	cout<<"8. Thang co so lan giao dich nhieu nhat"<<endl;
	cout<<"0. Thoat";
	
		cout<<endl<<"Nhap chuc nang: ";
		cin>>select;
		cout<<endl;
	switch(select){
		case 1:{
			for(int i = 0; i<n; i++)
			gd[i]->Xuat();	
			break;
		}
		case 2:{
			int flag = 0;
			for(int i = 0; i<n ;i++){
				if(((gd[i]->getNgay()>10)&&(gd[i]->getThang()==9)&&(gd[i]->getNam()==2024)) ||((gd[i]->getNgay()<20)&&(gd[i]->getThang()==9)&&(gd[i]->getNam()==2024)))
					{
						gd[i]->Xuat();
						flag++;	
					}
			}
			if(flag==0) cout<<endl<<"Khong co giao dich nao tu ngay 10/9 den 20/9/2024!";
			break;
		}
		case 3:{
			float tongThanhTien=0;
			float avgThanhTien=0;
			int flag = 0;
			for(int i = 0; i<n; i++)
				if((gd[i]->getThang()==11)&&(gd[i]->getNam()==2024))
				{
					tongThanhTien+=gd[i]->getThanhTien();
					flag++;
				}
			avgThanhTien = tongThanhTien/flag;
			if(flag != 0) cout<<endl<<"Trung binh cong thanh tien cua cac giao dich thang 11/2024: "<<avgThanhTien;
			else cout<<endl<<"Khong co giao dich trong thang 11 nam 2024";
			break;
		}
		case 4:{
			float tongThanhTien=0;
			for(int i = 0; i<n; i++)
				if((gd[i]->getThang()>4)&&(gd[i]->getNam()==2024))
					if((gd[i]->getThang()<6)&&(gd[i]->getNam()==2024))
						tongThanhTien+=gd[i]->getThanhTien();
			cout<<endl<<"Tong so tien giao dich trong qui II nam 2024: "<<tongThanhTien;
			break;
		}
		case 5:{
			float SotiencanSoSanh = 0;
			int flag = 0;
			cout<<endl<<"Nhap so tien can so sanh: "; cin>>SotiencanSoSanh;
				for(int i = 0; i<n; i++)
					if(gd[i]->getThanhTien()>SotiencanSoSanh){
						gd[i]->Xuat();
						flag++;
					}
			if(flag==0) cout<<endl<<"Khong co giao dich nao lon hon so tien can so sanh!";			
			break;
		}
		case 7:{
			for(int i = 0; i<n-1;i++)
				for(int j = i+1; j<n;j++)
					if( ( (gd[i]->getNam()) > (gd[j]->getNam()) ))
					{
							QLGiaoDich *gdtam = gd[i];
								gd[i]=gd[j];
								gd[j]=gdtam;
					}
					else if (( (gd[i]->getNam()) == (gd[j]->getNam()) )){
						
						if (( (gd[i]->getThang()) ) > (gd[j]->getThang()))
						{
								QLGiaoDich *gdtam = gd[i];
								gd[i]=gd[j];
								gd[j]=gdtam;
						}
						else if ( (gd[i]->getThang()) == (gd[j]->getThang())){
					
							if((gd[i]->getNgay()) > (gd[j]->getNgay()))
							{
								QLGiaoDich *gdtam = gd[i];
								gd[i]=gd[j];
								gd[j]=gdtam;
							}
						}
					}
			for(int i = 0; i<n;i++)
				gd[i]->Xuat();		
			break;
		}
		
		case 6:{
			for(int i = 0; i<n-1;i++)
				for(int j = i+1; j<n;j++)
					if(strcmp(gd[i]->getMaGD(),gd[j]->getMaGD())>0){
						QLGiaoDich *gdtam = gd[i];
						gd[i]=gd[j];
						gd[j]=gdtam;
					}
			for(int i = 0; i<n;i++)
				gd[i]->Xuat();	
			break;
		}
		
		case 8:{
			int count[11] = {0,0,0,0,0,0,0,0,0,0,0};
			int flag = 0;
			for(int i =0; i<n;i++)
				if(gd[i]->getNam() ==2024)
					for(int j = 1; j <12; j++)
						if(gd[i]->getThang() == j){
							count[j]++;
							flag++;	
						}
							
			int max = count[1];
			for(int i = 1; i<12;i++)
				if(max<count[i])
					max = i;
			if(flag != 0 ) cout<<endl<<"Thang co so giao dich nhieu nhat trong nam 2024: "<<max;
			else cout<<endl<<"Khong co giao dich trong nam 2024!";
			break;
		}
		
		case 0:{
			break;
		}
		
	}
}while(select != 0);
	
}

//QL Giao Dich
QLGiaoDich::QLGiaoDich(){
	strcpy(this->MaGd," ");
	this->ThanhTien = 0;	
} 

QLGiaoDich::QLGiaoDich(char* maGd,  float thanhTien){
	strcpy(this->MaGd,maGd);
	this->ThanhTien=thanhTien;
}

void QLGiaoDich::Nhap(){
	cout<<"MaGD: "; cin>>MaGd;
	cin.ignore();
	NgayGD::Nhap();
	TinhTien();
}

float QLGiaoDich::setThanhTien(float thanhTien){
	this->ThanhTien = thanhTien;
}

void QLGiaoDich::Xuat(){
	cout<<"MaGD: "<<MaGd;
	NgayGD::Xuat();
	cout<<", ThanhTien: "<<ThanhTien;
}

float QLGiaoDich::getThanhTien()
{
	return ThanhTien;
}

char* QLGiaoDich::getMaGD(){
	return MaGd;
}
//Giao Dich Vang
GiaoDichVang::GiaoDichVang():QLGiaoDich(){
	this->SoLuong = 0;
	strcpy(this->LoaiVang," ");
	this->DonGia = 0;
}  

GiaoDichVang::GiaoDichVang(char* maGd, float thanhTien,int soLuong,char* loaiVang,float donGia):QLGiaoDich(maGd,thanhTien){
	this->SoLuong = soLuong;
	strcpy(this->LoaiVang,loaiVang);
	this->DonGia = donGia;
}

void GiaoDichVang::Nhap(){
	QLGiaoDich::Nhap();
	cout<<"So luong: "; cin>>SoLuong;
	cout<<"Loai Vang: (PNJ/SJC/Khac)"; cin>>LoaiVang;
	cin.ignore();

	if((stricmp(LoaiVang,"PNJ")==0) || (stricmp(LoaiVang,"SJC")==0))
		DonGia = 9000.0;
	else DonGia = 8200.0;
	TinhTien();
} 

void GiaoDichVang::TinhTien(){
	float thanhTien = SoLuong * DonGia;
	setThanhTien(thanhTien);
}

void GiaoDichVang::Xuat(){
	QLGiaoDich::Xuat();
	cout<<", So luong: "<<SoLuong<<", Loai Vang: "<<LoaiVang<<", Don gia: "<<DonGia<<endl;
}

//Giao dich tien te

GiaoDichTienTe::GiaoDichTienTe():QLGiaoDich(){
	this->SoTien = 0;
	this->TyGia = 0;
	strcpy(this->LoaiTT," ");
}

GiaoDichTienTe::GiaoDichTienTe(char* maGd, float thanhTien,float soTien,float tyGia,char* loaiTT):QLGiaoDich(maGd,thanhTien){
	this->SoTien = soTien;
	this->TyGia = tyGia;
	strcpy(this->LoaiTT,loaiTT);
}

void GiaoDichTienTe::Nhap(){
	QLGiaoDich::Nhap();
	cout<<"So tien: "; cin>>SoTien;

	cout<<"Loai Tien te: "; cin>>(LoaiTT);
	cin.ignore();

	if(stricmp(LoaiTT,"Euro")==0)
		TyGia = 25;
	else if(stricmp(LoaiTT,"USD")==0)
			TyGia = 30;
		else TyGia = 0;	
	TinhTien();

}


void GiaoDichTienTe::TinhTien(){
	float thanhTien;
	if((stricmp(LoaiTT,"Euro")==0) || (stricmp(LoaiTT,"USD")==0))
		thanhTien = SoTien * TyGia;
	else thanhTien = SoTien;	
	setThanhTien(thanhTien);
}

void GiaoDichTienTe::Xuat(){
	QLGiaoDich::Xuat();
	cout<<", So tien: "<<SoTien<<", Ty Gia: "<<TyGia<<", Loai Tien te: "<<LoaiTT<<endl;
}

// Ngay

NgayGD::NgayGD(){
	this->ngay = 0;
	this->thang= 0;
	this->nam= 0;
}

NgayGD::NgayGD(int d,int m,int y){
	this->ngay = d;
	this->thang= m;
	this->nam= y;
}

void NgayGD::Nhap(){
	do{
		cout<<"Ngay: "; cin>>ngay;
	}while((ngay<1)||(ngay>31));
	
	do{
		cout<<"Thang: ";cin>>thang;	
	}while((thang<1)||thang>12);
	
	do{
		cout<<"Nam: "; cin>>nam;
	}while(nam<2000);
	
}

void NgayGD::Xuat(){
	cout<<", Ngay Gd: Ngay: "<<ngay<<", Thang: "<<thang<<", Nam: "<<nam;
}

int NgayGD::getNgay(){
	return ngay;
}

int NgayGD::getThang(){
	return thang;
}

int NgayGD::getNam(){
	return nam;
}
