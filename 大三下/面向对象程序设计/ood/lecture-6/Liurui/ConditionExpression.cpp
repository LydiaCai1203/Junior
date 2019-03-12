#include "ConditionExpression.h"

CConditionExpression::CConditionExpression( )
{
}

CConditionExpression::~CConditionExpression( )
{
}

void CConditionExpression::OutPut( std::ostream& out ) const
{
	out << m_Left << ' ' << m_Cmp << ' ' << m_Right;
}