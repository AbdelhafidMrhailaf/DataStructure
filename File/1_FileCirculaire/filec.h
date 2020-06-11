#define N 3

typedef struct { int tab_fc[N];
		 int it,iq;
		}filec;

void creerfc(filec *);
int videfc(filec );
int valeurfc(filec );
int ajouterfc(int ,filec *);
int supprimerc(filec *);
int afficherfc(filec );
void remplirfc(filec *);

