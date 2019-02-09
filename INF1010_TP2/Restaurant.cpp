/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Restaurant.h"

//constructeurs
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);

}

Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom);

	chiffreAffaire_ = 0;

	momentJournee_ = moment;

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);

	lireTable(fichier);
}

Restaurant::Restaurant(const Restaurant& restaurant) :chiffreAffaire_(restaurant.chiffreAffaire_), momentJournee_(restaurant.momentJournee_)  {
	nom_ = new string(*restaurant.nom_);
	menuMatin_ = new Menu(*restaurant.menuMatin_),
	menuMidi_ = new Menu(*restaurant.menuMidi_),
	menuSoir_ = new Menu(*restaurant.menuSoir_);
	

	for (int i = 0; i < restaurant.tables_.size(); i++) {
		tables_.push_back(new Table(*restaurant.tables_[i]));
	
	}
	
}
//destructeur

Restaurant::~Restaurant() {
	delete nom_;
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;

	for (int i = 0; i < tables_.size(); i++) {	
		delete tables_[i];
	}
}


//setter

void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}
void Restaurant::setNom(string* nom) {
	nom_ = nom;
}
//getters
string Restaurant::getNom() const {
	return *nom_;
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

//autres methodes
Restaurant & Restaurant::operator+=( Table * table)
{
	tables_.push_back(table);
	return *this;
}

Restaurant & Restaurant::operator=(const Restaurant & restaurant)
{
	chiffreAffaire_ = restaurant.chiffreAffaire_;
	momentJournee_ = restaurant.momentJournee_;
	nom_ = new string(*restaurant.nom_);
	menuMatin_ = new Menu(*restaurant.menuMatin_),
	menuMidi_ = new Menu(*restaurant.menuMidi_),
	menuSoir_ = new Menu(*restaurant.menuSoir_);


	for (int i = 0; i < restaurant.tables_.size(); i++) {
		tables_.push_back(new Table(*restaurant.tables_[i]));

	}

	
	return *this;
}


bool Restaurant::operator<(const Restaurant & resto)
{
	return (chiffreAffaire_ < resto.chiffreAffaire_ == true);

}

void Restaurant::libererTable(int id) {
	for (int i = 0; i < tables_.size(); i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
		}
	}
}

ostream & operator<<(ostream & fichier, const Restaurant & restaurant)
{
	fichier << "Le restaurant " << *restaurant.nom_;
	if (restaurant.chiffreAffaire_ != 0)
		fichier << " a fait un chiffre d'affaire de : " << restaurant.chiffreAffaire_ << "$" << endl;
	else
		fichier << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	fichier << "-Voici les tables : " << endl;
	for (int i = 0; i <restaurant.tables_.size(); i++) {
		fichier << "\t";

		fichier << *restaurant.tables_[i];
		fichier << endl;
	}
	fichier << endl;


	fichier << "-Voici son menu : " << endl;
	fichier << "Matin : " << endl;
	fichier << *restaurant.menuMatin_;
	fichier << "Midi : " << endl;
	fichier << *restaurant.menuMidi_;
	fichier << "Soir : " << endl;
	fichier << *restaurant.menuSoir_;

	return fichier;
}



void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* plat = nullptr;
	int index;
	for (int i = 0; i < tables_.size(); i++) {
		if (idTable == tables_[i]->getId()) {
			index = i;
			switch (momentJournee_) {
			case Matin :
				plat = menuMatin_->trouverPlat(nom);
				break;
			case Midi :
				plat = menuMidi_->trouverPlat(nom);
				break;
			case Soir :
				plat = menuSoir_->trouverPlat(nom);
				break;
			}
		}
	}
	if (plat != nullptr && tables_[index]->estOccupee()) {
		tables_[index]->commander(plat);
	}
	else cout << "Erreur : table non occupee ou plat introuvable" << endl;
}

void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (file) {
		string ligne;

		string idString;
		int id;

		string nbPersonnesString;
		int nbPersonnes;

		int curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-TABLES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (unsigned int i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						idString += ligne[i];
					}

					id = stoi(idString);

					nbPersonnesString = ligne.substr(curseur + 1);
					nbPersonnes = stoi(nbPersonnesString);
					Table* ptrTable = new Table(id, nbPersonnes);
					*this += ptrTable;
					
					nbPersonnesString = "";
					idString = "";
				}
			}
		}
		file.close();
	}
}




void Restaurant::placerClients(int nbClients) {
	int indexTable = -1;
	int minimum = 100;


	for (int i = 0; i < tables_.size(); i++) {
		if (tables_[i]->getNbPlaces() >= nbClients && !tables_[i]->estOccupee() && tables_[i]->getNbPlaces() < minimum) {
			indexTable = i;
			minimum = tables_[i]->getNbPlaces();
		}
	}
	if (indexTable == -1) {
		cout << "Erreur : il n'y a plus/pas de table disponible pour le client. " << endl;
	}else
	tables_[indexTable]->placerClient(nbClients);
}

