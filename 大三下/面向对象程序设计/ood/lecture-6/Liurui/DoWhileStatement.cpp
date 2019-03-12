#include "DoWhileStatement.h"

CDoWhileStatement::CDoWhileStatement( )
{
}

CDoWhileStatement::~CDoWhileStatement( )
{
}

bool CDoWhileStatement::Parse( std::list<std::string>& wl )
{
	try
	{
		wl.pop_front( );		// do
		wl.pop_front( );		// {

		if ( !CCompositeStatement::Parse( wl ) )	return false;

		wl.pop_front( );		// while
		wl.pop_front( );		// (

		m_Condition.m_Left = wl.front( );
		wl.pop_front( );

		m_Condition.m_Cmp = wl.front( );
		wl.pop_front( );

		m_Condition.m_Right = wl.front( );
		wl.pop_front( );

		wl.pop_front( );		// )
		wl.pop_front( );		// ;

		return true;
	}
	catch ( ... )
	{
		return false;
	}
}

void CDoWhileStatement::OutPut( std::ostream& out, int space ) const
{
	CStatement::OutPut( out, space );
	out << "do\n";
	CStatement::OutPut( out, space );
	out << "{\n";

	CCompositeStatement::OutPut( out, space );

	CStatement::OutPut( out, space );
	out << "} while ( ";
	m_Condition.OutPut( out );
	out << " ) ;\n";
}