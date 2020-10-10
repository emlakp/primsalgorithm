#include <iostream>
#include <vector>
#include <cmath>

#include "graph.h"

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<double, double>> coordinates (n);
    std::vector<std::vector<std::pair<double,int>>> edges (n);
    Graph graph1(coordinates, edges);
    double x,y;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        graph1.addNewVert(i,x,y);
    }

    for (size_t i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph1.addNewEdge(i,Graph::calculateDistance(graph1.getVertex(i),graph1.getVertex(j)),j);
        }
    }

    graph1.primsAlgorithm();
}
