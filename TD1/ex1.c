#include<stdio.h>
#include<stdlib.h>
#include"pile.h"
#include"file.h"

//1.
//Affichage de la pile avec passage par valeur.

void afficher_p(pile p){
	if(videp(p)) printf("La pile et vide\n");
	while(!(videp(p))){
		printf("%d ",valeurp(p));
		supprimerp(&p);
	}
	printf("\n");
}

//Affichage de la pile avec passafe par adresse.

void afficher_p1(pile *p){
	pile p1;
	creerp(&p1);
	if(videp(*p)) printf("La pile et vide\n");
	while(!(videp(*p))){
		printf("%d ",valeurp(*p));
		ajouterp(valeurp(*p),&p1);
		supprimerp(p);
	}
	printf("\n");
	while(!(videp(p1))){
		ajouterp(valeurp(p1),p);
		supprimerp(&p1);
	}
}

//2.

//la meme chose pour une file.

//Affichage de la file avec passage par valeur.

void afficher_f(file f){
        if(videf(f)) printf("La file et vide\n");
        while(!(videf(f))){
                printf("%d ",valeurf(f));
                supprimerf(&f);
        }
        printf("\n");
}

//affichage de la file  avec passage par adresse.

void afficher_f1(file *f){
        file f1;
        creerf(&f1);
        if(videf(*f)) printf("La file et vide\n");
        while(!(videf(*f))){
                printf("%d ",valeurf(*f));
                ajouterf(valeurf(*f),&f1);
                supprimerf(f);
        }
        printf("\n");
        while(!(videf(f1))){
                ajouterf(valeurf(f1),f);
                supprimerf(&f1);
        }
}
 

//3

void depilerKelt(pile *p,int k){
	if(videp(*p)) printf("La suppresion et impossible");
	while((!(videp(*p)))&&(k!=0)){
		supprimerp(p);
		k--;
	}
}

//4

//Same thing we just  change k!=0 by valeurp(*p)!=elt.

void depilerJusqua(pile *p,int elt){
        if(videp(*p)) printf("La suppresion et impossible");
        while((!(videp(*p)))&&(valeurp(*p)!=elt)){
                supprimerp(p);
        }
}

//5

//Same thing we just  change valeurp(*p)!=elt by valeurf(*f)!=elt.

void defilerJusqua(file *f,int elt){
        if(videf(*f)) printf("La suppresion et impossible");
        while((!(videf(*f)))&&(valeurf(*f)!=elt)){
                supprimerf(f);
        }
}

int main(){
	file f;
	creerf(&f);
	remplirf(&f);
	afficher_f(f);
	defilerJusqua(&f,3);
	printf("\n");
	afficher_f(f);
}
