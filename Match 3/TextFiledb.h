#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
//database for use with textFiles and binary files


class DB
{

};

struct Stage
{
	char name[25];
	int numOfLevel;
};

struct Profile
{
	char name[25];
	int currLevel;
	Stage currentStage;

	friend std::ostream& operator<<(std::ostream& os, const Profile p)
	{
		// write obj to stream
		os << p.name << endl;
		os << p.currLevel << endl;
		os << p.currentStage.name << endl;
		os << p.currentStage.numOfLevel << endl;

		return os;
	}
	friend ifstream& operator>>(std::ifstream& os, Profile& p)
	{
		os.open("mytext.txt");
		// write obj to stream
		os.getline(p.name, 25);
		os >> p.currLevel;
		os >> p.currentStage.name;
		os >> p.currentStage.numOfLevel;

		
		return os;
	}
};

class FileHandler
{
public:

	const static int MAX_BUFFER = 1024;
	char buffer[MAX_BUFFER];
	std::string str_buffer;
	
	FileHandler();
	void print(const char* s);
	void read(char* buf);
	void read(char* buf, int maxSize);
	int StringToInt(const char* s);
	void strreverse(char* pl);
	void intToString(int val, char* buf, int size);
	std::string Load(const char* filename);
	char* LoadC(const char* filename);
	void Save(const char* filename) const;
	void Save(const char* filename, const char *buff);
	void SaveCpp(const char* filename);
	void SaveCpp(const char* filename,const char * buff);
	void SaveCppEnd(const char* filename, const char* buff);
	
	template <typename T>
	void SaveStruct(const char* filename, T profile)
	{
		ofstream myfile("mytext.txt");
		if (myfile.is_open())
		{
			myfile << profile;
			myfile.close();
		}
		else cout << "Unable to open file";
	}

	template <typename T>
	void LoadStruct(const char* filename, T& profile)
	{
		ifstream myfile("mytext.txt");
		if (myfile.is_open())
		{
			myfile >> profile;
			myfile.close();
		}
		else cout << "Unable to open file";
	}



};