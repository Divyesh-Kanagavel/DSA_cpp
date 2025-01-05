/*
Write a method to sort an array of strings so that all the anagrams are next to each other.
· Loop through the array.
· For each word, sort the characters and add it to the hash map with keys as sorted
word and value as the original word. At the end of the loop, you will get all
anagrams as the value to a key (which is sorted by its constituent chars).
· Iterate over the hashmap, print all values of a key together and then move to the
next key.
*/

#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>


void sortAnagrams(std::vector<std::string>& strings)
{
    std::unordered_map<std::string, std::vector<std::string>> hash;
    for(auto s : strings)
    {
        std::string sorted = s;
        std::sort(sorted.begin(), sorted.end());
        hash[sorted].push_back(s);
    }

    int count = 0;

    for(auto it = hash.begin(); it !=hash.end();it++)
    {
        for(auto s : it->second)
        {
            strings[count++] = s;
        }
    }

}

int main()
{

    std::vector<std::string> strings = {"eat","tap","tea","bat","tan","ate","pat","ant","tab","apt"};
    sortAnagrams(strings);
    for(auto s : strings)
    {
        printf("%s ", s.c_str());
    }
    printf("\n");

    
    return 0;
}