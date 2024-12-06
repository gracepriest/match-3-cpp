#pragma once
#include <conio.h>
#include <fstream>
class StringHandler
{
public:
	char buffer[255];

	StringHandler() = default;
	int maxSize;
	void print(const char* s)
	{
		for (; *s != 0; s++)
		{
			_putch(*s);
		}
	}
	void read(char* buf)
	{
		char c;
		const char* const pEnd = buf + 255;
		while (c = _getch() and c != 13)
		{
			if (buf + 1 < pEnd)
			{
				_putch(c);
				*buf = c;
				buf++;
			}
			
			
		}
		*buf = 0;
	}
	int StringToInt(const char * s)
	{
		const char* p = s;
		// set p the starting point
		for (; *p >= '0' and *p <= '9'; p++);
		p--;
		int val = 0;
		int place = 1;
		//convert each char in string to int
		for (; p >= s; p--)
		{
			val += (*p - 0) * place;
			place *= 10;
		}
		
		return val;
	}
	//reverse the string
	void strreverse(char* pl)
	{
		
		char* pr = pl;
		for (; *pr != 0; pr++)
		{
			pr--;
		}
		for (; pl < pr; pl++, pr--)
		{
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}
	void intToString(int val, char* buf, int size)
	{
		char* const pStart = buf;
		char* const pEnd = buf + size;
		for (; val > 0 and (buf + 1 < pEnd); val /= 10, buf++)
		{
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strreverse(pStart);
	}
	std::string readFile(const char* file)
	{
		std::ifstream in(file);
		std::string s;
		char c;
		while (c = in.get() and in.good())
		{
			s = c;
		}
		return s;
	}
	void writeFile()
	{

	}

};

