#include "ElseStatement.h"

CElseStatement::CElseStatement( )
{
}

CElseStatement::~CElseStatement( )
{
}

bool CElseStatement::Parse( std::list<std::string>& wl )
{
	try
	{
		wl.pop_front( );		// else
		wl.pop_front( );		// {

		return CCompositeStatement::Parse( wl );
	}
	catch ( ... )
	{
		return false;
	}
}

void CElseStatement::OutPut( std::ostream& out, int space ) const
{
	CStatement::OutPut( out, space );
	out << "else\n";
	CStatement::OutPut( out, space );
	out << "{\n";

	CCompositeStatement::OutPut( out, space );

	CStatement::OutPut( out, space );
	out << "}\n";
}