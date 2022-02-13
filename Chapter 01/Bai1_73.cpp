#include <stdio.h>
/*
	Xac dinh goc thu tu thu may tren duong tron luong giac
*/
int main()
{
    int angle, k;
    do
    {
        printf("Nhap vao so do goc (0 <= x <= 360*k) = ");
        scanf("%d", &angle);
    }while(angle < 0);

    k = angle / 360;

    if(angle >= (360*k) && angle < (90 + 360*k))
        printf("%d o goc phan tu thu 1\n", angle);
    else if (angle >= (90 + 360*k) && angle < (180 + 360*k))
        printf("%d o goc phan tu thu 2\n", angle);
    else if (angle >= (180 + 360*k) && angle < (270 + 360*k))
        printf("%d o goc phan tu thu 3\n", angle);
    else if (angle >= (270 + 360*k) && angle <= 360*(k + 1))
        printf("%d o goc phan tu thu 4\n", angle);
    else
        printf("%d khong hop le\n");
    return 0;
}
