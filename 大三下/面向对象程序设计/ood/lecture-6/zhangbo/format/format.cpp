// format.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include "CompoundStatement.h"
using namespace std;

int main(int argc, char* argv[])
{
	ifstream inf("test.cpp");
    string s;
	inf >> s;
	//The entire program can be regarded as a compound statement.
	CompoundStatement * comps=new CompoundStatement();
    comps->Input(inf,s);
	ofstream outf("test_formatted.cpp");
	comps->Output(outf,0);
	return 0;
}
