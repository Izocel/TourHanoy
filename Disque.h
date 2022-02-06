#pragma once
#include <string>

class Disque
{
private:
	int m_rayon{ 0 };

public:
	Disque(int rayon);
	int rayon() const;
	std::string toString() const;
};

