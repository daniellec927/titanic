//
//  PassengerDataBase.cpp
//  Titanic
//
//  Created by Danielle Choi on 11/15/23.
//

#include "PassengerDatabase.h"

namespace cs32 {

PassengerDatabase::PassengerDatabase(){
    passengers.clear();
    isLoaded=false;
}
PassengerDatabase::~PassengerDatabase(){ 
    clearAllPassengers();
}
int PassengerDatabase::load( std::string filePath ){
    CSVFile file( this );
    int recordCount = file.readFile( filePath );
    if ( recordCount >= 1 ) isLoaded = true; //if more than 1 record, isLoaded value is true
    return( recordCount );
}
void PassengerDatabase::clearAllPassengers(){
    int pos=0;
    if ( passengers.size() != pos ) {
        delete passengers[pos]; //delete pointer
        pos++; //increase as we move to next postion
    }
    passengers.clear(); //clear all vector values
}
bool PassengerDatabase::loaded(){
    return isLoaded;
}
Passenger * PassengerDatabase::getPassenger_byName( std::string name ){
    for ( int i = 0; i < passengers.size(); i++ ){
        if ( passengers[i]->getName() == name ){
            return passengers[i];
        }
    }
    return nullptr; //if no name matches
}
std::vector<Passenger*> PassengerDatabase::getPassengers(){
    return passengers;
}
std::vector<Passenger*> PassengerDatabase::getPassengers_byClass( Class paidClass, bool survived, double minimumFare ){
    std::vector<Passenger*> v; //make a new vector value
    for ( int i = 0; i < passengers.size(); i++ ){
        if ( ( passengers[i]->getClass() == paidClass ) && ( passengers[i]->getSurvived() == survived ) && ( passengers[i]->getFare() > minimumFare ) ){
            v.push_back( passengers[i] ); //if all conditions meet, add to vector
        }
    }
    return v;
}
std::vector<Passenger*> PassengerDatabase::getPassengers_byEmbarcation( Embarcation embarked, bool Survived, double minimumFare ){
    std::vector<Passenger*> v; //make a new vector value
    for ( int i = 0; i < passengers.size(); i++ ){
        if ( ( passengers[i]->getEmbarcation() == embarked ) && ( passengers[i]->getSurvived() == Survived ) && ( passengers[i]->getFare() > minimumFare ) ){
            v.push_back( passengers[i] ); //if all conditions meet, add to vector
        }
    }
    return v;
}
void PassengerDatabase::csvData( std::map< std::string, std::string > row ){ 
    Passenger * p = new Passenger(); //pointer to track the data
    for( std::map< std::string, std::string >::iterator iter = row.begin(); iter != row.end(); iter++)
    {
        if ( iter->first == "name" ) p->setName( iter->second );
        if ( iter->first == "pclass" ) p->setClass( iter->second );
        if ( iter->first == "survived" ) p->setSurvived( iter->second );
        if ( iter->first == "fare" ) p->setFare( iter->second );
        if ( iter->first == "embarked" ) p->setEmbarcation( iter->second );
    } //insert the values in the map data type
    passengers.push_back(p); //add the map values to vector
}

}
