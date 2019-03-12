#pragma once

#include <iostream>
#include "Program.h"

class CCompiler
{
private:
	CProgram	m_Program;

public:
	CCompiler( );
	~CCompiler( );

	bool Compile( std::istream& in );
	void Format( std::ostream& out, int space ) const;
};