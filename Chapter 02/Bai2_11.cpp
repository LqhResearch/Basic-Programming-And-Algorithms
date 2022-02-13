#include<stdio.h>
/*
	Viet chuong trình giai he phuong trinh:
		ax + by = c
		dx + ey = f
	Cac he so a, b, c, d, e, f nhap tu ban phim.
*/

int main() 
{
	float a, b, c,d, e, f;
	float Dx, Dy, D;
	printf("Nhap vao cac he so a, b, c, d, e, f : \n");
	scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
	D = a*e - b*d;
	Dx = c*e - b*f;
	Dy = a*f - c*d;
	printf("\n%.2fx + %.2fy = %.2f", a, b, c);
	printf("\n%.2fx + %.2fy = %.2f", d, e, f);
	if(D == 0 && Dx == 0)
		printf("\nHe phuong trinh vo so nghiem");
	if(D == 0 && Dx != 0)
		printf("\nHe phuong trinh vo nghiem");
	if(D != 0)
	{
		printf("\nHe co nghiem");
		printf("\nx = %.3f", Dx/D);
		printf("\ny = %.3f", Dy/D);
	}
	return 0;
}
