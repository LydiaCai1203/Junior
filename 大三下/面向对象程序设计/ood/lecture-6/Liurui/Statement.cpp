#include "Statement.h"

CStatement::CStatement( )
{
	m_Level = 0;
}

CStatement::~CStatement( )
{
}

void CStatement::OutPut( std::ostream& out, int space ) const
{
	for ( int i = 1; i < m_Level; i ++ )
	{
		for ( int j = 0; j < space; j ++ )
		{
			out << ' ';
		}
	}
}