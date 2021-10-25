var snum = 6;
var colors = randcolor(snum);
var square = document.querySelectorAll(".square");
var pickedColor = pickColor();
var show = document.querySelector("#show");
var h1= document.querySelector("h1");
var message= document.querySelector("#mes");
var reset= document.querySelector("#reset");
var easy= document.querySelector("#easy");
var hard= document.querySelector("#hard");

show.textContent= pickedColor;

easy.addEventListener("click",function(){
    hard.classList.remove("selected")
    easy.classList.add("selected");
    message.textContent="";
    reset.textContent="NEW COLORS";
    snum=3;
    colors= randcolor(snum);
    pickedColor=pickColor();
    show.textContent= pickedColor;
    for(var i=0;i<square.length;i++){
        if(colors[i]){
            square[i].style.backgroundColor=colors[i];
        }
        else
            square[i].style.display= "none";
    }
    h1.style.backgroundColor="steelblue";

});

hard.addEventListener("click",function(){
    hard.classList.add("selected")
    easy.classList.remove("selected");
    message.textContent="";
    reset.textContent="NEW COLORS";
    snum=6;
    colors= randcolor(snum);
    pickedColor=pickColor();
    show.textContent= pickedColor;
    for(var i=0;i<square.length;i++){
            square[i].style.backgroundColor=colors[i];
            square[i].style.display= "block";
    }
    h1.style.backgroundColor="steelblue";

});

reset.addEventListener("click",function(){
    reset.textContent="NEW COLORS"; 
    message.textContent="";
    colors = randcolor(snum);
    pickedColor = pickColor();
    show.textContent= pickedColor;
    for(var i=0;i<square.length;i++){
        square[i].style.backgroundColor= colors[i];
    }
    h1.style.backgroundColor="steelblue";
});

for(var i=0;i<square.length;i++){
    square[i].style.backgroundColor= colors[i];   
    square[i].addEventListener("click",function(){
        var clickedColor = this.style.backgroundColor;
        if(clickedColor === pickedColor){
            change(pickedColor);
            message.textContent="Correct!!";
            h1.style.backgroundColor= clickedColor;
            reset.textContent= "PLAY AGAIN?";
        }  
        else{
            this.style.backgroundColor= "#232323";
            message.textContent="Try Again!";
        }
           
    });
}



function change(color){
    for(var i=0;i<square.length;i++){
        square[i].style.backgroundColor= color;
    }
}
function pickColor(){
    var ran = Math.floor(Math.random()*colors.length);
    return colors[ran];
}

function randcolor(num){
    var arr =[];
    for(var i=0;i<num;i++){
        arr.push(giverand());
    }
    return arr;
}

function giverand(){
    var r= Math.floor(Math.random()*256);
    var g= Math.floor(Math.random()*256);
    var b= Math.floor(Math.random()*256);
    return "rgb(" + r + ", " + g + ", "+ b + ")";

}