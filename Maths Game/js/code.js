var playing = false;
var score;
var remainingTime;
var correctAnswer;

document.getElementById("startReset").onclick = function () {

    if (playing == true) {
        location.reload();
    }

    else {
        score = 0;
        playing = true;
        show("timeRemaining");
        document.getElementById("scoreValue").innerHTML = score;
        document.getElementById("startReset").innerHTML = "Reset Game";
        hide("gameOver");
        remainingTime = 60;
        startCountdown();
        generateQA();
    }
}
for(i=1; i<5; i++){
    document.getElementById("box"+i).onclick = function() {
        if(playing == true) {
            if(this.innerHTML == correctAnswer) {
                score++;
                document.getElementById("scoreValue").innerHTML = score;
                show("correct");
                document.getElementById("container").style.backgroundColor = "#79ff5e";
                setTimeout(function() {
                    hide("correct");
                    document.getElementById("container").style.backgroundColor = "dodgerblue";
                    generateQA();
                },1000)
            }
            else {
                show("wrong");
                document.getElementById("container").style.backgroundColor = "#ff5252";
                setTimeout(function() {
                    hide("wrong");
                    document.getElementById("container").style.backgroundColor = "dodgerblue";
                },1000)
            }
        }
    }
}


function startCountdown() {
    action = setInterval(function() {
        remainingTime--;
        document.getElementById("timeRemainingValue").innerHTML = remainingTime;
        if(remainingTime == 0) {
            stopCountdown();
            document.getElementById("gameOver").innerHTML = "Game Over!<br>Your Score is: " + score;
            show("gameOver");
            hide("timeRemaining");
            hide("correct");
            hide("wrong");
            playing = false;
            document.getElementById("startReset").innerHTML = "Start Again";
        }
    }, 1000);
}

function stopCountdown() {
    clearInterval(action);
    
}

function show(id) {
    document.getElementById(id).style.display = "block";
}

function hide(id) {
    document.getElementById(id).style.display = "none";
}

function generateQA() {
    var x = 1 + Math.round(Math.random()*9);
    var y = 1 + Math.round(Math.random()*9);
    correctAnswer = x*y;
    document.getElementById("question").innerHTML = x + "x" + y;
    var correctPosition = 1 + Math.round(Math.random()*3);
    document.getElementById("box"+correctPosition).innerHTML = correctAnswer;
    
    for(i=1; i<5; i++) {
        if(i != correctPosition) {
            var wrongAnswer; 
            var prevWrongAnswer;
            prevWrongAnswer = 0;
            do {
            wrongAnswer = (1 + Math.round(Math.random()*9))*(1 + Math.round(Math.random()*9));
                
            } while((prevWrongAnswer == wrongAnswer) || (wrongAnswer == correctAnswer))
                
            
            document.getElementById("box"+i).innerHTML = wrongAnswer;
            prevWrongAnswer = wrongAnswer;
            }

    }
}