#include <stdio.h>
#include <stdlib.h>
#include "listchainnee.h"

cellule * fusion (cellule *l,cellule *m) {
	if (l==NULL) return m;
	if (m==NULL) return l;
	cellule *s,*pp;
	if ((*l).val<=(*m).val) {
		s=l;
		pp=l;
		l=l->lien;
	} else {
		s=m;
		pp=m;
		m=m->lien;
	}
	while ((l!=NULL) && (m!=NULL)) {
		if ((*l).val<=(*m).val) {
			pp->lien=l;
			//pp=pp->lien;
			l=l->lien;
		} else {
			pp->lien=m;
			//pp=pp->lien;
			m=m->lien;
		}
		pp=pp->lien;
	}
	if (l==NULL) {
		while (m!=NULL) {
			pp->lien=m;
			pp=pp->lien;
			m=m->lien;
		}
	}
	if (m==NULL) {
		while (l!=NULL) {
			pp->lien=l;
			pp=pp->lien;
			l=l->lien;
		}
	}
	return s; 
}

int main () {
	cellule *s=(cellule *)NULL;
	cellule *l=(cellule *)NULL;
	cellule *l2=(cellule *)NULL;
	l=creerc();
	cellule *m=(cellule *)NULL;
	cellule *m2=(cellule *)NULL;
	m=creerc();
	int i,x,y;
	printf("Rempliration de la premier list chainnee.\n");
	printf("Entrer le nombre d'element a saisir:");
	scanf("%d",&x);
	if (x!=0) remplirc(l);
	for (i=0;i<x-1;i++) {
		l2=creerc();
		remplirc(l2);
		l=insererFin(l,l2);
	}
	affichagel(l);
	printf("Rempliration de la deuxieme list chainnee.\n");
	printf("Entrer le nombre d'element a saisir:");
	scanf("%d",&y);
	if (y!=0) remplirc(m);
	for (i=0;i<y-1;i++) {
		m2=creerc();
		remplirc(m2);
		m=insererFin(m,m2);
	}
	affichagel(m);
	s=fusion(l,m);
	printf("Apres la fusion.\n");
	affichagel(s);
}
