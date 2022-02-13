/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Thuat toan quay lui liet ke cac tap con k phan tu
 **************************************************************/
# include <stdio.h>

int n, k;
int* x;
FILE* fr = fopen("A11_Input.inp", "r");
FILE* fw = fopen("A11_Output.out", "w");

void ReadFile()
{
	fscanf(fr, "%d%d", &n, &k);
}

void PrintResult()
{   // In cau hinh tim duoc, do thu tuc tim de quy Try goi thi tim ra mot cau hinh
	printf("{ ");
	for (int i = 0; i < k - 1; i++) // In cau hinh hien tai
		printf("%d, ", x[i]);
	printf("%d }\n", x[k - 1]);
}

void Try(int i)
{
	for (int j = x[i - 1] + 1; j < n - k + i + 2; j++)
	{
		x[i] = j;
		if (i == k - 1)
			PrintResult();
		else
			Try(i + 1);
	}
}

int main()
{
	ReadFile();
	x = new int[k];
	for (int i = 0; i < k; i++) //Cau hinh ban dau 0 = 1, 1=2, ... xK-1 = K
		x[i] = i + 1;
	Try(1);
	return 0;
}
