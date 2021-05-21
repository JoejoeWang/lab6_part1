#include <sstream>
#include "psData.h"
#include "visitor.h"

/* print police data - fill in*/

void psData:: accept(class Visitor &v){
	v.visit(this);
}

std::ostream& operator<<(std::ostream &out, const psData &PD) {
    out << "Police Shotting Info: " << PD.state;
    out << "\nPerson name: " << PD.name1;
    out << "\nAge: " <<PD.age1;
    out << "\nGender: " << PD.gender1;
    out << "\nRace: " << PD.race1;
    out << "\nMental Illness: " << PD.signs_of_mental_illness1;
    out << "\nFleeing: " << PD.flee1;
    return out;
}
