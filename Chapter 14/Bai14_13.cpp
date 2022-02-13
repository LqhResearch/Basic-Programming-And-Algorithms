/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Thuat toan quay lui liet ke cac cach phan tich so
 **************************************************************/
# include <stdio.h>

int n;
int* x, *t;
FILE* fr = fopen("A13_Input.inp", "r");
FILE* fw = fopen("A13_Output.out", "w");

void Init()
{
	x[0] = 1;
	t[0] = 0;
}

void ReadFile()
{
	fscanf(fr, "%d", &n);
}

void PrintResult(int k)
{ // In cau hinh tim duoc, do thu tuc tim de quy Try goi thi tim ra mot cau hinh
	fprintf(fw, "%d = ", n);
	for (int i = 1; i < k - 1; i++)
		fprintf(fw, "%d + ", x[i]);
	fprintf(fw, "%d\n", x[k - 1]);
}

void Try(int i)
{
	for (int j = x[i - 1]; j <= (n - t[i - 1]) / 2; j++) // Truong hop con chon tien x(i+1)
	{
		x[i] = j;
		t[i] = t[i - 1] + j;
		Try(i + 1);
	}
	x[i] = n - t[i - 1]; // Neu x[i] la phan tu cuoi thi bat buoc phai la ... va in ra ket qua.
	PrintResult(i + 1);
}

int main()
{
	ReadFile();
	x = new int[n];
	t = new int[n];
	Init();
	Try(1);
	return 0;
}
