//	Girilen 10 adet say� bir diziye atanacakt�r.
//	Bu dizi divide fonksiyonuna arg�ment olarak g�nderilecektir.
//	Fonksiyon pozitifleri bir diziye, negatifleri ba�ka bir diziye atayacakt�r. 
//	Bu program�n C kodunu yaz�n�z.

#include <stdio.h>
#include <locale.h>
#define BOYUT 10

void divide (int *sayilar, int *negatifler, int *pozitifler, int boyut);
void main() {
	setlocale(LC_ALL, "Turkish");
	int sayilar[BOYUT], temp;
	
	for(int i=0;i<BOYUT;i++) {
		printf(" L�tfen %d. tamsay�y� giriniz: ", (i+1));
		scanf("%d", &temp);
		sayilar[i] = temp;
	}
	
	int pozitifler[BOYUT] = {0,0,0,0,0,0,0,0,0,0};
	int negatifler[BOYUT] = {0,0,0,0,0,0,0,0,0,0};
	
	divide (sayilar, negatifler, pozitifler, BOYUT);

	printf("------------------------------------\n");
	printf(" Girilen say�lardan POZ�T�F olanlar: \n");
	for (int x=0;x<BOYUT;x++) if (pozitifler[x] != 0) printf(" %d ", pozitifler[x]);
	
	printf("\n------------------------------------\n");
	printf(" Girilen say�lardan NEGAT�F olanlar: \n");
	for (int y=0;y<BOYUT;y++) if (negatifler[y] != 0) printf(" %d ", negatifler[y]);
}

void divide (int *sayilar, int *negatifler, int *pozitifler, int boyut) {
	int n=0, p=0;
	for (int i=0;i<boyut;i++) {
		if (*(sayilar + i) < 0) { 
			*(negatifler + n) = *(sayilar + i);
			n++;
		}
		else {
			*(pozitifler + p) = *(sayilar + i);
			p++;
		}
	}
}