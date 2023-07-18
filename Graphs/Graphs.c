#include "Graphs.h"

#define INIT_VERTEX_CAP 10
#define INIT_EDGE_CAP 10

Graph* createGraph() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = (Vertex*) malloc(INIT_VERTEX_CAP * sizeof(Vertex));
    graph->vertexCount = 0;
    graph->vertexCapacity = INIT_VERTEX_CAP;
    return graph;
}

static Vertex* findVertex(Graph* graph, char* key) {
	int i;
    for(i = 0; i < graph->vertexCount; i++) {
        if(strcmp(graph->vertices[i].key, key) == 0) {
            return &graph->vertices[i];
        }
    }
    return NULL;
}

static int findEdge(Vertex* vertex, char* key) {
	int i;
    for(i = 0; i < vertex->edgeCount; i++) {
        if(strcmp(vertex->edges[i].vertex, key) == 0) {
            return 1;
        }
    }
    return 0;
}

void addVertex(Graph* graph, char* key) {
    if(findVertex(graph, key) != NULL) {
        printf("Duplicate vertex.\n");
        return;
    }
    if(graph->vertexCount >= (int)(0.6 * graph->vertexCapacity)) {
        graph->vertexCapacity *= 2;
        graph->vertices = (Vertex*) realloc(graph->vertices, graph->vertexCapacity * sizeof(Vertex));
    }
    Vertex* vertex = &graph->vertices[graph->vertexCount++];
    vertex->key = strdup(key);
    vertex->edges = (Edge*) malloc(INIT_EDGE_CAP * sizeof(Edge));
    vertex->edgeCount = 0;
    vertex->edgeCapacity = INIT_EDGE_CAP;
}

void addEdge(Graph* graph, char* key1, char* key2) {
    Vertex* vertex1 = findVertex(graph, key1);
    Vertex* vertex2 = findVertex(graph, key2);
    if(vertex1 == NULL || vertex2 == NULL) {
        printf("Vertices not found.\n");
        return;
    }
    if(findEdge(vertex1, key2)) {
        printf("Duplicate edge.\n");
        return;
    }
    if(vertex1->edgeCount >= (int)(0.6 * vertex1->edgeCapacity)) {
        vertex1->edgeCapacity *= 2;
        vertex1->edges = (Edge*) realloc(vertex1->edges, vertex1->edgeCapacity * sizeof(Edge));
    }
    Edge* edge = &vertex1->edges[vertex1->edgeCount++];
    edge->vertex = vertex2->key;
    edge->next = NULL;
    if(vertex1->edgeCount > 1) {
        vertex1->edges[vertex1->edgeCount - 2].next = edge;
    }
}

void deleteEdge(Graph* graph, char* key1, char* key2) {
    Vertex* vertex1 = findVertex(graph, key1);
    if(vertex1 == NULL) {
        printf("Vertex not found.\n");
        return;
    }
    int i, j;
    for(i = 0; i < vertex1->edgeCount; i++) {
        if(strcmp(vertex1->edges[i].vertex, key2) == 0) {
            // Shift the rest of the edges to fill the gap
            for(j = i; j < vertex1->edgeCount - 1; j++) {
                vertex1->edges[j] = vertex1->edges[j + 1];
            }
            vertex1->edgeCount--;
            printf("Edge %s-%s deleted.\n", key1, key2);
            return;
        }
    }
    printf("Edge not found.\n");
}

void deleteVertex(Graph* graph, char* key) {
    int i, j;
    for(i = 0; i < graph->vertexCount; i++) {
        if(strcmp(graph->vertices[i].key, key) == 0) {
            // First delete all edges pointing to this vertex
            for(j = 0; j < graph->vertexCount; j++) {
                if(i != j) {
                    deleteEdge(graph, graph->vertices[j].key, key);
                }
            }
            // Free the memory occupied by the vertex
            free(graph->vertices[i].key);
            free(graph->vertices[i].edges);
            // Shift the rest of the vertices to fill the gap
            for(j = i; j < graph->vertexCount - 1; j++) {
                graph->vertices[j] = graph->vertices[j + 1];
            }
            graph->vertexCount--;
            printf("Vertex %s deleted.\n", key);
            return;
        }
    }
    printf("Vertex not found.\n");
}

void printGraph(Graph* graph) {
	int i;
    for(i = 0; i < graph->vertexCount; i++) {
        Vertex* vertex = &graph->vertices[i];
        printf("%s: ", vertex->key);
        int j;
        for(j = 0; j < vertex->edgeCount; j++) {
            printf("%s ", vertex->edges[j].vertex);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
	int i;
    for(i = 0; i < graph->vertexCount; i++) {
        Vertex* vertex = &graph->vertices[i];
        free(vertex->key);
        free(vertex->edges);
    }
    free(graph->vertices);
    free(graph);
}

