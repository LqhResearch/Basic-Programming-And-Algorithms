/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Thuat toan quay lui liet ke cac chinh hop khong lap chap k
 **************************************************************/
# include <stdio.h>
# include <string.h>

int n, k;
int* x;
bool* c;
FILE* fr = fopen("A12_Input.inp", "r");
FILE* fw = fopen("A12_Output.out", "w");

void ReadFile()
{
	fscanf(fr, "%d%d", &n, &k);
}

void PrintResult()
{ // In cau hinh tim duoc, do thu tuc tim de quy Try goi thi tim ra mot cau hinh
	for (int i = 0; i < k; i++)
		fprintf(fw, "%3d", x[i] + 1);
	fprintf(fw, "\n");
}

void Try(int i)
{
	for (int j = 0; j < n; j++)
	{
		if (c[j])
		{ // Chi xet nhung gia tri j con tu do
			x[i] = j;
			if (i == k - 1)
				PrintResult();
			else
			{
				c[j] = false; // Danh dau: j da bi chon
				Try(i + 1);
				c[j] = true; // Bo dau: j lai la tu do
			}
		}
	}
}

int main()
{
	ReadFile();
	x = new int[k];
	c = new bool[n];
	memset(x, 0, sizeof(int) * k); // Cau hinh ban dau x0 = x1 = ... = xN = 0
	memset(c, true, sizeof(bool) * n); // Tat ca cac so deu chua bi chon
	Try(0);
	return 0;
}
