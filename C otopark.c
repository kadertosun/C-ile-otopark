#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Kullanacaðým fonksiyonlarým
void arac_ekle();
void arac_listele();
void arac_ara();
void arac_sil();
void cikis();
void musteri_ekle();
void musteri_listele();
void musteri_ara();
void musteri_sil();
void kirala();
void iade();


//Yapýlar
struct Arac
{
	int plaka;
	char model[50];
	char renk[50];
	int ucret;
	int musait;
	
	
}arc;

struct musteri
{
	int musteri_no;
	char isim[50];
	char soyisim[50];
	char memleket[50];
	
	
}mstr;

struct kiralama
{
	int plaka;
	int musteri_no;
	char kiralama_tarihi[10];
	char iade_tarihi[10];
}krlm;



int main() 
{
	int secim,secim1,secim2,secim3;
	printf("\n\n\t\t\t\t\t**~**~ ARAC KIRALAMA OTOMASYONU ~**~**\n\n");
	printf("\t\t\t\t\t[1]->Arac Islemleri\n\n");
	printf("\t\t\t\t\t[2]->Musteri Islemleri\n\n");
	printf("\t\t\t\t\t[3]->Kiralama Islemleri\n\n");
	printf("\t\t\t\t\tLutfen Seciminizi Giriniz:");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1:
			printf("1.Arac Ekle\n");
			printf("2.Arac Listele\n");
			printf("3.Arac Ara\n");
			printf("Arac Sil\n");
			printf("5.Cikis\n");
			scanf("%d",&secim1);
			switch(secim1)
			{
				case 1:
					arac_ekle();
					break;
					case 2:
						arac_listele();
						break;
						case 3:
							arac_ara();
							break;
							case 4:
								arac_sil();
								break;
				
			}
			break;
			case 2:
				printf("1.Musteri Ekle\n");
				printf("2.Musteri Listele\n");
				printf("3.Musteri Ara\n");
				printf("4.Musteri Sil\n");
				printf("5.Cikis\n");
				scanf("%d",&secim2);
				switch(secim2)
				{
					case 1:
						musteri_ekle();
						break;
						case 2:
							musteri_listele();
							break;
							case 3:
								musteri_ara();
								break;
				}
				break;
				case 3:
					printf("1.Kirala\n");
					printf("2.iade\n");
					printf("Cikis\n");
					switch(secim3)
					{
						case 1:
							kirala();
							break;
							case 2:
								iade();
								break;
					}
					break;
		
}
return 0;
}

  void arac_ekle()
  {
  	struct arac;
  	FILE *dosya;
  	dosya=fopen("arac.txt","a");
  	printf("Arac Model:\n");
  	scanf("%s",& arc.model);
  	printf("Arac Plaka(Turu int olarak belirlendigi icin Harf kullanmayiniz):\n");
  	scanf("%d", &arc.plaka);
  	printf("Arac Rengi:\n");
  	scanf("%s", &arc.renk);
  	printf("Arac Ucret:(Turu int olarak belirlendigi icin virgulu deger kullanmayiniz)\n");
  	scanf("%d",& arc.ucret);
  	printf("Arac Musait mi?");
  	scanf("%d",& arc.musait);
  	
  	fprintf(dosya,"%s %d %s %d %d\n",arc.model,arc.plaka,arc.renk,arc.ucret,arc.musait);
  	fclose(dosya);
  }
void arac_listele()
{
	
	struct arac;
	FILE *dosya;
	dosya=fopen("arac.txt","r");

	while(!feof(dosya))
	printf("%c",fgetc(dosya));
	fclose(dosya);
	getchar();
}
	
	

void arac_ara()
{
	struct arac;
	FILE *dosya;
    if(( dosya=fopen("arac.txt","r"))==NULL)
   {
  	printf("Kayitli arac yok");
   }
    while(!feof(dosya))
	printf("%c",fgetc(dosya));
	fclose(dosya);
	getchar();
		
}
void arac_sil()
{
FILE *dosya;
if(dosya=fopen("arac.txt","r"))
{
	int plakaa;
	FILE *dosya1=fopen("arac2.txt","w");
	printf("silinecek plaka");
	scanf("%d",&plakaa);

}


}
void musteri_ekle()
{
	struct musteri;
	FILE *F1;
	F1=fopen("musteri.txt","a");
	
	
  	printf("Musteri no:\n");
    scanf("%d",& mstr.musteri_no);
  	  
  	printf("Musteri isim:\n");
  	scanf("%s", &mstr.isim);
  	  
  	printf("Musteri Soyisim:\n");
  	scanf("%s", &mstr.soyisim);
  	  
  	printf("Musteri Memleket\n");
  	scanf("%s",& mstr.memleket);
  	
  	fprintf(F1," %d %s %s %s\n",mstr.musteri_no,mstr.isim,mstr.soyisim,mstr.memleket);
  	fclose(F1);
	
}
void musteri_listele()
{
	
	struct musteri;
	FILE *F1;
	F1=fopen("musteri.txt","r");

	while(!feof(F1))
	printf("%c",fgetc(F1));
	fclose(F1);
	getchar();
}
void musteri_ara()
{
	
 printf("Aradiginiz Musternin Adini Giriniz:");
 char aranan[30];  
 scanf("%s",aranan);
 int bayrak=0;
 FILE *F1=fopen("musteri.txt","r");  
 
 while(!feof(F1))
 {
fscanf(F1,"%d %s %s %s \n",&mstr.musteri_no,&mstr.isim,&mstr.soyisim,&mstr.memleket);
if(strcmp(mstr.isim,aranan)==0)
{  
    bayrak=1;  
    printf("Musteri no:%d\n Musteri Adi:%s\n Musteri Soyadi:%s\n Musteri Memleket %s\n",mstr.musteri_no,mstr.isim,mstr.soyisim,mstr.memleket);
    }
    if(bayrak==0)
    printf("Aradiginiz Musteri BULUNAMADI..!\n");
    fclose(F1);  
    }

}

void kirala()
{
    struct arac;  
  	struct kiralama;
  	FILE *d;
  	d=fopen("kirala.txt","a");
  	
  	printf("Arac Plakasi:\n");
  	scanf("%d",&krlm.plaka );
  	
  	printf("Musteri No:\n");
  	scanf("%d", &krlm.musteri_no);
  	
  	printf("Kiralama Tarihi:\n");
  	scanf("%s", &krlm.kiralama_tarihi);
  	
  	fprintf(d," %d %d %s \n",krlm.plaka,krlm.musteri_no,krlm.kiralama_tarihi);
  	if(arc.musait==0)
  	{
  		printf("Bu arac musait degil");
    }
	  else if(arc.musait==1)
	  {
	  	printf("Arac Kiralandi");
	  	arc.musait=0;
	  }
  	fclose(d);
  
	
}
void iade()
{
	FILE *F1;
	int kaldigi_gun;
	  	printf("Arac Plakasi:\n");
  	scanf("%d",&krlm.plaka );
  	printf("Iade Tarihi:\n");
  	scanf("%s", &krlm.kiralama_tarihi);
  	fprintf(F1," %d  %s \n",krlm.plaka,krlm.iade_tarihi);
  	kaldigi_gun=(krlm.iade_tarihi-krlm.kiralama_tarihi);
  	printf("aracin musteride kaldýgý gun sayisi:%d",kaldigi_gun);
}


	
                                

