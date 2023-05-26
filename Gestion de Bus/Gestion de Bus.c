#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//mot de pass est admin
char pass[10]="admin";
typedef char nom[10];
typedef struct bus{
	char info[100];
	int places[31];
	nom placesnom[10];
}bus;

//procedure pour afficher le menu
void mainmenu(){
	system("cls");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd BONJOUR \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n");
	printf("\t1)-Les Bus Disponibles \n");
	printf("\t2)-Reserver dans un Bus \n");
	printf("\t3)-Afficher Les Informations de Reservation \n");
	printf("\t4)-Anulle la reservation \n\n\n");
	printf("\t0)-Quitter \n");
	printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\xcd\xcd\xcd\xcd\xcd\xcd:");
}

//procedure pour retoure au menu
void retourfunc(){
	mainmenu();
}

//procedure pour quitter le program console
void quitter(){
	system("cls");
	printf("\n*\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
	printf("\n*\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  THANK YOU  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
	printf("\n*\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n\n");
	getch();
	exit(0);
}

//procedure pour installer les informations du bus
void installer_informations(bus *b,FILE *f){
	char bb[100];
	fgets(bb,100,f);
	strcpy(b->info,bb);
}

//procedure pour le mot de pass
void password(){
    char psw[10];
    int temp=0;
    do{
        if(temp==1){
            printf("\n\xcd\xcd\xcd\xcd\xcd\xcd CONNEXION ECHEC REESSAYER(cliquez sur n'importe quel bouton pour r�essayer)!!!\n\xcd\xcd\xcd\xcd\xcd\xcd ASTUCE : le mot de passe est le synonyme de proprietaire.");
            getch();
        }
    system("cls");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd bonjour \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("entrer le mot passe :");
    scanf("%s",psw);
    temp=1;
    }while(strcmp(psw,pass));
    system("cls");
}

//procedure pour reserver les bus
void reserver(bus *b,int *a,nom *n){
	do{
		printf("\nDonner la place que vous voullez:");
		scanf("%d",a);
	}while(*a<1 || *a>30);
	if(b->places[*a]!=1){
		printf("Donner votre nom:");
		scanf("%s",n);
		b->places[*a]=1;
		strcpy(b->placesnom[*a],*n);
		printf("\n\n 	INSCRIPTION TERMINE.\n\n");
	}
	else printf("LA PLACE EST DEJA RESERVER!!!!");
}

//anuller la resarvation
void nullreserver(bus *b,int *a){
	printf("\nDonner la place que vous voullez annuler:");
	scanf("%d",a);
	if(b->places[*a]==1){
		b->places[*a]=0;
		printf("\n\n 	SUPPRESSION TERMINE.\n\n");
	}
}

//procedure pour afficher les reservations
void informations(bus b1,bus b2,bus b3,bus b4,bus b5){
	int i;
	int a=0;
	for(i=1;i<=30;i++){
		
		if(b1.places[i]==1){
			a=1;
			printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n%s reserver dans bus 01\nNom:%s\nPlace:%d\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n",b1.placesnom[i],b1.placesnom[i],i);
		}
		if(b2.places[i]==1){
			a=1;
			printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n%s reserver dans bus 02\nNom:%s\nPlace:%d\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n",b2.placesnom[i],b2.placesnom[i],i);
		}
		if(b3.places[i]==1){
			a=1;
			printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n%s reserver dans bus 03\nNom:%s\nPlace:%d\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n",b3.placesnom[i],b3.placesnom[i],i);
		}
		if(b4.places[i]==1){
			a=1;
			printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n%s reserver dans bus 04\nNom:%s\nPlace:%d\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n",b4.placesnom[i],b4.placesnom[i],i);
		}
		if(b5.places[i]==1){
			a=1;
			printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n%s reserver dans bus 05\nNom:%s\nPlace:%d\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n",b5.placesnom[i],b5.placesnom[i],i);
		}
		
	}
	if(a==0)printf("aucune reservation a ete subit");
}

//procedure pour afficher les bus disponibles
void Bus_disponibles(bus b,int a){
	printf("BUS 0%d)- %s\n",a,b.info);
}




//main------------------------------------------------------
int main(){
	int i,bs;
	bus b1,b2,b3,b4,b5;
	//utiliser les fichiers pour importer les informations des bus
	FILE *f1,*f2,*f3,*f4,*f5;
	f1=fopen("bus01.txt","r");
	f2=fopen("bus02.txt","r");
	f3=fopen("bus03.txt","r");
	f4=fopen("bus04.txt","r");
	f5=fopen("bus05.txt","r");
	
	installer_informations(&b1,f1);
	installer_informations(&b2,f2);
	installer_informations(&b3,f3);
	installer_informations(&b4,f4);
	installer_informations(&b5,f5);
	
	
	password();
	do{
		mainmenu();
		scanf("%d",&i);
		switch(i){
			case 1:
				system("cls");
				printf("*\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Les bus disponibles \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n\n");
				Bus_disponibles(b1,1);
				Bus_disponibles(b2,2);
				Bus_disponibles(b3,3);
				Bus_disponibles(b4,4);
				Bus_disponibles(b5,5);
				printf("\n*\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n\n");
				printf("\n\nAPPUYEZ SUR N'IMPORTE QUEL BOUTON POUR CONTINUER!! ");
				getch();
				retourfunc();
				break;
			case 2:
				system("cls");
				printf("*\xcd\xcd\xcd\xcd\xcd System de reservation \xcd\xcd\xcd\xcd\xcd*         (cliquer 0 pour retourner vers l'etape precedente)\n\n");
				int bss;
				int pl;
				char no[10];
				printf("\xcd\xcd\xcd\xcd Donner le N de bus :");
				scanf("%d",&bss);
				if(bss==1){
					reserver(&b1,&pl,&no);
				}
				else{
					if(bss==2){
						reserver(&b2,&pl,&no);
					}
					else{
						if(bss==3){
							reserver(&b3,&pl,&no);
						}
						else{
							if(bss==4){
								reserver(&b4,&pl,&no);
							}
							else{
								if(bss==5){
									reserver(&b5,&pl,&no);
								}
								else{
									if(bss==0){
										break;
									}
									else printf("\n\nBus non disponible !!!!!");
								}
							}
						}
					}
				}
				printf("\n\nAPPUYEZ SUR N'IMPORTE QUEL BOUTON POUR CONTINUER!! ");
				getch();
				break;
			case 3:
				system("cls");
				informations(b1,b2,b3,b4,b5);
				printf("\n\nAPPUYEZ SUR N'IMPORTE QUEL BOUTON POUR CONTINUER!! ");
				getch();
				retourfunc();
				break;
			case 4:
				system("cls");
				printf("*\xcd\xcd\xcd\xcd\xcd System de anuller la reservation \xcd\xcd\xcd\xcd\xcd*(cliquer 0 pour retourner vers l'etape precedente)\n\n");
				int bs;
				int pll;
				printf("*Donner le N de bus :");
				scanf("%d",&bs);
				if(bs==1){
					nullreserver(&b1,&pll);
				}
				else{
					if(bs==2){
						nullreserver(&b2,&pll);
					}
					else{
						if(bs==3){
							nullreserver(&b3,&pll);
						}
						else{
							if(bs==4){
								nullreserver(&b4,&pll);
							}
							else{
								if(bs==5){
									nullreserver(&b5,&pll);
								}
								else{
									if(bs==0){
										break;
									}
									else printf("\n\nBus non disponible !!!!!");
								}
							}
						}
					}
				}
				printf("\n\nAPPUYEZ SUR N'IMPORTE QUEL BOUTON POUR CONTINUER!! ");
				getch();
				retourfunc();
				break;
		}
	}while(i!=0);
	quitter();
	
	return 0;
}
