const addon = require('../build/Release/binding');

console.log('Calculation from C++', addon.addition(5, 3));