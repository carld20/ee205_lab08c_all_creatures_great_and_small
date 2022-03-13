///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08c_all_creatures_great_and_small - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   12_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>


enum Gender {
    UNKNOWN_GENDER, MALE, FEMALE
};

const float UNKNOWN_WEIGHT = -1;

class Animal {
public:
    Animal(const std::string &species);

    Animal(const std::string &species, Gender gender);

    Animal(const std::string &species, Gender gender, float weight);

    Animal(const std::string &species, float weight);

    static const std::string &getKingdom();

    const std::string &getSpecies() const;

    Gender getGender() const;

    void setGender(Gender gender);

    float getWeight() const;

    void setWeight(float weight);

    void printInfo();

    bool isValid();

protected:
    static const std::string kingdom;
    std::string species;
    enum Gender gender = UNKNOWN_GENDER;
    float weight = UNKNOWN_WEIGHT;
};

