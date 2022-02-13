/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Thuat toan sinh liet ke cac tap con k phan tu
 **************************************************************/
# include <stdio.h>

int main()
{
	int n, k;

	// Doc file
	FILE* f = fopen("A8_Input.inp", "r");
	fscanf(f, "%d%d", &n, &k);
	fclose(f);

	//Xu ly va ghi file
	f = fopen("A8_Output.out", "w");
	int* x = new int[k];
	int i = 0;
	for (i = 0; i < k; i++) //Cau hinh ban dau 0 = 1, 1=2, ... xK-1 = K
		x[i] = i + 1;
	do
	{
		fprintf(f, "{ ");
		for (i = 0; i < k - 1; i++) // In cau hinh hien tai
			fprintf(f, "%d, ", x[i]);
		fprintf(f, "%d }\n", x[k - 1]);
		i = k - 1; //xI la phan tu cuoi cung, lui cho den khi gap 0 hoac cho den khi xI = n-k+i
		while (i >= 0 && (x[i] == n - k + i + 1))
			i--;
		if (i >= 0)
		{ // Neu lui chua den -1 thi co nghia la chua ket thuc
			x[i]++; // Tang xI them 1, dat cac phan tu xI bang gioi han duoi cua no
			for (int j = i + 1; j < k; j++)
				x[j] = x[j - 1] + 1;
		}
	} while (i != -1);
	fclose(f);
	return 0;
}
