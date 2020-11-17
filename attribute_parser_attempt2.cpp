#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

string findTagNameFromHRML(string line)
{
    //returns "" if it is a closing tag,
    //return the tagName only;
    string tagName;
    for (long unsigned int i = 1; i < line.size(); i++)
    {
        if (line.at(i) == ' ' || line.at(i) == '>')
            break;
        else if (line.at(i) == '/')
        {
            tagName = "";
            break;
        }
        tagName.push_back(line.at(i));
    }
    return tagName;
}

int isOnlyTagname(string line)
{
    int isOnlyTagname = 1;
    for (long unsigned int i = 1; i < line.size(); i++)
    {
        if (line.at(i) == ' ')
        {
            isOnlyTagname = 0;
            break;
        }
    }
    return isOnlyTagname;
}

map<string, map<string, string> /**/> findKeyAndValueFromHRML(string HRML[20], int N)
{
    map<string, map<string, string> /**/> allTagMapPairs;
    //each line
    for (int i = 0; i < N; i++)
    {
        map<string, string> keyValuePairs;
        string line = HRML[i];

        string tagName = findTagNameFromHRML(line);
        if (tagName != "" && isOnlyTagname(line) == 0)
        {
            int beforeKeySpaceIndex;
            int afterKeySpaceIndex;
            int beforeValueIndex;
            int afterValueIndex = 0;
            //key value pairs
            while (line.at(afterValueIndex + 1) != '>')
            {
                for (long unsigned int i = afterValueIndex + 1; i < line.size(); i++)
                {
                    if (line.at(i) == ' ')
                    {
                        beforeKeySpaceIndex = i;
                        break;
                    }
                }
                string key;
                for (long unsigned int i = (beforeKeySpaceIndex + 1); i < line.size(); i++)
                {
                    if (line.at(i) != ' ')
                    {
                        key.push_back(line.at(i));
                    }
                    else
                    {
                        afterKeySpaceIndex = i;
                        break;
                    }
                }
                beforeValueIndex = afterKeySpaceIndex + 3;
                string value;
                for (long unsigned int i = (beforeValueIndex + 1); i < line.size(); i++)
                {
                    if (line.at(i) != '\"')
                    {
                        value.push_back(line.at(i));
                    }
                    else
                    {
                        afterValueIndex = i;
                        break;
                    }
                }
                keyValuePairs[key] = value;
            }
            allTagMapPairs[tagName] = keyValuePairs;
        }
    }
    return allTagMapPairs;
}

string findKeyFromQuery(string line)
{
    string key;
    int found = 0;
    for (long unsigned int i = 0; i < line.size(); i++)
    {
        if (found == 1)
        {
            key.push_back(line.at(i));
        }
        else
        {
            if (line.at(i) == '~')
            {
                found = 1;
            }
        }
    }
    return key;
}

int main()
{
    int N, Q;
    string HRML[20];
    string Queries[20];
    cin >> N >> Q;
    getline(cin, HRML[0]);
    for (int i = 0; i < N; i++)
    {
        getline(cin, HRML[i]);
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> Queries[i];
    }
    map<string, map<string, string> /**/> allTagMapPairs;
    allTagMapPairs = findKeyAndValueFromHRML(HRML, N);
    for (int i = 0; i < Q; i++)
    {
        string query = Queries[i];
        string key = findKeyFromQuery(query);
        string tag;
        int found = 0;
        string foundString;
        for (long unsigned int i = 0; i < query.size(); i++)
        {
            if (query.at(i) != '.' && query.at(i) != '~')
            {
                tag.push_back(query.at(i));
            }
            else
            {
                if (!allTagMapPairs[tag].empty())
                {

                    if (!allTagMapPairs[tag][key].empty())
                    {
                        foundString = allTagMapPairs[tag][key];
                        found++;
                    }
                }
                if (query.at(i) == '~')
                    break;
                tag = "";
            }
        }
        if (found == 1)
            cout << foundString << endl;
        else
            cout << "Not Found!\n";
    }
    // for (auto it : allTagMapPairs)
    // {
    //     cout << "\nTagName: " << it.first;
    //     cout << "\nKey Value Pairs: ";
    //     for (auto it2 : it.second)
    //     {
    //         cout << "\nKey: " << it2.first;
    //         cout << "\nValue: " << it2.second;
    //     }
    //     cout << "\n---------------------";
    // }
    // string HRML[20];
    // HRML[0] = "<tag1 value = \"HelloWorld\" value2 = \"HelloWorl2d\">";

    return 0;
}