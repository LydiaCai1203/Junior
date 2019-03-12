#include <list>
#include <string>
#include "Compiler.h"
#include "Program.h"

CCompiler::CCompiler( )
{
}

CCompiler::~CCompiler( )
{
}

bool CCompiler::Compile( std::istream& in )
{
	std::list<std::string>	wordlist;
	std::string				word;

	while ( !in.eof( ) )
	{
		in >> word;
		wordlist.push_back( word );
	}

	bool result = m_Program.ParseProgram( wordlist );

	wordlist.clear( );
	return result;
}

void CCompiler::Format( std::ostream& out, int space ) const
{
	m_Program.OutPutProgram( out, space );
}