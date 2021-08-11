#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int boSungSV();
void danh_sach_sinh_vien_bao_ve_thanh_cong();
void sap_xep_sinh_vien_theo_ten();
typedef struct {
    char MSSV[6];
    char hoTen[31];
    float diem[5];
    float diemGK;
    float diemCK;
} thongTinSV;
thongTinSV danhSachSV[20];
int soSinhVien = 0;

void clearInput() 
{
    fflush(stdin);
}
int main() {
    // thongTinSV sinhVien1 = {"201", "Duy Doanh", {9, 9, {9, 9, 9}}};
    // printf("MSSV: %s - Ten SV: %s - diem HD: %d, diem PG: %d, diem HD1: %d, diem HD2: %d, diem HD3: %d", sinhVien1.MSSV, sinhVien1.hoTen, sinhVien1.diem.HD, sinhVien1.diem.PB, sinhVien1.diem.hoiDong[0], sinhVien1.diem.hoiDong[1], sinhVien1.diem.hoiDong[2]);
	int method = 0;
    while(1)
    {
        printf("=======Danh sách tính năng của chương trình=======\n");
        printf("1.Thêm/Bổ sung sinh viên\n");
        printf("2.Danh sách sinh viên bảo vệ thành công\n");
        printf("3.Sắp xếp theo tên sinh viên\n");
        printf("4.Thoát chương trình\n");
        fflush(stdin);
        printf("Nhập chức năng: ");
        scanf("%d", &method);
        switch(method) 
        {
            case 1:
                printf("Thêm/Bổ sung sinh viên\n");
                boSungSV();
                break;
            case 2: 
                danh_sach_sinh_vien_bao_ve_thanh_cong();
                break;
            case 3:
                printf("Sắp xếp theo tên sinh viên\n");
                sap_xep_sinh_vien_theo_ten();
                break;
            case 4:
                printf("Thoát chương trình\n");
                return 0;
                break;
            default:
                printf("Lựa chọn không hợp lệ\n");
                break;
        }
    }
	
}

float nhapDiem()
{
    float diem = 0;
    do {
        printf("\tNhập điểm nằm trong khoảng từ 0 đến 10: ");
        clearInput();
        scanf("%f", &diem);
    } while(diem < 0 || diem > 10);
    return diem;
}
bool kiemTraTrungMssv(const char *MSSV) 
{
    for(int i = 0; i < soSinhVien; i++)
    {
        if(strcmp(MSSV, danhSachSV[i].MSSV) == 0) return true;
    }
    return false;
}

bool kiemTraDiemLiet(const float * diem) 
{
    for(int i = 0; i < 5; i++, diem++)
    {
        if(*diem <= 5.5) return true;
    }

    return false;
}

bool kiemTraChenhLechDiem(const float * diem)
{
    float min = *diem;
    float max = *diem;
    for(int i = 0; i < 5; i++, diem++)
    {
        min = (min > *diem) ? *diem : min; 
        max = (max < *diem) ? *diem : max; 
    }

    if(max - min > 3)
    {
        return true;
    }

    return false;
}

bool kiemTraHoTen(const char * hoTen) 
{
    int lastSpace = 0;
    if(strlen(hoTen) < 1) {
        return false;
    } else if(hoTen[strlen(hoTen) - 1] == ' ' || hoTen[0] == ' ') {
        return false;
    } else {
        for(int i = 0; i < strlen(hoTen); i++) {
            if(hoTen[i] == ' ') lastSpace = i;
        }

        if(lastSpace == 0) return false;
    }
    return true;
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
void inDanhSachSinhVien(const thongTinSV * sinhVien) 
{
     printf("%10s %20s  %6.1f  %10.1f  %9.1f  %8.1f  %10.1f  %8.1f  %10.1f\n", sinhVien->MSSV, sinhVien->hoTen, sinhVien->diem[0], sinhVien->diem[1], sinhVien->diem[2], sinhVien->diem[3], sinhVien->diem[4], sinhVien->diemGK, sinhVien->diemCK);
}

int boSungSV() 
{
    int count = 0;
    do {
        printf("Nhập số lượng sinh viên cần thêm(Hiện đã có %d sinh viên.Số sinh viên tối đa bạn có thể thêm là %d): ", soSinhVien, 20 - soSinhVien);
        scanf("%d", &count);
    } while(count <= 0 || (count + soSinhVien) > 20);
    int start = 0;
    int end = 0;
    int soSinhVienTruoc = soSinhVien;
    soSinhVien += count;
    char MSSV[5];
    char hoTenTmp[30];
    for(int i = soSinhVienTruoc; i < soSinhVien; i++)
    {
            printf("Nhập thông tin sinh viên thứ %d \n", i + 1);
            do {
                printf("MSSV (Không được trùng với sinh viên khác): ");
                clearInput();
                scanf("%5s", MSSV);
            } while(kiemTraTrungMssv(MSSV) == true);
            strcpy(danhSachSV[i].MSSV, MSSV);
            do {
                printf("Họ tên: ");
                clearInput();
                fgets(hoTenTmp, 30, stdin);
                hoTenTmp[strcspn(hoTenTmp, "\n")] = 0;
            } while(kiemTraHoTen(hoTenTmp) == false);
            strcpy(danhSachSV[i].hoTen, hoTenTmp);
            do {    
                printf("Điểm hướng dẫn: \n");
                danhSachSV[i].diem[0] = nhapDiem();
                printf("Điểm phản biện: \n");
                danhSachSV[i].diem[1] = nhapDiem();
                printf("Điểm hội đồng 1: \n");
                danhSachSV[i].diem[2] = nhapDiem();
                printf("Điểm hội đồng 2: \n");
                danhSachSV[i].diem[3] = nhapDiem();
                printf("Điểm hội đồng 3: \n");
                danhSachSV[i].diem[4] = nhapDiem();
                if(kiemTraChenhLechDiem(danhSachSV[i].diem))
                {
                    printf("Điểm thành phần chênh lệch quá 3 điểm.Vui lòng kiểm tra và nhập lại\n");
                }
                else
                {
                    break;
                }
            } while(1);

            if(kiemTraDiemLiet(danhSachSV[i].diem))
            {
                danhSachSV[i].diemCK = 0.0;
                danhSachSV[i].diemGK = 0.0;
            }
            else
            {
                danhSachSV[i].diemGK = (float)round(10.0*(danhSachSV[i].diem[0] + danhSachSV[i].diem[1]) / 2)/10;
                danhSachSV[i].diemCK = (float)round(10.0*(danhSachSV[i].diem[2] + danhSachSV[i].diem[3] + danhSachSV[i].diem[4]) / 3)/10;
            }
    }
    printf("%10s %20s  %10s  %10s  %10s  %10s  %10s  %10s  %10s\n", "MSSV", "Họ và Tên", "HD", "PB", "HĐ1", "HĐ2", "HĐ3", "Giua Ki", "Cuoi Ki");
    for(int i = 0; i < soSinhVien; i++)
    {
        inDanhSachSinhVien(&danhSachSV[i]);
    }

}

void danh_sach_sinh_vien_bao_ve_thanh_cong() 
{
    printf("Danh sách sinh viên bảo vệ thành công\n");
    printf("%10s %20s  %10s  %10s  %10s  %10s  %10s  %10s  %10s\n", "MSSV", "Họ và Tên", "HD", "PB", "HĐ1", "HĐ2", "HĐ3", "Giua Ki", "Cuoi Ki");
    for(int i = 0; i < soSinhVien; i++)
    {
        if(danhSachSV[i].diemCK > 0 && danhSachSV[i].diemGK > 0)
            inDanhSachSinhVien(&danhSachSV[i]);
    }
}

void sap_xep_sinh_vien_theo_ten() 
{
    char ten[30];
    for(int i = 0; i < soSinhVien; i++)
    {
        for(int j = i + 1; j < soSinhVien; j++)
        {
            if(strcmp(layTenSinhVien(danhSachSV[i].hoTen), layTenSinhVien(danhSachSV[j].hoTen)) > 0)
            {
                thongTinSV tmp;
                tmp = danhSachSV[j];
                danhSachSV[j] = danhSachSV[i];
                danhSachSV[i] = tmp;
            }
        }
    }

    printf("Danh sách sinh viên sau khi sắp xếp theo tên \n");
    printf("%10s %20s  %10s  %10s  %10s  %10s  %10s  %10s  %10s\n", "MSSV", "Họ và Tên", "HD", "PB", "HĐ1", "HĐ2", "HĐ3", "Giua Ki", "Cuoi Ki");
    for(int i = 0; i < soSinhVien; i++)
    {
        inDanhSachSinhVien(&danhSachSV[i]);
    }

}
