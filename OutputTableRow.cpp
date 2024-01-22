//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by Danielle Choi on 11/16/23.
//

#include "OutputTableRow.h"

namespace cs32 {

OutputTableRow::OutputTableRow(){
    mDescription = "";
    mSurvived = 0;
    mTotal = 0;
}
void OutputTableRow::setDescription( std::string description ){
    mDescription = description;
}
void OutputTableRow::setSurvived( int survived ){
    mSurvived = survived;
}
void OutputTableRow::setTotal( int total ){
    mTotal = total;
}
std::string OutputTableRow::getDescription(){
    return mDescription;
}
int OutputTableRow::getSurvived(){
    return mSurvived;
}
int OutputTableRow::getTotal(){
    return mTotal;
}
double OutputTableRow::getPercentage(){
    double total = mTotal;
    return mSurvived/total;
}
void OutputTableRow::display(){
    std::cout<<mDescription<<"-    "<<padToThreeCharacters( mSurvived )<<"    / "<<padToThreeCharacters( mTotal )<<"       "<<padToThreeCharacters( getPercentage() * 100 )<<std::endl;
}
std::string OutputTableRow::padToThreeCharacters( int value ){
    std::string val = std::to_string( value );
    if ( val.size() == 3 )
        return val;
    else if ( val.size() == 2 )
        return " "+val; //if size is 1, add 1 blank spaces in the front
    else if ( val.size() == 1 )
        return "  "+val; //if size is 1, add 2 blank spaces in the front
    else
        return "   "; //if it doesn't match, just return 3 blank spaces
}

}
