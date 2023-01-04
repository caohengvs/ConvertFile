#include "CConvertFile.h"

void CConvertFile::FindAllFile(const filesystem::directory_entry& itEntry, vector<string>& arrFile)
{
	if (itEntry.is_directory())
	{
		for (const auto& itSub : filesystem::directory_iterator(itEntry.path().string()))
		{
			if (itSub.is_directory())
			{
				FindAllFile(itSub, arrFile);
			}
			else
			{
				arrFile.push_back(itSub.path().string());
			}
		}
	}
	arrFile.push_back(itEntry.path().string());
}
