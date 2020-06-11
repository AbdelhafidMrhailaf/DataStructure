#include<stdio.h>
#include<stdlib.h>
#include"listchainnee.h"

cellule *creerc(){
	cellule *c;
	c=(cellule *)malloc(1*sizeof(cellule));
	c->lien=NULL;
	return c;
}

int videc(cellule *c){ return (c==NULL);}

void remplirc(cellule *c){
	int x;
	printf("Entrer une valeur:");
	scanf("%d",&x);
	(*c).val=x;
}

void affichagel(cellule *l){
	cellule *p;
	p=l;
	printf("L'affichage de contenue de la list.\n");
	while(p!=NULL){
		printf("%3d",(*p).val);
		p=p->lien;
	}
	printf("\n");
}
void affichagelAdd(cellule *l){
        cellule *p;
        p=l;
        printf("L'affichage de contenue et ces adresses  de la list.\n");
        while(p!=NULL){
                printf("%p + %3d + %p",p,p->lien,(*p).val);
                p=p->lien;
        }
        printf("\n");
}

int longueurl(cellule *l){
        cellule *p;
        p=l;
	int c=0;
        while(p!=NULL){
		c++;
		p=p->lien;
	}
	return c;
}
cellule *insererDebut(cellule *l,cellule *c){
		c->lien=l;
		l=c;
	return l;
}
cellule *insererFin(cellule *l,cellule *c){
	if(videc(l)) l=c;
	else{
		cellule *p;
		p=l;
		while(p->lien!=NULL){
			p=p->lien;
		}
		p->lien=c;
	}
	return l;
}
cellule *rechercheEltl(cellule *l,int x){
	cellule *p=l;
	while ((p!=NULL)&&((*p).val!=x))
		p=p->lien;
	if(p==NULL) return NULL;
	return p;
}

cellule *rechercherEltSl(cellule *l,int x){
	cellule *p=l;
	cellule *pp=NULL;
	while((p!=NULL)&&((*p).val!=x)){
		pp=p;
		p=p->lien;
	}
	return pp;
}


cellule *supprimerc(cellule *l,int x){
	cellule *pp, *q;
	if(l==NULL) return NULL;
	if((*l).val==x){ q=l; l=l->lien; free(q); return l;}
	pp=rechercherEltSl(l,x);
	if(pp->lien==NULL)
		printf("Non trouvé.\n");
	else{
		q=pp->lien;
		pp->lien=q->lien;
		free(q);
		return l;
	}
}

cellule *recherchePreced(cellule *l,int x){
	if((l==NULL)||((*l).val>x)) return NULL;
	cellule *pp=l;
	cellule *p=l->lien;
	while((p!=NULL)&&((*p).val<x)){
		pp=p;
		p=p->lien;
	}
	return pp;
}
cellule *insererc(cellule *l,cellule *c){
	if(c==NULL) return l;
	cellule *pp,*p;
	pp=recherchePreced(l,(*c).val);
	p=l;
	if((p==NULL)||(pp==NULL)) l=insererDebut(l,c);
	else {
		c->lien=pp->lien;
		pp->lien=c;
	}
	return l;
}

