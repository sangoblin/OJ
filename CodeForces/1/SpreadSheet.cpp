#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

int n;

const int cBase = 26;

string convert(int);
int convert(string&);

int main()
{
	//ifstream in("Spreadsheet.in");
	//ofstream out("Spreadsheet.out");
	cin >> n;
	for (int i=1; i<=n; ++i)
	{
		string tmp;
		cin >> tmp;
		stringstream sstmp(tmp);

		if ('R'==tmp[0] && isdigit(tmp[1]) && tmp.find('C')!=string::npos) //mode1
		{
			char c;
			int row, col;
			sstmp >> c >> row >> c >> col;
			cout << convert(col) << row << endl;
		}
		else
		{
			string _stmp;
			int k = 0;
			while (isalpha(tmp[k]))
			{
				_stmp += tmp[k];
				++k;
			}
			cout << 'R' << tmp.substr(k) << 'C' << convert(_stmp) << endl;
		}
	}

	return EXIT_SUCCESS;
}

string convert(int i)
{
	string res;
	while (i > cBase)
	{
		if (0 == i%cBase)
		{
			res.insert(res.begin(), 'Z');
			i /= cBase;
			--i;
		}
		else
		{
			char ctmp = i%cBase+'A'-1;
			res.insert(res.begin(), ctmp);
			i /= cBase;
		}
	}
	res.insert(res.begin(), i+'A'-1);
	return res;
}

int convert(string& s)
{
	int res = 0, i = 0, len = s.size();

	for (; i<len; ++i)
	{
		res *= cBase;
		res += s[i]-'A'+1;
	}

	return res;
}