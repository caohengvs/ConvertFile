#include "CConvertFile.h"

void CConvertFile::FindAllFile(const std::string& strSrc, vector<string>& arrFile)
{
	auto itEntry = filesystem::directory_entry(strSrc);
	if (itEntry.is_directory())
	{
		for (const auto& itSub : filesystem::directory_iterator(itEntry.path().string()))
		{
			if (itSub.is_directory())
			{
				FindAllFile(itSub.path().string(), arrFile);
			}
			else
			{
				arrFile.push_back(itSub.path().string());
			}
		}
	}
	arrFile.push_back(itEntry.path().string());
}

void CConvertFile::ConvertFile(const vector<string>& arrFile)
{
	size_t nFindIndex = -1, nLen = 0;
	string strTarget, strDir, strReplace;
	ifstream in;
	ofstream out;
	cout << "转换进度：" << endl;
	int nCount = 0;
	for (auto& itFile : arrFile)
	{

		strTarget = itFile;
		strTarget.replace(0, 1, "e");

		nFindIndex = strTarget.rfind("\\");
		strDir = strTarget.substr(0, nFindIndex);
		if (!filesystem::exists(strDir))
			filesystem::create_directories(strDir);

		// 转换后缀
		nFindIndex = strTarget.rfind(".");
		if (nFindIndex == -1)
			continue;

		nLen = strTarget.length();
		strReplace = strTarget.substr(nFindIndex, nLen) + string(".txt");
		strTarget.replace(nFindIndex, nLen, strReplace);

		in.open(itFile, ios::binary);
		out.open(strTarget, ios::binary);
		out << in.rdbuf();
		in.close();
		out.close();
		cout << "-";
	}

	cout << endl << "转换完成" << endl;
}

void  CConvertFile::ConvertFile(const vector<string>& arrFile, const string& strConvertPath)
{
	size_t nFindIndex = -1, nLen = 0;
	string strTarget, strDir, strReplace;
	ifstream in;
	ofstream out;
	cout << "转换进度：" << endl;
	int nCount = 0;
	for (auto& itFile : arrFile)
	{

		strTarget = itFile;
		strTarget.replace(0, 3, "");
		strTarget.insert(0, strConvertPath);
		nFindIndex = strTarget.rfind("\\");
		strDir = strTarget.substr(0, nFindIndex);
		
		if (!filesystem::exists(strDir))
			filesystem::create_directories(strDir);

		// 转换后缀
		nFindIndex = strTarget.rfind(".");
		if (nFindIndex == -1)
			continue;

		nLen = strTarget.length();
		strReplace = strTarget.substr(nFindIndex, nLen) + string(".txt");
		strTarget.replace(nFindIndex, nLen, strReplace);

		in.open(itFile, ios::binary);
		out.open(strTarget, ios::binary);
		out << in.rdbuf();
		in.close();
		out.close();
		cout << "-";
	}

	cout << endl << "转换完成" << endl;
}

void CConvertFile::RConvertFile(const vector<string>& arrFile)
{
	size_t nFindIndex = -1, nLen = 0;
	string strTarget, strDir, strReplace;
	cout << "转换进度：" << endl;
	int nCount = 0;
	for (auto& itFile : arrFile)
	{
		strTarget = itFile;
		nLen = strTarget.length();
		nFindIndex = strTarget.rfind(".");
		if (nFindIndex == -1)
			continue;
		strTarget.replace(nFindIndex, nLen, "");
		int nRet = rename(itFile.c_str(), strTarget.c_str());
		cout << "-";
	}

	cout << endl << "逆转换完成" << endl;
}

