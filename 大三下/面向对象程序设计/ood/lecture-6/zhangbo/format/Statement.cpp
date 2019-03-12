// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CompoundStatement.h"
#include "Statement.h"



//##ModelId=3E0F9249003F
Statement::Input(ifstream& inf, string& first)
{
}

//##ModelId=3E0F92490042
Statement::Output(ofstream& outf, int ind)
{
}



//##ModelId=3E10F49901E4
Statement::Indent(ofstream& outf, int ind)
{
	for (int i=0; i<ind; i++) outf<< " ";
}

