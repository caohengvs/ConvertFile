#pragma once
#include<windows.h>
#include<fstream>
#include<filesystem>
#include<iostream>
using namespace std;
#pragma once
class CConvertFile
{
public :
	CConvertFile() = default;
	~CConvertFile() = default;

public:
	void FindAllFile(const filesystem::directory_entry& itEntry, vector<string>& arrFile);
	// ת���ļ���
	void ConvertFile(vector<string>& arrFile);
	// ת���ļ���
	void ConvertFile(vector<string>& arrFile,const string&strConvertPath);
	// ����ת��
	void RConvertFile(vector<string>& arrFile);
	
};

