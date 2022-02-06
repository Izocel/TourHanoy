#include "Main.h"


int main()
{
    bool estJouer{ true };
    int choixTourSource{ 0 };
    int choixTourCible{ 0 };
    std::cout << "Bienvenue sur la tour d'Hanoi\n";
    while (estJouer)
    {
        actualiserTourString();
        while (choixTourSource == choixTourCible)
        {
            afficherToursString();
            choixTourUsager(MSGSOURCE, choixTourSource);
            choixTourUsager(MSGCIBLE, choixTourCible);
        }
        if(choixTourCible <= NOMBRETOUR && choixTourSource <= NOMBRETOUR)
        deplacerDisque(choixTourSource, choixTourCible);

        choixTourSource = 0;
        choixTourCible = 0;

        estJouer = vecteurTours[NOMBRETOUR-1].nombreDisque() == NOMBREDISQUE ? false : true;
    }
    std::cout << "\n\n Partie gagné !!!\n";
    return estJouer;
}
