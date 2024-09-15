// Clone Graph - Basic implementation, missing cycle and disconnected component tests
function cloneGraph(node) {
    if (!node) return null;

    let map = new Map();

    function dfs(n) {
        if (map.has(n)) return map.get(n);
        
        let clone = new Node(n.val);
        map.set(n, clone);

        for (let neighbor of n.neighbors) {
            clone.neighbors.push(dfs(neighbor));
        }

        return clone;
    }

    return dfs(node); // Add tests for graphs with cycles and disconnected components
}

// Node class definition (for reference)
function Node(val, neighbors) {
    this.val = val;
    this.neighbors = neighbors || [];
}
