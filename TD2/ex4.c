#include <stdio.h>
#include <stdlib.h>
#include "listchainnee.h"

cellule * inverser (cellule *l) {
	cellule *c=l;
	cellule *pp=(cellule *)NULL;
	cellule *n=(cellule *)NULL;

	while (c!=NULL) {
		n=c->lien;
		c->lien=pp;
		pp=c;
		c=n;
	}
	return pp;
}

cellule * inverserRec (cellule *l) {
	if ((l==NULL)||(l->lien==NULL)) return l;
	l=inverserRec (l->lien);
	l->lien->lien=l;//next on reservsed linked list is me.
	l->lien=NULL; 
	return l;
}
int main () {
	cellule *l;
	l=creerc();
	cellule *l2;
	int i,x;
	printf("Rempliration de la list chainnée\n");
	printf("Entrer le nombre d'element a saisir:");
	scanf("%d",&x);
	for (i=0;i<x;i++) {
		l2=creerc();
		remplirc(l2);
		l=insererFin(l,l2);
	}
	affichagel(l);
	l=inverser(l);
	printf("Affichage apres l'inversion\n");
	affichagel(l);
}

