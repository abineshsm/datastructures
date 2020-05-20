class DirectedGraph{
    constructor(){
        this.adjList = {};
    }

    addVertex(v){
        this.adjList[v] = []
    }

    addDirectedEdge(v, w){
        !this.adjList.hasOwnProperty(v) ? this.addVertex(v) : false;
        !this.adjList.hasOwnProperty(w) ? this.addVertex(w) : false;
        this.adjList[v].push(w);
    }

    isConnected(v, w){
        return this.dfs(v, {}).hasOwnProperty(w);
    }

    dfs(v, visited){
        visited[v] = true;
        for(let vertex of Object.values(this.adjList[v])){
            if(!visited[vertex])
                this.dfs(vertex, visited);
        }

        return visited;
    }
}

let g = new DirectedGraph();
g.addVertex("E");
g.addDirectedEdge("A", "C");
g.addDirectedEdge("A", "B");
g.addDirectedEdge("A", "D");
g.addDirectedEdge("D", "C");
// g.addDirectedEdge("D", "E");
g.addDirectedEdge("E", "F");
g.addDirectedEdge("B", "G");
g.addDirectedEdge("E", "G");

// console.log(g.adjList);
// console.log(g.dfs('A', {}));

console.log(g.isConnected('A', 'E'));