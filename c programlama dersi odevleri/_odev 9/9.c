#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

void dongu(int kacar);

int main() {
	int kacar;
	setlocale(LC_ALL,"Turkish");
	
	printf("0 ile 100 say�lar� aras�da ka�ar ka�ar saymak istersiniz?");
	scanf("%d",&kacar);
	dongu(kacar);
	
	return 0;
}

void dongu(int kacar) {
	int i=0;
	for (;i<101;i+=kacar) printf("%d\n",i);

	char cevap[5];
	printf("\n\nDevam etmek ister misiniz? evet/hay�r \n\n");
	scanf("%s",cevap);
	
	if (strcmp("evet",cevap)==0) {
		printf("0 ile 100 say�lar� aras�da ka�ar ka�ar saymak istersiniz?");
		scanf("%d",&kacar);
		dongu(kacar);
	}
	else printf("\n��lem bitmi�tir.");
}