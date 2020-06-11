
typedef struct cellule{
		int val;
		struct cellule *lien;
	   } cellule;
cellule *creerc();
int videc(cellule *);
void remplirc(cellule *);
void affichagel(cellule *);
void affichagelAdd(cellule *);
int longueurl(cellule *);
cellule *insererDebut(cellule *,cellule *);
cellule *insererFin(cellule *,cellule *);
cellule *rechercheEltl(cellule *,int );
cellule *rechercheEltSl(cellule *,int );
cellule *supprimerc(cellule *,int );
cellule *recherchePreced(cellule *,int );
cellule *insererc(cellule *,cellule *);
