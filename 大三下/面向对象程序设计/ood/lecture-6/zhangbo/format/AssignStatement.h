// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_ASSIGNSTATEMENT_3E0F9249002E_INCLUDED
#define _INC_ASSIGNSTATEMENT_3E0F9249002E_INCLUDED

#include "Statement.h"

//Data members:
//left, right:  the left and right identifier of the 
//assignment statement.
//##ModelId=3E0F9249002E
class AssignStatement : 
public Statement  
  
{
public:
	//##ModelId=3E0F92490036
	string left;
	//##ModelId=3E0F92490037
	string right;

	//##ModelId=3E0F92490030
	Input(ifstream& inf, string& first);

	//##ModelId=3E0F92490033
	Output(ofstream& outf, int ind);

private:


};

#endif /* _INC_ASSIGNSTATEMENT_3E0F9249002E_INCLUDED */
