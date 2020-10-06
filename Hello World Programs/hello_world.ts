function sayHello(user: string): string {
    return `Hello, ${user}!`;
}

let user: string = "Bob";
let message = sayHello(user);
console.log(message);
