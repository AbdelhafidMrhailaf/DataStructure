#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
			int val;
			struct cellule * suivant;
			}cellule ;

int vide (cellule *f) {
	return (f==NULL);
}

cellule * creer () {
	cellule  *c;
	if ((c=(cellule *) malloc(sizeof(cellule)))==NULL) {
		printf("On n'a pas de place pour allouer une celulle.\n");
		exit(-1);
	}
	c->suivant=NULL;
	return c;
}

cellule *ajouter (cellule *f) {//Toujours lorsequ'on ajoute une cellule on augmente f donc attetion f ne point pas sur le debut de cellule mais il point sur la fin.
	int x;
	printf("Entrer un entier:");
	scanf("%d",&x);
	cellule *q=creer(),*p;
	(*q).val=x;
	if (vide(f)) {//lorsequ'on a  une seul cellule il point sur elle meme.
		f=q;
		q->suivant=f;
	}
	else {
		p=f->suivant;
		f->suivant=q;
		q->suivant=p;
		f=q;
	}
	return f;
}

cellule * supprimer (cellule *f) {
	if (vide(f)) {
		printf("Le file et vide.\n");
		exit(-1);
	}
	cellule *q=f->suivant;
	if (q!=f)
		f->suivant=q->suivant;
	else {
		free(f);
		return (cellule *)NULL;
	}
	free(q);
	return f;
}

int valeur (cellule *f) {
	if (vide(f)) {printf("file vide.\n"); exit(-1);}
	return (*(f->suivant)).val;
}

void afficher (cellule *f) {
	if (vide(f)) {printf("file vide.\n"); return;}
	cellule *q=f->suivant;
	while (q!=f) {
		printf("   %3d",(*q).val);
		q=q->suivant;
	}
	printf("   %3d.\n",(*q).val);
}


int main () {
	int i;
	int x=0;
	cellule *f=(cellule *)NULL;
	printf("File circulaire a partir de list chainnee\n");
	for (;;) {
		printf("===============================\n");
		printf("1:vide     .         2:ajouter.\n");
		printf("3:supprimer.         4:valeur .\n");
		printf("            5:afficher.\n"); 
		printf("===============================\n");
		printf("Entrer votre choix:");
		scanf("%d",&i);
		switch (i) {
			case 1 :
				if (vide(f)) printf("file vide\n"); else printf("non vide\n");break;
			case 2 :
				f=ajouter(f);break;
			case 3 :
				f=supprimer(f);break;
			case 4 :
				x=valeur(f);if(x!=0) printf("La valeur de file et:%d.\n",x);break;
			case 5 :
				afficher(f);break;
			default: exit(0);
		}
	}
}
