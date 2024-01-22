//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by Danielle Choi on 11/16/23.
//

#include "PassengerOutputTable.h"

namespace cs32 {

PassengerOutputTable::PassengerOutputTable( std::vector<Passenger*> passengers ){
    mField = Field::NOVALUE;
    mDescription = "";
    mPassengerList = passengers;
}
void PassengerOutputTable::setOutputField( Field f ){
    mField = f;
}
void PassengerOutputTable::setDescription( std::string description ){
    mDescription = description;
}
Field PassengerOutputTable::getOutputField(){
    return mField;
}
std::string PassengerOutputTable::getDescription(){
    return mDescription;
}
void PassengerOutputTable::display(){
    if ( mField == Field::NOVALUE )
        return; //if the field is NOVALUE, return nothing
    std::cout<<mDescription<<std::endl; //title of table
    std::cout<<"               Survived/Total        %"<<std::endl; //row description
    if ( mField == Field::BYCLASS ){
        int fSurvived = 0, sSurvived = 0, tSurvived = 0, nSurvived = 0;
        int fTotal = 0, sTotal = 0, tTotal = 0, nTotal = 0;
        for ( int i = 0; i < mPassengerList.size(); i++ ){
            if ( mPassengerList[i]->getClass() == Class::FIRST ){
                fTotal++; //increase if conditions meet
                if ( mPassengerList[i]->getSurvived() )
                    fSurvived++;
            }
            else if ( mPassengerList[i]->getClass() == Class::SECOND ){
                sTotal++;
                if ( mPassengerList[i]->getSurvived() )
                    sSurvived++;
            }
            else if ( mPassengerList[i]->getClass() == Class::THIRD ){
                tTotal++;
                if ( mPassengerList[i]->getSurvived() )
                    tSurvived++;
            }
            else if ( mPassengerList[i]->getClass() == Class::NOTKNOWN ){
                nTotal++;
                if ( mPassengerList[i]->getSurvived() )
                    nSurvived++;
            }
        }
        mRows.resize( 4 ); //make the row vector size to 4
        mRows[0].setDescription( "First Class " ); //set the row values as below
        mRows[0].setSurvived( fSurvived );
        mRows[0].setTotal( fTotal );
        mRows[1].setDescription( "Second Class" );
        mRows[1].setSurvived( sSurvived );
        mRows[1].setTotal( sTotal );
        mRows[2].setDescription( "Third Class " );
        mRows[2].setSurvived( tSurvived );
        mRows[2].setTotal( tTotal );
        mRows[3].setDescription( "Not Known   " );
        mRows[3].setSurvived( nSurvived );
        mRows[3].setTotal( nTotal );
        
        mRows[0].display(); //display all the rows
        mRows[1].display();
        mRows[2].display();
        mRows[3].display();
    } else if ( mField == Field::BYEMBARCATION ) {
        int cSurvived = 0, qSurvived = 0, sSurvived = 0, nSurvived = 0;
        int cTotal = 0, qTotal = 0, sTotal = 0, nTotal = 0;
        for ( int i = 0; i < mPassengerList.size(); i++ ){
            if ( mPassengerList[i]->getEmbarcation() == Embarcation::CHERBOURG ){
                cTotal++; //increase if conditions meet
                if ( mPassengerList[i]->getSurvived() )
                    cSurvived++;
            }
            else if ( mPassengerList[i]->getEmbarcation() == Embarcation::QUEENSTOWN ){
                qTotal++;
                if ( mPassengerList[i]->getSurvived() )
                    qSurvived++;
            }
            else if ( mPassengerList[i]->getEmbarcation() == Embarcation::SOUTHHAMPTON ){
                sTotal++;
                if ( mPassengerList[i]->getSurvived() )
                    sSurvived++;
            }
            else if ( mPassengerList[i]->getEmbarcation() == Embarcation::NOTKNOWN ){
                nTotal++;
                if ( mPassengerList[i]->getSurvived() )
                    nSurvived++;
            }
        }
        mRows.resize( 4 ); //make the row vector size to 4
        mRows[0].setDescription( "Cherbourg   " ); //set the row values as below
        mRows[0].setSurvived( cSurvived );
        mRows[0].setTotal( cTotal );
        mRows[1].setDescription( "Queenstown  " );
        mRows[1].setSurvived( qSurvived );
        mRows[1].setTotal( qTotal );
        mRows[2].setDescription( "Southhampton" );
        mRows[2].setSurvived( sSurvived );
        mRows[2].setTotal( sTotal );
        mRows[3].setDescription( "Not Known   " );
        mRows[3].setSurvived( nSurvived );
        mRows[3].setTotal( nTotal );
        
        mRows[0].display(); //display all the rows
        mRows[1].display();
        mRows[2].display();
        mRows[3].display();
    } else if ( mField == Field::BYFARE ) {
        int nSurvived = 0, survived1 = 0, survived10 = 0, survived25 = 0, survived50 = 0;
        int nTotal = 0, total1 = 0, total10 = 0, total25 = 0, total50 = 0;
        for ( int i = 0; i < mPassengerList.size(); i++ ){
            if ( mPassengerList[i]->getFare() > 0 && mPassengerList[i]->getFare() <= 10 ){
                total1++; //increase if conditions meet
                if ( mPassengerList[i]->getSurvived() )
                    survived1++;
            }
            else if ( mPassengerList[i]->getFare() > 10 && mPassengerList[i]->getFare() <= 25 ){
                total10++;
                if ( mPassengerList[i]->getSurvived() )
                    survived10++;
            }
            else if ( mPassengerList[i]->getFare() > 25 && mPassengerList[i]->getFare() <= 50 ){ 
                total25++;
                if ( mPassengerList[i]->getSurvived() )
                    survived25++;
            }
            else if ( mPassengerList[i]->getFare() > 50 ){ //inclusive?
                total50++;
                if ( mPassengerList[i]->getSurvived() )
                    survived50++;
            }
            else {
                nTotal++;
                if ( mPassengerList[i]->getSurvived() )
                    nSurvived++;
            }
        }
        mRows.resize( 5 ); //make the row vector size to 5
        mRows[0].setDescription( "Not Known   " ); //set the row values as below
        mRows[0].setSurvived( nSurvived );
        mRows[0].setTotal( nTotal );
        mRows[1].setDescription( "     $ 1-$10" );
        mRows[1].setSurvived( survived1 );
        mRows[1].setTotal( total1 );
        mRows[2].setDescription( "     $10-$25" );
        mRows[2].setSurvived( survived10 );
        mRows[2].setTotal( total10 );
        mRows[3].setDescription( "     $25-$50" );
        mRows[3].setSurvived( survived25 );
        mRows[3].setTotal( total25 );
        mRows[4].setDescription( "        >$50" );
        mRows[4].setSurvived( survived50 );
        mRows[4].setTotal( total50 );
        
        mRows[0].display(); //display all the rows
        mRows[1].display();
        mRows[2].display();
        mRows[3].display();
        mRows[4].display();
    }
}
size_t PassengerOutputTable::rowCount(){
    return mRows.size();
}
OutputTableRow PassengerOutputTable::getRow( int index ){
    return mRows[index];
}

}
