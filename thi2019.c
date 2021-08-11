#include <stdio.h>
#include <string.h>

int i,j;
typedef struct 
{
    char TenSV[20];
    float DiemQT, DiemCK, DiemTK;
    char DiemXL;
} DiemSV;

int chucnang() {
    int choose;
    printf("\n	**************************************\n");
    printf("	Chuong Trinh Quan Ly Diem Mon Hoc\n");
    printf("	1.\tNhap diem\n");
    printf("	2.\tIn bang diem\n");
    printf("	3.\tChenh lech diem\n");
    printf("	4.\tSap xep\n");
    printf("	5.\tThoat chuong trinh\n");
    printf("	Press (1,2,3,4,5) to choose: ");
    scanf("%d",&choose);
    printf("	**************************************\n");
    return choose;
}

DiemSV NhapSV(int thutu) {
    DiemSV SV;
    printf("Nhap thong tin cua sinh vien thu %d\n",thutu);
    printf("Ten SV: ");
    fflush(stdin);
    gets(SV.TenSV);
    fflush(stdin);
    do {
    	printf("Nhap diem QT [0;10]: ");
        scanf("%f",&SV.DiemQT);
	} while (SV.DiemQT<0 || SV.DiemQT>10);
	fflush(stdin);
	do {
		printf("Nhap diem CK [0;10]: ");
        scanf("%f",&SV.DiemCK);
	} while (SV.DiemCK<0 || SV.DiemCK>10);
    SV.DiemTK= 0.4*SV.DiemQT + 0.6*SV.DiemCK;
    if (SV.DiemQT<=3 || SV.DiemCK <=3) SV.DiemXL= 'F';
	else {
		if (SV.DiemTK < 4) SV.DiemXL='F';
		if (SV.DiemTK >= 4 && SV.DiemCK< 5.5) SV.DiemXL= 'D';
		if (SV.DiemTK >= 5.5 && SV.DiemCK< 7) SV.DiemXL= 'C';
		if (SV.DiemTK >=7 && SV.DiemCK <8.6) SV.DiemXL= 'B';
		if (SV.DiemTK >= 8.5) SV.DiemXL='A';
	}
    return SV;
}


void InBangdiem(DiemSV SV[], int n) {
	printf("%-20s%-10s%-10s%-10s%-10s\n","Ten SV","Diem QT","Diem CK","Diem TK","Xep loai");
	for (i=1; i<=n; i++)
		printf("%-20s%-10.1f%-10.1f%-10.1f%-10c\n",SV[i].TenSV,SV[i].DiemQT,SV[i].DiemCK,SV[i].DiemTK,SV[i].DiemXL);
 } 
 
void InChenhlech(int l, DiemSV SV[], int n) {
	printf("\nSinh vien co diem GK va CK chenh lech >= %d \n",l);
	for (i=1; i<=n; i++) 
		if (SV[i].DiemQT - SV[i].DiemCK >= l || SV[i].DiemCK-SV[i].DiemQT>=l) 
			printf("%-20s%-10.1f%-10.1f%-10.1f%-10c\n",SV[i].TenSV,SV[i].DiemQT,SV[i].DiemCK,SV[i].DiemTK,SV[i].DiemXL);
}


void SapxepSV(DiemSV SV[],int n) {
	DiemSV tmp;
	int k;
	for (i=1; i<=n; i++) 
		for (j=i+1; j<=n;j++)
		{
			if (SV[i].DiemTK < SV[j].DiemTK) {
				tmp=SV[i];
				SV[i]=SV[j];
				SV[j]=tmp;
			}
			if (SV[i].DiemTK == SV[j].DiemTK) {
				for (k=0;k<strlen(SV[i].TenSV);k++)
				if (SV[i].TenSV[k] < SV[j].TenSV[k]) {
					tmp=SV[i];
					SV[i]=SV[j];
					SV[j]=tmp;
					break;
				}
			}
		}
	}
int main()
{
    int n,cn,chenhlech;
    cn=chucnang();
    DiemSV Sinhvien[41];
    while (cn != 5)
    {
	
	    if (cn==1) {
		    do {
			
		        printf("Nhap so SV: ");
		        scanf("%d",&n);
		    } while (n<=0 || n > 40);
		        for (i=1; i<=n; i++) 
		            Sinhvien[i]=NhapSV(i);
		        
		}
		if (cn==2) InBangdiem(Sinhvien,n);
		
		if (cn==3) {
			do {
				printf("Nhap mot so nguyen [2,5]: ");
				scanf("%d",&chenhlech);
			} while (chenhlech<2 || chenhlech >5);
			InChenhlech(chenhlech,Sinhvien,n);
		}
		
		if (cn==4) {
			SapxepSV(Sinhvien,n);
			InBangdiem(Sinhvien,n);
		}
		cn=chucnang();
		if (cn==5) printf("Thanks for used my programming");
	}
    return 0;
}
