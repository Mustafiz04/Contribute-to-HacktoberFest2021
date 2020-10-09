// js function(s) to find factorial of a certain number
// feel free to modify or add functions that are more effective

// the function(s)
function factorial(num) {
    return num === 1 || num === 0 ? 1 : num * factorial(num-1);
}

// test result
console.log(factorial(5));