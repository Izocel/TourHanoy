#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "Disque.h"

class Tour :
    private std::stack<Disque>
{
public:
    std::vector<std::string> m_vecteurString{};
    Tour();
    Tour(int nombreDisqueEnJeu, std::string nomTour);
    Tour(std::string nomTour, std::vector<Disque> vecteurDisque);
    void recevoir(Tour& tour);
    std::string toString();
    int nombreDisque();
    
private:
    std::string m_nom{ "T1" };
    std::string m_string {""};
    int m_hauteur{ 6 };
    int m_largeur{ 18 };

    Disque sortir();
    void majStringSurSortie();
    void initialiserListeVecteurString();
    void majStringSurReception(std::string stringDisque);
    std::string ajouterEspaceChar(std::string stringDisque);
};

