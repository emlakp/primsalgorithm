//
// Created by Emil Akopyan on 08.10.2020.
//
#include "graph.h"
#include <queue>
#include <functional>
#include <iostream>
#include <iomanip>

void Graph::addNewEdge(int u, double weight, int v)
{
    _adjlist[u].push_back(edge(weight,v));
}

Graph::vertex Graph::getVertex(int n)
{
    return _vertices[n];
}

double Graph::calculateDistance(vertex u, vertex v)
{
    double x1 = u.first;
    double y1 = u.second;
    double x2 = v.first;
    double y2 = v.second;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void Graph::addNewVert(int i, double x, double y)
{
    _vertices[i] = {x,y};
}

void Graph::primsAlgorithm()
{
    std::vector<bool> visits = std::vector<bool> (_vertices.size(), 0);
    std::priority_queue<edge, std::vector<edge>, std::greater<>> PQ;
    edge current;
    double minimalCost = 0;
    int source = 0;
    PQ.push({0, source});
    std::vector<std::pair<vertex,vertex>> MST;
    std::vector<std::pair<int,double>> parents;
    for (int i = 0; i < _vertices.size(); i++)
    {
        parents.push_back({2147483647, 2147483647});
    }
    while (MST.size() != _vertices.size() - 1)
    {
        current = PQ.top();
        PQ.pop();
        source = current.second;
        if (visits[source] == 1)
            continue;
        visits[source] = true;
        if (current.second != 0)
            MST.push_back({_vertices[parents[current.second].first],_vertices[current.second]});
        minimalCost += current.first;
        for (auto it = _adjlist[source].begin(); it != _adjlist[source].end(); it++) {
            if (!visits[it->second])
            {
                if(parents[it->second].second > (*it).first)
                {
                    parents[it->second].first = source;
                    parents[it->second].second = (*it).first;
                }
                PQ.push(*it);
            }
        }
    }
    std::cout << std::setprecision(9) <<minimalCost << std::endl;
    for (size_t i = 0; i < MST.size(); ++i)
    {

            std::cout << MST[i].first.first << ' ' << MST[i].first.second << ' ' <<
            MST[i].second.first << ' ' << MST[i].second.second << std::endl;
    }
}





