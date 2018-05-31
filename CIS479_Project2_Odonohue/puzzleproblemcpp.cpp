/*
Author: Peter O'Donohue
Creation Date: 05/31/2018
Modification Date: 05/31/2018
Purpose:
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Path
{
public:
	vector<string> currentPath;
	int pathLength;
	Path();

};

Path::Path()
{
	pathLength = 0;
}


struct compare
{

	bool operator()(const Path& lhs, const Path& rhs)
	{
		return lhs.currentPath.size() > rhs.currentPath.size();
	}
};


// function definitions
void expandAndAppend(const vector<string>& path, priority_queue<Path, vector<Path>, compare>& listOfPaths);
void solve(priority_queue<Path, vector<Path>, compare>& listOfPaths, string start, string finish);

int main()
{
	priority_queue<Path, vector<Path>, compare> paths;
	Path foo;
	foo.currentPath.push_back("ART---");
	paths.push(foo);
	solve(paths, "ART---", "---ART");
	/*
	while (!paths.empty())
	{
		Path test = paths.top();
		for (auto foo : test.currentPath)
			cout << foo << " ";
		cout << endl;
		paths.pop();
	}
	*/
	system("pause");
	return 0;
}

void expandAndAppend(const vector<string>& path, priority_queue<Path, vector<Path>, compare>& listOfPaths)
{
	Path newPath;
	string currentMove = path[0];
	string newMove;
	char tempMove;

	newPath.currentPath = path;
	for (int i = 0; i < (currentMove.size() - 1); ++i)
	{

		if (currentMove.at(i) != '-')
		{
			if (currentMove.at(i + 1) == '-')
			{
				newMove = currentMove;
				tempMove = newMove[i];
				swap(newMove[i], newMove[i + 1]);
				newPath.currentPath.insert(newPath.currentPath.begin(), newMove);
				listOfPaths.push(newPath);
				newPath.currentPath.erase(newPath.currentPath.begin());
			}
			if ((currentMove.at(i + 1) != '-') && (currentMove.at(i + 2) == '-'))
			{
				newMove = currentMove;
				swap(newMove.at(i), newMove.at(i + 2));
				newPath.currentPath.insert(newPath.currentPath.begin(), newMove);
				listOfPaths.push(newPath);
				newPath.currentPath.erase(newPath.currentPath.begin());
			}
		}
	}

}

void solve(priority_queue<Path, vector<Path>, compare>& listOfPaths, string start, string finish)
{
	Path recentPath = listOfPaths.top();
	while (recentPath.currentPath[0] != finish)
	{
		cout << recentPath.currentPath[0] << endl;
		listOfPaths.pop();
		expandAndAppend(recentPath.currentPath, listOfPaths);
		recentPath = listOfPaths.top();
	}
}