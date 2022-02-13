#include<stdio.h>
#include<math.h>

#define E 0.0001
#define PI 3.141592654
/*
	Lap chuong trinh sin(x) voi do chính xac 0.00001 theo cong thuc:
		sin(x)=x-x^3/3+x^5/5+...+(-1)^n*x^(2n+1)/(2n+1)!
*/
	//Tinh n giai thua
long giaithua(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else
		return n*giaithua(n-1);
}

int main()
{
	float angle; // goc
	float e = 1; // sai so
	int n = 0;
	float sinx = 0;
	printf("\nNhap vao so do goc(do)= ");
	scanf("%f", &angle);
	while(e > E)
    {
		e = pow(float(angle*PI/180), (2*n+1))/giaithua(2*n+1); // tinh sai so
		if(n%2 == 0)// n chan
            sinx = sinx + e;
        else // n le
            sinx = sinx - e;
        n++;
	}
	printf("\n sin(%f) = %f", angle, sinx); 
	return 0;
}
