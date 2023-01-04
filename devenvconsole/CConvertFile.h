#pragma once
#include<windows.h>
#include<fstream>
#include<filesystem>
#include<iostream>
using namespace std;
class CConvertFile
{
public :
	CConvertFile() = default;
	~CConvertFile() = default;

public:
	void FindAllFile(const filesystem::directory_entry& itEntry, vector<string>& arrFile);
};

