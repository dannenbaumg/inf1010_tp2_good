/*
* Titre : Restaurant.h - Travail Pratique #2
* Date : 10 Fevrier 2019
* Auteurs : Gabriel Dannenbaum Lucas Tassaux
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "Menu.h"

const int INTTABLES = 6;
class Restaurant {
public:
	//constructeurs
	Restaurant();
	Restaurant(const string& fichier, const string& nom,  TypeMenu moment);
	Restaurant(const Restaurant& resto);
	//destructeur
	~Restaurant();

	//setters
	void setMoment(TypeMenu moment);
	void setNom(string* nom);

	//getters
	string getNom() const;
	TypeMenu getMoment() const;

	//Autres methodes
	void lireTable(const string& fichier);
	Restaurant& operator +=( Table* table); 
	Restaurant & operator =(const Restaurant& resto);
	bool operator < (const Restaurant& resto);
	void libererTable(int id);
	friend ostream& operator<<(ostream& fichier, const Restaurant& restaurant);
	void commanderPlat(const string& nom, int idTable); 

	void placerClients(int nbClients);

private:
	string* nom_;

	double chiffreAffaire_;
	TypeMenu momentJournee_;

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_;
	Menu* menuMidi_;
	Menu* menuSoir_;

	//liste des tables
	vector <Table*> tables_;
};
#endif // !RESTAURANT_H
