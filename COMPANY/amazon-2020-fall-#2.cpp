#include <vector>
#include <string>
#include <set>

using namespace std;

/*
There is one error found in "stoi" function of "out of range", which I haven't figured out yet.
*/

int countGroups(vector<string> related) {
	set<int>ansGroup;
	int binaryBase = 0;
	int binaryCompare = 0;
	for (auto i = related.begin();i!=related.end(); i++)
	{
		auto iter = *i; //"1100"
		binaryBase = stoi(iter, 0, 2);
		//binBase = 1100;
		//binBase = 0001;
		for (auto j = related.begin(); j != related.end(); j++)
		{
			auto iterCompare = *j;

			binaryCompare = stoi(iterCompare, 0, 2);
			//baseCompare = 1110;

			//비교 시에 0001 vs 다음 꺼
			if ((binaryBase & binaryCompare) > 0)
			{
				binaryBase |= binaryCompare;
				//binBase (1100 -> 1110);
			}
			
		}
		ansGroup.insert(binaryBase);
	}
	return ansGroup.size();
}


int main()
{
	int n = 5;
	vector<string> related = {
		{"11000"},
		{"11100"},
		{"01000"},
		{"00010"},	
		{"10000"}
	};
	countGroups(related);
	return 0;
}
