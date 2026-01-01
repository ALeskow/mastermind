let colors=6;
let spaces=4;
let max_attempts=10;

//generates random numbers between min and max-1
function randint(min, max) {
    let r = Math.floor(Math.random() * (max - min + 1)) + min;
    if (r == max) {
        r = max - 1;
    }
    return r;
}
 
//uses randint and generates a password
function gen_password(colors, spaces){
    let password=[];
    for (let i=0; i < spaces; i++){
        let r = randint(0, colors);
        password.push(r);
    }
    return password;
}

let password = gen_password(colors, spaces);



