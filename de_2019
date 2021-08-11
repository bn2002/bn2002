#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
typedef struct {
    char TenSV[20];
    float DiemQT, DiemCK, DiemTK;
    char DiemXL;
} DiemSV;
void nhapDiemSinhVien();
void danhSachDiem();
void sapXepSinhVienTheoDiem();
DiemSV bangDiemSV[40];
int soSinhVien = 0;

int main() {
    int method = 0;
    while(1)
    {
        printf("=======Chuong Trinh Quan Ly Diem Mon Hoc=======\n");
        printf("1.Nhap Diem\n");
        printf("2.In Bang Diem\n");
        printf("3.Chenh lech diem\n");
        printf("4.Sap xep\n");
        printf("5.Thoat chuong trinh\n");
        fflush(stdin);
        printf("Press(1, 2, 3, 4, 5) to choose: ");
        scanf("%d", &method);
        switch(method) 
        {
            case 1:
                nhapDiemSinhVien();
                break;
            case 2: 
                printf("Danh sach ket qua\n");
                danhSachDiem();
                break;
            case 3:
                chenhLechDiem();
                break;
            case 4:
                sapXepSinhVienTheoDiem();
                break;
            case 5:
                printf("Thoat chuong trinh");
                return 0;
                break;
            default:
                printf("Lựa chọn không hợp lệ\n");
                break;
        }
    }
}

void clearInput() {
    fflush(stdin);
}
void nhapDiem(float * diem) {
    while(1)
    {
        clearInput();
        scanf("%f", diem);
        if(*diem >= 0 && *diem <= 10)
        {
            break;
        }
        else
        {
            printf("\tDiem nam trong khoang tu 0 den 10.Vui long nhap lai: ");
        }
    }
}
char xepLoai(float DiemTK) {
    char diemChu;
    if(DiemTK < 4)
    {
        diemChu = 'F';
    }
    else if(DiemTK < 5.5)
    {
        diemChu = 'D';
    }
    else if(DiemTK < 7)
    {
        diemChu = 'C';
    }
    else if(DiemTK < 8.5)
    {
        diemChu = 'B';
    }
    else
    {
        diemChu = 'A';
    }

    return diemChu;
}
void inTieuDeBang() {
    printf("%-20s%-13s%-13s%-13s%-13s\n", "Ten SV", "Diem QT", "Diem CK", "Diem TK", "Xep loai");
}

void inBangDiem(DiemSV * ketQua) {
    printf("%-20s%-13.1f%-13.1f%-13.1f%-13.1c\n", ketQua->TenSV, ketQua->DiemQT, ketQua->DiemCK, ketQua->DiemTK, ketQua->DiemXL);
}
char * layTenSinhVien(char * hoTen) 
{
    int lastSpace;
    for(int i = 0; i < strlen(hoTen); i++)
	{
		if(hoTen[i] == ' ') lastSpace = i;
	}
    return hoTen + lastSpace + 1;
}

void nhapDiemSinhVien() {
    while(1)
    {
        printf("Nhap so sinh vien: ");
        clearInput();
        scanf("%d", &soSinhVien);
        if(soSinhVien > 40 || soSinhVien <= 0)
        {
            printf("So sinh vien phai nam trong khoang tu [0, 40].Vui long nhap lai\n");
        }
        else
        {
            break;
        }
    }
    char tmpTen[20];
    for (int i = 0; i < soSinhVien; i++)
    {
        printf("Nhap thong tin sinh vien thu: %d \n", i + 1);
        while(1)
        {
            printf("Ten sinh vien: ");
            clearInput();
            fgets(tmpTen, 20, stdin);
            tmpTen[strcspn(tmpTen, "\n")] = 0;
            if(strlen(tmpTen) > 0)
            {
                break;
            }
        }
        strcpy(bangDiemSV[i].TenSV, tmpTen);
        printf("Nhap diem qua trinh: ");
        nhapDiem(&bangDiemSV[i].DiemQT);
        printf("Nhap diem cuoi ky: ");
        nhapDiem(&bangDiemSV[i].DiemCK);
        bangDiemSV[i].DiemTK = 0.4*bangDiemSV[i].DiemQT + 0.6*bangDiemSV[i].DiemCK;
        bangDiemSV[i].DiemXL = xepLoai(bangDiemSV[i].DiemTK);
        if(bangDiemSV[i].DiemQT < 3 || bangDiemSV[i].DiemCK < 3) 
        {
            bangDiemSV[i].DiemXL = 'F';
        }

    }
    


}

void danhSachDiem() {
    inTieuDeBang();
    if(soSinhVien > 0)
    {
        for(int i = 0; i < soSinhVien; i++)
        {
            inBangDiem(&bangDiemSV[i]);
        }
    }
    else
    {
        printf("Chua co du lieu diem sinh vien\n");
    }
  
}

void chenhLechDiem() {
    int L;
    while(1)
    {
        printf("Nhap so L: ");
        clearInput();
        scanf("%d", &L);
        if(L < 2 || L > 5)
        {
            printf("L nam trong khoang [2, 5] \n");
        }
        else
        {
            break;
        }
    }
    float chenhLech;
    printf("Danh sach sinh vien chenh lech diem cuoi ki va giua ki lon hon %d \n", L);
    inTieuDeBang();
    for(int i = 0; i < soSinhVien; i++)
    {
        chenhLech = fabs(bangDiemSV[i].DiemQT - bangDiemSV[i].DiemCK);
        if(chenhLech >= (float)L)
        {
            inBangDiem(&bangDiemSV[i]);
        }
    }
}

void sapXepSinhVienTheoTen() {
    char ten[30];
    for(int i = 0; i < soSinhVien; i++)
    {
        for(int j = i + 1; j < soSinhVien; j++)
        {
            if(strcmp(layTenSinhVien(bangDiemSV[i].TenSV), layTenSinhVien(bangDiemSV[j].TenSV)) > 0)
            {
                DiemSV tmp;
                tmp = bangDiemSV[j];
                bangDiemSV[j] = bangDiemSV[i];
                bangDiemSV[i] = tmp;
            }
        }
    }
}

void sapXepSinhVienTheoDiem() {
    sapXepSinhVienTheoTen();
    for(int i = 0; i < soSinhVien; i++)
    {
        for(int j = i + 1; j < soSinhVien; j++)
        {
            if(bangDiemSV[i].DiemTK < bangDiemSV[i].DiemTK)
            {
                DiemSV tmp;
                tmp = bangDiemSV[i];
                bangDiemSV[i] = bangDiemSV[j];
                bangDiemSV[j] = tmp;
            }
        }
    }
    inTieuDeBang();
    for(int i = 0; i < soSinhVien; i++)
    {
       inBangDiem(&bangDiemSV[i]);
    }

}
