#include<stdio.h>
#include<stdlib.h>
#include"filec.h"

int main(){
	int i,k;
	filec f;
	creerfc(&f);
	for(i=1;i<=50;i++){
		printf("Entrer un entier a ajouter: ");
		scanf("%d",&k);
		ajouterfc(k,&f);
		}
	afficherfc(f);
	}

