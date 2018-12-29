#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
 
 using namespace std;
 
 struct NhanVien{
 	int MaNhanVien;
 	string HoLot;
 	string Ten;
 	int Luong;
 }
  NVFind, NVMax,NVMin;
  
  class ListNhanVien{
 	private:
 		int n;
 	public:
 	vector<NhanVien> ds;
 	void NhapDS();
 	void XuatDS();
 	NhanVien TimNV();
    NhanVien LuongMax();
    NhanVien LuongMin();
 	void SapXep();
 };
 int Chon;
 ListNhanVien DSNV;
 int TroVe;
 
void ShowMenu();
void LuaChon();
void NhapDS();
void XuatDS();
void LuuVaoFile(ListNhanVien DSNV);
void SapXep();
void LuuKQFile(NhanVien NVFind, NhanVien NVMax, ListNhanVien DSNV);
bool TroVeMenu();

void ShowMenu(){
 	cout<< "1.Nhap ma nhan vien"<< endl;
 	cout<< "2.Tim nhan vien"<< endl;
 	cout<< "3.Nhan vien co luong cao nhat va thap nhat"<< endl;
 	cout<< "4.Xap sep nhan vien"<< endl;
 	cout<< "5.Luu ket qua"<< endl;
 	cout<< "6.Thoat!!! "<<endl;
 }
  void LuaChon(){
 	cout<< "Moi Chon Yeu Cau"<< endl;
 	cin>> Chon;
 	switch(Chon){
 		case 1:
 			system("cls");
 			DSNV.NhapDS();
 			 LuuVaoFile(DSNV);
 			 if(TroVeMenu())
			   {
                system("cls");
                ShowMenu();
                LuaChon();
            	}
			else
			   {
           	    cout << "Nhap phim bat ky de thoat" << endl;
       			}
            break;
 		case 2:
            system("cls");
            NVFind = DSNV.TimNV();
            if(NVFind.MaNhanVien) {
                cout << "======================" << endl;
                cout << "Ma nhan vien: " << NVFind.MaNhanVien;
                cout << "\nHo Lot    : " << NVFind.HoLot << endl;
                cout << "\nTen       : " << NVFind.Ten << endl;
                cout << "\nLuong     : " << NVFind.Luong << endl;
                cout << "======================" << endl;
            } else {
                cout << "======================" << endl;
                cout << "Khong tim thay" << endl;
            }
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Nhap phim bat ky de thoat" << endl;
            }
            break;
            case 3:
            system("cls");
            NVMax = DSNV.LuongMax();
            if(NVMax.MaNhanVien) {
                // block empty list
                cout << "======================" << endl;
                cout << "Ma Nhan Vien: " << NVMax.MaNhanVien;
                cout << "\nHo Lot	 : " << NVMax.HoLot << endl;
                cout << "\nTen       : " << NVMax.Ten << endl;
                cout << "\nLuong     : " << NVMax.Luong << endl;
                cout << "======================" << endl;
            } else {
                cout << "======================" << endl;
                cout << "Khong tim thay" << endl;
            }
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Nhan phim bat ky de thoat" << endl;
            }
            break;
        case 4:
            	system("cls");
            	DSNV.SapXep();
            cout << "Sau khi sap xep" << endl;
            DSNV.XuatDS();
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Nhan phim bat ky de thoat" << endl;
            }
            break;
        case 5:
            LuuKQFile(NVFind, NVMax, DSNV);
            if(TroVeMenu()) {
                system("cls");
                ShowMenu();
                LuaChon();
            } else {
                cout << "Nhan phim bat ky de thoat" << endl;
            }
            break;
        case 6:
            	cout << "\t\t\t\t  Nhan phim bat ky de thoat" << endl;
            	break;
	 }
 }
  void ListNhanVien::NhapDS(){
 	cout<< "Nhap so luong nhan vien:  "; cin>>n;
 	ds.resize(n);
 	for(int i = 0; i < n; i++){
 		cout<< "--------------------"<< endl;
 		fflush(stdin);
 		cout<< "Nhap ma nhan vien: ";
		 fflush(stdin); cin>>ds[i].MaNhanVien;
 		cout<< "Nhap ho Lot: ";
		 fflush(stdin); getline(cin, ds[i].HoLot);
 		cout<< "Nhap ten nhan vien: "; 
		 fflush(stdin); getline(cin, ds[i].Ten);
		cout<< "Nhap luong nhan vien: "; 
		 cin>> ds[i].Luong; 
	 }
 }
 
 void ListNhanVien::XuatDS(){
 	for(int i=0; i < n; i++)
	 {	cout<<"------Nhan vien thu: "<< i;
 		cout<<"\n "<< ds[i].MaNhanVien;
 		cout<<"\n "<< ds[i].HoLot;
 		cout<<"\n "<< ds[i].Ten;
 		cout<<"\n "<< ds[i].Luong<< endl;
 	}
 }
 
 NhanVien ListNhanVien::TimNV() {
    int MaNhanVien;
    cout << "Nhap ma nv can find: > "; cin >> MaNhanVien;

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(ds[i].MaNhanVien == MaNhanVien) {
            return ds[i];
        }
    }
    return NVFind;
}
NhanVien ListNhanVien::LuongMax(){
    if(ds.size()) {
        int Max = ds[0].Luong;
        int key = 0;
        for(int i = 1; i < n; i++) {
            if(ds[i].Luong > Max) {
                Max = ds[i].Luong;
                key = i;
            }
        }
        return ds[key];
    } else {
        return NVMax;
    } 
} 

void ListNhanVien::SapXep() {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            if(ds[i].Ten.compare(ds[j].Ten) > 0) {
                // if ds[i].Ten > ds[i + 1].Ten
                // ASCII greater
                NhanVien tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }				
}

void LuuVaoFile(ListNhanVien DSNV) {
    ofstream fileDSNV;
    fileDSNV.open("dsnv.txt");
    int len = DSNV.ds.size();
    for(int i = 0; i < len; i++) {
        fileDSNV << "======================" << endl;
        fileDSNV << "MaNhanVien: " << DSNV.ds[i].MaNhanVien << endl;
        fileDSNV << "Ho Ten: " << DSNV.ds[i].HoLot << endl;
        fileDSNV << "Ten: " << DSNV.ds[i].Ten << endl;
        fileDSNV << "Luong: " << DSNV.ds[i].Luong << endl;
    }
    fileDSNV.close();
    cout << "\nWrited to dsnv.txt\n\n";
}

void LuuKQFile(NhanVien NVFind, NhanVien NVMax, ListNhanVien DSNV) {
    fstream KQ;
    KQ.open("output3.txt", ios::app);

    KQ << "Find employees result: " << endl;
    if(NVFind.MaNhanVien) {
        KQ << "Employee code: " << NVFind.MaNhanVien;
        KQ << "\nFirst name: " << NVFind.Ten << endl;
        KQ << "\nLast name: " << NVFind.HoLot << endl;
        KQ << "\nSalary: " << NVFind.Luong << endl;
        KQ << "======================" << endl;
    } else {
        KQ << "Not found\n\n";
    }

    KQ << "Max of salary result: " << endl;
    if(NVMax.MaNhanVien) {
        // block empty list
        KQ << "Employee code: " << NVMax.MaNhanVien;
        KQ << "\nFirst name: " << NVMax.Ten << endl;
        KQ << "\nLast name: " << NVMax.HoLot << endl;
        KQ << "\nSalary: " << NVMax.Luong << endl;
        KQ << "======================" << endl;
    } else {
        KQ << "Employees is empty\n\n";
    }
    KQ << "Employees after sorted: " << endl;
    int tmp = DSNV.ds.size();
    if(tmp) {
        for(int i = 0; i < tmp; i++) {
            KQ << "======================" << endl;
            KQ << "Employee code: " << DSNV.ds[i].MaNhanVien;
            KQ << "\nFirst name: " << DSNV.ds[i].Ten << endl;
            KQ << "\nLast name: " << DSNV.ds[i].HoLot << endl;
            KQ << "\nSalary: " << DSNV.ds[i].Luong << endl;
        }
    } else {
        KQ << "Employees is empty\n\n";
    }

    KQ.close();
    cout << "\nWrited to output1.txt\n\n";
}

 bool TroVeMenu() {
    cout << "Enter 1 de tro ve Menu:> "; cin >> TroVe;

    if(TroVe == 1) {
        return true;
    } return false;
}
 
 int main() {
    ShowMenu();
    LuaChon();
}
