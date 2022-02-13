#include<stdio.h>

#define MAX 50
/*
	Nhap vao hai mang so nguyen a va b. Dem so lan xuat hien mang a trong mang b
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
void ChildArrayCount(int arr1[], int arr2[], int n1, int n2);

int main() {
	int n1, n2, arr1[MAX], arr2[MAX];
	do{
		printf("\nNhap so phan tu = ");
		scanf("%d", &n1);
		if(n1 <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n1 <= 0);
	NhapMang(arr1, n1);
	
	do{
		printf("\nNhap so phan tu = ");
		scanf("%d", &n2);
		if(n2 <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n2 <= 0);
	NhapMang(arr2, n2);
	
	XuatMang(arr1, n1);
	XuatMang(arr2, n2);
	
	ChildArrayCount(arr1, arr2, n1, n2);
	return 0;
}

	//Nhap mang
void NhapMang(int arr[], int n) {
	for(int i=0; i<n; i++) {
		printf("Phan tu thu A[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

	//Xuat mang
void XuatMang(int arr[], int n) {
	printf("Xuat mang: ");
	for(int i=0; i<n; i++)
		printf("%d\t", arr[i]);
}

	//Dem so lan xuat hien mang a trong mang b
void ChildArrayCount(int arr1[], int arr2[], int n1, int n2) {
	//Mang a la con cua mang b thi so phan tu cua mang b >= mang a
	int count=0, viTri;
	bool check;
	if(n1 > n2)
		printf("\nMang a xuat hien 0 lan trong mang b");
	else {
		count=0;
		for(int i=0; i<n2; i++) {	//Duyet mang b
			if(arr2[i] == arr1[0]) {
				check=true;		//Kiem tra mang con dung hay khong?
				viTri=i;	//Danh dau vi tri hien tai
				for(int j=0; j<n1; j++)
					if(arr1[j] != arr2[viTri+j])
						check=false;
				if(check==true)	count++;
			}
		}
	}
	printf("\nMang a xuat hien %d lan trong mang b", count);
}
