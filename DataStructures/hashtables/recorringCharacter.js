

const recorring = (array) => {
    let occurred = {};

    for (let i = 0; i < array.length; i++) {
        if(occurred[array[i]]) {
            return array[i];
        }
        else {
            occurred[array[i]] = true;
        }
    }
}

console.log(recorring([2,5,1,2,3,5,1,2,4]));
console.log(recorring([2,1,1,2,3,5,1,2,4]));
console.log(recorring([2,3,4,5]));