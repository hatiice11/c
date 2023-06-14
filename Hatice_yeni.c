#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void kahvalti();
void aksam();
void icecek();
void anamenu();
void menu();
int userAdd();
float total;
char secim;
void kullaniciKaydi();
void kullaniciListeleDosya();

typedef struct {
    char name[30];
    char lastname[30];
    char phone[15];
    char tarih[10];
    int odaTipi;
} Record;


struct Kullanici {
    char ad[50];
    char soyad[50];
    int yas;
    char uyelik[20];
    int odemeYapildi;
};

struct Kullanici kullanicilar[100];
int kullaniciSayisi = 0;
int fitnes_secim;



int main()
{
    setlocale(LC_ALL, "Turkish");

    int choice = 0;
    menu();

    do {
        printf("\nBir se�im yap�n�z.\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (userAdd() == 0) {
                    printf("\nRezervasyon ba�ar�l� bir �ekilde olu�turuldu.\n");
                }
                break;
            case 2:
                printf("Resepsiyon telefon numaras�: +90 111 111 11 11\nBu numaray� arayarak resepsiyona do�rudan ba�lanabilirsiniz.\n");
                break;
            case 3:
                menu();
                break;
            case 4:
                // Restoran i�lemleri
			setlocale(LC_ALL, "Turkish");
			anamenu();
			kahvalti();
			aksam();
			icecek();

                break;
            case 5:
                // Spor salonu i�lemleri
		

    do {
        printf("\n ------ GELISIM Oteli Spor Salonuna Hosgeldiniz. ------\n");
        printf("---------------------\n");
        printf("1. Yeni Kullanici Kaydi\n");
        printf("2. Kullanicilari Listele\n");
        printf("3. cikis\n");
        printf("-----------------------\n");
        printf("Seciminizi yapin:");
        scanf("%d", &fitnes_secim);
        printf("-------------------\n");

        switch (fitnes_secim) {
            case 1:
                kullaniciKaydi();
                break;
            case 2:
                kullaniciListeleDosya();
                break;
            case 3:
                printf("Programdan cikiliyor.... ------- Geli�im Oteli Spor Salonu ---\n");
                main();
                break;
           
        }
    } 
    while (1);

                break;
            case 6:
                printf("��k�� yapt�n�z. Ho��akal�n...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("L�tfen 1 ile 6 aras�nda bir se�im yap�n�z.\n");
        }
    } while (choice != 6);

    return 0;
}

void menu()
{
    printf("*************************************************************\n");
    printf("-----------------------------------------------------------\n");
    printf("  ~~~~~~~~~~~~~ISTANBUL GELISIM OTELI ~~~~~~~~~~~~~  \n");
    printf("    1. Rezervasyon olu�turmak i�in 1'i se�iniz.'       	 		 \n");
    printf("    2. Resepsiyona Ba�lanmak ��in 2'yi tu�lay�n�z.   \n");
    printf("    3. Ana Men�ye D�nmek ��in 3'� tu�lay�n�z.       \n");
    printf("    4. Restoran i�lemleri i�in 4'� tu�lay�n�z.       	\n");
    printf("    5. Spor salonu i�lemleri i�in 5'i tu�lay�n�z.       		\n");
    printf("    6. ��k�� yapmak i�in 6'y� tu�lay�n�z.       		\n");
    printf("-----------------------------------------------------------\n");
    printf("*************************************************************\n");
}

int userAdd()
{
    Record newRecord;
    FILE* fptr;
    fptr = fopen("C:\\Users\\hatice\\Desktop\\projeler\\c proje\\verikaydi.txt", "a");

    if (fptr == NULL) {
        return -1;
    }

    printf("\n\n");
    printf("�sim giriniz: ");
    scanf("%s", newRecord.name);
    printf("Soyisim giriniz: ");
    scanf("%s", newRecord.lastname);
    printf("Telefon numaras� giriniz: ");
    scanf("%s", newRecord.phone);
    printf("Giri�-��k�� tarihi giriniz (�rn: 11.11.2022-12.11.2022): ");
    scanf("%s", newRecord.tarih);
    printf("Oda tipi se�iniz:\n");
    printf("   *************************************\n");
    printf("           ~~~~Oda Tipleri~~~~\n");
    printf("   *************************************\n");
    printf("   [1] Tek Ki�ilik Oda                           tek gecelik 500 TL\n");
    printf("   [2] �ki Ki�ilik Oda                           tek gecelik 600 TL\n");
    printf("   [3] �ekirdek Aile Tipi Oda (3 ki�i)           tek gecelik 700 TL\n");
    printf("   [4] Aile Tipi Oda (4 ki�i)                    tek gecelik 800 TL\n");
    printf("   [5] Geni� Aile Tipi Oda (5-6 ki�i)            tek gecelik 900 TL\n");
    printf("   [6] Suit Oda (5-6 ki�i)                       tek gecelik 1000 TL\n");
    printf("   [7] Ekonomik Oda (2 ki�i)                     tek gecelik 400 TL\n");
    printf("   [8] Teras Kat� Oda (3-4 ki�i)                 tek gecelik 1200 TL\n");
    printf("   [9] Jakuzili Oda (2-3 ki�i)                   tek gecelik 1500 TL\n");
    scanf("%d", &(newRecord.odaTipi));

    if (newRecord.odaTipi == 1) {
        printf("Tek ki�ilik oda se�ilmi�tir. Tek gecelik fiyat� 500 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 2) {
        printf("�ki ki�ilik oda se�ilmi�tir. Tek gecelik fiyat� 600 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 3) {
        printf("�ekirdek Aile Tipi oda se�ilmi�tir. Tek gecelik fiyat� 700 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 4) {
        printf("Aile Tipi oda se�ilmi�tir. Tek gecelik fiyat� 800 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 5) {
        printf("Geni� Aile Tipi oda se�ilmi�tir. Tek gecelik fiyat� 900 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 6) {
        printf("Suit Tipi oda se�ilmi�tir. Tek gecelik fiyat� 1000 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 7) {
        printf("Ekonomik oda se�ilmi�tir. Tek gecelik fiyat� 400 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 8) {
        printf("Teras Kat� oda se�ilmi�tir. Tek gecelik fiyat� 1200 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 9) {
        printf("Jakuzili oda se�ilmi�tir. Tek gecelik fiyat� 1500 TL'dir.\n");
    }
    else {
        printf("Ge�ersiz oda tipi se�imi yap�ld�.\n");
        return -1;
    }

    fprintf(fptr, "%s %s %s %s %d\n", newRecord.name, newRecord.lastname, newRecord.phone, newRecord.tarih, newRecord.odaTipi);
    fclose(fptr);

    return 0;
}

void anamenu()
{
	char secim = ' ' ;
	printf("\n\t\t\t\t***********************************************\n");
	printf("\n\t\t\t\t\t******* �stanbul Geli�im Restoran� ******\n");
	printf("\n\t\t\t\t***********************************************\n");
	printf("\n\t\t\t\t\t\tA.Kahvalt� Men�s�\n");
	printf("\n\t\t\t\t\t\tB.Ak�am Yeme�i Men�s�\n");
	printf("\n\t\t\t\t\t\tC.��ecekler\n");
	printf("\n\t\t\t\t\t\tD.Ana men�\n");
	printf("\n\t\t\t\t\t\tE.Ana Ekran\n");
	
	printf("\t  L�tfen se�iminizi giriniz: ");
  	scanf("%c", &secim);
  
  system("cls");/*Ekran� temizler ve ekranda verilerin g�r�nt�lenmesini sa�lar.*/
  /*TOUPPER:K���k harfi b�y�k harfe d�n��t�r�r.*/

    {
		if (toupper(secim) == 'A')
              kahvalti();
              
          else if (toupper(secim) == 'B')
              aksam(); 
        else if (toupper(secim) == 'C')
              icecek(); 
        else if (toupper(secim) == 'E')
              main(); 
        else{
               anamenu();
            }
	}

}

void kahvalti() ///Kahvalt� Ekran�
{

  int secim = 0;
  int adet = 0;
  int yeni=0;
  
  printf("\t                              *************************************         \n");
  printf("\t                                      ***Kahvalt� Men�s�***  \n");
  printf("\t                              **************************************          \n\n");

  printf("\t   [1] Pancake                          45 TL\n");
  printf("\t   [2] Avokado Tost                    	50 TL\n");
  printf("\t   [3] Granola                          60 TL\n");
  printf("\t   [4] Sade Omlet    			50 TL\n");
  printf("\t   [5] Kar���k Kahvalt� Taba��        	100 TL\n");
  printf("\t   [6] Ka�arl� Tost         		70 TL\n");
  printf("\t   [7] Patates K�zartmas�           	50 TL\n");
  printf("\t   [8] Menemen 				65 TL\n");
  printf("\t   [9] Ana Men�ye D�n        ");

  printf("\n\n \t  Se�iminizi giriniz : ");
  scanf("%d", &secim);
  
  if (secim == 1){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 45 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 2){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 50 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 3){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 60 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       
       if (secim == 4){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 50 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 5){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 100 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 6){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 70 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 7){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 50 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 8){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 65 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       else if ( secim == 9 )
        {
            anamenu();

        }
    else if (secim != 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9)
        {
            system("cls");
            printf("\n\n\t\t   Yanl�� numara girdiniz\n\n");
            kahvalti();
        }
  }

void aksam() /// Ak�am yeme�i Men�s�
{
  int secim;
  int adet;
  int yeni;

  printf("\t                              *************************************         \n");
  printf("\t                                      ***Ak�am Yeme�i Men�s�***  \n");
  printf("\t                              **************************************          \n\n");
  printf("\t   [1] Mercimek �orbas�      40 TL\n");
  printf("\t   [2] Domates �orbas�       40 TL\n");
  printf("\t   [3] Kremal� Makarna       70 TL\n");
  printf("\t   [4] Izgara K�fte         170 TL\n");
  printf("\t   [5] Izgara Tavuk Salata  150 TL\n");
  printf("\t   [6] Mant�                 90 TL\n");
  printf("\t   [7] Dana Rosto           350 TL\n");
  printf("\t   [8] Bolonez Soslu Makarna 150 TL\n");
  printf("\t   [9] Adana Kebap          250 TL\n");
  printf("\t   [10] Tavuk Burger        150 TL\n");
  printf("\t   [11] Sushi               250 TL\n");
  printf("\t   [12] Back To Main-Menu               \n");


  printf("\n \t  Se�iminizi giriniz : ");
  scanf("%d", &secim);
  
  if (secim == 1){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 40 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 2){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 40 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 3){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 70 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 4){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 170 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 5){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 150 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 6){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 90 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 7){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 350 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 8){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 150 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 9){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 250 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 10){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 150 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 11){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 250 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       else if ( secim == 12 )
        {
            anamenu();

        }
    else if (secim != 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9, 10, 11 ,12)
        {
            system("cls");
            printf("\n\n\t\t   Yanl�� numara girdiniz\n\n");
            aksam();
        }
}
void icecek() ///Kahvalt� Ekran�
{

  int secim = 0;
  int adet = 0;
  int yeni=0;
  
  printf("\t                              *************************************         \n");
  printf("\t                                      ***��ecekler***  \n");
  printf("\t                              **************************************          \n\n");

  printf("\t   [1] Su                       15 TL\n");
  printf("\t   [2] �ay                   	20 TL\n");
  printf("\t   [3] Kahve                    40 TL\n");
  printf("\t   [4] T�rk Kahvesi    		40 TL\n");
  printf("\t   [5] Latte        		55 TL\n");
  printf("\t   [6] Kola         		25 TL\n");
  printf("\t   [7] Fanta           	        25 TL\n");
  printf("\t   [8] Ayran 			25 TL\n");
  printf("\t   [9] Ice Tea 			25 TL\n");
  printf("\t   [10] Ana Men�ye D�n        ");

  printf("\n\n \t  Se�iminizi giriniz : ");
  scanf("%d", &secim);
  
  if (secim == 1){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 15 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 2){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 20 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 3){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 40 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
  
  if (secim == 4){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 40 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 5){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 55 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 6){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 25 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 7){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 25 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 8){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 25 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 9){
  	printf("Ka� Adet : ");
	       scanf("%d", &adet);
           total = 25 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\n�deme T�r�: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Ba�ka bir �ey sipari� vermek ister misiniz?\n[1] - Evet,[2] - Hay�r : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanl�� numara girdiniz\n\n");
				   exit(0);
				}
       }
}

// mustafa

void kullaniciKaydi() {
    struct Kullanici yeniKullanici;

    printf("Ad: ");
     scanf("%s", yeniKullanici.ad);

     printf("Soyad: ");
    scanf("%s", yeniKullanici.soyad);
 
    printf("Yas: ");
     scanf("%d", &yeniKullanici.yas);

   printf("uyelik Turu ? (Gunluk-Aylik-Yillik) ");
    scanf("%s", yeniKullanici.uyelik);

       printf("odeme Yapildi mi? (1: Evet, 0: Hayir): ");
       scanf("%d", &yeniKullanici.odemeYapildi);

    kullanicilar[kullaniciSayisi++] = yeniKullanici;

    printf("Kullanici basariyla kaydedildi.\n");

    // kullan�c�daan al�nan verileri kullanicilar.txt dosyas�na yazar.
    FILE *dosya = fopen("kullanicilar.txt", "a");
    
    fprintf(dosya, "Ad: %s\n", yeniKullanici.ad);
    fprintf(dosya, "Soyad: %s\n", yeniKullanici.soyad);
    fprintf(dosya, "Yas: %d\n", yeniKullanici.yas);
    fprintf(dosya, "uyelik Turu: %s\n", yeniKullanici.uyelik);
    fprintf(dosya, "---------------------------\n");

    fclose(dosya);
}

void kullaniciListeleDosya() {  
printf(" -*-*-*-*- Kayitli Kullanicilar -*-*-*-* \n");
    FILE *dosya = fopen("kullanicilar.txt", "r");


    char satir[100];
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        printf("%s", satir);
    }

    fclose(dosya);
}

