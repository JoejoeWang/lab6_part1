#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include <iostream>
#include "raceDemogData.h"
#include "regionData.h"
//#include "visitor.h"

using namespace std;

class Visitor;
/*
  class to represent county demographic data
  from CORGIS - LAB01 starter - replace with your FULL version!
*/
class demogData : public regionData {
  public:
    demogData() : regionData("",""), name(""), state(""), popOver65(0), popUnder18(0), popUnder5(0), popBAup(0), popHSup(0), totalPopulation2014(0), poverty(0) {}
    demogData(string inN, string inS, double in65, double in18, double in5, double totPopBAup, double totPopHAup, double poverty, int totPop14, raceDemogData b) :
        regionData(inN, inS, totPop14), name(inN), state(inS), popOver65(in65), popUnder18(in18), popUnder5(in5), popBAup(totPopBAup), popHSup(totPopHAup), poverty(poverty), totalPopulation2014(totPop14), race(b) {}
    demogData(string inN, string inS, double in65, double in18,
        double in5, int totPop14, raceDemogData b) :
            regionData(inN, inS, totPop14), name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), popBAup(0), popHSup(0), poverty(0), totalPopulation2014(totPop14), race(b) {}

    //getter for percentage
    string getName() const { return name; }
    string getStateName() const { return state; }
    double getpopOver65() const { return popOver65;}
    double getpopUnder18() const { return popUnder18; }
    double getpopUnder5() const { return popUnder5; }
    double getBAupPercent() const { return 100.0f*((double)(popBAup)/totalPopulation2014); }
    double getHSupPercent() const { return 100.0f*((double)(popHSup)/totalPopulation2014); }
    double getPovertyPercent() const { return 100.0f*((double)(poverty)/totalPopulation2014); }

    //getter for actual data
    int getPop() const { return totalPopulation2014; }
    int getpopOver65Count() const { return getpopOver65()*getPop()/100; }
    int getpopUnder18Count() const { return getpopUnder18()*getPop()/100; }
    int getpopUnder5Count() const { return getpopUnder5()*getPop()/100; }
    int getBAupCount() const { return popBAup; }
    int getHSupCount() const { return popHSup; }
    int getHSbelowCount() const { return (1-getHSupPercent()/100)*getPop(); }
    int getPovertyCount() const { return poverty; }
    //int getCountNum() const { return count_num; }
    raceDemogData getrace() const { return race; }
    //string getRegionName() const { return name; }

    void add(const demogData& a)
    {
      int count(0);
      popOver65 = 100.0f*((popOver65*totalPopulation2014/100)+(a.popOver65*a.totalPopulation2014/100))/(totalPopulation2014+a.totalPopulation2014);
      popUnder18 = 100.0f*((popUnder18*totalPopulation2014/100)+(a.popUnder18*a.totalPopulation2014/100))/(totalPopulation2014+a.totalPopulation2014);
      popUnder5 = 100.0f*((popUnder5*totalPopulation2014/100)+(a.popUnder5*a.totalPopulation2014/100))/(totalPopulation2014+a.totalPopulation2014); 
      // popBAup = 100.0f*((popBAup*totalPopulation2014/100)+(a.popBAup*a.totalPopulation2014)/100)/(totalPopulation2014+a.totalPopulation2014);
      // popHSup = 100.0f*((popHSup*totalPopulation2014/100)+(a.popHSup*a.totalPopulation2014)/100)/(totalPopulation2014+a.totalPopulation2014);
      //poverty = 100.0f*((double)(poverty*totalPopulation2014/100.0f)+(a.poverty*a.totalPopulation2014/100.0f))/(totalPopulation2014+a.totalPopulation2014);
      popBAup += a.popBAup;
      popHSup += a.popHSup;
      poverty += a.poverty;
      totalPopulation2014 += a.totalPopulation2014;
      race += a.race;
      if(stateS.size()==0)
      {
        addState(a.getStateName());
      }
      else
      {
        for(auto entry : stateS)
        {
          if(entry != a.getStateName())
          {
            count += 1;
            if(count == stateS.size())
            {
              addState(a.getStateName());
            }
          }
        }
      }
    }

   void toString(ostream& os) const;

   void accept(class Visitor &v);

   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

private:
    string name;
    string state;
    double popOver65;
    double popUnder18;
    double popUnder5;
    int popBAup;
    int popHSup;
    int totalPopulation2014;
    int poverty;
    //const int count_num;
    raceDemogData race;

};
#endif
