#include<stdio.h>
#include<stdlib.h>
#include"file.h"

void defilerEnfiler (file *f,file *g) {
	if (!(videf(*f))) {
	ajouterf(valeurf(*f),g);
	supprimerf(f);
	}
	else printf("Le file f et vide!!\n");
	}

int comparer (file f,file g) {
	if((videf(f))||(videf(g)))
		printf("l'une des files et vide!!\n");
	else{
		if(valeurf(f)<valeurf(g)) return 0;
		return 1;
	}
	return -1;
}

void permuteFile(file *f,file *g){
	file f1;
	creerf(&f1);
	while(!videf(*f)){
		ajouterf(valeurf(*f),&f1);
		supprimerf(f);
	}
	while(!videf(*g)){
		ajouterf(valeurf(*g),f);
		supprimerf(g);
	}
	while(!videf(f1)){
		ajouterf(valeurf(f1),g);
		supprimerf(&f1);
	}
}


void triFile (file f,file *g){
	file f1; creerf(&f1);
	defilerEnfiler(&f,g);
	while(!videf(f)){
		while((!videf(*g))&&(comparer(f,*g)))
			defilerEnfiler(g,&f1);
		defilerEnfiler(&f,&f1);
		while(!videf(*g))
			defilerEnfiler(g,&f1);
		permuteFile(g,&f1);
	}
}

int main(){
	file f; creerf(&f);
	file q; creerf(&q);
	remplirf(&f);
	afficherf(f);
	triFile(f,&q);
	afficherf(q);
}

