#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
			int val;
			struct cellule *prec;
			struct cellule *suiv;
		} cellule ;

cellule * creer () {
	cellule *c;
	c=(cellule *)malloc(sizeof(cellule);
	c->prec=c->suiv=NULL;
	return c;
}

int vide (cellule *c) {return (c==NULL) }

void remplir (cellule *c) {
	int x;
	printf("Entrer une valeur entier:");
	scanf("%d",&x);
	(*c).val=x;
}

cellule * insererd (cellule *l,cellule *c) {
	if (vide(l)) return c;
	l->prec=c;
	c->suiv=l;
	l=l->prec;
	return l;
}

cellule * insererf (cellule *l,cellule *c) {
	if (vide(l)) return c;
	cellule *p=l;
	while (p->suiv!=NULL) p=p->suiv;
	p->suiv=c;
	c->prec=p;
	return l;
}

cellule * rechercherElt (int x,cellule *l) {
	if(vide(l)) {printf("l'entier n'existe pas.\n"); return NULL;}
	cellule *p=l;
	while((p!=NULL)&&((*p).val!=x)) p=p->suiv; 
//Note!!
//We should write p!=NULL first to not access something that isn't existe.
//to avoid segmentation fault.
	if (p==NULL) {
		printf("L'entier n'existe pas.\n");
		return NULL;
	} else return p;
}

cellule *insererTri (cellule *l,cellule *c) {
	if (vide(l)) return c;
	cellule *p=l;
	while ((p!=NULL)&&((*p).val<=(*c).val)) p=p->suiv;
	if (p->prec==NULL)
		insererd(l,c);
	else {
		if (p==NULL)
			insererf(l,c);
		else {
			(p->prec)->suiv=c;
			c->prec=p->prec;
			p->prec=c;
			c->suiv=p;
		}
	}
	return l;
}

cellule *supprimerAdd(cellule *l,cellule *c) {
//Note:we give you the adresse so don't search for the value.
	if ((vide(l) || (vide(c)) return l;
	if (c->prec==NULL) {
		l=l->suiv;
		l->prec=NULL;
		free(c);
	} else {
		(c->prec)->suiv=c->suiv;
		if (c->suiv!=NULL) (c->suiv)->prec=c->prec;
		free(c);
	}
}

cellule *supprimer(cellule *l,int x) {
	if (vide(l)) return (cellule *)NULL;
	cellule *p=l;
	while ((p!=NULL)&&((*p).val!=x)) p=p->suiv;
/*Nt*/	if (p==NULL) {printf("Entier n'existe pas.\n"); return (cellule *)NULL;}
	if (p->prec==NULL) {
		l=l->suiv;
		l->prec=NULL;
		free(p);
	}
	else {
		(p->suiv)->prec=p->prec;
		if(p->suiv!=NULL) (c->suiv)->prec=c->prec;
		free(p);
	}
	return l;
}
