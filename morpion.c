#include<stdio.h>
#define ligne 3
#define colonne 3
#define BLANK ' '
#define J1 'X'
#define J2 'O'

char tab[ligne][colonne];

/**
* Fonction permettant d'initialiser
* chacune des cases du tableau de tab
* a BLANK
*
*/
/*Initialisation du tableau du morpion a vide : */
void InitialiserTableau(void)
{
	int i, j;
	for (i=0; i<ligne; i++)
		for (j=0; j<colonne; j++)
			tab[i][j] =BLANK;
}


/*Afficher du tableau du morpion : */
void AfficherTableau(void)
{
int i,j;
printf("\t\t    0       1       2\n");
printf("\t\t_________________________\n");
for(i=0;i<3;i++)
{
printf("\t %d",i);
for(j=0;j<3;j++)
{
printf("\t| %c",tab[i][j]);
}
printf("\t|");
printf("\n\t\t|_______|_______|_______|\n");
}
}

/**
* Verifie si une ligne donnée
* est gagnante pour le joueur
* passé en paramètre
*
* @param char joueur
* @return 0 si non
* 1 si oui
*/
int VerifLigne(char joueur)
{
int i,j;
int gagne=0;
for(i=0;i<3;i++)
{
gagne=0;
for(j=0;j<3;j++)
{
if(tab[i][j]==joueur)
{
gagne++;
}
}
if(gagne==3)
return 1;
}
return 0;
}

/**
* Verifie si une ligne donnée
* est gagnante pour le joueur
* passé en paramètre
*
* @param char joueur
* @return 0 si non
* 1 si oui
*/
int VerifCol(char joueur)
{
int i,j;
int gagne=0;
for(j=0;j<3;j++)
{
gagne=0;
for(i=0;i<3;i++)
{
if(tab[i][j]==joueur)
{
gagne++;
}
}
if(gagne==3)
return 1;
}
return 0;
}

/**
* Verifie si une diagonale donnée
* est gagnante pour le joueur
* passé en paramètre
*
* @param char joueur
* @return 0 si non
* 1 si oui
*/
int VerifDiagonale(char joueur)
{
if(tab[0][0]==joueur && tab[1][1]==joueur && tab[2][2]==joueur)
return 1;
if(tab[2][0]==joueur && tab[1][1]==joueur && tab[0][2]==joueur)
return 1;
return 0;
}

/**
* Fonction qui vérifie si le
* tab est terminé.
*
* @return 0 si pas terminé
* 1 si J1 gagné
* 2 si J2 gagné
* -1 si match nul
*/
int Fintab (void)
{
int i,j;
if(VerifLigne(J1)==1)
return 1;
if(VerifCol(J1)==1)
return 1;
if(VerifDiagonale(J1)==1)
return 1;
if(VerifLigne(J2)==1)
return 2;
if(VerifCol(J2)==1)
return 2;
if(VerifDiagonale(J2)==1)
return 2;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(tab[i][j]==BLANK)
return 0;
}
}
return -1;
}

/**
* Fonction qui permet de verifier
* si une case a déjà été jouée.
* Effectue le tab sinon.
*
* @param x abcisse de la case
* @param y ordonnée de la case
* @param Joueur caractère du joueur (J1 ou J2)
* @return 1 si le tab est possible (et le fait)
* 0 sinon
*/
int JouerCase(int x, int y, char Joueur)
{
printf("les numeros doivent etre compris entre [1,3]\n");
do
{
if ((x>0) && (x<=ligne) && (y>0) && (y<=colonne))
{
x--; /*pour etre compatible avec les indices du tableau*/
y--;
if(tab[y][x]==BLANK)
{
tab[y][x]=Joueur;
return 1;
}
if (tab[ligne][colonne]!=BLANK)
printf("Si tu sais pas compter jusqu'à 3, retourne a la maternelle !\n");
printf("Ma Grand Mere fait mieux que toi !\n");
printf("Retourne a la creche !\n");
printf("La case a deja ete remplie. Veuillez en choisir une autre :\n");
}
else
printf("si tu sais pas lire, retourne a la maternelle ! \n");
printf("Ma Grand Mere fait mieux que toi !\n");
printf("Retourne a la creche !\n");
printf("Indice de ligne ou colonne incorrect. Veuillez resaisir :\n");
}
while(tab[ligne][colonne]==BLANK);
return 0;
}

/**
* Fonction qui effectue un tour de tab
* et permet à chaque joueur de saisir
* ses coordonnées de tab
*
* @param char joueur (J1 ou J2)
*/
void Tourtab(char joueur)
{
int x,y;
do{
printf("\n\nTour de %c\n",joueur);
printf("Choix des coordonnees de la casse\n");
printf("Abscisse : ");
scanf("%d",&x);
printf("Ordonnee : ");
scanf("%d",&y);
printf("\n\n");
}
while(JouerCase(x,y,joueur)==0);
}

/**
* PROGRAMME PRINCIPAL
*/
int main()
{
printf("\t\t******************************\n");
printf("\t\t-*-Bienvenu Dans le Morpion-*-\n");
printf("\t\t******************************\n");
printf("\t\t     -*-CHOC DES TTIANS-*-\n");
printf("\n\n\n");
printf("les coordonnees doivent etre compris entre [1,3]\n");
printf("\n\n\n");
int tourtab=0;
int fintab;
InitialiserTableau();

fintab=Fintab();
while(fintab==0)
{
AfficherTableau();
if(tourtab%2==0)
{
Tourtab(J1);
}
else
{
Tourtab(J2);
}
tourtab++;
fintab=Fintab();
}
AfficherTableau();
switch(fintab)
{
case 1:
printf("Felicitation J1, vous avez gagne !!!\n");
printf("Tu as bien jouer J2\n");
break;
case 2:
printf("Félicitation J2, vous avez gagne !!!\n");
printf("Tu as bien jouer J1\n");
break;
default:
printf("Match Nul !!!\n");
printf("Vous etes de force egale !\n");
}
}
