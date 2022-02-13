#include<stdio.h>
#include<math.h>
/*
	Nhap vao ot so nguyen n, kiem tra no co phai la so armstrong hay khong?
	So armstrong la so ma tung chu so trong so do luy thua voi so luong chu so nang chinh no.
		x=a_k^k+a_(k-1)^k+a_(k-2)^k+?+a_2^k+a_1^k
	Vi du: 	So 153 thì 1^3+5^3+3^3 = 153
			So 1634 thì 1^4 + 6^4 + 3^4 + 4^4 = 1634
*/

	//Dem so luong chu so
int DemChuSo(int n) {
	int count = 0;
	while(n!=0)
	{
		count++;
		n/=10;
	}
	return count;
}

	//Kiem tra so Armstrong hay khong?
bool TestArmstrong(int n) {
	int sum = 0, chuSo = DemChuSo(n);
	
	int temp = n;
	while(temp!=0)
	{
		sum+=pow(temp%10, chuSo);
		temp/=10;
	}
	if(sum == n)	return true;
	else return false;
}

int main() {
	int n;
	do{
		printf("Nhap so nguyen: ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so lon hon hoac bang 0\n");
	}while(n < 0);
	
	if(TestArmstrong(n) == true)
		printf("So %d la so Armstrong", n);
	else
		printf("So %d khong phai la so Armstrong", n);
	return 0;
}

