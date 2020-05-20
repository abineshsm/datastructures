class EdgeWeightedGraph {
    constructor() {
        this.adjacencyList = {};
    }

    addVertex(vertex) {
        this.adjacencyList[vertex] = {};
    }
    
    addEdge(vertex1, vertex2, weight) {
        !this.adjacencyList.hasOwnProperty(vertex1) ? this.addVertex(vertex1) : false;
        !this.adjacencyList.hasOwnProperty(vertex2) ? this.addVertex(vertex2) : false;
        this.adjacencyList[vertex1][vertex2] = weight;
        this.adjacencyList[vertex2][vertex1] = weight;
    }
}

module.exports = EdgeWeightedGraph;

// let graph = new EdgeWeightedGraph();
// // let vertices = ['B', 'C', 'D', 'E', 'F'];
// // for (const vertex of vertices)
// //     graph.addVertex(vertex);

// graph.addEdge('A', 'B', 1);
// graph.addEdge('A', 'D', 2);
// graph.addEdge('A', 'E', 3);
// graph.addEdge('B', 'C', 4);
// graph.addEdge('D', 'E', 5);
// graph.addEdge('E', 'F', 6);
// graph.addEdge('E', 'C', 7);
// graph.addEdge('C', 'F', 8);

// console.log(graph.adjacencyList);