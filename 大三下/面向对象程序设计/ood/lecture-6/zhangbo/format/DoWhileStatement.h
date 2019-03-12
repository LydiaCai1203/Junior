// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_DOWHILESTATEMENT_3E0FAB54000F_INCLUDED
#define _INC_DOWHILESTATEMENT_3E0FAB54000F_INCLUDED

#include "CompoundStatement.h"
#include <string>
using namespace std;

//##ModelId=3E0FAB54000F
class DoWhileStatement : 
public CompoundStatement  
  
{
public:
	//##ModelId=3E0FAB890186
	Input(ifstream& inf, string& first);

	//##ModelId=3E0FAB9702BF
	Output(ofstream& outf, int ind);

private:
	//##ModelId=3E0FAB730222
	string cmp_left;

	//##ModelId=3E0FAB7802BF
	string cmp;

	//##ModelId=3E0FAB7B0157
	string cmp_right;

};

#endif /* _INC_DOWHILESTATEMENT_3E0FAB54000F_INCLUDED */
