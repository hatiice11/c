#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/* kullan�c�dan tarihi g�n ay y�l olarak ayr� girdilerde isteme */

int main() {
 
	setlocale(LC_ALL, "Turkish");

	int gun;
	int ay;
	int yil;

	printf("g�n giriniz: ");
	scanf("%d",&gun);
	printf("ay giriniz: ");
	scanf("%d",&ay);
	printf("y�l giriniz: ");
	scanf("%d",&yil);
	printf("tarih: %d - %d - %d", gun,ay,yil);

	return 0;
}










