#include "Tour.h"


    const int LONGUEURCHARMAX{ 2 };
    const int NOMBREDISQUEMAX{ 10 };
    const int ESPACEMENT{ 4 };

Tour::Tour()
{
    initialiserListeVecteurString();
}

Tour::Tour(int nombreDisqueEnJeu, std::string nomTour)
{
    if (nomTour.length() > LONGUEURCHARMAX)
        return; //throw

    if (nombreDisqueEnJeu > NOMBREDISQUEMAX)
        return; //throw


    m_nom = nomTour;
    m_hauteur = nombreDisqueEnJeu;
    
    initialiserListeVecteurString();
}

Tour::Tour(std::string nomTour, std::vector<Disque> vecteurDisque)
{   
    int nombreDisqueEnJeu = vecteurDisque.size();
    if (nomTour.length() > LONGUEURCHARMAX)
        return; //throw

    if (nombreDisqueEnJeu > NOMBREDISQUEMAX)
        return; //throw


    m_nom = nomTour;
    m_hauteur = nombreDisqueEnJeu;

    initialiserListeVecteurString();
    for (int i = nombreDisqueEnJeu -1; i >= 0; i--)
    {
        push(vecteurDisque[i]);
        majStringSurReception(vecteurDisque[i].toString());
    }
}

void Tour::initialiserListeVecteurString() {
    const std::string DEBUTLIGNE    {"        "};
    const std::string LARGEURVIDE   {"                  "};
    const std::string LIGNEVIDE     {"        |         "};
    const std::string LIGNEBAS      {"  --------------  "};
    if (m_vecteurString.size() == 0) {
        m_vecteurString.assign(m_hauteur + ESPACEMENT, LIGNEVIDE);
        m_vecteurString[0] = DEBUTLIGNE + m_nom + DEBUTLIGNE;
        m_vecteurString[1] = LARGEURVIDE;
        m_vecteurString[m_vecteurString.size() - 1] = LIGNEBAS;
    }
}

std::string Tour::ajouterEspaceChar(std::string stringDisque) {

    std::string newString{""};
    std::string espace{ "" };

    int nombreEspace = m_largeur - stringDisque.length();

    if (nombreEspace % 2 == 0)
    {
        espace.replace(0, 1, nombreEspace / 2, ' ');
        newString = espace + stringDisque;

        int diff =  m_largeur - newString.length();
        if (diff > 0) {
            newString.replace(newString.length(), 1, diff, ' ');
        }
    }
    else
    {
        espace.replace(0, 1, nombreEspace / 2, ' ');
        newString = espace + stringDisque;
        espace.replace(0, 1, (nombreEspace / 2) - 1, ' ');

        int diff = m_largeur - newString.length();
        if (diff > 0) {
            newString.replace(newString.length(), 1, diff, ' ');
        }
    }

    return newString;
}

void Tour::majStringSurSortie()
{
    const std::string LIGNEVIDE = "        |         ";
    m_vecteurString[m_hauteur - size() +2 ] = LIGNEVIDE;
}

void Tour::majStringSurReception(std::string stringDisque) {

    if (stringDisque.length() <= m_largeur - ESPACEMENT) {
        int positionLigne = m_hauteur - size() + ESPACEMENT-1;
        m_vecteurString[positionLigne] = ajouterEspaceChar(stringDisque);
    }
}

void Tour::recevoir(Tour& tour) {
    if (size() > 0) {
        if (top().rayon() >= tour.top().rayon()) {
            Disque disque = tour.sortir();
            push(disque);
            majStringSurReception(disque.toString());
        }
    }
    else {
        Disque disque = tour.sortir();
        push(disque);
        majStringSurReception(disque.toString());
        return;
    }
   
    std::cout << "Imposible de placer le disque ici!\n";
    return;
}

Disque Tour::sortir() {
    if (size() > 0) {
        Disque disk = top();
        pop();
        majStringSurSortie();
        return disk;
    }

}

std::string Tour::toString()
{
    return m_string;
}

int Tour::nombreDisque()
{
    return size();
}


