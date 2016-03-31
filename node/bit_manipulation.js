// http://stackoverflow.com/questions/9939760/how-do-i-convert-an-integer-to-binary-in-javascript
function dec2bin(dec){
    var pad = "00000000";
    var result = (dec >>> 0).toString(2);
    return pad.substring(result.length) + result;    
}

function rightPropagate(x) {
    return x | (x - 1);
}

function modPower2(val, pow2) {
    return val & (pow2 - 1);
}

function isPowerOf2(val) {
    var rightmostBit = val & ~(val - 1);
    var remainingBits = ~rightmostBit & val;
    rightmostBit = remainingBits & ~(remainingBits - 1);
    return rightmostBit === 0;
}

//console.log(dec2bin(rightPropagate(0b01010000)));
//console.log(dec2bin(rightPropagate(0b10000000)));
//console.log(modPower2(77, 2));
console.log(isPowerOf2(8));