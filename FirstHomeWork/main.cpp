//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

string SimplifyPath(string path)
{

    stack<string> pathStack;

    string actualDirection;

    string simplifiedPath;

    simplifiedPath.append("/");

    int sizeOfPath = path.size();

    for (int i = 0; i < sizeOfPath; i++) {

        actualDirection.clear();

        while (path[i] == '/') {
            i++;
        }

        while (i < sizeOfPath && path[i] != '/') {
            actualDirection.push_back(path[i]);
            i++;
        }

        if (actualDirection.compare("..") == 0) {
            if (!pathStack.empty()) {
                pathStack.pop();
            }
        }

        else if (actualDirection.compare(".") == 0) {
            continue;
        }

        else if (actualDirection.length() != 0) {
            pathStack.push(actualDirection);
        }
    }

    stack<string> pathStackCopy;
    while (!pathStack.empty()) {
        pathStackCopy.push(pathStack.top());
        pathStack.pop();
    }

    while (!pathStackCopy.empty()) {
        string temp = pathStackCopy.top();

        if (pathStackCopy.size() != 1) {
            simplifiedPath.append(temp + "/");
        }
        else {
            simplifiedPath.append(temp);
        }
        pathStackCopy.pop();
    }
    return simplifiedPath;
}

int main()
{
    string path("/home/a/./x/../b//c/");
    string simplifiedPath = SimplifyPath(path);
    cout << simplifiedPath;
    return 0;
}