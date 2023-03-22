#pragma once
#include<windows.h>
#include<fstream>
#include<filesystem>
#include<iostream>

#define  _SYS_STATUS_DLL_
#ifdef _SYS_STATUS_DLL_
#define _SYS_STATUS_HEADER_DLL_ _declspec(dllexport)
#define _SYS_STATUS_FUN_HEADER_DLL_  extern "C" __declspec(dllexport)
#else
#define _SYS_STATUS_HEADER_DLL_ __declspec(dllimport)
#define _SYS_STATUS_FUN_HEADER_DLL_  extern "C" __declspec(dllimport)
#endif
using namespace std;
#pragma once
class _SYS_STATUS_HEADER_DLL_  CConvertFile
{
public :
	CConvertFile() = default;
	~CConvertFile() = default;

public:
	void FindAllFile(const std::string& strSrc, vector<string>& arrFile);
	// 转换文件后
	void ConvertFile(const vector<string>& arrFile);
	// 转换文件后
	void ConvertFile(const vector<string>& arrFile,const string&strConvertPath);
	// 逆向转换
	void RConvertFile(const vector<string>& arrFile);
	
};

