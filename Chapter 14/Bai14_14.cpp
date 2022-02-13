/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Thuat toan quay lui giai bai tap xep quan hau
 **************************************************************/
# include <stdio.h>
# include <string.h>

int n;
int* x;
bool *a, *b, *c;
FILE* fr = fopen("A14_Input.inp", "r");
FILE* fw = fopen("A14_Output.out", "w");

void Init() {
	a = new bool[n];
	b = new bool[2*n];
	c = new bool[2*n];
	x = new int[n];
	memset(a, true, sizeof(bool)*n); // Moi cot deu tu do
	memset(b, true, sizeof(bool)*2*n); // Moi duong cheo Dong Bac - Tay Nam deu tu do
	memset(c, true, sizeof(bool)*2*n); // Moi duong cheo Dong Nam - Tay Bac deu tu do
	memset(x, 0, sizeof(int)*n);
}

void ReadFile() {
	fscanf(fr, "%d", &n);
}

void PrintResult() {
	// In cau hinh tim duoc, do thu tuc tim de quy Try goi thi tim ra mot cau hinh
	for (int i = 0; i < n; i++)
		printf("(%d, %d); ", i+1, x[i]+1);
	printf("\n");
}

void Try(int i) {
	for(int j=0; j<n; j++) {
		if(a[j] && b[i+j] && c[i-j]) {
			x[i]=j;
			if(i==n-1)
				PrintResult();
			else {
				a[j]=false;
				b[i+j]=false;
				c[i-j]=false; //Danh dau
				Try(i+1);
				a[j]=true;
				b[i+j]=true;
				c[i-j]=true; //Bo danh dau
			}
		}
	}
}

int main() {
	ReadFile();
	Init();
	Try(1);
	return 0;
}
