#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const float NET_ASG_UCRET = 2324.70;



 int main(int argc, char *argv[]) {
	
	
float AgiMatrahi,yillikAgiTutari,aylikAgiTutari;
float brutAsgUcret,agiPuani=0;;

char ad[20],soyad[30];

int yas;
int cocukSayisi,cocukYas, okuyanCocukSayisi=0;

int cocuklarinYasi[50];
bool bekarMi;
bool esiCalisiyorMu;
bool okuldaOkuyanCocukSayisi[20];

int a,b,i,j;


	
	
	printf(" __________ HOSGELDINIZ __________\n");

	printf("\nLutfen adinizi ve soyadinizi birer bosluk birakarak giriniz : ");
	scanf("%s %s", &ad, &soyad);	
	printf("___________________________________________________________________________________________________\n");
	
	printf("\nYasinizi giriniz :  ");
	scanf("%d",&yas);
	printf("___________________________________________________________________________________________________\n");
	
	printf("\n*Cocuk sayinizi giriniz (yok ise 0'a basiniz) :  ");
	scanf("%d", &cocukSayisi);
	printf("___________________________________________________________________________________________________\n");

	
	printf("\n*Okuyan cocuk sayinizi giriniz (yok ise 0'a basiniz):  ");
	scanf("%d", &okuyanCocukSayisi);
	printf("___________________________________________________________________________________________________\n");

	printf("\n*Evli misiniz ? (evet ise 1 - Hayir ise 2'ye basiniz) :  ");
	scanf("%s", &a);
	  if(a==1) {
		bekarMi=true;
	}
	else{
		bekarMi=false;
	}
	printf("___________________________________________________________________________________________________\n");
    
	printf("\n*Esiniz calisiyor mu? (evet ise 1 - Hayir ise 2'ye basiniz):  \n");
	  scanf("%d", &a);
	
	    if(a==1){
		esiCalisiyorMu=true;
		}
	    else{
		 esiCalisiyorMu=false;
		 }	      
	      
	printf("___________________________________________________________________________________________________\n");

		
	
	if(cocukSayisi>0){
		
		for(i=0; i<cocukSayisi; i++){
			printf("\n%d .cocugunuzun yasini giriniz:  ", (i+1));
			scanf("%d", &cocukYas);
			
			cocuklarinYasi[i]=cocukYas;
		
		}
	}
		      

	

	for(i=0; i<cocukSayisi; i++){
		
		if(cocuklarinYasi[i]>5 && cocuklarinYasi[i]<18 ){
			okuyanCocukSayisi++;
		}
		
		if(cocuklarinYasi[i]>18 && cocuklarinYasi[i]<26 ){
			
	    	printf("\n%d yasindaki cocugunuz egitimine devam ediyor mu? (evet ise 1 - Hayir ise 2'ye basiniz): ", cocuklarinYasi[i] );
	    	scanf("%d", &a);
	    	if(a==1){
			 okuyanCocukSayisi++;
			 okuldaOkuyanCocukSayisi[i]=true;
			  }
		}
	
		
	}



	if(yas>=16 ){ agiPuani= agiPuani+0.5; }
	
	if(esiCalisiyorMu == false ){ agiPuani=agiPuani+0.10; }
	 else { agiPuani=agiPuani+0.0; }



	if(cocukSayisi>0  ){
			
	       for(i=1; i<=cocukSayisi; i++){
	       	if(cocuklarinYasi[i]<18 || (cocuklarinYasi[i]>18 && okuldaOkuyanCocukSayisi[i]==true ) ){
	       	
			if(i==1){agiPuani=agiPuani+0.075;}
	          else if(i == 2){agiPuani=agiPuani+0.075;}
		      else if(i==3){agiPuani=agiPuani+0.10;}
		      else{agiPuani = agiPuani+0.05;}
			   }
		     
		}
	   }
		
		
	
	if(agiPuani == 0){
		
    brutAsgUcret= NET_ASG_UCRET+0;
    
	} else{
		
	AgiMatrahi = (12*NET_ASG_UCRET*agiPuani);
	yillikAgiTutari = (AgiMatrahi*15)/100;
	aylikAgiTutari = (yillikAgiTutari/12);
	brutAsgUcret= NET_ASG_UCRET+aylikAgiTutari;

	}
	
	printf("\n___________________________________________________________________________________________________\n");
	
	printf("Sayin %s %s , asgari ucret tutariniz : %f",ad,soyad,brutAsgUcret);
	
	
	return 0;
}
