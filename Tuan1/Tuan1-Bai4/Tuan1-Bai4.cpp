#include <stdio.h>
#include <conio.h>
#include<iostream>
#include<fstream>
#include <vector>
int a[50];
using namespace std;
int dem=0, n, p, tam[50], kq[50][50], tong=0, k=0;

void DocFile(){
	ifstream f;
	f.open("T:\\input4.txt", ios::in);
	f>>n >>p;
	for(int i=0;i<n;i++){
		f>>a[i];
	}
	f.close();
}
void SoCachChon(){
	for(int i = 0;i<n;i++)
	{
		kq[dem][i] = tam[i];
	}
}
void QuayLui(int sum,int x) 
{
	for (int i=x;i<n;i++) 
	{
		if ((sum + a[i])<=p) 
		{
			sum =sum+a[i];
			tam[i]=1;
			if (sum==p) 
			{
				for (int i =0;i<n;i++) 
				{
					kq[dem][i]=tam[i];
				}
				dem =dem+1;
			}
			else {
				QuayLui(sum,i+1);
			}
				sum =sum-a[i];
				tam[i] = 0;
		}
	}
}

void CheckGiaTri(int tong, int k) {
	for (int i = k; i < n; i++) {
		if ((tong + a[i]) <= p) {
			tong = tong + a[i];
			tam[i] = 1;
			if (tong == p) {
				SoCachChon();
				dem++;
			}
			else {
				CheckGiaTri(tong, i + 1);
			}
			tong = tong - a[i];
			tam[i] = 0;
		}
	}
}

void Xuat()
{
	for (int i=0;i<dem;i++) 
	{
		for (int j=0;j<n;j++) 
		{
			cout<<kq[i][j]<<" ";
		}
			cout<<endl;
	}
}

void GhiFile(){
	ofstream f;
	f.open("T:\\output4.txt", ios::out);
	f <<"So cach lua chon qua la: "<< dem << endl;
	for (int i = 0; i < dem; i++) {
			for (int j = 0; j < n; j++) {
				f << kq[i][j] << " " ;
			}
	}
		CheckGiaTri(tong, k);
	if (dem == 0) {
		cout << "Khong Chon Duoc" << endl;
	}
	else {
		cout << dem << endl;
		Xuat();
	}
}

void DocFile();
void SoCachChon();
void CheckGiaTri();
void QuayLui();
void Xuat();
void GhiFile();

int main()
{
	DocFile();
	GhiFile();
	getch();
	return 0;
}
