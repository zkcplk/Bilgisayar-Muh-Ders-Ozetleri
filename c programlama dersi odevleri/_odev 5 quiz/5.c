#include<stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Turkish");

	int i = 0, girilen, sonuc = 0;
	for (;i<10;i++) {
		printf("L�pten %d. tam say�y� giriniz: ",i+1);
		scanf("%d", &girilen);
		sonuc += girilen;
	}


	printf("Girilen say�lar�n toplam�: %d", sonuc);
}