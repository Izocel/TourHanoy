#include "Disque.h"

/// <summary>
/// Constructeur de base du disque
/// </summary>
/// <param name="rayon">Le rayon unitaire du disque</param>
Disque::Disque(int rayon)
{
	if (rayon > 0  && rayon < 10) {
		m_rayon = rayon;
	}
	//else throw

}
int Disque::rayon() const
{
	return m_rayon;
}
/// <summary>
/// Retourne la représentation du disque en chaine de caractère ex: '++2++' pour un rayon de 2
/// </summary>
/// <returns>Une chaine de caractère</returns>
std::string Disque::toString() const
{
	std::string resultat = "";
	for (int i = 0; i <= m_rayon-1; i++)
	{
		resultat.append("+");
	}
	resultat.append(std::to_string(m_rayon));

	for (int i = 0; i <= m_rayon - 1; i++)
	{
		resultat.append("+");
	}
    return resultat;
}
