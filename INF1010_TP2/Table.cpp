/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 10 Fevrier 2019
* Auteurs : Gabriel Dannenbaum Lucas Tassaux
*/

#include "Table.h"

//constructeurs
Table::Table() {
	

	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
	

	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}

//destructeur
Table::~Table() {
	for (int i = 0; i < commande_.size(); i++) {
		delete commande_[i];
	}
}

//getters
int Table::getId() const {
	return id_;
}

int Table::getNbPlaces() const {
	return nbPlaces_;
}

int Table::getnbClientATable() const
{
	return nbClientsATable_;
}

bool Table::estPleine() const {
	return nbPlaces_==0;
}

bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

//setters
void Table::setId(int id) {
	id_ = id;
}


void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	
	commande_.clear();
	
}

void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;

}

//autres methodes
// ajout d'un plat a une commande
void Table::commander(Plat* plat) {

	commande_.push_back(new Plat(*plat));
	
}
//calcul du chiffre d'affaire sur une table 
double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (unsigned int i = 0; i < commande_.size(); i++) {
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}

//affichage
ostream & operator<<(ostream & fichier, const Table & table)
{
 fichier << "La table numero " << table.id_;
	if (table.estOccupee()) {
		fichier << " est occupee. ";
		if (table.commande_.size() > 0) {
			fichier << "Voici la commande passee par les clients : " << endl;
			for (unsigned int i = 0; i < table.commande_.size(); i++) {

				fichier << *table.commande_[i];
			}
		}
		else
			fichier << "Mais ils n'ont rien conmmande pour l'instant. " << endl;
	}
	else {
		fichier << " est libre. " << endl;
	}

	return fichier;
}
