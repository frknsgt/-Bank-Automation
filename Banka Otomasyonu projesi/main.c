#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
typedef struct
{
   long long tc;
   int musteriNo;
   int Bakiye;

}musteri;
int main()
{
    printf("*****************************BAF BANK*****************************");
    int menu,b_t;
    int tempbakiye=0,kontrol,h_secenek,noKontrol=0,m_indis=0,para=0;
    char dosyaAdi[12];
    while(1)
    {//******************************ANA MENU VE ALT MENULER**********************
    printf("\n\n***************************ANA MENU***************************");
    printf("\n1-Musteri Ekle\n2-Musteri Sil\n3-Musteri Islemleri\n4-Banka Raporu Al\n5-Dekont Al\n6-Cikis Yap:");
    printf("\n\nBir secim yapiniz:");
    scanf("%d",&menu);
    switch(menu)
    {
        //******************************MUSTERI EKLEME MENUSU*********************
    case 1:
        printf("\n**********Musteri Ekle**********");
        printf("\n\t1-Ticari\n\t2-Bireysel");
        while(1)
        {
        printf("\nTicari-Bireysel Seciniz:");
        scanf("%d",&b_t);
        if(b_t==1)
            {   char dosyaAdi[10];
                strcpy(dosyaAdi,"Ticari.txt");
                MusteriEkle(dosyaAdi);  break;
            }
        else if(b_t==2)
            {   char dosyaAdi[12];
                strcpy(dosyaAdi,"Bireysel.txt");
                MusteriEkle(dosyaAdi);  break;
            }
        else
            printf("Yanlis secim yaptiniz !");
        }
        break;
        //*****************************MUSTERI SILME MENUSU************************
   case 2:
        printf("\n**************************Musteri Sil**************************");
        printf("\n\t1-Ticari\n\t2-Bireysel");
        tempbakiye=0;noKontrol=0;m_indis=0;para=0;	int k=0; 
        while(1)
        {kontrol=0;
        printf("\nTicari-Bireysel Seciniz:");
        scanf("%d",&b_t);
        if(b_t==1)
            {strcpy(dosyaAdi,"Ticari.txt"); k=1;
			printf("Musteri Numaranizi Giriniz:");
    		scanf("%d",&noKontrol);
			MusteriBul(&noKontrol,&m_indis,dosyaAdi,&tempbakiye,&kontrol);
			printf("\n\n");
			if(kontrol==1)
			{if(tempbakiye==0)
			{
			MusteriUpdate(&para,m_indis,dosyaAdi,k);
			printf("\nMusteri Kaydiniz Basariyla silinmistir!");
			}
			else
			printf("Silme islemi icin bakiyeniz '0' olmalidir!");
			break;}}
        else if(b_t==2)
            {strcpy(dosyaAdi,"Bireysel.txt"); k=1;
			printf("Musteri Numaranizi Giriniz:");
    		scanf("%d",&noKontrol);
			MusteriBul(&noKontrol,&m_indis,dosyaAdi,&tempbakiye,&kontrol);
			printf("\n\n");
			if(kontrol==1)
			{if(tempbakiye==0)
			{
			MusteriUpdate(&para,m_indis,dosyaAdi,k);
			printf("\nMusteri Kaydiniz Basariyla silinmistir!");
			}
			else
			printf("Silme islemi icin bakiyeniz '0' olmalidir!");
		 	break;}}
        else
            printf("Yanlis secim yaptiniz !");
        }
        break;
        //************************MUSTERI ISLEMLERI MENUSU**************************
    case 3:
        printf("\n**************************Musteri Islemleri**************************");
        printf("\n\t1-Ticari\n\t2-Bireysel");
        tempbakiye=0;noKontrol=0;m_indis=0;para=0;
        char dosyaTicari[10],dosyaBireysel[12];
        while(1)
        {
        printf("\nMusteri Turunu Seciniz:");
        scanf("%d",&b_t);
        if(b_t==1)
            {strcpy(dosyaTicari,"Ticari.txt");
			strcpy(dosyaAdi,dosyaTicari);	break;}
        else if(b_t==2)
            {strcpy(dosyaBireysel,"Bireysel.txt");
			strcpy(dosyaAdi,dosyaBireysel);	break;}
        else
        printf("Yanlis Deger Girdiniz!");
        }
    printf("Musteri Numaranizi Giriniz:");
    scanf("%d",&noKontrol);
    MusteriBul(&noKontrol,&m_indis,dosyaAdi,&tempbakiye,&kontrol);
    int kontrolHavale=0;
            if(kontrol==1)
            {
            	printf("\n\n*******Hesap Islemleri Menusu*******");
		printf("\n1-Hesaba Para Yatirma\n2-Hesaptan Para Cekme\n3-Hesaptan Hesaba Havale\n");
	    while(1)    {
            printf("\n\nYapacaginiz Islemi seciniz:");
            scanf("%d",&h_secenek);

            if(h_secenek==1)
            {
                //*************************para yatirma islemi************************
                printf("Yatirmak istediginiz miktari giriniz:");
                scanf("%d",&para);
                BankaRapor(para,h_secenek);
                Dekont(noKontrol,para);
                if(b_t==2)
                MusteriUpdate(&para,m_indis,dosyaBireysel);
                if(b_t==1)
                MusteriUpdate(&para,m_indis,dosyaTicari);
                break;
            }
            else if(h_secenek==2)
            {
                //*************************para cekme islemi**************************
                if(tempbakiye==0)
                {printf("\nBakiye Yetersiz!");	break;}
                printf("Cekmek istediginiz miktari giriniz:");
                scanf("%d",&para);
                if((b_t==2&&para>750)||(b_t==1&&para>1500))
                printf("\nGunluk para cekme limitiniz yetersiz!");
                else{
                if(tempbakiye>=para)
                {BankaRapor(para,h_secenek);
				para=para*(-1);
				Dekont(noKontrol,para);
                if(b_t==2)
                MusteriUpdate(&para,m_indis,dosyaBireysel);
				if(b_t==1)
                MusteriUpdate(&para,m_indis,dosyaTicari);}
                else
                printf("\nBakiye Yetersiz!");
            }
                break;
            }
            else if(h_secenek==3)
            {
                //****************************havale islemi****************************
                int no_havale,m2_indis=0,bosBakiye=tempbakiye;	k=2;kontrol=0;
                if(tempbakiye==0)
                {printf("\nBakiye Yetersiz!");	break;}
                printf("Gondereceginiz Musteri No Giriniz:");
                scanf("%d",&no_havale);
                MusteriBul(&no_havale,&m2_indis,dosyaAdi,&tempbakiye,&kontrol);
                if(kontrol==1)
                {printf("\nGondermek istediginiz miktari giriniz:");
                scanf("%d",&para);
                if(bosBakiye>=para)
                {Dekont(noKontrol,para,no_havale,k);
				para=para*(-1);
                if(b_t==2)
                MusteriUpdate(&para,m_indis,dosyaBireysel,k,m2_indis,b_t);
				if(b_t==1)
                MusteriUpdate(&para,m_indis,dosyaTicari,k,m2_indis);}
                else
                printf("\nBakiye Yetersiz!");}
                break;
            }
            else
            printf("Yanlis deger girdiniz tekrar deneyiniz!\n");
        }}
        break;
    case 4:
      	printf("\n**************************Banka Gelir-Gider Raporu**************************"); 	
      	BankaRaporAl();
      	break;
    case 5:
        printf("\n*******************************Dekont Yaziliyor*******************************");
		DekontAl();
		break;	
		//***********************************CIKIS VE KONTROL ISLEMI********************************
    case 6:
        printf("\nProgram Sonlandirildi!\n");
        exit(1);
    default:
        printf("\nYanlis secim yaptiniz !");
    }
    }
    return 0;
}

//**********************************MUSTERI EKLEMEK ICIN KULLANILAN FONKSIYON*************************
int MusteriEkle(char dosyaAdi[])
{
    musteri m;
    FILE *dosya;
    dosya=fopen(dosyaAdi,"a+");
    printf("Tc Numaranizi Giriniz:");
    scanf("%lld",&m.tc);
    srand(time(NULL));
    m.musteriNo=1000+rand()%9999;
   	printf("Musteri Numaraniz:%d",m.musteriNo);
    m.Bakiye=0;
    fprintf(dosya,"%lld",m.tc);
    fprintf(dosya," %d",m.musteriNo);
    fprintf(dosya," %d\n",m.Bakiye);
    printf("\nMusteri basari ile eklendi!");
    fclose(dosya);
}
//*************************************MUSTERIYI DOSYADAN OKUYUP BULAN FONKSIYON*************************
int MusteriBul(int *noKontrol,int *i,char dosyaAdi[],int *tempbakiye,int *Kontrol)
{
    musteri m,tempX;
    FILE *dosya;
    dosya=fopen(dosyaAdi,"a+");
    while(!feof(dosya))
    {
        fseek(dosya,0,SEEK_CUR);
        fscanf(dosya,"%lld %d %d",&tempX.tc,&tempX.musteriNo,&tempX.Bakiye);
    if(*noKontrol==tempX.musteriNo)
    {   *Kontrol=1;
        printf("\n\n*****Musteri Bilgileriniz*****");
		printf("\nTc No: %lld\nMusteri No: %d\nBakiye: %d",tempX.tc,tempX.musteriNo,tempX.Bakiye);
        *tempbakiye=tempX.Bakiye;
        break;
    }
    *i=*i+1;
    }
    if(*noKontrol!=tempX.musteriNo)
       {
        *Kontrol=0;
        printf("\nMusteri Kaydi Bulunamadi!");
       }
        fclose(dosya);
}
//*******************DINAMIK BELLEK YARDIMIYLA TUM DOSYANIN OKUNUP VERILERIN GUNCELLENMESI***************
int MusteriUpdate(int *para,int indis,char dosyaAdi[],int k,int indis2,int b_t)
{
    int i=0,a=0,*Mno,no,bakiye,*Mbakiye;
    long long tc,*Mtc;
    FILE *dosya;
    dosya=fopen(dosyaAdi,"r");
    while(!feof(dosya))
    {
    fseek(dosya,0,SEEK_CUR);
    fscanf(dosya,"%lld %d %d",&tc,&no,&bakiye);  a++;
    }
    Mno=(int*)malloc(sizeof(int)*a);
    Mtc=(long long*)malloc(sizeof(long long)*a);
    Mbakiye=(int*)malloc(sizeof(int)*a);
    rewind(dosya);
    while(!feof(dosya))
    {
        fseek(dosya,0,SEEK_CUR);
        fscanf(dosya,"%lld %d %d",&tc,&no,&bakiye);
        if(no!=Mno[i-1])
            {Mno[i]=no; Mbakiye[i]=bakiye; Mtc[i]=tc;}
        else
            i--;
        i++;
    }
    fclose(dosya);
	if(k==2&&b_t==2)
	*(Mbakiye+indis2)+=((*para)-ceil((*para)*2/100))*(-1);
	else if(k==2)
	*(Mbakiye+indis2)+=(*para)*(-1);
    *(Mbakiye+indis)+=*para;
    FILE *dosya1;
    dosya1=fopen(dosyaAdi,"w");
    for(i=0;i<a-1;i++){
    	if((k==1)&&(indis==i))
    	{
		i++;	if(indis==i&&(a-1)==i)	break;}
    fprintf(dosya1,"%lld",Mtc[i]);
    fprintf(dosya1," %d",Mno[i]);
    fprintf(dosya1," %d\n",Mbakiye[i]);
    if(i==0)
    if(k!=1)
    printf("\n\n*****Guncel Hesap Bilgileriniz*****\nTc No:%lld\nMusteri No:%d\nBakiye:%d\n",Mtc[indis],Mno[indis],Mbakiye[indis]);
    }
    fclose(dosya1);
}
//*******************RAPOR.TXT DOSYASININ YAZILMA KISMI*********************
int BankaRapor(int para,int secenek)
{	
	int bulunan=0,gelen=0,giden=0;
	FILE *dosya;
	dosya=fopen("Rapor.txt","r");
	fscanf(dosya,"%d %d %d",&gelen,&giden,&bulunan);
	if(secenek==1)
	gelen+=para;
	else if(secenek==2)
	giden+=para;
	bulunan=gelen-giden;
	fclose(dosya);
	dosya=fopen("Rapor.txt","w");
	fprintf(dosya,"%d",gelen);
	fprintf(dosya," %d",giden);
	fprintf(dosya," %d",bulunan);
	fclose(dosya);
}
//*****************************RAPOR ALMA KISMI********************************
int BankaRaporAl()
{
	int bulunan,gelen,giden;
	FILE *dosya;
	dosya=fopen("Rapor.txt","r");
	fscanf(dosya,"%d %d %d",&gelen,&giden,&bulunan);
	fclose(dosya);
	printf("\nGelen Para Miktari:%d",gelen);
	printf("\nGiden Para Miktari:%d",giden);
	printf("\nBankada Bulunan Para Miktari:%d",bulunan);
}
//*****************************DOSYAYA DEKONT YAZDIRMA FONKSIYONU********************************
void Dekont(int Mno,int para,int Hno,int k)
{	
	int temp=0;
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE *dosya;
    dosya=fopen("Dekont.txt","a+");
    if(k==2)
    fprintf(dosya,"%d %d %d %d/%d/%d\n",Mno,Hno,para,tm.tm_mday , tm.tm_mon + 1,tm.tm_year + 1900 );
    else
	fprintf(dosya,"%d %d %d %d/%d/%d\n",temp,Mno,para,tm.tm_mday , tm.tm_mon + 1,tm.tm_year + 1900 );
	fclose(dosya);
}
//*****************************DEKONDU EKRANA YAZDIRAN FONKSIYON********************************
void DekontAl()
{
	int Mno,gonderen,alici,para,gun,ay,yil,gun1,ay1,yil1,gun2,ay2,yil2,kontrol=0;
	FILE *dosya;
	dosya=fopen("Dekont.txt","r");
	printf("\nMusteri No Giriniz:");
	scanf("%d",&Mno);
	printf("\nIstediginiz Tarih Araliklarini Belirtiniz!\n");
	printf("ilk tarihi (gun/ay/yil)formatinda giriniz:");
	scanf("%d/%d/%d",&gun1,&ay1,&yil1);	
	printf("\nikinci tarihi (gun/ay/yil)formatinda giriniz:");
	scanf("%d/%d/%d",&gun2,&ay2,&yil2);	
	while(!feof(dosya))
	{fseek(dosya,0,SEEK_CUR);
	fscanf(dosya,"%d %d %d %d/%d/%d",&gonderen,&alici,&para,&gun,&ay,&yil);
	kontrol=0;
	if(yil>yil1&&yil<yil2)
			kontrol=1;
	 if(yil==yil2||yil==yil1)
	{if(ay<ay2&&ay>ay1)
			kontrol=1;
		else if(ay==ay2&&ay==ay1)
			if(gun>=gun1&&gun<=gun2)
			kontrol=1;
		else if(ay<ay2&&ay==ay1&&gun>=gun1)
			kontrol=1;
		else if(ay==ay2&&ay>ay1&&gun<=gun2)
			kontrol=1;

	}
		if(kontrol==1)	
{
	if(Mno==gonderen)
	{
		printf("\n\nTarih:%d/%d/%d\n",gun,ay,yil);
		printf("Alici Musteri No:%d\n",alici);
		printf("Gonderilen Para:%d",para);
	}
	else if(Mno==alici)
	{
		if(gonderen==0)
		{
		if(para<0)
		{
		printf("\n\nTarih:%d/%d/%d\n",gun,ay,yil);
		printf("Cekilen Para:%d",(-1)*para);
		}
		else
		{
		printf("\n\nTarih:%d/%d/%d\n",gun,ay,yil);
		printf("Yatirilan Para:%d",para);
		}
		}
		else
		{
		printf("\n\nTarih:%d/%d/%d\n",gun,ay,yil);
		printf("Gonderici Musteri No:%d\n",gonderen);
		printf("Alinan Para:%d",para);
		}
		
	}
}
	}
	
	
}
