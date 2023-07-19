class LRUCache {
  private readonly max_size: number;
  private hash: Map<number, number>;

  constructor(capacity: number) {
    this.max_size = capacity;
    this.hash = new Map<number, number>();
  }

  get(key: number): number {
    const val = this.hash.get(key);

    if (val !== undefined) {
      this.hash.delete(key);
      this.hash.set(key, val);
      return val;
    }

    return -1;
  }

  put(key: number, value: number): void {
    this.hash.delete(key);
    this.hash.set(key, value);

    if (this.hash.size > this.max_size) {
      const firstKey = this.hash.keys().next().value;
      this.hash.delete(firstKey);
    }
  }
}

const lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4