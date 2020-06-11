#include<stdio.h>
#include<stdlib.h>

#include"pile.h"

void creerp(pile *p){
	(*p).ip=0;
}

int videp(pile p){
	if(p.ip==0) return 1;
	return 0;
}

int ajouterp(int x,pile *p){
	(*p).ip++;
	if((*p).ip<N){
		(*p).tab_p[(*p).ip]=x;
		return 1;
	}
	printf("Implimentation Insufissante.\n");
	exit(-1);   //Je sais pas pourquoi cette exit.
}
int supprimerp(pile *p){
	if(!(videp(*p))){
		(*p).ip--;
		return 1;
	}
	printf("Suppression non definie.\n");
	exit(-1);
}
int valeurp(pile p){
	if(!(videp(p)))
		return p.tab_p[p.ip];
	printf("La valeur non definie\n");
	exit(-1);
}

void afficherp(pile p){
	int i;
	printf("Affichage de pile des entiers.\n");
	printf("La tete de la pile et %d.\n",valeurp(p));
	for(i=1;(i<=p.ip);i++){
		printf("%d ",p.tab_p[i]);
	}
	printf("\n");
}

void remplirp(pile *p){
	int i;
	printf("Rempliration de la pile.\n");
	for(;;){
		printf("donner un entier diff de -1 : ");
		scanf("%d",&i);
		if(i>=0) ajouterp(i,p);
		else break;
	}
}
