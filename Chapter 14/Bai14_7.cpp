/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Thuat toan sinh liet ke cac day nhi phan co do dai n
 **************************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main()
{
	int n;
	
	// Doc file
    FILE* f = fopen("A7_Input.inp", "r");
    fscanf(f, "%d", &n);
    fclose(f);

	//Xu ly va ghi file
    f = fopen("A7_Output.out", "w");
    int *x = new int[n];
    int i = 0;
    memset(x, 0, sizeof(int) * n); // Cau hinh ban dau x0 = x1 = ... = xN = 0

    do
    {
        for (i = 0; i < n; i++) //In ra cau hinh hien tai
            fprintf(f, "%d", x[i]);
        fprintf(f, "\n");
        i = n - 1; //xI la phan tu cuoi cung, lui cho den khi gap 0 hoac cho den khi i = -1
        while (i > -1 && x[i] == 1)
            i--;
        if (i > -1) // Chua gap cau hinh 11...1
        {
            x[i] = 1; // Thay xI = 1
            for (int j = i + 1; j < n; j++)
                x[j] = 0; // Gan xI+1 = xI+2 = ... xN-1 = 0
        }
    } while (i != -1);
    fclose(f);
    return 0;
}

