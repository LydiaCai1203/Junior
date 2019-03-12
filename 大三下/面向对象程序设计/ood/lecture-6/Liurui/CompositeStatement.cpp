#include "CompositeStatement.h"
#include "IfStatement.h"
#include "ElseStatement.h"
#include "DoWhileStatement.h"
#include "AssignmentStatement.h"

CCompositeStatement::CCompositeStatement( )
{
}

CCompositeStatement::~CCompositeStatement( )
{
	while ( !m_StatementList.empty( ) )
	{
		delete m_StatementList.front( );
		m_StatementList.pop_front( );
	}
}

bool CCompositeStatement::Parse( std::list<std::string>& wl )
{
	while ( !wl.empty( ) && wl.front( ) != "}" )
	{
		CStatement* ps = NULL;
		if ( wl.front( ) == "if" )
		{
			ps = new CIfStatement;
		}
		else if ( wl.front( ) == "else" )
		{
			ps = new CElseStatement;
		}
		else if ( wl.front( ) == "do" )
		{
			ps = new CDoWhileStatement;
		}
		else
		{
			ps = new CAssignmentStatement;
		}

		if ( ps )
		{
			ps->SetLevel( m_Level + 1 );
			if ( !ps->Parse( wl ) )		return false;
			m_StatementList.push_back( ps );
		}
	}

	if ( !wl.empty( ) )		wl.pop_front( );

	return true;
}

void CCompositeStatement::OutPut( std::ostream& out, int space ) const
{
	for ( std::list<CStatement*>::const_iterator cit = m_StatementList.begin( ); cit != m_StatementList.end( ); cit ++ )
	{
		(*cit)->OutPut( out, space );
	}
}