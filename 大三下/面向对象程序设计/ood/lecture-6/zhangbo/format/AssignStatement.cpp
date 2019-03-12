// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "AssignStatement.h"
#include <string>
using namespace std;


//##ModelId=3E0F92490030
AssignStatement::Input(ifstream& inf, string& first)
{
	string tmp;
	left = first;
	inf >> tmp >> right >> tmp;
	// store the immediately following identifier into first. 
	if (inf) inf >> first;
}

//##ModelId=3E0F92490033
AssignStatement::Output(ofstream& outf, int ind)
{
	Indent(outf, ind);
	outf << left << " = " << right << " ;" << endl;
}

