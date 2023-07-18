#include "Graphs.h"
#include <stdlib.h>

int main() {

    system("cls");

    // Create a new graph
    Graph* graph = createGraph();

    // Add vertices
    printf("Adding vertices...\n");
    addVertex(graph, "Manila");
    addVertex(graph, "Cebu");
    addVertex(graph, "Davao");
    addVertex(graph, "Baguio");
    addVertex(graph, "Iloilo");
    printf("\n");
    system("pause");
    system("cls");

    // Print the graph
    printf("Printing the map...\n");
    printGraph(graph);
    printf("\n");
    system("pause");
    system("cls");

    // Try adding a duplicate vertex
    printf("Adding a duplicate location...\n");
    addVertex(graph, "Manila");
    printf("\n");
    system("pause");
    system("cls");

    // Print the graph
    printf("Printing the map...\n");
    printGraph(graph);
    printf("\n");
    system("pause");
    system("cls");

    // Add edges
    printf("Adding edges...\n");
    addEdge(graph, "Manila", "Cebu");
    addEdge(graph, "Manila", "Davao");
    addEdge(graph, "Cebu", "Davao");
    addEdge(graph, "Cebu", "Iloilo");
    addEdge(graph, "Davao", "Baguio");
    addEdge(graph, "Davao", "Iloilo");
    addEdge(graph, "Baguio", "Manila");
    printf("\n");
    system("pause");
    system("cls");

    // Print the graph
    printf("Printing the map...\n");
    printGraph(graph);
    printf("\n");
    system("pause");
    system("cls");

    // Try adding a duplicate edge
    printf("Adding a duplicate edge...\n");
    addEdge(graph, "Manila", "Cebu");
    printf("\n");
    system("pause");
    system("cls");

    // Print the graph
    printf("Printing the map...\n");
    printGraph(graph);
    printf("\n");
    system("pause");
    system("cls");

    // Add an edge between non-existing vertices
    printf("Adding an edge between non-existing vertex...\n");
    addEdge(graph, "Zamboanga", "Bacolod");
    printf("\n");
    system("pause");
    system("cls");

    // Print the graph
    printf("Printing the map...\n");
    printGraph(graph);
    printf("\n");
    system("pause");
    system("cls");

    // Delete an edge
    printf("Deleting an edge...\n");
    deleteEdge(graph, "Manila", "Cebu");
    printf("\n");
    system("pause");
    system("cls");

    // Print the graph
    printf("Printing the map...\n");
    printGraph(graph);
    printf("\n");
    system("pause");
    system("cls");

    // Delete a vertex
    printf("Deleting a vertex...\n");
    deleteVertex(graph, "Davao");
    printf("\n");
    system("pause");
    system("cls");

    // Print the graph
    printf("Printing the map...\n");
    printGraph(graph);
    printf("\n");
    system("pause");
    system("cls");

    // Free the graph
    printf("Freeing the map...\n");
    freeGraph(graph);

    system("pause");
    system("cls");

    return 0;
}
