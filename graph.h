//
// Created by Emil Akopyan on 08.10.2020.
//

#ifndef KSNWRK_GRAPH_H
#define KSNWRK_GRAPH_H

#include <vector>
#include <utility>
#include <cmath>


class Graph
{
public:
    typedef std::pair<double,int> edge; //weight, vertex. The first vertex is determined by the position in AL
    typedef std::vector<std::vector<edge>> adjList;
    typedef std::pair<double, double> vertex;

public:

    Graph(std::vector<std::pair<double, double>> coordinates,std::vector<std::vector<std::pair<double,int>>> vecEdges )
    {
        _vertices = coordinates;
        _adjlist = vecEdges;
    };

    void addNewEdge(int u, double weight, int v);
    void addNewVert(int i,double x, double y);
    vertex getVertex(int n);

    static double calculateDistance(vertex u, vertex v);
    void primsAlgorithm();

private:
    adjList _adjlist;
    std::vector<vertex> _vertices;
};



#endif //KSNWRK_GRAPH_H
