#include <iomanip>
#include "psCombo.h"
#include "visitor.h"



/* print state data - as aggregate of all incidents in this state */
void psCombo:: accept(class Visitor &v){
	v.visit(this);
}

std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    //out << "**Police shooting incidents:";
    out << "State Info: " << PD.printState();
    out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    // out << "State Info: " << PD.state;
    // out << "\nNumber of incidents: " << PD.NumberOfCases;
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.CasesOver65 << "\%: " << 100.0f*((double)PD.CasesOver65/PD.getNumberOfCases());
    out << "\n(19 to 64): " << PD.NumberOfCases-PD.CasesOver65-PD.CasesUnder18 << "\%: "<< 100.0f*((double)(PD.NumberOfCases-PD.CasesOver65-PD.CasesUnder18)/PD.getNumberOfCases());
    out << "\n(under 18): " << PD.CasesUnder18 << "\%: " << 100.0f*((double)PD.CasesUnder18/PD.getNumberOfCases());
    out << "\nIncidents involving fleeing: " << PD.FleeingCount << " \%: " << 100.0f*((double)PD.FleeingCount/PD.getNumberOfCases());
    out << "\nIncidents involving mental illness: " << PD.NumMentalI << " \%: " << 100.0f*((double)PD.NumMentalI/PD.getNumberOfCases());
    out << "\nMale incidents: " <<  PD.numMales << " female incidents: " << PD.numFemales;
    out << "\nRacial demographics of state incidents: " << PD.onepiece;
    //fill in
    return out;
}