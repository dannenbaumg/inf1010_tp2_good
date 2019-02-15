/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 10 Fevrier 2019
* Auteurs : Gabriel Dannenbaum Lucas Tassaux
*/

#include "Plat.h"

//constructeurs
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}
//getters

string Plat::getNom() const {
	return nom_;
}

double Plat::getPrix() const {
	return prix_;
}

double Plat::getCout() const {
	return cout_;
}
//setters
void Plat::setNom(string nom) {
	nom_ = nom;
}

void Plat::setPrix(double prix) {
	prix_ = prix;
}



//methodes en plus
// Operateur d'affichage
ostream & operator<<(ostream & fichier, const Plat & plat)
{
	fichier << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return fichier;
}

// operateur comparant les prix de deux plats 
bool Plat::operator<(const Plat & plat1)
{
	return (prix_ < plat1.prix_ == true);
	
}


