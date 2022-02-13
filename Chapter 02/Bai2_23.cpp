#include<stdio.h>
/*
	Viet chuong trinh giai bai toan co ve ga va cho
		Vua ga vua cho
		Bo lai cho tron
		Ba muoi sau con
		Mot tram chan chan
		Hoi may ga, may cho?
*/
int main() {
	/*
		Su dung 2 vong lap so con ga va cho
		Ga co 2 chan va cho co 4 chan 2*ga+4*ga==100
		So con ga va con cho la ga+cho==36
	*/
	for(int ga=1; ga<=36; ga++)
		for(int cho=1; cho<=36; cho++)
			if((2*ga+4*cho==100) && (ga+cho==36))
				printf("%d con ga va %d con cho\n", ga, cho);
	return 0;
}

