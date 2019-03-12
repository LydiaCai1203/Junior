#include "AssignmentStatement.h"

CAssignmentStatement::CAssignmentStatement( )
{
}

CAssignmentStatement::~CAssignmentStatement( )
{
}

bool CAssignmentStatement::Parse( std::list<std::string>& wl )
{
	try
	{
		m_Left = wl.front( );
		wl.pop_front( );

		wl.pop_front( );		// =

		m_Right = wl.front( );
		wl.pop_front( );

		wl.pop_front( );		// ;

		return true;
	}
	catch ( ... )
	{
		return false;
	}
}

void CAssignmentStatement::OutPut( std::ostream& out, int space ) const
{
	CStatement::OutPut( out, space );
	out << m_Left << " = " << m_Right << " ;\n";
}