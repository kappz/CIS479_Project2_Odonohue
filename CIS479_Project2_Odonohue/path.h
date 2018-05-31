#pragma once
#ifndef PATH_H
#define PATH_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Path
{
public:
	vector<string> currentPath;
	int pathLength;
};

Path::Path()
{
		pathLength = 0;
}

#endif