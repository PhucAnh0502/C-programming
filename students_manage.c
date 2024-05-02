#include<stdio.h> 
#include<string.h>
#include<time.h>
struct date{
	int ngay;
	int thang;
	int nam;
};
typedef struct SinhVien{
	int id;
	char ten[50];
	char gioitinh[5];
	date ngaysinh;
	int tuoi;
} SV;
void Xoaxuongdong(char x[]){
	size_t len = strlen(x);
	if(x[len - 1]=='\n') x[len - 1] = '\0';
}

void nhapsinhvien(SV &sv){
	printf("\nID:"); scanf("%d",&sv.id);
	printf("\nTen:"); fflush(stdin); fgets(sv.ten,sizeof(sv.ten),stdin);
	Xoaxuongdong(sv.ten);
	printf("\nGioi tinh:"); fflush(stdin); fgets(sv.gioitinh,sizeof(sv.gioitinh),stdin);
	Xoaxuongdong(sv.gioitinh);
	printf("\nNgay sinh:"); scanf("%d%d%d",&sv.ngaysinh.ngay,&sv.ngaysinh.thang,&sv.ngaysinh.nam);
}

void inSV(SV sv){
	printf("%10d \t %20s \t %10s \t %2d/%d/%d \t %10d \t",sv.id,sv.ten,sv.gioitinh,sv.ngaysinh.ngay,sv.ngaysinh.thang,sv.ngaysinh.nam,sv.tuoi);
}

void tinhtuoi(SV &sv){
	time_t TIME = time(0);
	tm* NOW = localtime(&TIME);
	int namht = NOW -> tm_year + 1900;
	sv.tuoi = namht - sv.ngaysinh.nam;
}

void capnhatsv(SV &sv){
	nhapsinhvien(sv);
	tinhtuoi(sv);
}

void nhapDanhSach(SV ds[], int &n){
	do{
		printf("\nNhap vao n:");
		scanf("%d",&n);
	} while(n<=0);
	for(int i=0;i<n;i++){
		printf("Nhap vao sinh vien thu %d",i);
		capnhatsv(ds[i]);
	}
}

void xuatds(SV ds[], int n){
	printf("%10s \t %20s \t %10s \t %10s \t %10s \n","ID","Ho va Ten","Gioi tinh","Ngay sinh","Tuoi");
	printf("\n");
	for(int i=0;i<n;i++){
		inSV(ds[i]);
		printf("\n");
	}
}

int timSVtheoten(SV ds[], int n, char ten[]){
	//0 -> false
	//1 -> true
	for(int i=0;i<n;i++){
		if(strstr(ds[i].ten, ten)){
			return 1;
		}
	}
	return 0;
}

void xoaSVtheoid(SV ds[], int &n, int id){
	for(int i=0;i<n;i++){
		if(ds[i].id==id){
			for(int j=i;j<n;j++){
				ds[j]=ds[j+1];
			}
			n -= 1;
		}
	}
}

void Sapxeptheoten(SV ds[], int n){
	for(int i=0;i<n - 1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(ds[i].ten, ds[j].ten)<0){
				SV temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}

int main(){
	SV ds[100];
	int n;
	int select;
	do{
		printf("\nMENU:");
		printf("\n1- Nhap danh sach sinh vien");
		printf("\n2- Xuat danh sach sinh vien");
		printf("\n3- Tim sinh vien theo ten");
		printf("\n4- Xoa sinh vien theo id");
		printf("\n5- Sap xep theo ten");
		printf("\n0- Thoat");
		printf("\n");
		scanf("%d", &select);
		
		switch(select){
			case 1:
				nhapDanhSach(ds, n); break;
			case 2:
				xuatds(ds,n); break;
			case 3:
				char ten[50];
				printf("Nhap ten can tim kiem: ");
				fflush(stdin); fgets(ten,sizeof(ten),stdin); Xoaxuongdong(ten);
				printf("Ket qua sinh vien can tim: %d",timSVtheoten(ds,n,ten));
				break;
			case 4:
				int ID;
				printf("Nhap ID sinh vien can xoa: "); scanf("%d", &ID);
				xoaSVtheoid(ds,n,ID);
				break;
			case 5:
				Sapxeptheoten(ds,n);
				xuatds(ds,n);
				break;
		}
	} while (n!=0);
	return 0;
}
