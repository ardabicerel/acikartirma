#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	typedef struct
	{
		char teklifveren_isim[50];
		double teklif;
	}TEKLIF_VEREN;
	
	typedef struct
	{
		int teklifveren_sayisi;
		TEKLIF_VEREN *teklifler;
	}Arttirma;
	
	typedef struct
	{
		char esya[50];
		double mevcut_teklif;
		TEKLIF_VEREN en_yuksek_teklif;
	}MuzayedeEsya;

void esyayi_tanimla(MuzayedeEsya *esya, const char *esya_isim, double baslangic_teklif){
	
	strcpy(esya->esya, esya_isim);
	esya->mevcut_teklif = baslangic_teklif;
	strcpy(esya->en_yuksek_teklif.teklifveren_isim, "Henuz teklif yok");
	esya->en_yuksek_teklif.teklif = 0.0;
}

void esya_goruntule(const MuzayedeEsya *esya){
	
	printf("\nMuzeyedeki esya : %s\n",esya->esya);
	printf("Mevcut teklif : %.2lf TL\n",esya->mevcut_teklif);
	printf("En yuksek teklifi veren : %s\n",esya->en_yuksek_teklif.teklifveren_isim);
	printf("En yuksek teklif : %.2lf TL\n",esya->en_yuksek_teklif.teklif);
}

void odemeyi_hesapla(Arttirma a, int kazanan_no){
	
	double odeme;
	int i;
	
	odeme = 0.0;
	i=0;
	
	for(;i<=a.teklifveren_sayisi;i++)
	{
		if(i!=kazanan_no)
		{
			odeme += a.teklifler[i].teklif;	
		}
		odeme;
	}
}

void acikarttirma(Arttirma a){
	
	double enyuksek_teklif;
	double odeme;
	int kazanan_no;
	
	enyuksek_teklif = -1.0;
	kazanan_no = -1;
	
	for(int i=0;i<=a.teklifveren_sayisi;i++)
	{
		if(a.teklifler[i].teklif>enyuksek_teklif)
		{
			enyuksek_teklif = a.teklifler[i].teklif;
			kazanan_no = i;
		}
		
		odemeyi_hesapla(a,kazanan_no);
	}
}

int main() { 
	
	MuzayedeEsya satilan_esya;
	TEKLIF_VEREN teklifler[5];
	int teklif_sayisi = 0;
	
	esyayi_tanimla(&satilan_esya, "Dizustu Bilgisayar", 12.50);
	
	esya_goruntule(&satilan_esya);
	
		while(1){
			char isim[50];
			double teklif_miktari;
		
			if(teklif_sayisi >= 5){
				printf("\nMuzayedeye katilim orani sinira ulasti. Muzayede bitmistir.\n");
				break;
			}
		
			printf("\nIsminizi giriniz : ");
			scanf("%s",isim);
		
			printf("\nTeklifinizi giriniz : ");
			scanf("%lf",&teklif_miktari);
		
			if(teklif_miktari > satilan_esya.mevcut_teklif){
			
				strcpy(satilan_esya.en_yuksek_teklif.teklifveren_isim, isim);
				satilan_esya.en_yuksek_teklif.teklif = teklif_miktari;
				satilan_esya.mevcut_teklif = teklif_miktari;
				printf("\nSimdiki en yuksek teklif! %s 'nin teklifi %.2lf TL\n",isim,teklif_miktari);
			
				strcpy(teklifler[teklif_sayisi].teklifveren_isim, isim);
				teklifler[teklif_sayisi].teklif = teklif_miktari;
				teklif_sayisi++;
			}
		
			else{
				printf("\nUzgunum, teklifin olan %.2lf TL mevcut en yuksek teklifden az. (Su anki en yuksek teklif : %.2lf)\n",
				teklif_miktari,satilan_esya.mevcut_teklif);
			}
	}
	
	printf("\nNihai Muzayede Sonuclari :\n");
	esya_goruntule(&satilan_esya);
	
	printf("\nTeklifler :\n");
	
	for(int i=0; i < teklif_sayisi; i++){
	
		printf("%s - %.2lf\n",teklifler[i].teklifveren_isim,teklifler[i].teklif);	
	}
	
    return 0;
}
