#include "Cell.hpp"

#include <cstdlib>

int Cell::TryConvertInt(const std::string& str)
{
	try
	{
		for (int i  = 0; i < str.size(); ++i)
		{
			if (!(str[i] >= '0' &&  str[i] <= '9'))
			{
				throw std::runtime_error("Is not a Integer! "); 
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::terminate();		
	}
	return std::atoi(m_value.c_str());	
}

double Cell::TryConvetDouble(const std::string& str)
{
	int count = 0;
	try
	{
		for (int i  = 0; i < str.size(); ++i)
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				continue;
			}
			else if(str[i] == '.')
			{
				++count;
			}
		}
		
		if(count != 1 || (str[0] == '.' || str[str.size() - 1] == '.'))
		{
			throw std::runtime_error("Is not a Double! ");
		}	 
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::terminate();
	}

	return std::stod(m_value.c_str());
}

void Cell::SetStringValue(std::string str)
{
	m_value = str;
}

int Cell::GetIntValue()
{
	return TryConvertInt(m_value);
}

double Cell::GetDoubleValue()
{
	return TryConvetDouble(m_value);
}

std::string Cell::GetStringValue() const
{
	return m_value;
}

