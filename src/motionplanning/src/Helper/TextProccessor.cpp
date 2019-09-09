#include "TextProccessor.h"

TextProccessor::TextProccessor()
{

}

TextProccessor::~TextProccessor()
{

}

vector<vector<int>> TextProccessor::readText2Vector (string filename)
{
    ifstream file {filename};
    if (!file.is_open()) return {};
    vector<int> m;
    string mazeSize;
    getline(file,mazeSize);
    string tmp = "";
    for (int i = 0; i < mazeSize.length(); i++) {
        if (isdigit(mazeSize[i])) {
            tmp += mazeSize[i];
        }
        if (mazeSize[i] == ',') {
            m.push_back(stoi(tmp));
            tmp = "";
        }
    }
    string tmpMaze;
    vector<vector<int>> res = vector<vector<int>>(m[0],vector<int>(m[1],0));
    for (int i = 0; i < m[0]; i++) {
        getline(file,tmpMaze);
        int id = 0;
        for (int j = 0; j < tmpMaze.length(); j++) {
            if (isdigit(tmpMaze[j])) {
                res[i][id] = tmpMaze[j] - '0';
                id++;
            }
        }
    }
    return res;
}
