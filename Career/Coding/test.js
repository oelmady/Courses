const omar = {
    name : "Omar Elmady",
    age : 22,
    hobby : ['Draw', 'Blog', 'Code'],
    languages : { Native : 'English',
                  Learning : 'Arabic'},
    greeting : function() {
        console.log('Hey, salam!');
    }
}

let learning = 'learning';
console.log(learning.length);
omar[learning] = omar.hobby[2];

console.log(omar.languages.Native);
console.log(omar.hobby[1]);
console.log(omar.hobby.length);
console.log(omar);

function f () {
    console.log('F!');
    return 2;
  }
  function g () {
    console.log('G!');
    return 3;
  }

let x,y;
y = x = f()
y = [ f(), x = g() ]
x[f()] = g()
