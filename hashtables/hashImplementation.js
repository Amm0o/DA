class HashTable  {
    constructor(size) {
        this.data = new Array(size);
    }

    _hash(key) {
        let hash = 0;
        for (let i = 0; i < key.length; i++) {
            hash = (hash + key.charCodeAt(i) * i) % this.data.length; // the hash will be within the length of the array so it can become a key
        }
        return hash;
    }

    set(key, value) {
        let address = this._hash(key);
        if(!this.data[address]) {
            this.data[address] = [];
        }
        this.data[address].push([key,value])
        return this.data;
    } 

    get(key) {
        let address = this._hash(key);
        const bucket = this.data[address];
        console.log(bucket);
        if(bucket) {
            for(let i = 0; i , bucket.length; i++) {
                if (bucket[i][0] === key) {
                    return bucket[i][1];
                }
            } 
        }
        return undefined; 
    }

    keys() {
        const keysArray = [];

        for(let i = 0; i < this.data.length; i++) {
            if(this.data[i]) {
                keysArray.push(this.data[i][0][0]);
            }
        }

        return keysArray;
    }
}


const myHashTable = new HashTable(50);

myHashTable.set('grapes', 1000);
myHashTable.set('apples', 1000);
myHashTable.set('oranges', 1213000);
myHashTable.set('Banana', 1);
// console.log(myHashTable.get('grapes'));

console.log(myHashTable.keys());
// console.log(myHashTable.get('grapess'));