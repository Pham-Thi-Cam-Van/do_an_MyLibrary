#include"myLibrary.h"

void main()
{
	THUVIENSACH tv;
	DANHSACHDOCGIA dg;
	int chon = 0;
	do
	{
		showMenu();
		scanf("%d", &chon);
		switch (chon)
		{
		case 0: break;
		case 1:
			tv.nhapSachThuVien();
			system("pause");
			break;
		case 2:
			tv.themSach();
			system("pause");
			break;
		case 3:
			tv.xoaSachThuVien();
			system("pause");
			break;
		case 4:
			tv.suaSachThuVien();
			system("pause");
			break;
		case 5:
			tv.timSach();
			system("pause");
			break;
		case 6:
			dg.nhapDSDGBuoc2();
			system("pause");
			break;
		case 7:
			dg.themDocGia();
			system("pause");
			break;
		case 8:
			dg.timDocGia();
			system("pause");
			break;
		case 9:
			dg.xuatDocGiaQuaHan();
			system("pause");
			break;
		case 10:
			dg.xoaDocGiaTrongDS();
			system("pause");
			break;
		case 11:
			dg.suaDSDocGia();
			system("pause");
			break;
		default:
			printf("Ban chon sai. Moi ban chon lai MENU!\n");
			system("pause");
			break;
		}
	} while (chon != 0);
}