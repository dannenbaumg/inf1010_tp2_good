/*
* Titre : main.cpp - Travail Pratique #2
* Date : 10 Fevrier 2019 
* Auteurs : Gabriel Dannenbaum Lucas Tassaux
*/

#include "Restaurant.h"

using namespace std; 

int main() {

	//creation du restaurant 
	Restaurant poly("polyFood.txt", "PolyFood", Soir); 

	//creer plusieurs clients 
	int nbclient1 = 1; 
	int nbclient2 = 5; 
	int nbclient3 = 15; 
	int nbclient4 = 3; 
	int nbclient5 = 2; 


	//placer les clients 
	poly.placerClients(nbclient1);
	poly.placerClients(nbclient2);
	poly.placerClients(nbclient3); 
	poly.placerClients(nbclient4); 
	poly.placerClients(nbclient5); 

	// commander des plats 
	poly.commanderPlat("Poisson", 1);
	poly.commanderPlat("Poulet", 2);
	poly.commanderPlat("Pizza", 2); 
	poly.commanderPlat("Poulet", 4); 
	poly.commanderPlat("Muffin", 4); 
	poly.commanderPlat("Oeuf", 4); 


	//Creation d'une copie du poly restaurant 
	Restaurant poly2(poly);
	string* ptrNom = new string("PolyFood2");
	poly2.setNom(ptrNom);

	//Affichage du restaurant poly 
	cout << poly;

	cout << "--------------------------------------------------------------------------------------------------" << endl; 


	//liberer les tables et calcule du chiffre d'affaire
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);

	cout << poly;

	cout << "====================================================================================================" << endl;

	// Le restaurant Poly2 ne doit pas encore avoir liberer ses tables
	cout << poly2;
	// Copie du restaurant poly dans poly2
	poly2 = poly;
	

	cout << "--------------------------------------------------------------------------------------------------" << endl;
	// Le restaurant Poly2 doit maintenant avoir toutes ses tables lib�r�es
	cout << poly2;
	return 0;

}