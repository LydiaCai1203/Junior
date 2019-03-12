// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "IfElseStatement.h"
#include <string>
#include <cassert>
using namespace std;


//##ModelId=3E0F92490054
IfElseStatement::Input(ifstream& inf, string& first)
{
	string tmp;
	// read in the boolean expression
	inf >> tmp >> cmp_left >> cmp >> cmp_right >> tmp >> tmp;
	// read in the first compound statement.
	inf >> first;
	CompoundStatement::Input(inf,first);
	// first should be the '}" that immediately follows the keyword if.
	assert( first == "}" );	
	separator = children.size();
    // the next identifier should be "else", ";" or another statement.
	inf >> first;
	if ( first == "else" ) {
		inf >> tmp >> first;
		CompoundStatement::Input(inf,first);
		// the optional ';" that immediately follows the keyword else.
		inf >> first;
		if (first==";" && inf) inf >> first;
	}else if (first==";" && inf) inf>> first;
}

//##ModelId=3E0F92490057
IfElseStatement::Output(ofstream& outf, int ind)
{	
	Indent(outf, ind);
	outf << "if ( " << cmp_left << " " << cmp << " " 
		 << cmp_right << " ) {" << endl;
	CompoundStatement::Output(outf, ind + 4 );
	if ( separator == children.size() ) { // the if statement
		Indent(outf, ind);
		outf << "} ;" << endl;
	}else{
		Indent(outf, ind);
		outf << "}" << endl;
		Indent(outf, ind);
		outf << "else {" << endl;
		CompoundStatement::Output(outf, ind + 4 );
		Indent(outf, ind);
        outf << "} ;" << endl;
	}
}

