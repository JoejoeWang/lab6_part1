#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <utility>
#include "regionData.h"


using namespace std;

class Visitor;
/*
  class to represent police shooting data
  from CORGIS
*/
class psData : public regionData {
  public:
    //add appropriate function paramaters to constructor once you add data
    //psData(string inState) : state(inState) {}
    //add appropriate function paramaters to constructor once you add data
    psData() : state(""),name1(""),age1(0),gender1(""),race1(""),county1(""),signs_of_mental_illness1(""),flee1(""),regionData("","") {}
    psData(string inState, string Na, int old, string fm, string rc, string cty, string smi, string fl) : 
    regionData(Na, inState), state(inState), name1(Na), age1(old), gender1(fm), race1(rc), county1(cty), signs_of_mental_illness1(smi), flee1(fl) {}


    string getStateName() const { return state; }
    string getname() const { return name1; }
    int getage() const { return age1; }
    string getgender() const {return gender1; }
    string getrace() const { return race1; }
    string getcounty() const { return county1; }
    string getsigns_of_mental_illness() const { return signs_of_mental_illness1; }
    string getflee() const { return flee1; }
    //add getters


    string getState() const { return state; }
    //add getters

    void accept(class Visitor &v);

   friend std::ostream& operator<<(std::ostream &out, const psData &PD);

private:
    const string state;
    const string name1;
    const int age1;
    const string gender1;
    const string race1;
    const string county1;
    const string signs_of_mental_illness1;
    const string flee1;
    //add others

};

#endif
