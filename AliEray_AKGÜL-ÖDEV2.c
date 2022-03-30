#include<stdio.h>
#include<stdlib.h>
//ALÝ ERAY AKGÜL
//02210224056
//ÖDEV2




struct Node{
	int data;
	struct Node *after;
};

struct Node* ilk=NULL;
  	
	  int boyut=0;

 
void ElemanSil(int siraNo){
	struct Node*gecici;
	int i=2;
	
		if(ilk==NULL){
		printf("\nListe BOS\n");
	}
	else{
	
	   if(siraNo==1){
	  	struct Node* gecici=ilk;
	    ilk=ilk->after;
			free(gecici);
	
     }
		else{
		
		struct Node*konum;

        gecici=ilk;
        while(i<siraNo ){
        	gecici=gecici->after;
        	i++;
		}
		konum=gecici->after;
			gecici->after=konum->after;
		free(konum);
	}
}
}
void ElemanEkle(int veri,int sirano){
	int flag=0;
	struct Node *add;
	add=(struct Node*)malloc(sizeof(struct Node));
	add->data=veri;
	add->after=NULL;
	
	if(sirano==1){
		if(ilk==NULL){
			ilk=add;
			
		}
		else{
			add->after=ilk;
			ilk=add;
		}
	}
 else if(boyut>=sirano){
	 	struct Node *gecici=ilk;
		 flag=2;
		 while(flag<sirano){
		 gecici=gecici->after;
		 flag++;
		 
		 }
	
	add->after = gecici->after;	
		gecici->after=add;
	
	}
	 else {
	 	if(ilk==NULL){
		 ilk=add;
		 
		}
		 else{
		struct Node *gecici2=ilk;
	while(gecici2->after!=NULL){
		gecici2=gecici2->after;
	}

	gecici2->after=add;
		}
	
	}
boyut++;
 }
void ElemanAra(int siraNo){
    int a;
    int i=1;

    if(ilk==NULL){
        printf("Liste BOS!");
    }
    else
    {
        struct Node* gecici=ilk;

        while(i<siraNo){
         if(gecici->after==NULL){
                printf("Eleman bulunamadi\n");
                return;
            }
            else{
			
            gecici=gecici->after;
            i++;
       }

        }

            a=gecici->data;
          printf("%d\n",a);
    }
}



void Yazdir(){
	
	if(ilk==NULL){
	printf("liste bos");
}
else{
printf("\n");
	if(ilk==NULL){
		printf("Liste BOS!");
	}
	else{
		struct Node* gecici=ilk;
		while(gecici!=NULL){
			printf("%d-> ",gecici->data);
			gecici=gecici->after;
		}
	}
	printf("\n");
	printf("NULL");
}}

void OrtadakiEleman(){
if(ilk==NULL){
	printf("liste bos");
}
else{

    struct Node *yeni=ilk;
    int elemanSayisi=0;
    while(yeni!=NULL){
        yeni=yeni->after;
        elemanSayisi++;
    }
    int orta;
    orta=elemanSayisi/2;
    yeni=ilk;
    
    int i;
    for(i=1; i<orta+1; i++)
        yeni=yeni->after;
        
    printf("Listenin ortadaki eleman elemani:\n");
    printf("%d\n",yeni->data);
    
}
}	

int tamsay(){

     struct Node* gecici=ilk;
       int a=1,b=0;
       
       while(gecici->after!=NULL){//kaç eleman var ise o kadar basamak deðeri ekledim
      gecici=gecici->after;
        a=a*10;
      }
      
     gecici=ilk;
       while(gecici->after!=NULL){
   int toplam=gecici->data; 
      if (a>=10){
      toplam=toplam*a;//listeyi her seferinde 10la carptim
         b=b+toplam;
          a=a/10;
     }
     gecici=gecici->after;
     }
    b=b+gecici->data;
    return b;
 }


 
int main() {
int secim;
int b,a;
	  int sira;
	do{
		printf("----------------\n");
		printf("MENU\n");
		printf("----------------\n");
		printf("Islem seciniz:\n");
		printf("1.ekleyiniz\n");
		printf("2.siliniz\n");
		printf("3.eleman bulunuz\n");
		printf("4.yazdiriniz\n");
		printf("5.ortadaki sayýyý bulunuz\n");
		printf("6.tam sayýya dönüþtürünüz\n");
		scanf("%d",&secim);
		int sayi,sira2;
		switch(secim){
			case 1: 
		
	  
	  printf("Eklencek Sayiyi Giriniz:\n");
      scanf("%d",&b);
      printf("Sirasini Giriniz:\n");
      scanf("%d",&sira);
      ElemanEkle(b,sira);
      Yazdir(); 
			
			break;
			
			case 2: 
				
				 printf("sirasini giriniz\n");
                 scanf("%d",&sira2);
				ElemanSil(sira2);
				Yazdir();
			break;
			
			case 3: 
				
				 printf("sirasini giriniz\n");
                 scanf("%d",&sira);
			     ElemanAra(sira);
				
			break;
			
			case 4:
					Yazdir();
			break;
			
			case 5:
			       OrtadakiEleman();
			break;
		
			case 6:
		       a=tamsay();
		       printf("%d\n",a);
              break; 	
			  case -1:
			printf("çýkýþ");
			  return;	
		}
		
	}
while(secim=-1);
}
