#include<stdio.h>
#include<stdlib.h>
#include"listchainnee.h"

void defilerEnfiler (file *f1,file *f2) {
	if(videf(*f1)) printf("Attention! le file et vide.\n");
	else {
		ajouterf(valeurf(*f1),f2);
		supprimerf(f1);
	}
}


int comparer (file f1,file f2) {
	if ((videf(f1) || (videf(f2)) printf("L'une des files et vide.\n");
	else {
		if (valeurf(f1)<valeurf(f2)) return 0;
		else return 1;
	}
}

void permuteFile (file *f1,file *f2) {
	file f3;
	creerf(&f3);
	while (!videf(*f1)) {
		ajouterf(valeurf(*f1),&f3);
		supprimerf(f1);
	}
	while (!videf(*f2)) {
		ajouterf(valeurf(*f2),f1);
		supprimerf(f2);
	}
	while (!videf(f3)) {
		ajouterf(valeurf(f3),f1);
		supprimerf(&f3);
	}
}

void triFile (file f1,file *f2) {
	file f3;
	creerf(&f3);
	if (videf(f1)) printf("La file a trie et vide!!!\n");
	else {
		defilerEnfiler(&f1,f2);
		while (!videf(f1)){
			while ((!videf(f2))&&comparer(f1,*f2)) defilerEnfiler(f2,&3);
			defilerEnfiler(&f1,&f3);
			while (!videf(*f2)) 
				defilerEnfiler(f2,&f3);
			permuteFile(f2,&f3);
			}
	}
}


