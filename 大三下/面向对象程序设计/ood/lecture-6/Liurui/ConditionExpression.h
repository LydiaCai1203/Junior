#pragma once

#include <iostream>
#include <string>

class CConditionExpression
{
public:
	std::string		m_Left;
	std::string		m_Right;
	std::string		m_Cmp;

public:
	CConditionExpression( );
	~CConditionExpression( );

	void OutPut( std::ostream& out ) const;
};