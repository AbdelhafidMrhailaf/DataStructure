#include<stdio.h>
#include<stdlib.h>
#include"filec.h"

void creerfc(filec *f){
	(*f).it=(*f).iq=0;
}

int videfc(filec f){
	if(f.it==f.iq) return 1;
	return 0;
}

int valeurfc(filec f){
	if(videfc(f)){
		printf("La valeur non définie.\n");
		exit(-1);
	}
	if(f.it==N) return f.tab_fc[0];
	else return f.tab_fc[f.it+1];
}

int ajouterfc(int x,filec *f){
	if((*f).iq==N)  (*f).iq=0;
	else (*f).iq++;
	if((*f).iq==(*f).it){
		 printf("Le file circulaire et plein\n");
		 exit(-1);
		}
	else{
	(*f).tab_fc[(*f).iq]=x; //Not sure.
	return 1;
	}
}

int supprimerfc(filec *f){
	if(videfc(*f)){
		printf("La suppression non definie.\n");
		exit(-1);
	}//Not sure if i should add else.
	(*f).it=(*f).it+1;
	if((*f).it==N+1) (*f).it=0;
}
void remplirfc(filec *f){
	int i;
	printf("Rempliration de la file avec des entiers\n");
	for(;;){
		printf("Enter an integer exept -1 :");
		scanf("%d",&i);
		if(i>=0) ajouterfc(i,f);
		else break;
	}
}
int afficherfc(filec f){
	int i;
	if(videfc(f)){
		printf("La file et vide\n");
		return 0;
	}
        printf("Affichage de la file des entiers. \n");
        printf("La tete de la file et %d.\n",valeurfc(f));
	for(i=f.it+1;(i<=f.iq);i++)
		printf("%d  ",f.tab_fc[i]);
	printf("\n");
}

