#ifndef VISITOR_H
#define VISITOR_H

#include "psData.h"
#include "psCombo.h"
#include "demogData.h"

/* a visitor can visit any of my specific data types */
class Visitor {
  //FILL IN
  public:
	virtual void visit(psData *e) = 0;
	virtual void visit(psCombo *e) = 0;
	virtual void visit(demogData *e) = 0;
};
#endif
