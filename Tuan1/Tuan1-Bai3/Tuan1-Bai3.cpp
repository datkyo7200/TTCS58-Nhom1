#include <conio.h>
#include <iomanip>
#include <string.h>
#include<fstream>
#include <iostream>
#define MAX 50
 using namespace std;
 struct Nhanvien{
 	int Manhanvien;
 	string HoLot;
 	string Ten;
 	int Luong;
 };
Nhanvien a[MAX];
int n;
int ds;
int Maxi=0,Mini=0;
int Chon;


void DocttNV()
{
	
	ifstream file;
	file.open("input3.txt", ios::in);
	file>>n;
	for(int i=1;i<=n;i++)
	{
		file>>a[i].Manhanvien;
		file>>a[i].HoLot;
		file>>a[i].Ten;
		file>>a[i].Luong;
	}

   
}

 NhapMaNV()
{
	
	cout<<"Nhap ma nhan vien can kiem tra: ";
	cin>>ds;
	for(int i=1;i<=n;i++) if(a[i].Manhanvien==ds)
		{
			cout<<setw(10)<<a[i].Manhanvien<<setw(10)<<a[i].HoLot<<setw(10)<<a[i].Ten<<setw(10)<<a[i].Luong<<endl;
		}
}
void SapXepNV()
{
	Nhanvien v;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i].Ten.compare(a[j].Ten)==0)
			{
			
				if(a[i].HoLot.compare(a[j].HoLot)>0)
					{
						v=a[i];
						a[i]=a[j];
						a[j]=v;
					
					}
			}
			 else if(a[i].Ten.compare(a[j].Ten)>0)
					{
						v=a[i];
						a[i]=a[j];
						a[j]=v;
					
					}
				
		}
			

}
void ghi()
{
	ofstream file;
	file.open("output3.txt", ios::out);
	file<<"Thong tin Nhan vien can kiem tra:\n";
	for(int i=1;i<=n;i++) if(a[i].Manhanvien==ds)
		{
			file<<setw(10)<<a[i].Manhanvien<<setw(10)<<a[i].HoLot<<setw(10)<<a[i].Ten<<setw(10)<<a[i].Luong<<endl;
		}
	file<<"Ket qua sau khi sap xep:\n";
	file<<setw(10)<<"MaNV"<<setw(10)<<"Holot"<<setw(10)<<"Tennv"<<setw(10)<<"Luongnv"<<endl;
			for(int i=1;i<=n;i++)
	{
		file<<setw(10)<<a[i].Manhanvien;
		file<<setw(10)<<a[i].HoLot;
		file<<setw(10)<<a[i].Ten;
		file<<setw(10)<<a[i].Luong;
		file<<endl;
	}
	
}

void ShowMenu();		
void LuaChon();		
int ChonMenu();

void ShowMenu(){
	cout<<"Phan Thanh Dat 58131284\n\n\n";
 	cout<< "1.Doc tt nhan vien"<< endl;
 	cout<< "2.Nhap ma va hien thi nhan vien"<< endl;
 	cout<< "3.Nhan vien co luong cao nhat va thap nhat"<< endl;
 	cout<< "4.Xap sep nhan vien"<< endl;
 	cout<< "5.Luu ket qua"<< endl;
    cout<< "6.Exit !!!\n";
	cout<<"=============================================\n";
 }
 
int ChonMenu()
{
	int n=0;
	cout<<"\n\nHay nhan chon yeu cau:";
	cin>>n;
	if(n > 0 || n < 6) return n;
		else return ChonMenu();
}
void LuaChon(){
 	
	int chon;
	chon=ChonMenu();
	switch(chon)
	{
		case 1:
			cout<<"1. Doc thong tin nhan vien tu file  input3.txt\n";
			DocttNV();
			break;
		case 2:
			cout<<"2. Nhap ma nhan vien va hien thi thong tin nhan vien \n"; 
			NhapMaNV();
			break;
		case 3:
			cout<<"3. Nhan vien co luong cao nhat thap nhat \n";
			//luongnv();
			break;
		case 4:
			cout<<"4. Sap xep nhan vien tang dan theo ten\n";
			SapXepNV();
			break;
		case 5:
			cout<<"5.Ghi tat ca vao file output3.txt!!\n";
			ghi();
			break;
		case 6:
			cout<<" Nhap phim bat ky de thoat!!!\n\n\n";
			exit(1);
			break;		
	}
}

 int main() {
 	
    ShowMenu();
	while(1)
	{
		LuaChon();
	}

	getch();
}
