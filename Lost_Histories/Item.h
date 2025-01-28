#pragma once
#include <string>

using namespace std;

class Item
{

private:
	/**
	*	@brief Name of the Item. Private.
	*/
	string itemName;

	/**
	*	@brief The Items description. Private.
	*/
	string itemDescription;

	/**
	*	@brief If the item is destroyed, it wont be able to be used again. Private.
	*/
	bool isDestroyed;

public:
	/**
	*	@brief Defualt constructor for the Item. 
	*/
	Item();
	//Obstacle iLinkedObs

	/**
	*	@breif Set defualt name and description for Item
	*	@param nName The name of the Item, as a String
	*	@param nDesc The description for the item, as a String
	*/
	void set_Item_Defaults(string iName, string iDesc);

	/**
	*	@brief Gets the Items name
	*	@return The name of the Item as a String
	*/
	string get_Item_Name();

	/**
	*	@brief Gets the Items description
	*	@return The Items description as a String
	*/
	string get_Item_Description();

	/**
	*	@brief Changes the item to be destroyed
	*/
	void destroy_Item();

	/**
	*	@brief A check to see if the Item is destroyed
	*	@return The items destroyed value as a Bool
	*/
	bool is_Item_Destroyed();


};

