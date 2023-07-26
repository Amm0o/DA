// implement an express server on port 3000

const express = require('express');
const app = express();

app.get('/', (req, res) => {
    res.send('Hello World!');
    });

app.listen(3000, () => {
    console.log('Example app listening on port 3000!');
    }   
);




// Path: test.js