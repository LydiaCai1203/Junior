// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CompoundStatement.h"
#include "AssignStatement.h"
#include "IfElseStatement.h"
#include "DoWhileStatement.h"
#include <string>
#include <vector>
using namespace std;


//##ModelId=3E0F92490049
CompoundStatement::Input(ifstream& inf, string& first)
{	
	do {
		if ( first != "if" && first != "do" ) { // AssignStatement
			AssignStatement * assignStatement = new AssignStatement();
			assignStatement->Input(inf,first);
			children.push_back(assignStatement);			
		}else 
		if (first == "if" ) {  // IfElseStatement
			IfElseStatement * ifElseStatement = new IfElseStatement();
			ifElseStatement->Input(inf,first);
			children.push_back(ifElseStatement);
		}else
		if (first == "do" ) { // DoWhileStatement
			DoWhileStatement * doWhileStatement = new DoWhileStatement();
			doWhileStatement->Input(inf,first);
			children.push_back(doWhileStatement);			
		}		
	}while ( inf && first !="}" );
}

//##ModelId=3E0F9249004C
CompoundStatement::Output(ofstream& outf, int ind)
{
	vector<Statement*>::iterator it;
	for (it=children.begin(); it!=children.end(); it++){
		(*it)->Output(outf, ind);
	}
}

