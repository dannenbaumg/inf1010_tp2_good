/*
* Titre : Plat.h - Travail Pratique #2
* Date : 10 Fevrier 2019
* Auteurs : Gabriel Dannenbaum Lucas Tassaux
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Plat {
public:
	// constructeurs
	Plat();
	Plat(string nom, double prix, double cout);

	//getters
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	//setters
	void setNom(string nom);
	void setPrix(double prix);

	//methodes en plus
	friend ostream& operator<<(ostream& fichier, const Plat& plat);
    bool operator < (const Plat& plat1);

private:
	string nom_;
	double prix_;
	double cout_;

};

#endif // !PLAT_H
