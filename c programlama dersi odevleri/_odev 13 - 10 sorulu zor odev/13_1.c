//	10x10 boyutunda bir matris, doldur() isimli fonksiyona g�nderiliyor. 
//	Kullan�c�n�n belirledi�i aral�kta, rastgele say� atamas� yap�l�yor.
//	Ard�ndan bu matris, degerler() isimli fonksiyona g�nderilerek;
//	matrisin toplam�, ortalamas�, standart sapmas�, en k���k, en b�y�k de�erlerini geriye dizi olarak d�nd�ren
//	C program kodunu yaz�n�z.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

void doldur(int matris[10][10], int aralik1, int aralik2);
void degerler(int matris[10][10], float *deger);

void main() {
	srand(time(0));
	setlocale(LC_ALL, "Turkish");
	
	float deger[5];
	int mn, mx, matris[10][10];
	
	printf("Matristeki say�lar hangi aral�kta olsun?\n�ki say� giriniz! (15 75 gibi): ");
	scanf("%d %d", &mn, &mx);
	
	//	matris dolduruluyor...
	doldur(matris, mn, mx);

	printf("-----------Olu�turulan Matris-----------\n");
	for (int a=0;a<10;a++) {
		for (int b=0;b<10;b++) printf(" %d ", matris[a][b]);
		printf("\n");
	}
	
	//	de�erler hesaplan�yor...
	degerler(matris, deger);
	
	printf("------------De�erler Dizisi-------------\n");
	printf("Matris Toplam�: %d \n", (int) deger[0]);
	printf("Matris 0rtalamas�: %.2f \n", deger[1]);
	printf("Matris Standart Sapma: %.3f \n", deger[2]);
	printf("Maksimum Say�: %d \n", (int) deger[3]);
	printf("Minimum Say�: %d \n", (int) deger[4]);
	printf("----------------------------------------");
}

void doldur(int matris[10][10], int aralik1, int aralik2) {
	int temp;
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			bul:
			temp = rand();
			if (temp >= aralik1 && temp <= aralik2) *(*(matris+i)+j) = temp;
			else goto bul;
		}
	}
}

void degerler(int matris[10][10], float *deger) {
	float toplam = 0.0, ortalama, standart_sapma = 0.0;
	int temp, max=**matris, min=**matris;
	
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			temp = *(*(matris+i)+j);
			toplam += temp;
			
			if (temp > max) max = temp;
			if (temp < min) min = temp;
		}
	}
	
	*deger = toplam;
	ortalama = toplam / 100;
	*(deger + 1) = ortalama;
	
	for (int a=0;a<10;a++) for (int b=0;b<10;b++) standart_sapma += pow(*(*(matris+a)+b) - ortalama, 2);
	
	standart_sapma = sqrt(standart_sapma/100);
	*(deger + 2) = standart_sapma;
	*(deger + 3) = max;
	*(deger + 4) = min;
}
