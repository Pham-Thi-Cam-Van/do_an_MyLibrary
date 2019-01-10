#ifndef __MYLIBRARY_H__
#define __MYLIBRARY_H__
#include<iostream>
#include <iomanip>
#include<string>
#include<time.h>
#include<math.h>
#include<fstream>
#include<vector>
#define fileSach "ThuVienSach.txt"
#define fileDG "DSDocGia.txt"
using namespace std;

class TIME
{
private:
	int ng, th, na;
public:
	TIME();
	friend istream& operator>>(istream& inDev,TIME& tg);
	friend ostream& operator<<(ostream& outDev, const TIME& tg);
	int layNam();
	int layNgay();
	int layThang();
	void ganNam(int);
	void ganNgay(int);
	void ganThang(int);
	bool namNhuan(int);
	int ngayTrongThang(int);
	int ngayTrongNam(int);
	int ngayTuDau();
	int ngayDenCuoi();
	int tinhKhoangTgian(TIME);
};
class SACH
{
private:
	string maSach; 
	string ISBN;
	string tenSach;
	string tacGia;
	string NXB;
	string giaSach;
	string loaiSach;
	int soCuon;
public:
	void nhapSach();
	void xuatSach();
	void nhapTTMuon();
	string layMaSach();
	string layTacGia();
	string layTenSach();
	string layLoaiSach();
	string layISBN();
	string layNXB();
	string layGiaSach();
	int laySoCuon();
	void ganSoCuon(int);
	void ganNXB(string);
	void ganISBN(string);
	void ganLoaiSach(string);
	void ganMaSach(string);
	void ganTenSach(string);
	void ganTacGia(string);
	void ganGiaSach(string);
	void suaSach();
	SACH operator=(const SACH&);
};
class THUVIENSACH
{
private:
	vector<SACH> dsSach;
public:
	void nhapSachThuVien();
	void themSach();
	void xoaSachThuVien();
	void timSach();
	void ghiFileSach();
	void docFileSach();
	void ghiSauThayDoi();
	void suaSachThuVien();
	void xoaListSach();
	bool tontai(string, string);
};
class PHIEUMUONTRA:public SACH
{
private:
	string maPhieu;
	TIME ngMuon;
	TIME ngTra;
public:
	void nhapPhieu();
	string layMaPhieu();
	TIME layNgayMuon();
	TIME layNgayTra();
	void ganMaPhieu(string);
	void ganNgayMuon(TIME);
	void ganNgayTra(TIME);
	int khoangNgay();
};
class DOCGIA:public PHIEUMUONTRA, THUVIENSACH
{
private:
	string tenDG;
	string truong;
	string mssv;
	int soLuongSachMuon;
	vector <SACH> sachMuon;
public:
	void nhapSachMuon();
	void nhapDocGia();
	void xuatDocGia();
	string laytenDG();
	string layTruong();
	string layMSSV();
	int laySoLuongSachMuon();
	void ganSoLuongSachMuon(int);
	void ganTenDG(string);
	void ganMSSV(string);
	void ganTruong(string);
	void suaDocGia();
	int tinhTienPhat(string);
	SACH layGanSachMuon(int);
	void pushSachMuon(SACH);
	void popSachMuon();
};
class DANHSACHDOCGIA: public THUVIENSACH
{
private:
	vector<DOCGIA> dsDG;
public:
	void xuatDocGiaQuaHan();
	void themDocGia();
	void timDocGia();
	void ghiFileDG();
	void ghiSauChinhSua();
	void docFileDG();
	void xoaListDG();
	void nhapDSDGBuoc1();
	void nhapDSDGBuoc2();
	void suaDSDocGia();
	void xoaDocGiaTrongDS();
};
void chuyen(string a, int &n);
void chuyenTGian(string a, TIME &tg);
void ganChuoi(string& a, char b[]);
void showMenu();
#endif