class DisjointSet {
    constructor(vertices) {
        this.parent = {};
        vertices.forEach(vertex => this.parent[vertex] = vertex);
    }

    find(vertex) {
        while (this.parent[vertex] != vertex)
            vertex = this.parent[vertex];
        return vertex;
    }

    union(a, b) {
        let rootA = this.find(a);
        let rootB = this.find(b);

        if (rootA == rootB)
            return;

        if (rootA < rootB) {
            if (this.parent[b] != b)
                this.union(this.parent[b], a);
            this.parent[b] = this.parent[a];
        } else {
            if (this.parent[a] != a)
                this.union(this.parent[a], b);
            this.parent[a] = this.parent[b];
        }
    }

    isConnected(a, b) {
        return this.find(a) == this.find(b);
    }
}

module.exports = DisjointSet;

// let unionFind = new DisjointSet(["A", "B", "C", "D", "E"]);
// unionFind.union('A', 'B');
// unionFind.union('A', 'C');
// unionFind.union('C', 'D');
// console.log(unionFind.parent);
// console.log(unionFind.isConnected('B', 'E'));
// console.log(unionFind.isConnected('B', 'D'));
