/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Thuat toan sinh liet ke hoan vi
 **************************************************************/
# include <stdio.h>

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n;

	// Doc file
	FILE* f = fopen("A9_Input.inp", "r");
	fscanf(f, "%d", &n);
	fclose(f);

	//Xu ly va ghi file
	f = fopen("A9_Output.out", "w");
	int* x = new int[n];
	int i = 0;
	for (i = 0; i < n; i++) //Cau hinh ban dau 0 = 1, x1=2, ... xN-1 = N
		x[i] = i + 1;
	do
	{
		for (i = 0; i < n; i++) //In ra cau hinh hien tai
			fprintf(f, "%5d", x[i]);
		fprintf(f, "\n");
		i = n - 1;
		while (i > -1 && x[i] > x[i + 1])
			i--;
		if (i >= 0)
		{ // Chua gap phai hoan doi cuoi n, n-1, n-2, ...
			int k = n;//xK la phan tu cuoi day
			while (x[k] < x[i]) //Lui dan k de tim gap xK dau tien lon hon xI
				k--;
			Swap(x[k], x[i]); // Hoan vi xK va xI
			int a = i + 1, b = n - 1;//Lat nguoc doan cuoi giam dan. a: dau doan, b: cuoi doan
			if (a < b)
			{
				Swap(x[a], x[b]); // Hoan vi xA va xB
				a++;
				b--;
			}
		}
	} while (i != -1);
	fclose(f);
	return 0;
}
