/*
 * PokemonList.cpp
 *
 *  Created on: 2013-11-02
 *      Author: Jagath
 */

#include "pokemonlist.h"
#include <iostream>
using std::cerr;
using std::endl;
/*
 * PokemonList is derive from DataModel which provides the base class for the "model"
 * in the model-view-controller pattern used by the ListView UI control
*/

PokemonList::PokemonList(QObject* parent) : bb::cascades::DataModel(parent) {
}

// Return the number of child items contained in a given entry
// Since we only implement a flat list, we must return 0 for any sub item.
int PokemonList::childCount(const QVariantList& indexPath) {
	// For indexPath, See http://developer.blackberry.com/native/reference/cascades/bb__cascades__datamodel.html

	// Return the item count if asking for top level count
	if (indexPath.empty()){
		static int ind = 0;
		QFile file("app/native/assets/data/pokemon_species_names.csv");
			if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
				QTextStream in(&file);
				while (!in.atEnd() && ind!=719) {
					QStringList line = in.readLine().split(","); // Read a line as a QStringList and split it where ever a "," exists
					if((line[0]).toInt()==(ind+1) && line[1]=="9") ind++; //incrementing 'ind' every time an english pokemon is found
				}
			}
			else cerr << "Failed to open types.csv: " << file.error() << endl;
			return ind;	// TODO: Return the correct number of pokemon
	}

	// No sub levels
	return 0;
}

// Used for displaying multi-level lists
bool PokemonList::hasChildren(const QVariantList& indexPath) {
	if (indexPath.empty())
		return true; // The root node always has children
	else
		return false; //d
}

// Return the data for the item given by indexPath
QVariant PokemonList::data(const QVariantList& indexPath) {
	// TODO: Load the list from db/pokemon.csv file
	//static QString pokemon_list[6]={"#001 Bulbasaur [Grass, Poison]", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard"};
	//static QString pokemon_type[6]={"Grass, Poison", "Grass, Poison", "Grass, Poison", "Fire", "Fire", "Fire, Flying"};
	static QString pokemon_list[718];

	QFile file("app/native/assets/data/pokemon_species_names.csv");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream in(&file);
		static int j = 1;
		while (!in.atEnd() && j!=719) {
			QStringList line = in.readLine().split(",");
			if((line[0]).toInt()==j && line[1]=="9"){
				pokemon_list[j-1] = line[2];
				j++;
				//cerr<<j<<endl;
			}
		//j++
		}
	}
	else cerr << "Failed to open types.csv: " << file.error() << endl;

	int i = indexPath[0].toInt(); 		// Get the menu index
	QString pokemon = pokemon_list[i];
/*	QVariantMap data;
	data["name"] = pokemon_list[i];	// Get the name of pokemon for this index
	data["type"] = pokemon_type[i];
	return data;			// Return the name as a QVariant object
*/
	return QVariant(pokemon);
}

PokemonList::~PokemonList() {
	// TODO: Delete any object that were created
}

