
cellule *rES(cellule *l,int x){
	cellule *p=l;
	cellule *pp=NULL;
	while((p!=NULL)&&((*p).val!=x){
		pp=p;
		p=p->lien;
	}
	return pp;
}


cellule *supprimerc(cellule *l,int x){
	cellule *p=l,*pp=NULL;
	if(((*p).val==x)&&(p->lien!=NULL)){l=p->lien;free(p);return l;}
	pp=rES(l,x);
	p=pp->lien;
	pp->lien=p->lien;
	free(p);
}


