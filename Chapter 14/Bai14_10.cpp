/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Thuat toan quay lui liet ke cac day nhi phan do dai n
 **************************************************************/
# include <stdio.h>
# include <string.h>

int n;
int* x;
FILE* fr = fopen("A10_Input.inp", "r");
FILE* fw = fopen("A10_Output.out", "w");

void ReadFile()
{
	fscanf(fr, "%d", &n);
}

void PrintResult()
{ // In cau hinh tim duoc, do thu tuc tim de quy Try goi thi tim ra mot cau hinh
	for (int i = 0; i < n; i++)
		fprintf(fw, "%d", x[i]);
	fprintf(fw, "\n");
}

void Try(int i)
{ // Thu cac cach chon xI
	for (int j = 0; j < 2; j++)
	{ //Xet cac gia tri co the gan cho xI, voi moi gia tri do
		x[i] = j; // Thu dat xI = j
		if (i == n - 1)
			PrintResult();
		else
			Try(i + 1); // Neu i chua phai gia tri cuoi thi x(i+1)
	}
}

int main()
{
	ReadFile();
	x = new int[n];
	memset(x, 0, sizeof(int) * n); // Cau hinh ban dau x0 = x1 = ... = xN = 0
	Try(0);
	return 0;
}
