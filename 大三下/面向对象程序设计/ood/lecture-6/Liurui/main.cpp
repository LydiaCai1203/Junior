#include <fstream>

#include "Compiler.h"

using namespace std;

ifstream fin( "in.txt" );
ofstream fout( "out.txt" );

void main( )
{
	CCompiler cp;

	if ( cp.Compile( fin ) )
	{
		cout << "OK!" << endl << "Please Input TabSpace :";
		int space;
		cin >> space;
		cp.Format( fout, space );
	}
	else
	{
		cout << "Error!" << endl;
	}
}