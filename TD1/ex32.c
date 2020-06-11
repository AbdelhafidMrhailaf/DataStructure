#include<stdio.h>
#include<stdlib.h>
#include"pile.h"

void pairOrdre(pile p,pile *q){
	pile q1; creerp(&q1);
	while(!(videp(p))){
		if(!(valeurp(p)%2)) ajouterp(valeurp(p),&q1);
		supprimerp(&p);
	}
	while(!(videp(q1))){
		ajouterp(valeurp(q1),q);
		supprimerp(&q1);
	}
}

int main(){
	pile p; creerp(&p);
	pile q; creerp(&q);
	remplirp(&p);
	afficherp(p);
	pairOrdre(p,&q);
	afficherp(q);
}

