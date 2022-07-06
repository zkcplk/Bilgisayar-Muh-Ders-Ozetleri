#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
	int toplam;
	char girilen_cumle[100];
	char *parcali, *en_kucuk_kelime;
	setlocale(LC_ALL, "Turkish");
	
	printf("L�tfen bir C�MLE giriniz: ");
	gets(girilen_cumle);

	parcali = strtok (girilen_cumle, " ");
	toplam = strlen(parcali);
	en_kucuk_kelime = parcali;
	
	//	D�ng�l�
	int temp;
	while (parcali != NULL)  {
		parcali = strtok (NULL, " ");
		
		//	Bu k�s�m �nemli
		// 	D�ng� i�inde strlen() kullan�nca yeniden sorgulama yapmak gerekiyor.
		//	Aksi halde d�ng�de problem ��k�yor.
		// 	https://stackoverflow.com/questions/20305853/length-of-string-returned-by-strtok
		if (parcali != NULL) temp = strlen(parcali);
		
		if (toplam > temp) { 
			toplam = temp;
			en_kucuk_kelime = parcali;
		}
	}
	
	printf("\nGirilen c�mledeki en k�sa ilk kelime: %s", en_kucuk_kelime);
	return 0;
}