#include "demogData.h"
#include <sstream>
#include <iomanip>
#include "visitor.h"

/* print county demographic data */
void demogData:: accept(class Visitor &v){
	v.visit(this);
}

std::ostream& operator<<(std::ostream &out, const demogData &DD) {
    //out << "County Demographics Info: " << DD.getRegionName() << ", " << DD.getState();
    out << std::setprecision(2) << std::fixed;
    out << "\nPopulation info: \n(\% over 65): " << DD.getpopOver65();
    out <<  " count: " << DD.getpopOver65Count();
    out << "\n(\% under 18): " << DD.getpopUnder18();
    out <<  " count: " << DD.getpopUnder18Count();
    out << "\n(\% under 5): " << DD.getpopUnder5();
    out <<  " count: " << DD.getpopUnder5Count();
    out << "\nEducation info: " << "\n";
    out << "(\% Bachelor degree or more): " << DD.getBAupPercent();
    out << " count: " << DD.getBAupCount();
    out << "\n(\% high school or more): " << DD.getHSupPercent();
    out << " count: " << DD.getHSupCount() << "\n";
    out << "\nperson below poverty: " << DD.getPovertyPercent();
    out << " count: " << DD.getPovertyCount();
    //fill in
    return out;
}
