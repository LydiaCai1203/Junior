#pragma once

#include "CompositeStatement.h"
#include "ConditionExpression.h"

class CIfStatement : public CCompositeStatement
{
private:
	CConditionExpression	m_Condition;

public:
	CIfStatement( );
	virtual ~CIfStatement( );

	virtual	bool Parse( std::list<std::string>& wl );
	virtual void OutPut( std::ostream& out, int space ) const;
};