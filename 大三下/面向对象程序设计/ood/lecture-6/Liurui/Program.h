#pragma once

#include <list>
#include "CompositeStatement.h"

class CProgram
{
private:
	CCompositeStatement		m_Statements;

public:
	CProgram( );
	~CProgram( );

	bool ParseProgram( std::list<std::string>& wl );
	void OutPutProgram( std::ostream& out, int space = 4 ) const;
};