#include<stdio.h>
#include<stdlib.h>
#include"pile.h"
#include"file.h"
//Passage par valeur.
int appartientp(pile p,int x){
	if(videp(p)) return 0;
	while((!(videp(p)))&&(valeurp(p)!=x)){
		supprimerp(&p);
	}
	if(videp(p)) return 0;
	return 1;
}
//passage par adresse.
int appartinetpp(pile *p,int x){
	pile p1;
	creerp(&p1);
	if(videp(*p)) return 0;
	while((!(videp(*p)))&&(valeurp(*p)!=x)){
		ajouterp(valeurp(*p),&p1);
		supprimerp(p);
	}
	if(videp(*p)){
		while(!videp(p1)){
			ajouterp(valeurp(p1),p);
			supprimerp(&p1);
		}
		return 0;
	}
	while(!videp(p1)){
                        ajouterp(valeurp(p1),p);
                        supprimerp(&p1);
        }
	return 1;
}
void inverserf(file *f){
	pile p;
	creerp(&p);
	while(!videf(*f)){
		ajouterp(valeurf(*f),&p);
		supprimerf(f);
	}
	while(!videp(p)){
		ajouterf(valeurp(p),f);
		supprimerp(&p);
	}
}

void inverserp(pile *p){
	pile p1,p2;
	creerp(&p1);
	creerp(&p2);
	while(!videp(*p)){
		ajouterp(valeurp(*p),&p1);
		supprimerp(p);
	}
	while(!videp(p1)){
		ajouterp(valeurp(p1),&p2);
		supprimerp(&p1);
	}
	while(!videp(p2)){
		ajouterp(valeurp(p2),p);
		supprimerp(&p2);
	}
}

int main(){
	 pile p;
	 creerp(&p);
	 remplirp(&p);
	 afficherp(p);
	 printf("\n");
	 if(appartientp(p,3)) printf("Il appartient.\n");
	 else printf("Il n'appartient pas.\n");
	 inverserp(&p);
	 afficherp(p);
}

