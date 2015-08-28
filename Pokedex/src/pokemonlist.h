/*
 * PokemonList.h
 *
 *  Created on: 2013-11-02
 *      Author: Jagath
 */

#ifndef POKEMONLIST_H_
#define POKEMONLIST_H_

#include <bb/cascades/DataModel>
#include <iostream>

class PokemonList: public bb::cascades::DataModel {
	Q_OBJECT
public:
	PokemonList(QObject *parent = 0);

	// Required interface implementation
	virtual int childCount(const QVariantList& indexPath);
	virtual bool hasChildren(const QVariantList& indexPath);
	virtual QVariant data(const QVariantList& indexPath);

	virtual ~PokemonList();
};
#endif /* POKEMONLIST_H_ */
