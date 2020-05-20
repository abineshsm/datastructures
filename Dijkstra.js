const PriorityQueue = require('./MinHeap');

class EdgeWeightedDirectedGraph {
    constructor() {
        this.adjacencyList = {};
    }

    addVertex(vertex) {
        this.adjacencyList[vertex] = {};
    }

    addDirectedEdge(vertex1, vertex2, weight) {
        !this.adjacencyList.hasOwnProperty(vertex1) ? this.addVertex(vertex1) : false;
        !this.adjacencyList.hasOwnProperty(vertex2) ? this.addVertex(vertex2) : false;
        this.adjacencyList[vertex1][vertex2] = weight;
    }

    dijkstra(startVertex) {
        let distance = { [startVertex]: 0 };
        Object.keys(this.adjacencyList).forEach(element => {
            if (element != startVertex)
                distance[element] = Infinity;
        });


        let pq = new PriorityQueue();
        pq.add(0, startVertex);

        while(!pq.isEmpty()){
            let current = pq.poll()['data'];
            for(let [vertex, weight] of Object.entries(this.adjacencyList[current])){
                let alt = distance[current] + weight;
                if(alt < distance[vertex]){
                    distance[vertex] = alt;
                    pq.add(alt, vertex);
                }
            }
        }

        return distance;
    }
}

let g = new EdgeWeightedDirectedGraph();
g.addDirectedEdge("A", "C", 100);
g.addDirectedEdge("A", "B", 3);
g.addDirectedEdge("A", "D", 4);
g.addDirectedEdge("D", "C", 3);
g.addDirectedEdge("D", "E", 8);
g.addDirectedEdge("E", "F", 10);
g.addDirectedEdge("B", "G", 9);
g.addDirectedEdge("E", "G", 50);

console.log(g.dijkstra('A'));
