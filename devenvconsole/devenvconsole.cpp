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
	ifstream in;
	ofstream out;
	cout << "转换进度：" << endl;
	for (auto& itFile : arrFile)
	{
		strTarget = itFile;
		strTarget.replace(0, 1, "e");

		nIndex = strTarget.rfind("\\");
		strDir = strTarget.substr(0, nIndex);
		strDir.replace(0, 1, "e");
		if (!filesystem::exists(strDir))
			filesystem::create_directories(strDir);

		in.open(itFile, ios::binary);
		out.open(strTarget, ios::binary);
		out << in.rdbuf();
		in.close();
		out.close();
		cout << "-";
	}

	cout << endl<<"转换完成" << endl;
}


