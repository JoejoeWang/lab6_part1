/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "psData.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "visitorReport.h"

dataAQ::dataAQ() {}

void dataAQ::comboReport(double thresh){
  visitorReport report;
	for(auto entry : allComboDemogData)
  {
		if(entry.second->getHSupPercent()>thresh)
    {
			pileData.push_back(entry.second);
			pileData.push_back(allComboPoliceData[entry.first]);
		}
	}	
	
	for(const auto &obj : pileData)
  {
		obj->accept(report);
	}	
}

string makeKeyExample1(shared_ptr<demogData> theData) {


  string theKey = "Key";


  if (theData->getPovertyPercent() < 10) {
    theKey += "BelowPovLessTenPer";
  } else if (theData->getPovertyPercent() < 20) {
    theKey += "BelowPovLessTwentyPer";
  } else if (theData->getPovertyPercent() < 30) {
    theKey += "BelowPovLessThirtyPer";
  } else {
    theKey += "BelowPovAboveThirtyPer";
  }

  return theKey;
}


string makeKeyExample2(shared_ptr<psData> theData) {

  string theKey = "Key";
  
  if (theData->getrace() == "W") {
    theKey += "WhiteVictim";
  } else if (theData->getrace() == "A") {
    theKey += "AsianVictim";
  } else if (theData->getrace() == "H") {
    theKey += "HispanicVictim";
  } else if (theData->getrace() == "N") {
    theKey += "NativeAmericanVictim";
  } else if (theData->getrace() == "B") {
    theKey += "AfricanAmericanVictim";
  } else if (theData->getrace() == "O") {
    theKey += "OtherRaceVictim";
  } else {
    theKey += "RaceUnspecifiedVictim";
  }

  return theKey;
}


//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {
  demogCombo first;
  first = demogCombo(theData[0]);
  pair<string, shared_ptr<demogCombo>> NUMONE (makeKeyExample1(theData[0]),make_shared<demogCombo>(first));
  allComboDemogData.insert(NUMONE);
  for(int i=1;i<theData.size();i++)
  {
    bool in = false;
    for(auto entry : allComboDemogData)
    {
      if(makeKeyExample1(theData[i])==entry.first)
      {
        entry.second->popUpdate(*theData[i]);
        in = true;
      }
    }
    if(in == false)
    {
      //cout << "jere?" << endl;
      demogCombo newone;
      newone = demogCombo(theData[i]);
      pair<string, shared_ptr<demogCombo>> Firstterm (makeKeyExample1(theData[i]),make_shared<demogCombo>(newone));
      allComboDemogData.insert(Firstterm);
    }
  }
}

void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {
//fill in
  psCombo first;
  first = psCombo(*theData[0]);
  pair<string, shared_ptr<psCombo>> NUMONE (makeKeyExample2(theData[0]),make_shared<psCombo>(first));
  allComboPoliceData.insert(NUMONE);
  for(int i=1;i<theData.size();i++)
  {
    bool in = false;
    for(auto entry : allComboPoliceData)
    {
      if(makeKeyExample2(theData[i])==entry.first)
      {
        entry.second->Update(*theData[i]);
        in = true;
      }
    }
    if(in == false)
    {
      psCombo newone;
      newone = psCombo(*theData[i]);
      pair<string, shared_ptr<psCombo>> Firstterm (makeKeyExample2(theData[i]),make_shared<psCombo>(newone));
      allComboPoliceData.insert(Firstterm);
    }
  }
}

/******************************************/
/* state examples */
void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData> >&  theData) {
//fill in
  demogCombo first;
  first = demogCombo(theData[0]);
  pair<string, shared_ptr<demogCombo> > NUMONE (theData[0]->getStateName(), make_shared<demogCombo>(first));
  allComboDemogData.insert(NUMONE);
  for(int i=1;i<theData.size();i++)
  {
    bool in = false;
    for(auto entry: allComboDemogData)
    {
      if(theData[i]->getStateName()==entry.first)
      {
        // demogCombo second;
        // second = demogCombo(theData[i]);
        entry.second->popUpdate(*theData[i]);
        in = true;
      }
    }
    if(in == false)
    {
      demogCombo newone;
      newone = demogCombo(theData[i]);
      pair<string, shared_ptr<demogCombo> > Firstterm (theData[i]->getStateName(), make_shared<demogCombo>(newone));
      allComboDemogData.insert(Firstterm);
    }
  }
}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData> >& theData) {
//fill in
  psCombo first;
  first = psCombo(*theData[0]);
  pair<string, shared_ptr<psCombo> > NUMONE (theData[0]->getState(), make_shared<psCombo>(first));
  allComboPoliceData.insert(NUMONE);
  for(int i=1;i<theData.size();i++)
  {
    bool in = false;
    for(auto entry: allComboPoliceData)
    {
      if(theData[i]->getState()==entry.first)
      {
        entry.second->Update(*theData[i]);
        in = true;
        // if(entry.first=="CA")
        // {
        //   cout<<entry.second->getNumMentalI()<<endl;
        // }
      }
    }
    if(in == false)
    {
      psCombo newone;
      newone = psCombo(*theData[i]);
      pair<string, shared_ptr<psCombo> > Firstterm (theData[i]->getState(), make_shared<psCombo>(newone));
      allComboPoliceData.insert(Firstterm);
    }
  }
}


//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() {
  //fill in
  shared_ptr<psCombo> max;
  shared_ptr<psCombo> a;
  vector<shared_ptr<psCombo>> psPop;
  for(auto entry : allComboPoliceData)
  {
    psPop.push_back(entry.second);
  }
  for(int i=0;i<psPop.size();i++)
  {
    int p(i),q;
    a = psPop[i];
    max = psPop[i];
    for(int j=i+1;j<psPop.size();j++)
    {
      if(psPop[j]->getNumberOfCases()>max->getNumberOfCases())
      {
        max = psPop[j];
        q = j;
      }
    }
    psPop[i] = max;
    psPop[q] = a;
  }
  cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
  for(int i=0;i<9;i++)
  {
    cout << psPop[i]->getState();
    cout << "\nTotal population: ";
    cout << allComboDemogData[psPop[i]->getState()]->getPop();
    cout << "\nPolice shooting incidents: ";
    cout << psPop[i]->getNumberOfCases() <<endl;
    cout << "Percent below poverty: ";
    cout << setprecision(2) << fixed;
    //cout << 100.0f*(double)(allComboDemogData[psPop[i]->getState()]->getPovertyCount())/allComboDemogData[psPop[i]->getState()]->getPop();
    cout << allComboDemogData[psPop[i]->getState()]->getPovertyPercent();
    cout << "\n";
  }
}


    //sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP() {
//fill in
  shared_ptr<demogCombo> max;
  shared_ptr<demogCombo> a;
  vector<shared_ptr<demogCombo>> dePop;
  for(auto entry : allComboDemogData)
  {
    dePop.push_back(entry.second);
    //cout << entry.second->getPop()<<endl;
  }
  for(int i=0;i<dePop.size();i++)
  {
    int q;
    a = dePop[i];
    max = dePop[i];
    for(int j=i+1;j<dePop.size();j++)
    {
      double percent1 = 100.0f*dePop[j]->getPovertyCount()/dePop[j]->getPop();
      double percent2 = 100.0f*max->getPovertyCount()/max->getPop();
      if(percent1>percent2)
      {
        max = dePop[j];
        q = j;
      }
    }
    dePop[i] = max;
    dePop[q] = a;
  }
  for(int i=0;i<9;i++)
  {
    //cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
    // if(dePop[i]->getStateName()=="NM")
    // {
    //   
    // }
    cout << dePop[i]->getState();
    cout << "\nTotal population: ";
    cout << dePop[i]->getPop();
    cout << "\nPercent below poverty: ";
    cout << setprecision(2) << fixed;
    cout << dePop[i]->getPovertyPercent();
    cout << "\nPolice shooting incidents: ";
    cout << allComboPoliceData[dePop[i]->getState()]->getNumberOfCases();
    cout << "\n";
  }
}

/* print all combo data */
std::ostream& operator<<(std::ostream &out, const dataAQ &theAnswers) {
  out << "Combo Demographic Info: ";
  for (auto const& entry : theAnswers.allComboDemogData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";
      // out << "Combo Info: ";
      // entry.second->printState();
      // out << "total states: " << entry.second->StateSsize() << endl;
      // out << "Number of Counties: " << entry.second->getCountNum();
      // out << "County Demographics Info: " << entry.second->getState()<<endl;
      // out << "\nPopulation info: \n(\% over 65): " << entry.second->getpopOver65();
      // out <<  " and total: " << entry.second->getpopOver65Count();
      // out << "\n(\% under 18): " << entry.second->getpopUnder18() << " and total: " << entry.second->getpopUnder18Count();
      // out << "\n(\% under 5): " << entry.second->getpopUnder5() << " and total: " << entry.second->getpopUnder5Count();
      // out << "\nEducation info: " << "\n";
      // out << "(\% Bachelor degree or more): " << 100*entry.second->getBAup();
      // out << " and total: " << entry.second->getBAupCount();
      // out << "\n(\% high school or more): " <<100*entry.second->getHSup();
      // out << " and total: " << entry.second->getHSupCount();
      // out << "\npersons below poverty: " << 100*entry.second->getPoverty();
      // out << " and total: " << entry.second->getPovertyCount();
      // out << "\nTotal population: " << entry.second->getPop();
      // out  << "\ncommunity racial demographics: " << entry.second->getrace() << endl;
    }

  for (auto const& entry : theAnswers.allComboPoliceData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";
      // out << "State Info: ";
      // entry.second->printState();
      // out << "total states: " << entry.second->StateSsize() << endl;
      // out << "Number of incidents: " << entry.second->getNumberOfCases();
      // out << std::setprecision(2) << std::fixed;
      // out << "\nIncidents with age \n(over 65): " << entry.second->getCasesOver65();
      // out << "\n(19 to 64): " << entry.second->getNumberOfCases()-entry.second->getCasesUnder18()-entry.second->getCasesOver65();
      // out << "\n(under 18): " << entry.second->getCasesUnder18();
      // out << "\nIncidents involving fleeing: " << entry.second->getFleeingCount();
      // out << "\nIncidents involving mental illness: " << entry.second->getNumMentalI();
      // out << "\nMale incidents: " <<  entry.second->getnumMales() << " female incidents: " << entry.second->getnumFemales();
      // out << "\nRacial demographics of state incidents: " << entry.second->getRacialData() << endl;

  }

  return out;
}