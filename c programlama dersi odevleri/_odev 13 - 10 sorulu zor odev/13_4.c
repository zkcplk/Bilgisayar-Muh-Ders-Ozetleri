//	Radyoaktif elementin k�tle (m_0) ve yar�lanma s�resi (dt) ve s�res (t) bilgisi 
//	fonksiyona g�nderilecektir. �lgili program�n C kodunu yaz�n�z. 
//	(n = t/dt) ve (m=m_0/2^n)

#include <stdio.h>
#include <math.h>
#include <locale.h>

void fonksiyon (double m_0, double dt, double t);

void main() {
	setlocale(LC_ALL, "Turkish");
	
	double m_0, dt, t;
	printf("L�tfen m_0 de�erini giriniz: ");
	scanf("%lf", &m_0);
	
	printf("L�tfen dt de�erini giriniz: ");
	scanf("%lf", &dt);
	
	printf("L�tfen t de�erini giriniz: ");
	scanf("%lf", &t);
	
	fonksiyon (m_0, dt, t);
}

void fonksiyon (double m_0, double dt, double t) { 
	double n = t/dt;
	double m = m_0/pow(2,n);
	printf("Fonksiyon sonucu: %lf", m);
}
