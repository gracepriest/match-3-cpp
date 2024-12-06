#include "TextFiledb.h"
//using namespace std;
FileHandler::FileHandler()
{
	for (int i = 0; i < MAX_BUFFER; i++)
	{
		buffer[i] = '\0';
	}
}
void FileHandler::print(const char* s)
{

	for (; *s != 0; s++)
	{
		_putch(*s);
	}
}
void FileHandler::read(char* buf)
{
	char c = ' ';
	int count = 0;
	const char* const pEnd = buf + 255;
	c = _getch();
	while (c != 13)
	{
		if (c == 8)
		{
			--buf;
			--count;
			*buf = '\0';
			system("CLS");
			print(buf - count);

		}
		else if (buf + 1 < pEnd)
		{
			_putch(c);
			*buf = c;
			buf++;
			count++;
		}
		c = _getch();

	}
	*buf = 0;
}
void FileHandler::read(char* buf, int maxSize)
{
	char c = ' ';
	int count = 0;
	const char* const pEnd = buf + maxSize;
	c = _getch();
	while (c != 13)
	{
		if (c == 8)
		{
			--buf;
			--count;
			*buf = '\0';
			system("CLS");
			print(buf - count);

		}
		else if (buf + 1 < pEnd)
		{
			_putch(c);
			*buf = c;
			buf++;
			count++;
		}
		c = _getch();

	}
	*buf = 0;
}
int FileHandler::StringToInt(const char* s)
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
void FileHandler::strreverse(char* pl)
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
void FileHandler::intToString(int val, char* buf, int size)
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
std::string FileHandler::Load(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);

	in.read(buffer, sizeof(buffer));
	std::string  s = (std::string)buffer;
	return s;

}
char* FileHandler::LoadC(const char* filename)
{
	std::ifstream in(filename);
	int j = 0;
	int sizeOfBuffer = 0;
	char c;
	/*for (int i = 0; i < MAX_BUFFER; i++)
	{
		if (buffer[i] != '\0')
			sizeOfBuffer++;
		else if (buffer[i] == '\0')
		{
			break;
		}
	}*/
	in.read(buffer, sizeof(buffer));
	
	for (char c = in.get(); in.good(); c = in.get(),j++)
	{
		buffer[j] = c;

	}

	return buffer;

}
void FileHandler::Save(const char* filename) const
{
	int sizeOfBuffer = 0;
	std::ofstream out(filename);
	for (int i = 0; i < MAX_BUFFER; i++)
	{
		if (buffer[i] == '\0')
			sizeOfBuffer++;
	}
	out.write(buffer, sizeof(sizeOfBuffer));
	for (const auto e : buffer)
	{
		if (e != NULL)
		{
			out.put(e);
		}
		else
		{
			break;
		}
	}

}
void FileHandler::Save(const char* filename,  const char * buff)
{
	int sizeOfBuffer = 0;
	std::ofstream out(filename);
	for (int i = 0; i < MAX_BUFFER; i++)
	{
		if (buff[i] != '\0')
			sizeOfBuffer++;
		else
			break;
	}
	//out.write(buff, sizeof(int));
	for (int j =0; j< sizeOfBuffer; j++)
	{
		out.put(buff[j]);
	}

}
void FileHandler::SaveCpp(const char* filename)
{
	ofstream myfile("mytext.txt");
	if (myfile.is_open())
	{
		myfile << buffer;
		myfile.close();
	}
	else cout << "Unable to open file";
}
void FileHandler::SaveCpp(const char* filename, const char * buff)
{
	ofstream myfile("mytext.txt");
	if (myfile.is_open())
	{
		myfile << buff;
		myfile.close();
	}
	else cout << "Unable to open file";
}
void FileHandler::SaveCppEnd(const char* filename, const char* buff)
{
	ofstream myfile("mytext.txt",std::ios::app);
	if (myfile.is_open())
	{
		myfile << buff;
		myfile.close();
	}
	else cout << "Unable to open file";
}
