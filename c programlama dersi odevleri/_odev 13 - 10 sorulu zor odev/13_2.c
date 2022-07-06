//	Klavyeden girilen iki say� aras�ndaki asal say�lar� bir diziye atan 
//	ve bu diziyi g�r�nt�leyen C program kodunuzu yaz�n�z.


#include <stdio.h>
#include <locale.h>
int asalmi (int bak);
void main() {
	//	Ya�as�n T�RK�E!
	setlocale(LC_ALL, "Turkish");
	
	int num1, num2, dizi[1000];
	printf("L�tfen iki say� giriniz: ");
	scanf("%d %d", &num1, &num2);
	
	int max, min;
	if (num2 > num1) { 
		max = num2;
		min = num1;
	}
	else {
		max = num1;
		min = num2;
	}
	
	int temp=0, j=0;
	for (int i=min; i<max; i++) {
		temp = asalmi(i);
		if (temp) {
			dizi[j] = i;
			j++;
		}
	}
		
	printf("%d ile %d aras�ndaki asal say�lar: \n", min, max);
	for (int z=0; z<j; z++) 
		printf("%d. eleman: %d \n", (z+1), dizi[z]);
}

int asalmi (int bak) {
	int sonuc=1,i=2;
	
	if (bak == 2) return 1;
	else if (bak < 2) return 0;
	else {
		while(i<bak) {
			if (bak % i == 0) return 0;
			i++;
		}
	}
	
	return 1;
}