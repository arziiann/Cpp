#include "SpreadSheet.hpp"

SpreadSheet::SpreadSheet(int row, int column)
{
	SpreadSheet::AddRow(row);
	SpreadSheet::AddColumn(column);
}

SpreadSheet::SpreadSheet() = default;

void SpreadSheet::AddRow(int row = 1)
{
	for (int i = 0; i < row; ++i)
	{
		std::vector<Cell> cm;
		m_2dVector.push_back(cm);
	}
	m_row += row;
}

void SpreadSheet::AddColumn(int column_count = 1)
{
	for (int i = 0; i < m_row; ++i)
	{
		for(int k = 0; k < column_count; ++k)
		{
			Cell tmp;
			tmp.SetStringValue("NONE");
			m_2dVector[i].push_back(tmp);
		}
	}	
	m_column += column_count;
}

void SpreadSheet::RemoveRow(int index)
{
	try
	{
		if (index < 0 || index > m_row)
		{
			throw std::runtime_error("Its not valid value" );
		}
		m_2dVector.erase(m_2dVector.begin() + index);

	}
	catch(const  std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::terminate();
	}
	--m_row;
}


void SpreadSheet::RemoveColumn(int index)
{
	try
	{
		if (index < 0 || index > m_row)
		{
			throw std::runtime_error("Its not valid value" );
		}

		for(int i = 0; i < m_row; ++i)
		{
			m_2dVector[i].erase(m_2dVector[i].begin() + index);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::terminate();
	}
	--m_column;
}


Cell SpreadSheet::GetCell(int row, int column)
{
	try
	{	
		if ((row < 0 || row > m_row - 1) || (column < 0 || column > m_column - 1))
		{
			throw std::runtime_error("Its not valid value" );
		}
		return m_2dVector[row][column];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::terminate();
	}


}

void SpreadSheet::SetCell(const Cell& c, int row, int column)
{
	try
	{	
		if ((row < 0 || row > m_row - 1) || (column < 0 || column > m_column - 1))
		{
			throw std::runtime_error("Its not valid value" );
		}
	
		m_2dVector[row][column] = c;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::terminate();
	}
}

void SpreadSheet::PrintSpreadSheet() const
{
	for (int i = 0; i < m_row; ++i)
	{
		for (int j = 0; j < m_column; ++j)
		{
			std::cout << m_2dVector[i][j].GetStringValue() << " ";
		}
		std::cout << "\n";

	}
}

