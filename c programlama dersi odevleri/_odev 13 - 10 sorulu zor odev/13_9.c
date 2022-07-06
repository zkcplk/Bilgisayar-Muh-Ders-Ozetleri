//	A dizisi, bu dizinin eleman say�s� ve B dizisi,
//	tekil fonksiyonuna arg�ment olarak verilecektir. 
//	�ndisleri tek say� olan A dizisi elemanlar�, 
//	B dizisine kopyalanacakt�r.
//	Bunun i�in gerekli olan C program kodunu yaz�n�z.

#include <stdio.h>
#include <locale.h>
#define BOYUT 10

void tekil (int *diziA, int boyut, int *diziB);
void main() {
	setlocale(LC_ALL, "Turkish");
	int A[BOYUT] = {10,20,30,40,50,60,70,80,90,100};
	int B[BOYUT] = {0,0,0,0,0,0,0,0,0,0};
	
	printf(" A dizisinde indisleri tek olan elemanlar: %d %d %d %d %d \n",A[1],A[3],A[5],A[7],A[9]);
	printf(" B dizisine aktar�lan elemanlar: \n");
	tekil (A, BOYUT, B);
	
	for (int z=0;z<BOYUT;z++) 
		printf(" %d\n",B[z]);
}

void tekil (int *diziA, int boyut, int *diziB) {
	int b=0;
	for (int i=0;i<boyut;i++) {
		if (i % 2 != 0) { 
			*(diziB + b) = *(diziA + i);
			b++;
		}
	}
}
