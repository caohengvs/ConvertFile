// devenvconsole.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"CConvertFile.h"
#include<string>
int main()
{
	CConvertFile oConvert;
	int nIndex = 0;
	string strSrc, strTarget, strDir;
	getline(cin, strSrc);

	auto itBegin = filesystem::directory_entry(strSrc);
	vector<string> arrFile;

	oConvert.FindAllFile(itBegin, arrFile);
	oConvert.RConvertFile(arrFile);
	system("pause");
}


