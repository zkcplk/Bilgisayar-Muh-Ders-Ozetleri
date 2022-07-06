#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include<locale.h>

int *intMallocKur (int boyut, ...);
int *enKucuk (int boyut, int *dizi);

int main() {
	setlocale(LC_ALL, "Turkish");
	
	int buffer[5];
	printf("Program ba�l�yor: En fazla 5 adet tam say� girilebilir!\n\n");
	
	int temp, i = 0;
	while (1) {
		printf("L�tfen tam say� giriniz: ");
		scanf("%d", &temp);
		
		if (temp == 0) {
			printf("\nToplam %d adet say� girdiniz...\n\n",i);
			
			if (i == 2) {
				int *min = enKucuk(i,intMallocKur(i,buffer[0],buffer[1]));
				printf("Min De�er:%d, Min. De�er Pointer: %d\n", *min, min);
				free(min);
			}
			else if (i == 3) {
				int *min = enKucuk(i,intMallocKur(i,buffer[0],buffer[1],buffer[2]));
				printf("Min De�er:%d, Min. De�er Pointer: %d\n", *min, min);
				free(min);
			}
			else if (i == 4) {
				int *min = enKucuk(i,intMallocKur(i,buffer[0],buffer[1],buffer[2],buffer[3]));
				printf("Min De�er:%d, Min. De�er Pointer: %d\n", *min, min);
				free(min);
			}
			else if (i == 5) {
				int *min = enKucuk(i,intMallocKur(i,buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]));
				printf("Min De�er:%d, Min. De�er Pointer: %d\n", *min, min);
				free(min);
			}
			else {
				printf("EKS�K VEYA FAZLA SAYI G�RD�N�Z!");
			}
			
			break;
		}
		else buffer[i] = temp;
		
		i++;
	}
	
	return 0;
}


int *intMallocKur (int boyut, ...) {
	int *dizi=(int*)malloc(boyut*sizeof(int));

	va_list ag;
	va_start (ag, boyut);  
	
	int i;
	for (i = 0; i < boyut; i++)
		dizi[i] = va_arg (ag, int);    

	va_end (ag);
	  
	return dizi;
}


int *enKucuk (int boyut, int *dizi) {
	int m, *min;
	
	min = dizi;
	
	for (m = 0; m < boyut; m++) 
		if (*(dizi + m) < *min) 
			min = (dizi + m);

	return min;
}