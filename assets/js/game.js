var colors=6;
var spaces=4;
var max_attempts=10;

//generates random numbers between min and max-1
function randint(min, max) {
    let r = Math.floor(Math.random() * (max - min + 1)) + min;
    if (r == max) {
        r = max - 1;
    }
    return r;
}
 
//uses randint and generates a password
function gen_password(col, sps){
    let numbers=[];
    for (let i=0; i < sps; i++){
        let r = randint(0, col);
        numbers.push(r);
    }
    return numbers;
}

let password = gen_password(colors, spaces);



