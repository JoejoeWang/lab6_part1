#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "raceDemogData.h"

/*
  class to represent combined demographic data 
*/
class demogCombo : public demogData {
  public:
    //write demogCombo constructor
    //demogCombo()
    demogCombo() : count_num(0) {}
    demogCombo(shared_ptr<demogData> in) : 
    demogData(in->getName(),in->getStateName(),in->getpopOver65(),in->getpopUnder18(),in->getpopUnder5(),in->getBAupCount(),in->getHSupCount(),in->getPovertyCount(),in->getPop(),in->getrace()), count_num(1) {}
    //getter
    
    int getCountNum() const { return count_num; }
  //fill in
    void popUpdate(demogData& theData)
    {
      add(theData);
      count_num += 1;
    }
    // demogCombo& operator+=(const demogCombo& a)
    // {
    //   this->theData += a.theData;
    //   count_num += 1;
    // }
  friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);

  private:
    int count_num;
    //demogData theData;
    //fill in
};


#endif
