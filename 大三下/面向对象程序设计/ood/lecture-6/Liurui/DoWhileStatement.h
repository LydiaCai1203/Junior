#pragma once

#include "CompositeStatement.h"
#include "ConditionExpression.h"

class CDoWhileStatement : public CCompositeStatement
{
private:
	CConditionExpression	m_Condition;

public:
	CDoWhileStatement( );
	virtual ~CDoWhileStatement( );
	
	virtual	bool Parse( std::list<std::string>& wl );
	virtual void OutPut( std::ostream& out, int space ) const;
};
