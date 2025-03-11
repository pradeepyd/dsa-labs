#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 10  // Maximum number of cities

// Function to solve the Travelling Salesman Problem using a Greedy approach
void tspGreedy(int graph[MAX_N][MAX_N], int N, int start) {
    // Check if the number of cities is valid
    if (N <= 1) {
        printf("Error: TSP requires at least 2 cities.\n");
        return;
    }

    bool visited[MAX_N] = {false};  // Track visited cities
    int path[MAX_N + 1];  // Store the travel path
    int cost = 0;  // Total travel cost

    int current = start;  // Start from the chosen city
    visited[current] = true;  // Mark as visited
    path[0] = current;  // Store in path

    // Loop to visit all cities
    for (int i = 1; i < N; i++) {
        int nearest = -1;
        int minDist = INT_MAX;

        // Find the nearest unvisited city with a valid path
        for (int j = 0; j < N; j++) {
            if (!visited[j] && graph[current][j] < minDist && graph[current][j] != INT_MAX) {
                nearest = j;
                minDist = graph[current][j];
            }
        }

        // If no valid city found, the graph is disconnected
        if (nearest == -1) {
            printf("Error: The graph is not fully connected.\n");
            return;
        }

        // Move to the nearest city
        visited[nearest] = true;
        path[i] = nearest;
        cost += minDist;
        current = nearest;
    }

    // Check if we can return to the starting city
    if (graph[current][start] == INT_MAX) {
        printf("Error: Cannot return to the starting city. No valid path exists.\n");
        return;
    }

    // Complete the tour by returning to the start city
    cost += graph[current][start];
    path[N] = start;

    // Print the result
    printf("Path: ");
    for (int i = 0; i <= N; i++) {
        printf("%d ", path[i]);
    }
    printf("\nTotal Cost: %d\n", cost);
}

// Main function
int main() {
    // Number of cities
    int N = 4;  

    // Distance between cities (graph) - INT_MAX means no direct connection
    int graph[MAX_N][MAX_N] = {
        {0, 10, 15, 20},  
        {10, 0, 35, 25},  
        {15, 35, 0, 30},  
        {20, 25, 30, 0}  
    };

    int start = 0;  // Start from city 0
    tspGreedy(graph, N, start);  // Call the function

    return 0;
}
