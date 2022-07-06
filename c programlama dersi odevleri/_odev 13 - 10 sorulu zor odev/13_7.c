//	Klavyeden dizi eleman say�s� girilecektir. Her bir eleman�n giri�i yap�lacakt�r.
//	Ard�ndan istenilen bir eleman, dizi i�erisinde aranacak, bulunursa indisi d�nd�r�lecek.
//	Aranan eleman dizi i�erisinde bulunamazsa, -1 de�eri d�necektir.
//	(Pointer Kullan�lacak)

#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Turkish");
	
	int n;
	printf("Dizi ka� elemanl� olsun?: ");
	scanf("%d", &n);
	printf("---------------------------\n");
	
	int temp, dizi[n];
	for (int i=0;i<n;i++) {
		printf("L�tfen %d. eleman� %d. indisi giriniz: ", (i+1), i);
		scanf("%d", &temp);
		*(dizi + i) = temp;
	}
	
	int ara, sonuc=-1;
	printf("L�tfen dizide aranacak eleman� giriniz: ");
	scanf("%d", &ara);
	
	for (int z=0;z<n;z++) {
		if (*(dizi + z) == ara) {
			sonuc = z;
			break;
		}
	}
	
	printf("Bulunan indis: %d", sonuc);
}
