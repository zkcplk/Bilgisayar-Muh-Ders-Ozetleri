#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

int rndm(int limit, int ayni);

int main() {
	srand(time(0));
	
	char *parcali, *kelimeler[100], girilen_cumle[100];
	setlocale(LC_ALL, "Turkish");
	
	printf("L�tfen -K���K HARFL� B�R C�MLE- giriniz: ");
	gets(girilen_cumle);
	
	parcali = strtok(girilen_cumle, " ");
	kelimeler[0] = parcali;
	
	//	Kelimelerdeki iki harfin b�y�k olmas� istenmi�,
	//	3'ten k���k harfe sahip kelimelerle u�ra�mayal�m.
	int r1,r2,len=strlen(kelimeler[0]);
	if (len>2) { 
		r1=rndm(len,-1);
		r2=rndm(len,r1);
		
		kelimeler[0][r1] = toupper(kelimeler[0][r1]);
		kelimeler[0][r2] = toupper(kelimeler[0][r2]);
	}
	
	printf("%s ",kelimeler[0]);
	
	int i=1;
	while (parcali != NULL)  {
		kelimeler[i] = strtok(NULL, " ");
		
		if (kelimeler[i] != NULL) { 
			len=strlen(kelimeler[i]);

			if (len>2) { 
				r1=rndm(len,-1);
				r2=rndm(len,r1);
				
				kelimeler[i][r1] = toupper(kelimeler[i][r1]);
				kelimeler[i][r2] = toupper(kelimeler[i][r2]);
			}
			
			printf("%s ",kelimeler[i]);
		}
		
		i++;
	}

	return 0;
}

int rndm(int limit, int ayni) {
	// 0 ile limit aras�nda random say� �reteci
	int temp;
	
	
	if (ayni == -1) {
	//	ayn� say�dan bir daha �retmesin diye...
		while (1) {
			temp = rand();
			if (temp < limit) break;
		}
	}
	else {
		while (1) {
			temp = rand();
			if (temp < limit && ayni != temp) break;
		}
	}

	return temp;
}
