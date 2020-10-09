// Bubble sort algorithm using javascript

function bubbleSort(numbers) {
    let x, y;
    // nested looping to compare each number
    for (x = 0; x < numbers.length-1; x++) {
        for (y = 0; y < numbers.length-x-1; y++) {
            // comparing a number with the number after
            if (numbers[y] > numbers[y+1]){
                // swapping the numbers
                [numbers[y], numbers[y+1]] = [numbers[y+1], numbers[y]];
            }
        }
    }
}

// testing the algorithm
let numbers = [6, 3, 4, 7, 5, 2, 9, 1, 8];
bubbleSort(numbers);
console.log(...numbers);