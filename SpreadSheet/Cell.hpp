#include <string>
#include <iostream>

class Cell
{
public:
	void SetStringValue(std::string);
	int GetIntValue();
	double GetDoubleValue();
	std::string GetStringValue() const;
	
private:
	std::string m_value;
private:
	int TryConvertInt(const std::string&);
	double TryConvetDouble(const std::string&);
};
