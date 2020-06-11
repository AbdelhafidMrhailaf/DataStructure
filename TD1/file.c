#include<stdio.h>
#include<stdlib.h>
#include"file.h"

void creerf(file *f){
	(*f).it=(*f).iq=0;
}

int videf(file f){
	if(f.it==f.iq) return 1;
	return 0;
}

int valeurf(file f){
	if(!(videf(f)))
		return f.tab_f[f.it+1];
	printf("Valeur non definie\n");
	exit(-1);
}

int ajouterf(int x,file *f){
	(*f).iq++;
	if((*f).iq<N){
		(*f).tab_f[(*f).iq]=x;
		return 1;
	}
	printf("Implimentation Inssufisante\n");
	exit(-1);
}

int supprimerf(file *f){
	if(videf(*f)){
			printf("Suppression et Impo\n");
			exit(-1);
	}
	(*f).it++;
	return 1;
}
void remplirf(file *f){
	int i;
	printf("Rempliration de la file avec des entiers\n");
	for(;;){
		printf("Enter an integer exept -1 :");
		scanf("%d",&i);
		if(i>=0) ajouterf(i,f);
		else break;
	}
}
int afficherf(file f){
	int i;
	if(videf(f)){
		printf("La file et vide\n");
		return 0;
	}
        printf("Affichage de la file des entiers. \n");
        printf("La tete de la file et %d.\n",valeurf(f));
	for(i=f.it+1;(i<=f.iq);i++)
		printf("%d  ",f.tab_f[i]);
	printf("\n");
}

