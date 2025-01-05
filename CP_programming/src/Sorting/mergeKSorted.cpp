#include <cstdio>
#include <queue>
#include <vector>

struct Node
{
    int value;
    int streamIndex;
    Node(int value_, int streamIndex_)
    {
        value = value_;
        streamIndex = streamIndex_;

    }

    bool operator<(const Node& other) const
    {
        return other.value < value;
    }
};


void mergeKSorted(std::vector<std::vector<int>>& streams)
{
    std::priority_queue<Node> pq;

    for(int i=0;i<streams.size();i++)
    {
        if (!streams[i].empty())
        {
            pq.push(Node(streams[i][0],i));
            streams[i].erase(streams[i].begin());
        }
    }

    while(!pq.empty())
    {
        Node node = pq.top();
        pq.pop();

        printf("%d ",node.value);

        if (!streams[node.streamIndex].empty())
        {
            pq.push(Node(streams[node.streamIndex][0],node.streamIndex));
            streams[node.streamIndex].erase(streams[node.streamIndex].begin());
        }
    }
}

int main()
{
    std::vector<std::vector<int>> streams = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };
    printf("merging the k sorted streams!\n");
    mergeKSorted(streams);
    printf(
        "\n"
    );
    return 0;

}