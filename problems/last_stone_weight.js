const PriorityQueue = require('../heap');

var lastStoneWeight = function (stones) {
    let pq = new PriorityQueue(stones);
    while (pq.heap.length > 2) {
        let smash = pq.poll() - pq.poll();
        if (smash != 0) {
            pq.add(smash);
        }
    }
    return pq.heap.pop();
};

console.log(lastStoneWeight([1, 3]));