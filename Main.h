#pragma once
#include <iostream>
#include <stack>
#include "Disque.h"
#include "Tour.h"

const std::string MSGSOURCE = "Entrez le numero de la tour source.\n[1-3]-SOURCE: ";
const std::string MSGCIBLE = "Entrez le numero de la tour cible.\n[1-3]-CIBLE: ";
const int NOMBREDISQUE{ 5 };
const int NOMBRETOUR{ 3 };

Disque disk1{ 1 }, disk2{ 2 }, disk3{ 3 }, disk4{ 4 }, disk5{ 5 };
std::vector<Disque> initialiserVecteurDisque() {

    std::vector<Disque> vecteurDisque{ 
        disk1, 
        disk2, 
        disk3,
        disk4,
        disk5
    };

    return vecteurDisque;
}
std::vector<Disque> vecteurDisque1{ initialiserVecteurDisque() };

Tour tourInitiale{ "T1" , vecteurDisque1 },
tourSeconde{ NOMBREDISQUE , "T2" },
tourFinale{ NOMBREDISQUE , "T3" };
std::vector<Tour> initialiserVecteurTours() {

    std::vector<Tour> vecteurTours{ 
        tourInitiale,
        tourSeconde,
        tourFinale
    };

    return vecteurTours;
}
std::vector<Tour> vecteurTours{ initialiserVecteurTours() };

std::string stringTour{ "" };



void choixTourUsager(const std::string message, int& intEntrer)
{

    std::cout << message;
    std::cin >> intEntrer;
}

void deplacerDisque(int& numSource, int& numCible)
{

    Tour& tourSource{ vecteurTours[numSource-1] };
    Tour& tourCible{ vecteurTours[numCible-1] };

    if (tourSource.nombreDisque() > 0)
        tourCible.recevoir(tourSource);
    return;
}

void actualiserTourString() {
    int n1 = vecteurTours[0].m_vecteurString.size();
    int n2 = vecteurTours.size();
    int k{ 0 };
    stringTour = "";

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            stringTour.append(vecteurTours[j].m_vecteurString[i]);
        }
        stringTour += "\n";
    }

}


void afficherToursString()
{
    std::cout << stringTour + "\n\n";
}