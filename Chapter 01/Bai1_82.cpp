#include<stdio.h>
/*
	Mo phong phep nhan tren giay voi 2 so nguyen duong
*/
int inpNum(int n)
{
	do{
		printf("Nhap so nguyen = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n <= 0);
	return n;
}

int CountNumber(int n) {
	int count = 0;
	while(n!=0)
	{
		n/=10;
		count++;
	}
	return count;
}

void Space(int abNum, int n, char kiTu)
{
	for(int i=1; i<=(abNum - n); i++)
		printf("%c", kiTu);
}

int main() {
	int a = inpNum(a);
	int b = inpNum(b);

	int abNum = CountNumber(a) + CountNumber(b);	//Tong so luong so chu so cua a va b
		//Xuat gia tri a ra man hinh
	Space(abNum, CountNumber(a), ' ');		
	printf("%d\n", a);
		//Xuat dau nhan truoc gia tri b va gia tri b
	printf("x");	
	Space(abNum, CountNumber(b)+1, ' ');
	printf("%d\n", b);
		//Xuat -----------------
	Space(abNum, 0, '-');
		
	int bNew = b;
	while(bNew != 0)	//Tach tung chu so cua b
	{
		int lastNum = bNew%10;
		printf("\n");	Space(abNum, CountNumber(a), ' ');		//Ket qua nhan cua gia tri cuoi voi a
		printf("%d", lastNum*a);
		bNew/=10;/*Buoc nhay*/	abNum--;
	}
	
	printf("\n");	Space(abNum, 0, '-');	//Xuat -----------------
	printf("\n %d", a*b);		//Xuat ket qua cuoi cung cua a va b
	return 0;
}

