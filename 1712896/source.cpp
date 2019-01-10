#include"myLibrary.h"

TIME::TIME()
{
	ng = 0; th = 0; na = 0;
}
istream& operator>>(istream& inDev,TIME& tg)
{
	cout << "(ngay/thang/nam)" << endl;
	inDev >> tg.ng;
	inDev >> tg.th;
	inDev >> tg.na;
	return inDev;
}
ostream& operator<<(ostream& outDev, const TIME& tg)
{
	outDev << tg.ng << "/" << tg.th << "/" << tg.na;
	return outDev;
}
int TIME::layNam()
{
	return na;
}
bool TIME::namNhuan(int nam)
{
	return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
void TIME::ganNam(int n)
{
	na = n;
}
void TIME::ganNgay(int n)
{
	ng = n;
}
void TIME::ganThang(int n)
{
	th = n;
}
int TIME::layNgay()
{
	return ng;
}
int TIME::layThang()
{
	return th;
}
int TIME::ngayTrongThang(int thang)
{
	if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
		return 30;
	if (thang == 2){
		if (namNhuan(na)) return 29;
		else return 28;
	}
	return 31;
}
int TIME::ngayTrongNam(int n)
{
	if (namNhuan(n)) return 366;
	return 365;
}
int TIME::ngayTuDau()
{
	int sum = 0;
	for (int i = 1; i < th; i++)
		sum += ngayTrongThang(i);
	sum += ng;
	return sum;
}
int TIME::ngayDenCuoi()
{
	return ngayTrongNam(na) - ngayTuDau();
}
int TIME::tinhKhoangTgian(TIME tg)
{
	int sum = 0;
	int nam = tg.na - na;
	if (nam == 0)
		sum = tg.ngayTuDau() - ngayTuDau();
		//sum = abs(ng - tg.ng - ngayTrongThang(th)*(abs(th - tg.th)));
	else{
		sum = ngayDenCuoi() + tg.ngayTuDau();
		for (int i = na + 1; i < tg.na; i++)
			sum += ngayTrongNam(i);
	}
	return sum;
}
void SACH::nhapSach()
{
	cout << "Nhap maSach: ";
	fflush(stdin);
	getline(cin,maSach);
	cout << "Nhap ISBN: ";
	getline(cin, ISBN);
	cout << "Nhap tenSach: ";
	getline(cin, tenSach);
	cout << "Nhap tacGia: ";
	getline(cin, tacGia);
	cout << "Nhap NXB: ";
	getline(cin, NXB);
	cout << "Nhap giaSach: ";
	getline(cin, giaSach);
	cout << "Nhap loaiSach(tieng viet/ngoai van): ";
	getline(cin, loaiSach);
	cout << "Nhap soCuon co trong thu vien: ";
	cin >> soCuon;
}
void SACH::xuatSach()
{
	cout << " - maSach: " << maSach << endl;
	cout << " - ISBN: " << ISBN << endl;
	cout << " - tenSach: " << tenSach << endl;
	cout << " - tacGia: " << tacGia << endl;
	cout << " - NXB: " << NXB << endl;
	cout << " - giaSach: " << giaSach << endl;
	cout << " - loaiSach: " << loaiSach << endl;
	cout << " - soCuon thu vien hien con: " << soCuon << endl;
}
void SACH::nhapTTMuon()
{
	cout << "Nhap tenSach: ";
	fflush(stdin);
	getline(cin, tenSach);
	cout << "Nhap maSach: ";
	getline(cin, maSach);
	cout << "Nhap loai sach: ";
	getline(cin, loaiSach);
}
string SACH::layISBN()
{
	return ISBN;
}
string SACH::layNXB()
{
	return NXB;
}
string SACH::layGiaSach()
{
	return giaSach;
}
string SACH::layMaSach()
{
	return maSach;
}
string SACH::layTenSach()
{
	return tenSach;
}
string SACH::layLoaiSach()
{
	return loaiSach;
}
string SACH::layTacGia()
{
	return tacGia;
}
void SACH::ganISBN(string str)
{
	ISBN = str;
}
void SACH::ganNXB(string str)
{
	NXB = str;
}
void SACH::ganMaSach(string str)
{
	maSach = str;
}
void SACH::ganTenSach(string str)
{
	tenSach = str;
}
void SACH::ganTacGia(string str)
{
	tacGia = str;
}
void SACH::ganGiaSach(string str)
{
	giaSach = str;
}
void SACH::ganLoaiSach(string str)
{
	loaiSach = str;
}
int SACH::laySoCuon()
{
	return soCuon;
}
void SACH::ganSoCuon(int n)
{
	soCuon = n;
}

void SACH::suaSach()
{
	cout << "NHAP THONG TIN MOI:\n";
	cout << "Nhap maSach: ";
	fflush(stdin);
	getline(cin, tenSach);
	cout << "Nhap ISBN: ";
	getline(cin, ISBN);
	cout << "Nhap tenSach: ";
	getline(cin, tenSach);
	cout << "Nhap tacGia: ";
	getline(cin, tacGia);
	cout << "Nhap NXB: ";
	getline(cin, NXB);
	cout << "Nhap giaSach: ";
	getline(cin, giaSach);
	cout << "Nhap loaiSach(tieng viet/ngoai van): ";
	getline(cin, loaiSach);
	cout << "Nhap soCuon co trong thu vien: ";
	cin >> soCuon;
}
void DOCGIA::suaDocGia()
{
	string src;
	int n; SACH sa; TIME tgian;
	cout << "Nhap maPhieu moi: ";
	fflush(stdin);
	getline(cin, src);
	ganMaPhieu(src);
	cout << "Nhap ngMuon: ";
	cin >> tgian;
	ganNgayMuon(tgian);
	cout << "Nhap ngTra: ";
	cin >> tgian;
	ganNgayTra(tgian);
	nhapSachMuon();
}
SACH SACH::operator=(const SACH& sh)
{
	maSach = sh.maSach;
	ISBN = sh.ISBN;
	tenSach = sh.tenSach;
	tacGia = sh.tacGia;
	NXB = sh.NXB;
	giaSach = sh.giaSach;
	loaiSach = sh.loaiSach;
	soCuon = sh.soCuon;
	return *this;
}

void THUVIENSACH::nhapSachThuVien()
{
	int n;
	cout << "Nhap so tua sach trong thu vien: ";
	cin >> n;
	SACH sh;
	for (int i = 0; i < n; i++){
		cout << "SACH THU " << i + 1 << ":" << endl;
		sh.nhapSach();
		dsSach.push_back(sh);
	}
	ghiFileSach();
	xoaListSach();
}
void THUVIENSACH::xoaListSach()
{
	for (int i = 0; i < dsSach.size(); i++)
		dsSach.pop_back();
}
void DANHSACHDOCGIA::xoaListDG()
{
	for (int i = 0; i < dsDG.size(); i++)
		dsDG.pop_back();
}
void THUVIENSACH::themSach()
{
	SACH sh;
	cout << "Nhap thong tin sach can them: " << endl;
	sh.nhapSach();
	dsSach.push_back(sh);
	ghiFileSach();
}
void THUVIENSACH::xoaSachThuVien()
{
	docFileSach();
	string tuaSach, tg;
	cout << "Nhap tuaSach can xoa: ";
	fflush(stdin);
	getline(cin, tuaSach);
	cout << "Nhap tacGia sach: ";
	getline(cin, tg);
	int n = -1, i = 0;
	while (1){
		if (tuaSach == dsSach[i].layTenSach()&&tg==dsSach[i].layTacGia()){
			n = i;
			break;
		}
		i++;
		if (i == dsSach.size()) break;
	}
	if (n == -1) cout << "TUA SACH KHONG CO TRONG THU VIEN.\n";
	else{
		dsSach[n] = dsSach[dsSach.size() - 1];
		dsSach.pop_back();
		cout << "DA XOA SACH KHOI THU VIEN.\n";
	}
	ghiSauThayDoi();
}

void THUVIENSACH::timSach()
{
	docFileSach();
	string tuaSach, tgia;
	int i = 0;
	cout << "Nhap tua sach va tac gia sach can tim:" << endl;
	cout << "Nhap tuaSach: ";
	fflush(stdin);
	getline(cin, tuaSach);
	cout << "tgia: ";
	getline(cin, tgia);
	while(i!=dsSach.size()){
		if (tuaSach == dsSach[i].layTenSach() && tgia == dsSach[i].layTacGia())
			break;
		i++;
	}
	if (i == dsSach.size())
		cout << "\nKHONG CO SACH CAN TIM.\n";
	else{
		cout << "\nTHONG TIN SACH CAN TIM:\n";
		dsSach[i].xuatSach();
	}
}
void THUVIENSACH::suaSachThuVien()
{
	docFileSach();
	string ten, tg; int i = 0;
	cout << "\nNhap ten sach can doi thong tin: ";
	fflush(stdin);
	getline(cin, ten);
	cout << "Tac gia: ";
	getline(cin, tg);
	while (i != dsSach.size()){
		if (ten == dsSach[i].layTenSach() && tg == dsSach[i].layTacGia())
			break;
		i++;
	}
	if (i == dsSach.size())
		cout << "\nKHONG CO SACH CAN SUA.\n";
	else{
		dsSach[i].suaSach();
		ghiSauThayDoi();
		cout << "DA THAY DOI THONG TIN SACH.\n";
	}
}
void PHIEUMUONTRA::nhapPhieu()
{
	cout << "Nhap maPhieu: ";
	fflush(stdin);
	getline(cin, maPhieu);
	cout << "Nhap ngMuon: ";
	cin >> ngMuon;
	cout << "Nhap ngTra: ";
	cin >> ngTra;
}
string PHIEUMUONTRA::layMaPhieu()
{
	return maPhieu;
}
TIME PHIEUMUONTRA::layNgayMuon()
{
	return ngMuon;
}
TIME PHIEUMUONTRA::layNgayTra()
{
	return ngTra;
}
void PHIEUMUONTRA::ganMaPhieu(string str)
{
	maPhieu = str;
}
void PHIEUMUONTRA::ganNgayMuon(TIME tg)
{
	ngMuon = tg;
}
void PHIEUMUONTRA::ganNgayTra(TIME tg)
{
	ngTra = tg;
}
int PHIEUMUONTRA::khoangNgay()
{
	return abs(ngMuon.tinhKhoangTgian(ngTra));
}
string DOCGIA::layMSSV()
{
	return mssv;
}
void DOCGIA::ganTenDG(string str)
{
	tenDG = str;
}
void DOCGIA::ganMSSV(string str)
{
	mssv = str;
}
void DOCGIA::ganTruong(string str)
{
	truong = str;
}
void DOCGIA::ganSoLuongSachMuon(int sl)
{
	soLuongSachMuon = sl;
}
void DOCGIA::nhapSachMuon()
{
	int luongSach;
	cout << "Nhap so luong sach muon:";
	cin >> luongSach;
	ganSoLuongSachMuon(luongSach);
	SACH sh;
	for (int i = 0; i < luongSach; i++){
		cout << "SACH THU " << i + 1 << ":" << endl;
		sh.nhapTTMuon();
		sachMuon.push_back(sh);
	}
}
void DOCGIA::nhapDocGia()
{
	cout << "Nhap tenDG: ";
	fflush(stdin);
	getline(cin, tenDG);
	cout << "Nhap truong: ";
	getline(cin, truong);
	cout << "Nhap mssv: ";
	getline(cin, mssv);
	nhapPhieu();
	nhapSachMuon();
}
void DOCGIA::xuatDocGia()
{
	cout << setw(30) << left<< tenDG;
	cout << setw(30) << left<< truong;
	cout << setw(10) << right << mssv;
}
string DOCGIA::laytenDG()
{
	return tenDG;
}
string DOCGIA::layTruong()
{
	return truong;
}
int DOCGIA::laySoLuongSachMuon()
{
	return soLuongSachMuon;
}
void DANHSACHDOCGIA::nhapDSDGBuoc1()
{
	DOCGIA sh;
	sh.nhapDocGia();
	dsDG.push_back(sh);
	ghiFileDG();
	xoaListDG();
}
void DANHSACHDOCGIA::nhapDSDGBuoc2()
{
	int n;
	cout << "Nhap so luong doc gia muon sach: ";
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "DOC GIA THU " << i + 1 << ":" << endl;
		nhapDSDGBuoc1();
	}
}
void DANHSACHDOCGIA::themDocGia()
{
	DOCGIA sh;
	cout << "Nhap thong tin doc gia can them: " << endl;
	sh.nhapDocGia();
	dsDG.push_back(sh);
	ghiFileDG();
}
void DANHSACHDOCGIA::timDocGia()
{
	string ten, trg, msv;
	docFileDG();
	int i = 0;
	cout << "\nNhap thong tin doc gia can tim:" << endl;
	cout << "Nhap ten: ";
	fflush(stdin);
	getline(cin, ten);
	cout << "Nhap truong: ";
	getline(cin, trg);
	cout << "Nhap mssv: ";
	getline(cin, msv);
	while (i != dsDG.size()){
		if (ten == dsDG[i].laytenDG() && trg == dsDG[i].layTruong()&&msv==dsDG[i].layMSSV())
			break;
		i++;
	}
	if (i == dsDG.size())
		cout << "\nKHONG CO DOC GIA CAN TIM.\n";
	else{
		cout << "\nTHONG TIN DOC GIA CAN TIM:\n";
		cout << setw(30) << left << "HOTEN";
		cout << setw(30) << left << "TRUONG";
		cout << setw(10) << right << "MSSV" << endl;
		dsDG[i].xuatDocGia();
		cout << endl;
	}
}
bool THUVIENSACH::tontai(string ten, string ma)
{
	docFileSach();
	int i = 0;
	while (i != dsSach.size()){
		if (dsSach[i].layTenSach() == ten&&dsSach[i].layMaSach() == ma)
			return true;
		i++;
	}
	return false;
}
int DOCGIA::tinhTienPhat(string loai)
{
	int tien = 0;
	if (loai == "tieng viet" || loai == "sach tieng viet")
		tien = 10000 * (khoangNgay() - 7);
	else tien = 20000 * (khoangNgay() - 7);
	return tien;
}
void DANHSACHDOCGIA::xuatDocGiaQuaHan()
{
	docFileDG();
	SACH sa;
	cout << "==DANH SACH DOC GIA QUA HAN==" << endl;
	cout << setw(30) << left << "HOTEN";
	cout << setw(30) << left << "TRUONG";
	cout << setw(10) << right << "MSSV";
	cout << setw(20) << right << "TIENPHAT";
	cout << setw(25) << right << "NGAY QUA HAN" << endl;
	int tienPhat = 0;
	for (int i = 0; i < dsDG.size(); i++){
		docFileDG();
		if (dsDG[i].khoangNgay()>7){
			for (int j = 0; j < dsDG[i].laySoLuongSachMuon(); j++){
				sa = dsDG[i].layGanSachMuon(j);
				if(tontai(sa.layTenSach(), sa.layMaSach()))
					tienPhat += dsDG[i].tinhTienPhat(sa.layLoaiSach());
			}
			if (tontai(sa.layTenSach(), sa.layMaSach())){
				dsDG[i].xuatDocGia();
				cout << setw(20) << right << tienPhat;
				cout << setw(25) << right << dsDG[i].khoangNgay()-7 << endl;
			}
			tienPhat = 0;
		}
		xoaListDG();
	}
}
void THUVIENSACH::docFileSach()
{
	fstream fp;
	SACH sh;
	int k;
	char temp[300];
	fp.open(fileSach, ios::in);
	fp.getline(temp, 300);
	while (!fp.eof()){
		fp.getline(temp, 300);
		sh.ganMaSach(temp);
		fp.getline(temp, 300);
		sh.ganISBN(temp);
		fp.getline(temp, 300);
		sh.ganTenSach(temp);
		fp.getline(temp, 300);
		sh.ganTacGia(temp);
		fp.getline(temp, 300);
		sh.ganNXB(temp);
		fp.getline(temp, 300);
		sh.ganGiaSach(temp);
		fp.getline(temp, 300);
		sh.ganLoaiSach(temp);
		fp.getline(temp, 300);
		chuyen(temp, k);
		sh.ganSoCuon(k);
		dsSach.push_back(sh);
	}
	fp.close();
}
void THUVIENSACH::ghiFileSach()
{
	fstream fp;
	int k;
	char temp[300];
	fp.open(fileSach, ios::app);
	for (int i = 0; i < dsSach.size(); i++){
		ganChuoi(dsSach[i].layMaSach(), temp);
		fp << endl << temp << endl;
		ganChuoi(dsSach[i].layISBN(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layTenSach(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layTacGia(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layNXB(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layGiaSach(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layLoaiSach(), temp);
		fp << temp << endl;
		fp << dsSach[i].laySoCuon();
	}
	fp.close();
}
SACH DOCGIA::layGanSachMuon(int n)
{
	return sachMuon[n];
}
void DOCGIA::pushSachMuon(SACH sh)
{
	sachMuon.push_back(sh);
}
void DANHSACHDOCGIA::docFileDG()
{
	fstream fp;
	DOCGIA dgia; TIME tg; SACH sh;
	int k, i = 0;
	char temp[300];
	fp.open(fileDG, ios::in);
	fp.getline(temp, 300);
	while (!fp.eof()){
		fp.getline(temp, 300);
		dgia.ganTenDG(temp);
		fp.getline(temp, 300);
		dgia.ganTruong(temp);
		fp.getline(temp, 300);
		dgia.ganMSSV(temp);
		fp.getline(temp, 300);
		dgia.ganMaPhieu(temp);
		fp.getline(temp, 300);
		chuyenTGian(temp, tg);
		dgia.ganNgayMuon(tg);
		fp.getline(temp, 300);
		chuyenTGian(temp, tg);
		dgia.ganNgayTra(tg);
		fp.getline(temp, 300);
		chuyen(temp, k);
		dgia.ganSoLuongSachMuon(k);
		for (int j = 0; j < k; j++){
			fp.getline(temp, 300);
			sh.ganTenSach(temp);
			fp.getline(temp, 300);
			sh.ganMaSach(temp);
			fp.getline(temp, 300);
			sh.ganLoaiSach(temp);
			dgia.pushSachMuon(sh);
		}
		dsDG.push_back(dgia);
		dgia.popSachMuon();
	}
	fp.close();
}
void DOCGIA::popSachMuon()
{
	for (int i = 0; i < laySoLuongSachMuon(); i++)
		sachMuon.pop_back();
}
void DANHSACHDOCGIA::ghiFileDG()
{
	SACH sh;
	fstream fp;
	char temp[300];
	TIME ng;
	fp.open(fileDG, ios::app);
	for (int i = 0; i < dsDG.size(); i++){
		ganChuoi(dsDG[i].laytenDG(), temp);
		fp << endl << temp << endl;
		ganChuoi(dsDG[i].layTruong(), temp);
		fp << temp << endl;
		ganChuoi(dsDG[i].layMSSV(), temp);
		fp << temp << endl;
		ganChuoi(dsDG[i].layMaPhieu(), temp);
		fp << temp << endl;
		ng = dsDG[i].layNgayMuon();
		fp << ng << endl;
		ng = dsDG[i].layNgayTra();
		fp << ng << endl;
		fp << dsDG[i].laySoLuongSachMuon();
		for (int j = 0; j < dsDG[i].laySoLuongSachMuon(); j++){
			sh = dsDG[i].layGanSachMuon(j);
			ganChuoi(sh.layTenSach(), temp);
			fp << endl << temp << endl;
			ganChuoi(sh.layMaSach(), temp);
			fp << temp << endl;
			ganChuoi(sh.layLoaiSach(), temp);
			fp << temp;
		}
	}
	fp.close();
}
void THUVIENSACH::ghiSauThayDoi()
{
	fstream fp;
	int k;
	char temp[300];
	fp.open(fileSach, ios::out);
	for (int i = 0; i < dsSach.size(); i++){
		ganChuoi(dsSach[i].layMaSach(), temp);
		fp << endl << temp << endl;
		ganChuoi(dsSach[i].layISBN(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layTenSach(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layTacGia(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layNXB(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layGiaSach(), temp);
		fp << temp << endl;
		ganChuoi(dsSach[i].layLoaiSach(), temp);
		fp << temp << endl;
		fp << dsSach[i].laySoCuon();
	}
	fp.close();
}
void DANHSACHDOCGIA::xoaDocGiaTrongDS()
{
	string ten, trg;
	docFileDG();
	cout << "Nhap ten doc gia can xoa: ";
	fflush(stdin);
	getline(cin, ten);
	cout << "Nhap truong cua doc gia: ";
	getline(cin, trg);
	int n = -1, i = 0;
	while (1){
		if (ten == dsDG[i].laytenDG() && trg == dsDG[i].layTruong()){
			n = i;
			break;
		}
		i++;
		if (i == dsDG.size()) break;
	}
	if (n == -1) cout << "DOC GIA KHONG CO TRONG DANH SACH.\n";
	else{
		dsDG[i].popSachMuon();
		dsDG[n] = dsDG[dsDG.size() - 1];
		dsDG.pop_back();
		cout << "DA XOA DOC GIA KHOI DANH SACH.\n";
	}
	ghiSauChinhSua();
}
void DANHSACHDOCGIA::suaDSDocGia()
{
	docFileDG();
	string ten, tg; int i = 0;
	cout << "Nhap ten doc gia can doi thong tin: ";
	fflush(stdin);
	getline(cin, ten);
	cout << "Ma phieu: ";
	getline(cin, tg);
	while (i != dsDG.size()){
		if (ten == dsDG[i].laytenDG() && tg == dsDG[i].layMaPhieu())
			break;
		i++;
	}
	if (i == dsDG.size())
		cout << "\nKHONG CO DOC GIA CAN SUA.\n";
	else{
		dsDG[i].popSachMuon();
		dsDG[i].suaDocGia();
		ghiSauChinhSua();
		cout << "DA THAY DOI THONG TIN DOC GIA.\n";
	}
}
void DANHSACHDOCGIA::ghiSauChinhSua()
{
	fstream fp;
	char temp[300];
	TIME ng; SACH sh;
	fp.open(fileDG, ios::out);
	for (int i = 0; i < dsDG.size(); i++){
		ganChuoi(dsDG[i].laytenDG(), temp);
		fp << endl << temp << endl;
		ganChuoi(dsDG[i].layTruong(), temp);
		fp << temp << endl;
		ganChuoi(dsDG[i].layMSSV(), temp);
		fp << temp << endl;
		ganChuoi(dsDG[i].layMaPhieu(), temp);
		fp << temp << endl;
		ng = dsDG[i].layNgayMuon();
		fp << ng << endl;
		ng = dsDG[i].layNgayTra();
		fp << ng << endl;
		fp << dsDG[i].laySoLuongSachMuon();
		for (int j = 0; j < dsDG[i].laySoLuongSachMuon(); j++){
			sh = dsDG[i].layGanSachMuon(j);
			ganChuoi(sh.layTenSach(), temp);
			fp << endl << temp << endl;
			ganChuoi(sh.layMaSach(), temp);
			fp << temp << endl;
			ganChuoi(sh.layLoaiSach(), temp);
			fp << temp;
		}
	}
	fp.close();
}
void chuyen(string a, int &n)
{
	int r = 1; n = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		n += (a[i] - 48)*r;
		r = r * 10;
	}
}
void chuyenTGian(string str, TIME &tg)
{
	int i = 0, k = 0, n; char src[10];
	while (str[i] != '/'){
		src[i] = str[i];
		i++;
	}
	src[i] = '\0'; i++;
	chuyen(src, n); tg.ganNgay(n);
	while (str[i] != '/'){
		src[k] = str[i];
		i++;
		k++;
	}
	src[k] = '\0'; k = 0;
	chuyen(src, n);
	tg.ganThang(n);
	i++;
	while (str[i] != '\0'){
		src[k] = str[i];
		i++;
		k++;
	}
	src[k] = '\0';
	chuyen(src, n);
	tg.ganNam(n);
}
void ganChuoi(string& a, char b[])
{
	for (int i = 0; i < a.length(); i++)
		b[i] = a[i];
	b[a.length()] = '\0';
}
void showMenu()
{
	system("cls");
	printf("\t\t\t =================MENU=======================================\n");
	printf("\t\t\t |0. Thoat                                                  |\n");
	printf("\t\t\t |1. Nhap va them sach cho thu vien                         |\n");
	printf("\t\t\t |2. Them sach vao thu vien                                 |\n");
	printf("\t\t\t |3. Xoa sach khoi thu vien                                 |\n");
	printf("\t\t\t |4. Thay doi thong tin sach trong thu vien                 |\n");
	printf("\t\t\t |5. Tim kiem sach trong thu vien                           |\n");
	printf("\t\t\t |6. Nhap va them danh sach doc gia muon sach               |\n");
	printf("\t\t\t |7. Them doc gia                                           |\n");
	printf("\t\t\t |8. Tim kiem doc gia                                       |\n");
	printf("\t\t\t |9. Xuat doc gia qua han muon                              |\n");
	printf("\t\t\t |10. Xoa doc gia                                           |\n");
	printf("\t\t\t |11. Thay doi thong tin doc gia                            |\n");
	printf("\t\t\t ============================================================\n");
	printf("--> Chon lenh: ");
}