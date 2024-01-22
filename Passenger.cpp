//
//  Passenger.cpp
//  Titanic
//
//  Created by Danielle Choi on 11/15/23.
//

#include "Passenger.h"

namespace cs32
{

Passenger::Passenger(){
    mClass = Class::NOTKNOWN;
    mEmbarked = Embarcation::NOTKNOWN;
    mName = "";
    mSurvived = false;
    mFare = 0.0;
}
void Passenger::setName( std::string name ){
    mName = name;
}
std::string Passenger::getName(){
    return mName;
}
void Passenger::setEmbarcation( std::string embarked ){
    if ( embarked == "C" )
        mEmbarked = Embarcation::CHERBOURG;
    else if ( embarked == "Q" )
        mEmbarked = Embarcation::QUEENSTOWN;
    else if ( embarked == "S" )
        mEmbarked = Embarcation::SOUTHHAMPTON;
    else
        mEmbarked = Embarcation::NOTKNOWN;
}
void Passenger::setClass( std::string classOfFare ){
    if ( classOfFare == "1" )
        mClass = Class::FIRST;
    else if ( classOfFare == "2" )
        mClass = Class::SECOND;
    else if ( classOfFare == "3" )
        mClass = Class::THIRD;
    else
        mClass = Class::NOTKNOWN;
}
void Passenger::setSurvived( std::string survived ){
    if ( survived == "1" )
        mSurvived = true;
    else if (survived == "0" )
        mSurvived = false;
    else
        mSurvived = false;
}
void Passenger::setFare( std::string fare ){ 
    if( fare != "" )
        mFare = std::stof( fare );
}
Embarcation Passenger::getEmbarcation(){
    return mEmbarked;
}
Class Passenger::getClass(){
    return mClass;
}
bool Passenger::getSurvived(){
    return mSurvived;
}
double Passenger::getFare(){
    return mFare;
}

}
