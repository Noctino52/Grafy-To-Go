
#ifndef GRAPH_H
#define GRAPH_H

/* ************************************************************************** */

#include "../utility.h"

#include "../adt/adt.h"

#include "../itr/itr.h"

/* ************************************************************************** */

typedef void* (*GraphConstruct)(void*); //IN:rappresentazione, OUT:
// typedef type (*GraphDestruct)(arguments);

// typedef type (*GraphEmpty)(arguments);

// typedef type (*GraphClone)(arguments);
// typedef type (*GraphTranspose)(arguments);

// typedef type (*GraphInsertVertex)(arguments);
// typedef type (*GraphRemoveVertex)(arguments);
// typedef type (*GraphInsertEdge)(arguments);
// typedef type (*GraphRemoveEdge)(arguments);

// typedef type (*GraphExistsVertex)(arguments);
// typedef type (*GraphExistsEdge)(arguments);

// typedef type (*GraphGetVertexData)(arguments);
// typedef type (*GraphSetVertexData)(arguments);

// typedef type (*GraphVertexFromPointer)(arguments);

// typedef type (*GraphVertices)(arguments);
// typedef type (*GraphVertexEdges)(arguments);

// typedef type (*GraphEqual)(arguments);


// typedef type (*GraphShortestPath)(arguments);

// typedef type (*GraphIsAcyclic)(arguments);
// typedef type (*GraphTopologicalOrder)(arguments);

// typedef type (*GraphMaximalReachableSubgraph)(arguments);

// typedef type (*GraphSCCGraph)(arguments);

// typedef type (*GraphPreOrderMap)(arguments);
// typedef type (*GraphPostOrderMap)(arguments);
// typedef type (*GraphBreadthMap)(arguments);
// typedef type (*GraphPreOrderFold)(arguments);
// typedef type (*GraphPostOrderFold)(arguments);
// typedef type (*GraphBreadthFold)(arguments);

/* ************************************************************************** */

typedef struct GraphRepresentation
{

    GraphConstruct graphconstruct;
    GraphDestruct graphdestruct;
    GraphEmpty graphempty;
    GraphClone graphclone;
    GraphTraspose graphtraspose;
    GraphInsertVertex graphinsertvertex;
    GraphRemoveVertex graphremovevertex;
    GraphInsertEdge graphinsertedge;
    GraphRemoveEdge graphremovedge;

} GraphRepresentation;


typedef struct GraphType
{
    GraphRepresentation tipo;
    GraphExistsVertex graphexistsvertex;
    GraphExistsEdge graphexistsedge;
    GraphGetVertexData graphgetvertexdata;
    GraphSetVertexData graphsetvertexdata;
    GraphVertexFromPointer graphvertexfrompointer;
    GraphVertices graphvertices;
    GraphVertexEdges graphvertexedges;
    GraphEqual graphequal;
    GraphShortestPath graphshortestpath;
    GraphIsAcyclic graphisacyclic;
    GraphTopologicalOrder graphtopologicalorder;
    GraphMaximalReachableSubgraph graphmaximalreachablesubgraph;
    GraphSCCGraph graphsccgraph;
    GraphPreOrderMap graphpreordermap;
    GraphPostOrderMap graphpostordermap;
    GraphPreOrderMap graphordermap;







  // callbac
} GraphType;

typedef struct GraphObject
{
    void* struttura;
    GraphType* tipo;
    //grafo

} GraphObject;

/* ************************************************************************** */

// type graphConstruct(arguments);
// type graphDestruct(arguments);

// type graphEmpty(arguments);

// type graphVertexNumber(arguments);
// type graphEdgeNumber(arguments);

// type graphClear(arguments);

// type graphClone(arguments);

// type graphTranspose(arguments);

// type graphInsertVertex(arguments);
// type graphRemoveVertex(arguments);
// type graphInsertEdge(arguments);
// type graphRemoveEdge(arguments);

// type graphExistsVertex(arguments);
// type graphExistsEdge(arguments);

// type graphGetVertexData(arguments);
// type graphSetVertexData(arguments);

// type graphVertexFromPointer(arguments);

// type graphVertices(arguments);
// type graphVertexEdges(arguments);

// type graphEqual(arguments);

// type graphExistsVertexWithData(arguments);

// type graphShortestPath(arguments);

// type graphIsAcyclic(arguments);
// type graphTopologicalOrder(arguments);

// type graphMaximalReachableSubgraph(arguments);

// type graphSCCGraph(arguments);

// type graphPreOrderMap(arguments);
// type graphPostOrderMap(arguments);
// type graphBreadthMap(arguments);
// type graphPreOrderFold(arguments);
// type graphPostOrderFold(arguments);
// type graphBreadthFold(arguments);

/* ************************************************************************** */

#endif
