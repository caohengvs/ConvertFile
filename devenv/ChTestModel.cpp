// devenvconsole.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"CConvertFile.h"
#include<string>
using namespace std;
void Covert();
void RCovert();
CConvertFile m_oFile;
string strSrc, strTarget;
char** pArgvBuffer = nullptr;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "请输入: devenv.exe -n[转换] -s 源路径 -t 目标路径";
		cout << "请输入: devenv.exe -r[逆转换] -s 源路径";
		return -1;
	}

	pArgvBuffer = argv;

	if (string(pArgvBuffer[1]) == "-n")
	{
		Covert();
	}
	else if(string(pArgvBuffer[1]) == "-r")
	{
		RCovert();
	}
	
	system("pause");
	return 0;
}

void Covert()
{
	if (string(pArgvBuffer[2]) == "-s")
	{
		strSrc = string(pArgvBuffer[3]);
	}
	if (string(pArgvBuffer[4]) == "-t")
	{
		strTarget = string(pArgvBuffer[5]);
	}

	vector<string> arrFile;
	m_oFile.FindAllFile(strSrc, arrFile);
	m_oFile.ConvertFile(arrFile, strTarget);
}
void RCovert()
{
	if (string(pArgvBuffer[2]) == "-s")
	{
		strSrc = string(pArgvBuffer[3]);
	}

	vector<string> arrFile;
	m_oFile.FindAllFile(strSrc, arrFile);
	m_oFile.RConvertFile(arrFile);
}

