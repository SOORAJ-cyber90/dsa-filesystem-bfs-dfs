/*
 * File System Representation and Search Using BFS and DFS
 * Activity ID: SY-S3-B-09
 *
 * Each file/directory is a node; each parent->child link is an edge.
 * The graph is stored as an adjacency matrix.
 */
#include <stdio.h>
#include <string.h>

#define MAX 50
#define NAME_LEN 32

int  n;                          /* number of nodes            */
char names[MAX][NAME_LEN];       /* node names                 */
int  adj[MAX][MAX];              /* adjacency matrix           */

/* Return index of a node by name, or -1 if not present */
int findIndex(const char *name) {
    for (int i = 0; i < n; i++)
        if (strcmp(names[i], name) == 0)
            return i;
    return -1;
}

/* ---------- BFS ---------- */
int bfs(int start, const char *target) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    printf("BFS traversal: ");
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int cur = queue[front++];
        printf("%s ", names[cur]);

        if (strcmp(names[cur], target) == 0) {
            found = 1;
            break;
        }
        for (int j = 0; j < n; j++) {
            if (adj[cur][j] && !visited[j]) {
                visited[j] = 1;
                queue[rear++] = j;
            }
        }
    }
    printf("\n");
    return found;
}

/* ---------- DFS (recursive) ---------- */
int dfsUtil(int cur, const char *target, int visited[]) {
    visited[cur] = 1;
    printf("%s ", names[cur]);

    if (strcmp(names[cur], target) == 0)
        return 1;

    for (int j = 0; j < n; j++) {
        if (adj[cur][j] && !visited[j])
            if (dfsUtil(j, target, visited))
                return 1;
    }
    return 0;
}

int dfs(int start, const char *target) {
    int visited[MAX] = {0};
    printf("DFS traversal: ");
    int found = dfsUtil(start, target, visited);
    printf("\n");
    return found;
}

/* Print the adjacency matrix */
void printMatrix(void) {
    printf("\nAdjacency Matrix:\n      ");
    for (int i = 0; i < n; i++) printf("%-6.5s", names[i]);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-6.5s", names[i]);
        for (int j = 0; j < n; j++) printf("%-6d", adj[i][j]);
        printf("\n");
    }
}

int main(void) {
    int edges;
    char a[NAME_LEN], b[NAME_LEN], startName[NAME_LEN], target[NAME_LEN];

    printf("Enter number of files/directories (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter the names of the %d nodes:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%31s", names[i]);
    }

    printf("Enter number of connections (edges): ");
    if (scanf("%d", &edges) != 1 || edges < 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter each edge as: parent child\n");
    for (int e = 0; e < edges; e++) {
        scanf("%31s %31s", a, b);
        int u = findIndex(a), v = findIndex(b);
        if (u == -1 || v == -1) {
            printf("  Unknown node in edge (%s, %s) - skipped.\n", a, b);
            continue;
        }
        adj[u][v] = 1;   /* directed: parent -> child */
    }

    printMatrix();

    printf("\nEnter starting node: ");
    scanf("%31s", startName);
    int start = findIndex(startName);
    if (start == -1) {
        printf("Starting node not found.\n");
        return 1;
    }

    printf("Enter file to search: ");
    scanf("%31s", target);

    printf("\n--- Search for '%s' starting from '%s' ---\n", target, startName);

    int fb = bfs(start, target);
    printf("BFS result: %s\n\n", fb ? "File FOUND" : "File NOT found");

    int fd = dfs(start, target);
    printf("DFS result: %s\n", fd ? "File FOUND" : "File NOT found");

    return 0;
}
