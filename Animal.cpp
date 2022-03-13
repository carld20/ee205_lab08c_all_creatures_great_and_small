///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08c_all_creatures_great_and_small - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   12_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Animal.h"
using namespace std;

const string Animal::kingdom = "Animalia";

Animal::Animal(const string &newSpecies){
    Animal::species = newSpecies;

}

Animal::Animal(const string &newSpecies, Gender gender) : gender(gender) {
    setSpecies( newSpecies );
}

Animal::Animal(const string &newSpecies, Gender gender, float newWeight) : gender(gender) {
    setSpecies( newSpecies );
    setWeight( newWeight);

}

Animal::Animal(const string &newSpecies, float newWeight){
    setSpecies( newSpecies );
    setWeight( newWeight );

}

const string &Animal::getKingdom() {
    return kingdom;
}

const string &Animal::getSpecies() const {
    return species;
}

Gender Animal::getGender() const {
    return gender;
}

void Animal::setGender(Gender newGender) {
    if( gender != UNKNOWN_GENDER && newGender == UNKNOWN_GENDER ){
        throw logic_error( "Previous must be UNKNOWN_GENDER" );
    }
        Animal::gender = newGender;
}

float Animal::getWeight() const {
    return weight;
}

void Animal::setWeight(float newWeight) {
    if( !validateWeight( weight )) {
        throw invalid_argument("Weight must be > 0");
    }
    Animal::weight = newWeight;
}

void Animal::printInfo() {
    cout << "Animal Fields" << endl;
    cout << "   Kingdom = [" << getKingdom() << "]" << endl;
    cout << "   Species = [" << getSpecies() << "]" << endl;
    cout << "   Weight = [" << getWeight() << "]" << endl;
    cout << "   gender = [" << getGender() << "]" << endl;


}

bool Animal::isValid() {
    if( !validateWeight( weight ) )
        return false;

    return true;

}

bool Animal::validateWeight(const float newWeight) {
    if( newWeight == UNKNOWN_WEIGHT) {
        return true;
    }

    if( newWeight > 0 ) {
        return true;
    }
    return false;
}

bool Animal::validateSpecies(const std::string newSpecies) {
    if( newSpecies.empty() )
        return false;
    return true;
}

void Animal::setSpecies(const std::string newSpecies) {
    if (!validateSpecies( newSpecies ) )
        throw( invalid_argument ( "Can't be emnpty" ) );

    species = newSpecies;

}
