/***************************************************
* Author: LQH
* Date created: 30/05/2021
* Last modified date:
* Topic: Tinh dien tich cua hinh elip.
* S = PI * ab (trong do a va b la do dai cac ban truc lon va be cua elip).
***************************************************/
#include <stdio.h>
#include <math.h>

int main() {
	float a, b;
	printf("- Ban kinh truc lon = ");
	scanf("%f", &a);
	printf("- Ban kinh truc be = ");
	scanf("%f", &b);
	
	printf("Dien tich = %f", (3.14*a*b));
	return 0;
}

