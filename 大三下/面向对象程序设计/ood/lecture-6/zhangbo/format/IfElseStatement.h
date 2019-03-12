// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_IF_ELSE_STATEMENT_3E0F92490053_INCLUDED
#define _INC_IF_ELSE_STATEMENT_3E0F92490053_INCLUDED

#include "CompoundStatement.h"

//The class: Both the if-statement and the if-else-statement  
//are described by this
//     class. The if-statement is regarded as a special case 
//of the if-else-statement.
//     The reason to do this is that when we encounter a "if" 
//keyword, we can not 
//     judge whether the following statement is a 
//if-statement or a if-else statement.
//     Thus, if we used a "if-statement" class and a 
//"if-else-statement" class to describe
//     the two types of statements separately, we would 
//encounter difficulty in the
//     decision of the types of the object to create when we 
//encounter the "if" keyword.
//
//Data members:
//cmp_left, cmp, cmp_right: to store a boolean expression 
//which has the form
//     ( cmp_left  cmp  cmp_right )
//separator: the CompoundStatement::children vector is 
//separated into two parts.
//    The elements whose indexes are smaller than this field 
//store the statements
//    appearing after the if keyword but before the else (if 
//any) keyword, while the 
//    remaining elements store those appearing after the else 
//(if any) keyword.
//    If this field equals to the size of the vector, the 
//object stores an if statement.
//##ModelId=3E0F92490053
class IfElseStatement : 
public CompoundStatement  
  
{
public:
	//##ModelId=3E0F92490054
	Input(ifstream& inf, string& first);

	//##ModelId=3E0F92490057
	Output(ofstream& outf, int ind);

private:
	//##ModelId=3E0F9249005A
	string cmp_left;

	//##ModelId=3E0F9249005B
	string cmp;

	//##ModelId=3E0F9249005C
	string cmp_right;

	//##ModelId=3E0F9249005D
	int separator;

};

#endif /* _INC_IF_ELSE_STATEMENT_3E0F92490053_INCLUDED */
