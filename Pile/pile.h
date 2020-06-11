#define N 50
typedef struct { int tab_p[N];
		 int ip;
		}pile;

void creerp(pile *);
int videp(pile );
int ajouterp(int ,pile *);
int valeurp(pile );
int supprimerp(pile *);
void remplirp(pile *);
void afficherp(pile );

