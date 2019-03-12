// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "DoWhileStatement.h"


//##ModelId=3E0FAB890186
DoWhileStatement::Input(ifstream& inf, string& first)
{
}

//##ModelId=3E0FAB9702BF
DoWhileStatement::Output(ofstream& outf, int ind)
{
	outf << "do {" << endl;
	CompoundStatement::Output(outf, ind + 4 );
	outf << "while ( " << cmp_left << " " << cmp << " " 
		 << cmp_right << " ) ;" << endl;
}

