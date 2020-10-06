<?php
    // Bubble sort algorithm using php

    function bubbleSort($numbers) {
        // nested looping to compare each number
        for ($x = 0; $x < count($numbers)-1; $x++) {
            for ($y = 0; $y < count($numbers)-$x-1; $y++) {
                // comparing a number with the number after
                if ($numbers[$y] > $numbers[$y+1]) {
                    // swapping the numbers
                    $temp = $numbers[$y];
                    $numbers[$y] = $numbers[$y+1];
                    $numbers[$y+1] = $temp;
                }
            }
        }

        // defining and appending the results
        $result = '';
        foreach ($numbers as $number) {
            $result = $result.$number.' ';
        }
        return $result;
    }

    // testing and showing the result
    $numbers = [5, 6, 3, 2, 7, 9, 1, 4, 8];
    echo bubbleSort($numbers);
?>