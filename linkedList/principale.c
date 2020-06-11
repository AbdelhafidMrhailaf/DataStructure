
#include<stdio.h>
#include<stdlib.h>
#include"listchainnee.h"

int main(){
	int i,x;
	cellule *l=(cellule *) NULL;
	cellule *p;
	for(;;){
		printf("===================\n");
		printf("1:InsererDebut.\n2:InsererFin.\n3:Afficherl.\n4:Longueurl.\n5:RechercherEltl.\n6:Insererc.\n7:Supprimer.\n");
		printf("Entrer une Option:");
		scanf("%d",&i);
		printf("===================\n");
	switch (i) {
	case 1: 	p=creerc();remplirc(p);
			l=insererDebut(l,p);break;
	case 2:		p=creerc();remplirc(p);
			l=insererFin(l,p);break;
	case 3:		affichagel(l);
			affichagelAdd(l);break;
	case 4:		printf("Longueur=%d.\n",longueurl(l));break;
	case 5:		printf("Donner le nombre entier a rechercher:");
			scanf("%d",&x);
			printf("%d %p\n",x,rechercheEltl(l,x));break;
	case 6:		p=creerc();remplirc(p);
			l=insererc(l,p);break;
	case 7:		printf("Donner l'entier a supprimer:");
			scanf("%d",&x);
			l=supprimerc(l,x);break;
	default:	exit(0);
}
}
}
