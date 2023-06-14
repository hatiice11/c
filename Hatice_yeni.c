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
        printf("\nBir seçim yapýnýz.\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (userAdd() == 0) {
                    printf("\nRezervasyon baþarýlý bir þekilde oluþturuldu.\n");
                }
                break;
            case 2:
                printf("Resepsiyon telefon numarasý: +90 111 111 11 11\nBu numarayý arayarak resepsiyona doðrudan baðlanabilirsiniz.\n");
                break;
            case 3:
                menu();
                break;
            case 4:
                // Restoran iþlemleri
			setlocale(LC_ALL, "Turkish");
			anamenu();
			kahvalti();
			aksam();
			icecek();

                break;
            case 5:
                // Spor salonu iþlemleri
		

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
                printf("Programdan cikiliyor.... ------- Geliþim Oteli Spor Salonu ---\n");
                main();
                break;
           
        }
    } 
    while (1);

                break;
            case 6:
                printf("Çýkýþ yaptýnýz. Hoþçakalýn...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Lütfen 1 ile 6 arasýnda bir seçim yapýnýz.\n");
        }
    } while (choice != 6);

    return 0;
}

void menu()
{
    printf("*************************************************************\n");
    printf("-----------------------------------------------------------\n");
    printf("  ~~~~~~~~~~~~~ISTANBUL GELISIM OTELI ~~~~~~~~~~~~~  \n");
    printf("    1. Rezervasyon oluþturmak için 1'i seçiniz.'       	 		 \n");
    printf("    2. Resepsiyona Baðlanmak Ýçin 2'yi tuþlayýnýz.   \n");
    printf("    3. Ana Menüye Dönmek Ýçin 3'ü tuþlayýnýz.       \n");
    printf("    4. Restoran iþlemleri için 4'ü tuþlayýnýz.       	\n");
    printf("    5. Spor salonu iþlemleri için 5'i tuþlayýnýz.       		\n");
    printf("    6. Çýkýþ yapmak için 6'yý tuþlayýnýz.       		\n");
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
    printf("Ýsim giriniz: ");
    scanf("%s", newRecord.name);
    printf("Soyisim giriniz: ");
    scanf("%s", newRecord.lastname);
    printf("Telefon numarasý giriniz: ");
    scanf("%s", newRecord.phone);
    printf("Giriþ-Çýkýþ tarihi giriniz (örn: 11.11.2022-12.11.2022): ");
    scanf("%s", newRecord.tarih);
    printf("Oda tipi seçiniz:\n");
    printf("   *************************************\n");
    printf("           ~~~~Oda Tipleri~~~~\n");
    printf("   *************************************\n");
    printf("   [1] Tek Kiþilik Oda                           tek gecelik 500 TL\n");
    printf("   [2] Ýki Kiþilik Oda                           tek gecelik 600 TL\n");
    printf("   [3] Çekirdek Aile Tipi Oda (3 kiþi)           tek gecelik 700 TL\n");
    printf("   [4] Aile Tipi Oda (4 kiþi)                    tek gecelik 800 TL\n");
    printf("   [5] Geniþ Aile Tipi Oda (5-6 kiþi)            tek gecelik 900 TL\n");
    printf("   [6] Suit Oda (5-6 kiþi)                       tek gecelik 1000 TL\n");
    printf("   [7] Ekonomik Oda (2 kiþi)                     tek gecelik 400 TL\n");
    printf("   [8] Teras Katý Oda (3-4 kiþi)                 tek gecelik 1200 TL\n");
    printf("   [9] Jakuzili Oda (2-3 kiþi)                   tek gecelik 1500 TL\n");
    scanf("%d", &(newRecord.odaTipi));

    if (newRecord.odaTipi == 1) {
        printf("Tek kiþilik oda seçilmiþtir. Tek gecelik fiyatý 500 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 2) {
        printf("Ýki kiþilik oda seçilmiþtir. Tek gecelik fiyatý 600 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 3) {
        printf("Çekirdek Aile Tipi oda seçilmiþtir. Tek gecelik fiyatý 700 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 4) {
        printf("Aile Tipi oda seçilmiþtir. Tek gecelik fiyatý 800 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 5) {
        printf("Geniþ Aile Tipi oda seçilmiþtir. Tek gecelik fiyatý 900 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 6) {
        printf("Suit Tipi oda seçilmiþtir. Tek gecelik fiyatý 1000 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 7) {
        printf("Ekonomik oda seçilmiþtir. Tek gecelik fiyatý 400 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 8) {
        printf("Teras Katý oda seçilmiþtir. Tek gecelik fiyatý 1200 TL'dir.\n");
    }
    else if (newRecord.odaTipi == 9) {
        printf("Jakuzili oda seçilmiþtir. Tek gecelik fiyatý 1500 TL'dir.\n");
    }
    else {
        printf("Geçersiz oda tipi seçimi yapýldý.\n");
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
	printf("\n\t\t\t\t\t******* Ýstanbul Geliþim Restoraný ******\n");
	printf("\n\t\t\t\t***********************************************\n");
	printf("\n\t\t\t\t\t\tA.Kahvaltý Menüsü\n");
	printf("\n\t\t\t\t\t\tB.Akþam Yemeði Menüsü\n");
	printf("\n\t\t\t\t\t\tC.Ýçecekler\n");
	printf("\n\t\t\t\t\t\tD.Ana menü\n");
	printf("\n\t\t\t\t\t\tE.Ana Ekran\n");
	
	printf("\t  Lütfen seçiminizi giriniz: ");
  	scanf("%c", &secim);
  
  system("cls");/*Ekraný temizler ve ekranda verilerin görüntülenmesini saðlar.*/
  /*TOUPPER:Küçük harfi büyük harfe dönüþtürür.*/

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

void kahvalti() ///Kahvaltý Ekraný
{

  int secim = 0;
  int adet = 0;
  int yeni=0;
  
  printf("\t                              *************************************         \n");
  printf("\t                                      ***Kahvaltý Menüsü***  \n");
  printf("\t                              **************************************          \n\n");

  printf("\t   [1] Pancake                          45 TL\n");
  printf("\t   [2] Avokado Tost                    	50 TL\n");
  printf("\t   [3] Granola                          60 TL\n");
  printf("\t   [4] Sade Omlet    			50 TL\n");
  printf("\t   [5] Karýþýk Kahvaltý Tabaðý        	100 TL\n");
  printf("\t   [6] Kaþarlý Tost         		70 TL\n");
  printf("\t   [7] Patates Kýzartmasý           	50 TL\n");
  printf("\t   [8] Menemen 				65 TL\n");
  printf("\t   [9] Ana Menüye Dön        ");

  printf("\n\n \t  Seçiminizi giriniz : ");
  scanf("%d", &secim);
  
  if (secim == 1){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 45 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 2){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 50 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 3){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 60 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       
       if (secim == 4){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 50 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 5){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 100 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 6){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 70 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 7){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 50 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 8){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 65 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 kahvalti();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
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
            printf("\n\n\t\t   Yanlýþ numara girdiniz\n\n");
            kahvalti();
        }
  }

void aksam() /// Akþam yemeði Menüsü
{
  int secim;
  int adet;
  int yeni;

  printf("\t                              *************************************         \n");
  printf("\t                                      ***Akþam Yemeði Menüsü***  \n");
  printf("\t                              **************************************          \n\n");
  printf("\t   [1] Mercimek Çorbasý      40 TL\n");
  printf("\t   [2] Domates Çorbasý       40 TL\n");
  printf("\t   [3] Kremalý Makarna       70 TL\n");
  printf("\t   [4] Izgara Köfte         170 TL\n");
  printf("\t   [5] Izgara Tavuk Salata  150 TL\n");
  printf("\t   [6] Mantý                 90 TL\n");
  printf("\t   [7] Dana Rosto           350 TL\n");
  printf("\t   [8] Bolonez Soslu Makarna 150 TL\n");
  printf("\t   [9] Adana Kebap          250 TL\n");
  printf("\t   [10] Tavuk Burger        150 TL\n");
  printf("\t   [11] Sushi               250 TL\n");
  printf("\t   [12] Back To Main-Menu               \n");


  printf("\n \t  Seçiminizi giriniz : ");
  scanf("%d", &secim);
  
  if (secim == 1){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 40 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 2){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 40 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 3){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 70 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 4){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 170 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 5){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 150 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 6){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 90 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 7){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 350 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 8){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 150 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 9){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 250 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 10){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 150 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 11){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 250 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 aksam();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
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
            printf("\n\n\t\t   Yanlýþ numara girdiniz\n\n");
            aksam();
        }
}
void icecek() ///Kahvaltý Ekraný
{

  int secim = 0;
  int adet = 0;
  int yeni=0;
  
  printf("\t                              *************************************         \n");
  printf("\t                                      ***Ýçecekler***  \n");
  printf("\t                              **************************************          \n\n");

  printf("\t   [1] Su                       15 TL\n");
  printf("\t   [2] Çay                   	20 TL\n");
  printf("\t   [3] Kahve                    40 TL\n");
  printf("\t   [4] Türk Kahvesi    		40 TL\n");
  printf("\t   [5] Latte        		55 TL\n");
  printf("\t   [6] Kola         		25 TL\n");
  printf("\t   [7] Fanta           	        25 TL\n");
  printf("\t   [8] Ayran 			25 TL\n");
  printf("\t   [9] Ice Tea 			25 TL\n");
  printf("\t   [10] Ana Menüye Dön        ");

  printf("\n\n \t  Seçiminizi giriniz : ");
  scanf("%d", &secim);
  
  if (secim == 1){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 15 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 2){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 20 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 3){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 40 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
  
  if (secim == 4){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 40 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 5){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 55 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 6){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 25 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 7){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 25 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 8){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 25 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
				   exit(0);
				}
       }
       
       if (secim == 9){
  	printf("Kaç Adet : ");
	       scanf("%d", &adet);
           total = 25 * adet ;
           printf("*********************************          ");
           printf("\nToplam Tutar: %.2f TL\nÖdeme Türü: Nakit\n", total);
           printf("*********************************           \n");
	       printf("Baþka bir þey sipariþ vermek ister misiniz?\n[1] - Evet,[2] - Hayýr : ");
           scanf("%d", &yeni);
           system("cls");

			 if (yeni == 1 )
				 icecek();
			 else if (yeni == 2 )
                 anamenu();
			 else if (yeni != 1 , 2)
				{
				   printf("\n\n\t\tYanlýþ numara girdiniz\n\n");
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

    // kullanýcýdaan alýnan verileri kullanicilar.txt dosyasýna yazar.
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

