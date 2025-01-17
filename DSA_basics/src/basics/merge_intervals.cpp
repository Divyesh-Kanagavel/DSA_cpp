#include <cstdio>
#include <vector>
#include <utility>

int main(void)
{
    
    std::vector<std::pair<int,int>> intervals = {{1,4},{3,6},{8,10}};
    std::vector<std::pair<int,int>> merged;
    merged.reserve(intervals.size());
    int i=0;
    while(i!=intervals.size()-1)
    {
        if (intervals[i].second >= intervals[i+1].first)
        {
            std::pair<int,int> temp = {intervals[i].first, intervals[i+1].second};
            intervals.erase(intervals.begin()+i);
            intervals.erase(intervals.begin()+i);
            intervals.insert(intervals.begin()+i, temp);
        }
        else
        {
            i++;
        }
    }

    for(auto i:intervals)
    {
        printf("%d,%d ",i.first, i.second);
    }
    printf("\n");
    return 0;





 






}