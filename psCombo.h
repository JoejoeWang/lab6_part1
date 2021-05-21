#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "raceDemogData.h"
#include "psData.h"
#include "regionData.h"
#include <memory>
#include <cassert>
//#include "visitor.h"


using namespace std;

class Visitor;

class psCombo : public regionData  {
public:
    //write psCombo constructor
    psCombo() : regionData("",""), state(""), NumMentalI(0), FleeingCount(0), CasesOver65(0),CasesUnder18(0),
        numMales(0), numFemales(0), NumberOfCases(0), onepiece() {}
    
    //complete these
    psCombo(psData& a)
    {
        //regionData(a.getname(),a.getStateName());
        addState(a.getStateName());
        state = a.getStateName();
        if(a.getsigns_of_mental_illness()=="True")
        {
            NumMentalI = 1;
        }
        else
        {
            NumMentalI = 0;
        }
        if(a.getflee()=="Foot"||a.getflee()=="Car"||a.getflee()=="Other")
        {
            FleeingCount = 1;
        }
        else
        {
            FleeingCount = 0;
        }
        if(a.getage()>65)
        {
            CasesOver65 = 1;
            CasesUnder18 = 0;
        }
        else if(a.getage()<18)
        {
            CasesOver65 = 0;
            CasesUnder18 = 1;
        }
        else
        {
            CasesOver65 = 0;
            CasesUnder18 = 0;
        }
        if(a.getgender()=="M")
        {
            numMales = 1;
            numFemales = 0;
        }
        else
        {
            numMales = 0;
            numFemales = 1;
        }
        NumberOfCases = 1;
        raceDemogData b;
        if(a.getrace()=="A")
        {
            b=raceDemogData(0,1,0,0,0,0,0,0,1);
        }
        else if(a.getrace()=="W")
        {
            b=raceDemogData(0,0,0,0,0,0,1,0,1);
        }
        else if(a.getrace()=="H")
        {
            b=raceDemogData(0,0,0,1,0,0,0,0,1);
        }
        else if(a.getrace()=="B")
        {
            b=raceDemogData(0,0,1,0,0,0,0,0,1);
        }
        else if(a.getrace()=="O")
        {
            b=raceDemogData();
            b.addOtherCount(1);
        }
        else if(a.getrace()=="N")
        {
            b=raceDemogData(1,0,0,0,0,0,0,0,1);
        }
    }
    int getNumMentalI() { return NumMentalI; }
    int getFleeingCount() { return FleeingCount; }
    int getCasesOver65() { return CasesOver65; }
    int getCasesUnder18() { return CasesUnder18; }
    raceDemogData getRacialData() { return onepiece; }
    int getnumMales() { return numMales; }
    int getnumFemales() { return numFemales; }
    int getNumberOfCases() const { return NumberOfCases; }
    string getStateName() const {return state; } 

    //add any others needed
    void Update(psData& a)
    {
        //cout<<a.getsigns_of_mental_illness()<<endl;
        addState(a.getStateName());
        if(a.getsigns_of_mental_illness()=="True")
        {
            //cout << 1 << endl;
            NumMentalI += 1;
        }
        //cout << "here" << endl;
        if(a.getflee()=="Foot"||a.getflee()=="Car"||a.getflee()=="Other")
        {
            FleeingCount += 1;
        }
        if(a.getage()>65)
        {
            CasesOver65 += 1;
        }
        else if(a.getage()<18)
        {
            CasesUnder18 += 1;
        }
        if(a.getgender()=="M")
            numMales += 1;
        if(a.getgender()=="F")
            numFemales += 1;

        NumberOfCases += 1;

        if(a.getrace()=="A")
        {
            onepiece.addAsianCount(1);
        }
        else if(a.getrace()=="B")
        {
            onepiece.addBlackCount(1);
        }
        else if(a.getrace()=="H")
        {
            onepiece.addLatinxCount(1);
        }
        else if(a.getrace()=="W")
        {
            onepiece.addWhiteCount(1);
        }
        else if(a.getrace()=="O")
        {
            onepiece.addOtherCount(1);
        }
        else if(a.getrace()=="N")
        {
            onepiece.addFirstNationCount(1);
        }
    }

    void accept(class Visitor &v);

    friend std::ostream& operator<<(std::ostream &out, const psCombo& PD);

protected:
        string state;
        int NumMentalI;
        int FleeingCount;
        int CasesOver65;
        int CasesUnder18;
        int numMales;
        int numFemales;
        int NumberOfCases;
        raceDemogData onepiece;
        //add others
    //fill in
};

#endif