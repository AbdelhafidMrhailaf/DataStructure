#define N 50

typedef struct { int tab_f[N];
		 int it,iq;
		}file;

void creerf(file *);
int videf(file );
int valeurf(file );
int ajouterf(int ,file *);
int supprimer(file *);
int afficherf(file );
void remplirf(file *);

