<?php
    // Factorials function in php
    // please feel free to add or modify to make it better

    // defining the function
    function factorials($num) {
        if ($num == 1 || $num == 0) {
            return 1;
        } else {
            return $num * factorials($num-1);
        }
    }

    // testing the function
    echo factorials(5);
?>