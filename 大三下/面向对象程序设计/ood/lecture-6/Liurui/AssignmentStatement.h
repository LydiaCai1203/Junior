#pragma once

#include "Statement.h"

class CAssignmentStatement : public CStatement
{
private:
	std::string		m_Left;
	std::string		m_Right;

public:
	CAssignmentStatement( );
	virtual ~CAssignmentStatement( );

	virtual	bool Parse( std::list<std::string>& wl );
	virtual void OutPut( std::ostream& out, int space ) const;
};