#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4  // Number of cities

// Function to solve TSP using the Greedy approach
void tspGreedy(int graph[N][N], int start) {
    bool visited[N] = {false};  // Keep track of visited cities
    int path[N + 1];  // Store the travel path
    int cost = 0;  // Total travel cost

    int current = start; // Start from the chosen city
    visited[current] = true; // Mark as visited
    path[0] = current; // Store in path

    // Loop to visit all cities
    for (int i = 1; i < N; i++) {
        int nearest = -1;
        int minDist = INT_MAX;

        // Find the nearest unvisited city
        for (int j = 0; j < N; j++) {
            if (!visited[j] && graph[current][j] < minDist) {
                nearest = j;
                minDist = graph[current][j];
            }
        }

        // Move to the nearest city
        if (nearest != -1) {
            visited[nearest] = true;
            path[i] = nearest;
            cost += minDist;
            current = nearest;
        }
    }

    // Return to the starting city
    cost += graph[current][start];
    path[N] = start; // Store the start city at the end

    // Print the result
    printf("Path: ");
    for (int i = 0; i <= N; i++) {
        printf("%d ", path[i]);
    }
    printf("\nTotal Cost: %d\n", cost);
}

// Main function
int main() {
    // Distance between cities (graph)
    int graph[N][N] = {
        {0, 10, 15, 20},  // City 0 distances
        {10, 0, 35, 25},  // City 1 distances
        {15, 35, 0, 30},  // City 2 distances
        {20, 25, 30, 0}   // City 3 distances
    };

    int start = 0;  // Start from city 0
    tspGreedy(graph, start);  // Call function

    return 0;
}
