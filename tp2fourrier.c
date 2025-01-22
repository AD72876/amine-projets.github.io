#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void fourrier(){
	unsigned  n;
	unsigned  i;				// variables pour naviguer dans le tableau 2D i = ligne; j = colonne
	unsigned j;
    unsigned  ligne;
    unsigned  colonne;
	printf("n = ");		// entrée de la valeur n par l'utilisateur
    scanf("%d",&n);
	ligne = pow(2,n);
	colonne=(2 * n)+1;
    unsigned  tab[ligne][colonne];
	int		division;		// variable permettant de diviser le tableau en plusieurs partie pour guider la boucle
	int		compteur;		// variable servant de repère dans la boucle (incrémentation)
	int		valeur;			// variable servant au remplissage de la table de vérité (valeur booléenne)

	i = 0;
	j = 0;
	compteur = 0;
	valeur = 0;
	division = ligne / 2;
	while (division >= 1)		// boucle pour initialiser les valeurs de vérité (les n premieres colonnes)
	{
		if (compteur < division)		// on place les valeurs par bloc de division (ex: 4 par 4 si division = 4)
		{
			tab[i][j] = valeur;
			compteur++;
		}
		else
		{
			compteur = 1;
			valeur = (valeur + 1) % 2;		// on change la valeur assignée de 0 à 1 ou de 1 à 0 si le bloc est fini
			tab[i][j] = valeur;
		}
		i++;
		if (i == ligne)		// si on arrive à la fin de la colonne on passe à la prochaine
		{
			j++;
			i = 0;
			division = division / 2;
			compteur = 0;
			valeur = 0;
		}
	}
	colonne = n;		// colonne = n pour remplir f
	i = 0;
	while (i < ligne)		// remplissage de f
	{
		printf("donnez f valeur %i: ", (i + 1));
		scanf("%d", &tab[i][colonne]);
		i++;
	}
	colonne=(2 * n)+1;
	compteur = 0;
	division = ligne / 2;
	i = 0;
	j = n + 1;		// on commence le calcul à la colonne n + 1 (après celle de f)
	while (j < colonne)		// calcul de la ANF
	{
		if (compteur < division)
		{
			tab[i][j] = (tab[i][j - 1]+tab[i+division][j-1]) % 2;		// on recopie les valeurs (première étape de l'Algorithme papillon)
			compteur++;
		}
		else if (compteur < division + division)		// addition des termes entre eux
		{
			compteur++;
			tab[i][j] = (tab[i-division][j-1]-tab[i][j-1])%2;
		}
		else		// on retourne à la première partie (recopier)
		{
			compteur = 0;
			continue ;		// revient au début de la boucle
		}
		i++;
		if (i == ligne)		// si on arrive à la fin de la colonne on passe à la suivante
		{
			i = 0;
			j++;
			division = division / 2;
			compteur = 0;
		}
	}
    for(i=0; i<ligne ; i++)		// affichage
    {
    	for(j=0; j<colonne ; j++)
        {
            printf("%d | ",tab[i][j]);
        }
        printf("\n");
    }

}

int main()
{
	fourrier();
	return (0);
}
