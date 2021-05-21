#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

//add member functions here

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogCombo& ComboD) {
    // out << "State Info: " << ComboD.getStateName() << std::endl;
    // out << "Number of Counties: " << ComboD.getCountNum();
    // //consider re-writing with getters....
    // out << "\nPopulation info: \n(\% over 65): " << 100*ComboD.getpopOver65()/ComboD.getPop();
    // out <<  " and total: " << ComboD.getpopOver65();
    // out << "\n(\% under 18): " << 100*ComboD.getpopUnder18()/ComboD.getPop() << " and total: " << ComboD.getpopUnder18();
    // out << "\n(\% under 5): " << 100*ComboD.getpopUnder5()/ComboD.getPop() << " and total: " << ComboD.getpopUnder5();
    // out << "\nEducation info: " << "\n";
    // out << "(\% Bachelor degree or more): " << 100*ComboD.getBAupCount()/ComboD.getPop();
    // out << " and total: " << ComboD.getBAupCount();
    // out << "\n(\% high school or more): " <<100*ComboD.getHSupCount()/ComboD.getPop();
    // out << " and total: " << ComboD.getHSupCount();
    // out << "\npersons below poverty: " << 100*ComboD.getPovertyCount()/ComboD.getPop();
    // out << " and total: " << ComboD.getPovertyCount();
    // out  << "community racial demographics: " << ComboD.getrace();
    // out << "\nTotal population: " << ComboD.getPop() << "\n";
    out << "Combo Info: ";
    out << ComboD.printState();
    out << "\nNumber of Counties: " << ComboD.getCountNum();
    out << " County Demographics Info: comboData, " << ComboD.getState()<<endl;
    // out << "\nPopulation info: \n(\% over 65): " << ComboD.getpopOver65();
    // out <<  " and total: " << ComboD.getpopOver65Count();
    // out << "\n(\% under 18): " << ComboD.getpopUnder18() << " and total: " << ComboD.getpopUnder18Count();
    // out << "\n(\% under 5): " << ComboD.getpopUnder5() << " and total: " << ComboD.getpopUnder5Count();
    out << "\nEducation info: " << "\n";
    //out << std::setprecision(2) << std::fixed;
    out << "(Bachelor or more): " << ComboD.getBAupPercent() << "\%";
    out << " and total: " << ComboD.getBAupCount();
    out << "\n(high school or more): " <<ComboD.getHSupPercent() << "\%";
    out << " and total: " << ComboD.getHSupCount();
    out << "\npersons below poverty: " << ComboD.getPovertyPercent() << "\%";
    out << " and total: " << ComboD.getPovertyCount();
    out << "\nTotal population: " << ComboD.getPop();
    out  << "\ncommunity racial demographics: " << ComboD.getrace() << endl;
    return out;
}
