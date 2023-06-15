#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/* kullanýcýdan tarihi gün ay yýl olarak ayrý girdilerde isteme */

int main() {
 
	setlocale(LC_ALL, "Turkish");

	int gun;
	int ay;
	int yil;

	printf("gün giriniz: ");
	scanf("%d",&gun);
	printf("ay giriniz: ");
	scanf("%d",&ay);
	printf("yýl giriniz: ");
	scanf("%d",&yil);
	printf("tarih: %d - %d - %d", gun,ay,yil);

	return 0;
}










