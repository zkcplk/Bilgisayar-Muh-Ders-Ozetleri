//	Klavyeden girilen 3 basamakl� say�n�n, 
//	basamak de�erleri toplam�na sahip di�er say�lar� listeleyen C kodunu yaz�n�z.

#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Turkish");
	
	int toplam;
	char sayi[3]; 
	
	printf("L�tfen 3 basamakl� bir say� giriniz: ");
	scanf("%s", sayi);
	
	for (int i=0;i<3;i++) 
		toplam += sayi[i] - '0';
		
	printf("Girdi�iniz say�n�n basamak de�erleri toplam�: %d \n", toplam);
	printf("Ayn� toplama sahip di�er 3 basamakl� say�lar: \n");
	
	int temp;
	for (int a=0; a<10; a++) {
		for (int b=0; b<10; b++) {
			for (int c=0; c<10; c++) {
				temp = a + b + c;
				if (temp == toplam && a != 0) printf("* %d%d%d \n", a,b,c);
			}
		}
	}
}