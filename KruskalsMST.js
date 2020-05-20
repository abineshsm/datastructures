const EdgeWeightedGraph = require('./EdgeWeightedGraph');
const PriorityQueue = require('./MinHeap');
const DisjointSet = require('./DisjointSet');

// Minimum Spanning Tree - Kruskal's algorithm 
function kruskalsMST(graph){
    let mst = new EdgeWeightedGraph();

    let pq = new PriorityQueue();
    for(let [vertex1, edges] of Object.entries(graph)){
        for(let [vertex2, weight] of Object.entries(edges)){
            pq.add(weight, {vertex1, vertex2});
        }
    }

    let uf = new DisjointSet(Object.keys(graph));
    
    while(!pq.isEmpty()){
        let {priority, data} = pq.poll();
        let {vertex1, vertex2} = data;
        if(!uf.isConnected(vertex1, vertex2)){
            mst.addEdge(vertex1, vertex2, priority);
            uf.union(vertex1, vertex2);
        }       
    }
    return mst;
}

let graph = new EdgeWeightedGraph();
graph.addEdge('A', 'B', 1);
graph.addEdge('A', 'D', 2);
graph.addEdge('A', 'E', 3);
graph.addEdge('B', 'C', 4);
graph.addEdge('D', 'E', 5);
graph.addEdge('E', 'F', 6);
graph.addEdge('E', 'C', 7);
graph.addEdge('C', 'F', 8);

// console.log(graph.adjacencyList);

console.log(kruskalsMST(graph.adjacencyList).adjacencyList);

