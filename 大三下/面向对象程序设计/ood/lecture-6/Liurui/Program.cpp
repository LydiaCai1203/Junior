#include "Program.h"

CProgram::CProgram( )
{
}

CProgram::~CProgram( )
{
}

bool CProgram::ParseProgram( std::list<std::string>& wl )
{
	return ( m_Statements.Parse( wl ) && wl.empty( ) );
}

void CProgram::OutPutProgram( std::ostream& out, int space ) const
{
	m_Statements.OutPut( out, space );
}