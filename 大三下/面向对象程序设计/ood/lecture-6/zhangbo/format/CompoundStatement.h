// Copyright (C) 1991 - 1999 Rational Software Corporation
#include <vector>
using namespace std;

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_COMPOUNDSTATEMENT_3E0F92490048_INCLUDED
#define _INC_COMPOUNDSTATEMENT_3E0F92490048_INCLUDED

#include "Statement.h"

//The class: describes a statement which may include one or 
//many sub-statements.
//     The sub-statements are stored in the vector data 
//member.
//
//     At the toppest level, the entire program  can be 
//viewed as a compound statement.
//
//Operations:
//Input(): reads in statements until encountering a "}' 
//character or the end-of-file character.
//##ModelId=3E0F92490048
class CompoundStatement : 
public Statement  
  
{
protected:
	//##ModelId=3E0F9249004F
	vector<Statement*> children;

public:
	//##ModelId=3E0F92490049
	 Input(ifstream& inf, string& first);

	//##ModelId=3E0F9249004C
	 Output(ofstream& outf, int ind);

	//##ModelId=3E0F9249006E
	Statement theStatement;

private:

};

#endif /* _INC_COMPOUNDSTATEMENT_3E0F92490048_INCLUDED */
