#pragma once

#include <list>
#include <string>

class CStatement
{
protected:
	int		m_Level;

public:
	CStatement( );
	virtual ~CStatement( );

	void	SetLevel( int level );

	virtual	bool Parse( std::list<std::string>& wl ) = 0;
	virtual void OutPut( std::ostream& out, int space ) const;
};

inline void CStatement::SetLevel( int level )
{
	m_Level = level;
}