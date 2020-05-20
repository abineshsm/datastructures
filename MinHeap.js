class PriorityQueue {
    constructor() {
        this.heap = [null];
    }

    add(priority, data) {
        let index = this.heap.length;
        let element = new this.Element(priority, data);
        this.heap[index] = element;
        if (index > 1) {
            // heapify up
            while (Math.floor(index / 2) >= 1 && this.heap[index].priority < this.heap[Math.floor(index / 2)].priority) {
                let parent = Math.floor(index / 2);
                [this.heap[index], this.heap[parent]] = [this.heap[parent], this.heap[index]];
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
            return this.heap.pop()
        else {
            let item = this.heap[1];
            this.heap[1] = this.heap.pop();
            this.minHeapify(1);
            return item;
        }
    }

    minHeapify(parent) {
        let len = this.heap.length;
        let left = 2 * parent;
        let right = 2 * parent + 1;
        let smallest = parent;
        if (left < len && this.heap[parent].priority > this.heap[left].priority)
            smallest = left;
        if (right < len && this.heap[smallest].priority > this.heap[right].priority)
            smallest = right;
        if (parent != smallest) {
            [this.heap[parent], this.heap[smallest]] = [this.heap[smallest], this.heap[parent]];
            this.minHeapify(smallest);
        }
    }

    isEmpty(){
        return this.heap.length == 1 ? true : false;
    }
}

PriorityQueue.prototype.Element = class {
    constructor(priority, data) {
        this.priority = priority;
        this.data = data;
    }
};

module.exports = PriorityQueue;

// let pq = new PriorityQueue();
// pq.add(5, 'five');
// pq.add(2, 'two');
// pq.add(10, 'ten');
// pq.add(1, 'one');
// console.log(pq.peek());
// console.log(pq.poll());
// console.log(pq.poll());