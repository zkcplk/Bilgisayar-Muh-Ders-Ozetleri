//	Maksimum boyutu 1000 karakterlik bir string (klavyeden girilecektir) 
//	i�erisinde istenilen karakterden ka� tane oldu�unu bulan C program�n� yaz�n�z.

#include <stdio.h>
#include <string.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Turkish");
	
	char karakter, string[1000];
	printf("L�tfen max 1000 karakter olacak bir yaz� giriniz: ");
	gets(string);
	
	fflush(stdin);
	
	printf("\nL�tfen girdi�iniz metinde aranacak olan karakteri giriniz: ");
	scanf("%c", &karakter);
	
	int toplam, len=strlen(string);
	for (int i=0; i<len; i++) if (string[i] == karakter) toplam++;
	
	printf("Girdi�iniz metinde bulunan %c say�s�: %d", karakter, toplam);
}