class PriorityQueue {
    constructor(arr) {
        if (arr) {
            this.heap = [null, ...arr];
            this.buildMaxHeap();
        }
        else {
            this.heap = [null];
        }
    }

    maxHeapify(parent) {
        let len = this.heap.length;
        let leftChild = 2 * parent;
        let rightChild = 2 * parent + 1;
        let largest = parent;
        if (leftChild < len && this.heap[leftChild] > this.heap[parent])
            largest = leftChild;
        else
            largest = parent;
        if (rightChild < len && this.heap[rightChild] > this.heap[largest])
            largest = rightChild;
        if (largest != parent) {
            [this.heap[parent], this.heap[largest]] = [this.heap[largest], this.heap[parent]];
            this.maxHeapify(largest);
        }
    }

    buildMaxHeap() {
        let n = Math.floor(this.heap.length / 2);
        for (let i = n; i >= 1; i--)
            this.maxHeapify(i);
    }

    add(data) {
        let index = this.heap.length;
        if (index == 1)
            this.heap[1] = data;
        else {
            this.heap[index] = data;
            // heapify up 
            while (Math.floor(index / 2) >= 1 && this.heap[Math.floor(index / 2)] < this.heap[index]) {
                let parent = Math.floor(index / 2);
                [this.heap[parent], this.heap[index]] = [this.heap[index], this.heap[parent]];
                index = parent;
            }
        }
    }

    peek() {
        return this.heap[1] ? this.heap[1] : null;
    }

    poll() {
        if (this.heap.length == 1)
            return null;
        else if (this.heap.length == 2)
            return this.heap.pop();
        else {
            let item = this.heap[1];
            this.heap[1] = this.heap.pop();
            this.maxHeapify(1);
            return item;
        }
    }
}

module.exports = PriorityQueue;


