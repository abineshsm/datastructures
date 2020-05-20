const Queue = require('./Queue');

class Graph {
    constructor() {
        this.adjacencyList = new Map();
    }

    addVertex(vertex) {
        this.adjacencyList.set(vertex, []);
    }

    addEdge(vertex1, vertex2) {
        this.adjacencyList.get(vertex1).push(vertex2);
        this.adjacencyList.get(vertex2).push(vertex1);
    }

    bfs(startVertex) {
        let visited = {};
        let q = new Queue();
        let graph = '';
        visited[startVertex] = true;
        q.enqueue(startVertex);
        while (!q.isEmpty()) {
            let parent = q.dequeue();
            graph += parent + ' ';
            let neighbours = this.adjacencyList.get(parent);
            for (const neigh of neighbours) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.enqueue(neigh);
                }
            }
        }
        console.log(graph);
    }

    dfs(startVertex, visited){
        visited[startVertex] = true;
        console.log(startVertex);
        let neighbours = this.adjacencyList.get(startVertex);
        for(const neigh of neighbours){
            if(!visited[neigh]){
                this.dfs(neigh, visited);
            }
        }
    }
}

module.exports = Graph;

let graph = new Graph();
let vertices = ['A', 'B', 'C', 'D', 'E', 'F'];
for (const vertex of vertices)
    graph.addVertex(vertex);

graph.addEdge('A', 'B');
graph.addEdge('A', 'D');
graph.addEdge('A', 'E');
graph.addEdge('B', 'C');
graph.addEdge('D', 'E');
graph.addEdge('E', 'F');
graph.addEdge('E', 'C');
graph.addEdge('C', 'F');

console.log(graph.adjacencyList)
// graph.bfs('A');
// graph.dfs('A', {});
