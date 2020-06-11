#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
			int val;
			struct cellule * suivant;
			} cellule ;

int vide (cellule *c) {
		return (c==NULL);
		}

cellule * creer () {
	cellule * c=(cellule *) malloc(1*sizeof(cellule));
	c->suivant=NULL;
	return (cellule *)c;
	}

void  remplir (cellule *c) {
	int x;
	printf("Entrer une valeur :");
	scanf("%d",&x);
	(*c).val=x;
}

cellule * inserer (cellule *l,cellule *c) {
	if (vide(l)) {
		l=c;
		c->suivant=l;
	}
	else {
		c->suivant=l->suivant;
		l->suivant=c;
	}
		return (cellule *)l;
}

void afficher (cellule *l) {
	if (vide(l)) printf("La cellule et vide!!\n");
	else {
		cellule *p=l;
		while (p->suivant!=l) {
			printf(" %3d",(*p).val);
			p=p->suivant;
		}
		printf(" %3d.\n",(*p).val);
	}
}

cellule * supprimer (cellule *l,int x) {
	if (vide(l)){printf("On ne peut pas supprimer la liste et vide.\n"); return (cellule *)NULL; }
	if ((l==l->suivant)&&((*l).val==x)) {
		free(l);
		return (cellule *)NULL;
	}
	else {
		cellule *p=l->suivant;//on fait comme ca pour ne pas tomber
		cellule *pp=l;//dans le probleme de pp et NULL et qui 
		while ((p!=l) && ((*p).val!=x)) {//contient rien.
			pp=p;
			p=p->suivant;
		}
		cellule *q=p;
		if ((*p).val==x) {
			pp->suivant=p->suivant;
			if (p==l) l=l->suivant;
			free(q);
		}
		else printf("cette valeur n'existe pas.\n");
		return (cellule *)l;
	}
}

int main () {
	int i,x;
	cellule *p;
	cellule *l=(cellule *)NULL;
	printf("~~~~~~~~~~~~~~listchainnée circulaire ~~~~~~~~~~~~~~\n");
	for(;;){
                printf("======================================\n");
		printf("1:inserer cellule .        2:afficher .\n");
		printf("3:vide            .        4:supprimer.\n");
		printf("======================================\n");
		printf("Entrer votre choix:");
		scanf("%d",&i);
		switch (i) {
			case 1:
			       p=creer();remplir(p);
			       l=inserer(l,p);break;
			case 2:
			       afficher(l);break;
			case 3:
			       if (vide(l)) printf("La list circulaire et vide.\n"); 
			       else printf("la list circulaire et non vide.\n");break;
			case 4:
			       printf("Entrer l'entier a supprimer:");
			       scanf("%d",&x);
			       l=supprimer(l,x);break;
			default:
			       exit(0);
		}
	}
}

