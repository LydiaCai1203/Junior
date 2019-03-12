#pragma once

#include "Statement.h"

class CCompositeStatement : public CStatement
{
private:
	std::list<CStatement*>		m_StatementList;

public:
	CCompositeStatement( );
	virtual ~CCompositeStatement( );

	virtual	bool Parse( std::list<std::string>& wl );
	virtual void OutPut( std::ostream& out, int space ) const;
};