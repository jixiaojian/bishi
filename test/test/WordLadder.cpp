#include <iostream>
#include <string>
#include <vector>
//#include <boost/unordered_map.hpp>
//#include <boost/unordered_set.hpp>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//using namespace boost;

class Solution 
{
private:
	    vector<vector<string>> result_;
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
    {        
        result_.clear();
        unordered_map<string, vector<string>> prevMap;
        
        for(auto iter = dict.begin(); iter != dict.end(); ++iter)
        {
            prevMap[*iter] = vector<string>();
        }
        
        vector<unordered_set<string>> candidates(2);
        
        int current = 0;
        int previous = 1;
        
        candidates[current].insert(start);
        
        while(true)
        {
            current = !current;
            previous = !previous;
            
            for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
            {
                dict.erase(*iter);
            }
            
            candidates[current].clear();
            
            for(auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
            {
                for(size_t pos = 0; pos < iter->size(); ++pos)
                {
                    std::string word = *iter;
                    for(int i = 'a'; i <= 'z'; ++i)
                    {
                        if(word[pos] == i)
                        {
                            continue;
                        }
                        
                        word[pos] = i;
                        
                        if(dict.count(word) > 0)
                        {
                            prevMap[word].push_back(*iter);
                            candidates[current].insert(word);
                        }
                    }
                }
            }
            
            if (candidates[current].size() == 0)
            {
                return result_;
            }
            if (candidates[current].count(end))
            {
                break;
            }
        }
        
        
        std::vector<std::string> path;
        GeneratePath(prevMap, path, end);
        
        return result_;
    }
    
private:
    void GeneratePath(std::unordered_map<std::string, std::vector<std::string>> &prevMap, std::vector<std::string>& path,
                      const std::string& word)
    {
        if (prevMap[word].size() == 0)
        {
            path.push_back(word);
            std::vector<std::string> curPath = path;
            reverse(curPath.begin(), curPath.end());
            result_.push_back(curPath);
            path.pop_back();
            return;
        }
        
        path.push_back(word);
        for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
        {
            GeneratePath(prevMap, path, *iter);
        }
        path.pop_back();
    }
    

};