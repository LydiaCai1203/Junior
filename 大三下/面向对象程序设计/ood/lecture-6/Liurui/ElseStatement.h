#pragma once

#include "CompositeStatement.h"

class CElseStatement : public CCompositeStatement
{
public:
	CElseStatement( );
	virtual ~CElseStatement( );

	virtual	bool Parse( std::list<std::string>& wl );
	virtual void OutPut( std::ostream& out, int space ) const;
};