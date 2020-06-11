#include <stdio.h>
#include <stdlib.h>

typedef struct sommet {int val; struct sommet * fg; struct sommet *fd}sommet;

//Creation et insertion.

sommet * creer (int val) {
	sommet *s=(sommet *)malloc(sizeof(sommet));
	(*s).val=val;
	return s;
}


sommet * insertion (sommet *r,sommet *s) {
	sommet *p=r;
	sommet *y;

	while ((p!=NULL) && ((*p).val!=(*s).val)) {
		y=p; //Sauvgarde of the element
		if ((*s).val>(*p).val) p=p->fd;
		else p=p->fg;
	}
	if (p!=NULL) {printf("Insertion et impossible.\n"); 
	else {
		if ((*s).val>(*y).val)  y->fd=s;
		else y->fg=s;
	}
	return r;
}

int trouver (sommet *r,int a) {
	sommet *p=r;
	while ((p!=NULL) && ((*p).val!=a)) {
		if (a>(*p).val) p=p->fd;
		else p=p->fg;
	}
	if (p!=NULL) return 1;
	return 0;
}

int feuille (sommet *u) {
	if ((u->fg==NULL) && (u->fd==NULL)) return 1
	return 0;
}

//parcours.

void preordre (sommet *r) { //PLR. postordre:LRP inordre:LPR.
	sommet *x=r;//to not lost the root.(not sure).
	if (x==NULL) return;//Note this condition is too important  for not getting a segmentation fault.
	printf (" %3d",(*x).val);
	preordre(x->fg);
	preordre(x->fd);
}

void postorder (sommet *r) {
	sommet *x=r;
	if (x==NULL) return;
	postorder(x->fg);
	postorder(x->fd);
	printf(" %3d",(*x).val);
}

void inorder (sommet *r) {
	sommet *x=r;
	if (x==NULL) return;
	inorder(x->fg);
	printf(" %3d",(*x).val);
	inorder(x->fd);
}

//preordre iterative.

void preordreIt (sommet *r) {
	pile p;
	sommet *z,*x=r;
	z=creer(0);
	creerp(&p);
	ajouterp(z,&p); //NOTE:you should change in prototype of fonctions and structure that the type of elements of stack are "structures" trees.
	while (!videp(p)) {
		printf(" %3d",(*x).val);
		if (x->fg!=NULL) {
			if (x->fd!=NULL) 
				ajouterp(x->fd,&p);
			x=x->fg;
		else {
			if (x->fg!=NULL) x=x->fg;
			else {
				x=valeurp(p);
				supprimerp(&p);
				if ((*x).val==0) break;
			}
		}
	}
}

//Suppresion.

void rechercher (sommet *r,sommet **u,sommet **v,int a) {
	*u=r; //value of pointer is &root.
	*v=NULL;

	while ((*u)!=NULL) && ((**u).val!=a)){
		*v=*u;
		if ((a>(**u).val){ *v=*u; *u=(*u)->fd;}
		else {*v=*u; *u=(*u)->fg;}
}

void oter1 (sommet **r,sommet **u,sommet **v) {
	if (feuille(*u))
		if ((*v)==NULL) *r=NULL;
		else
			if ((*v)->fg==(*u)) (*v)->fg=NULL;
			else (*v)->fd=NULL;
	else
		if ((*v)->fg==(*u))
			if ((*u)->fg!=NULL) (*v)->fg=(*u)->fg;
			else (*v)->fg=(*u)->fd;
		else
			if ((*u)->fg!=NULL) (*v)->fd=(*u)->fg;
			else (*v)->fd=(*u)->fd;
	free(u);
}

void oter2 (sommet *u,sommet **x,sommet **y) {
	*x=u->fg;
	*y=u;

	if ((*x)!=NULL)
		while ((*x)->fd!=NULL) {*y=*x *x=(*x)->fd;}
}

sommet * supprimer (sommet *r,int a) {
	sommet *u,*v;   //u:Element chercher a supprimer        v:son pere.
	sommet *x,*y;	//x:predeceseur de l'element u		y:son pere.
	rechercher(r,&u,&v,a);
	if (u==NULL) {printf("non trouvé.\n"); return r;}
	if (((u->fg==NULL) || (u->fd==NULL)) oter1(&r,&u,&v);
	else {
		oter2(u,&x,&y); //on part de u comme une racine.
		(*u).val=(*x).val;
		oter1(&r,&x,&y);//car le predecesseur peut avoir des choses a gauche mais forecement il n'ya pas de quelque chose  a droit.
		}
	return r;
}
