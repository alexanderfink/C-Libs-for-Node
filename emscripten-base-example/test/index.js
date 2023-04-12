const cppLib = require('../build.emscripten/client');

cppLib().then(instance => {
    console.log(instance.cppFunction(5, 10, 2)) 
    console.log('TEST');
});