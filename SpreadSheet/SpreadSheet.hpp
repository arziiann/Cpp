#include "Cell.hpp"

#include <vector>

class SpreadSheet
{
public:
	void AddRow(int);
	void AddColumn(int);
	void RemoveRow(int);
	void RemoveColumn(int);
	Cell GetCell(int, int);
	void SetCell(const Cell&,int, int);
	void PrintSpreadSheet() const;
	SpreadSheet(int, int);
	SpreadSheet();
	int GetRow();
private:
	int m_row = 0;
	int m_column = 0;
	std::vector<std::vector<Cell> > m_2dVector; 
};
