class String
{
	private:
		int m_size;	
 		
		union string
		{
			char on_stack[16];
			char *dyn_str{nullptr};
		}obj_string;
		
	
	public:
	
	
	String(const char* operand) : m_size{0}  
	{
		obj_string.dyn_str = nullptr;
		memory(operand);
		std::cout << "OK!" << std::endl;
	}	
	~String()
	{
		obj_string.dyn_str = nullptr;
		delete obj_string.dyn_str;
		std::cout << "Delete" << std::endl;
	}
	int CalculateSize(const char *line) 
	{	
		
		while (*line)
		{
			m_size++;
			++line;
		}
		return m_size;
	}	


	bool checker(int size)const
	{
		if (m_size <= 16)
		{
			return true;
		}
		return false;
	}

	void memory(const char *line)
	{
		int size = CalculateSize(line);
		bool state = checker(size);
		if (state)
		{
			for (int i = 0; i < size; ++i)
			{
				obj_string.on_stack[i] = line[i];
			}
		}
		else
		{	
	 		obj_string.dyn_str = new char[size];
			for (int i = 0; i < size; ++i)
			{
				obj_string.dyn_str[i] = line[i];
			}
		}	


	}
	
	int size()
	{
		return m_size;
	}
};
