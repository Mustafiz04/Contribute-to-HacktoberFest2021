  var startTime = new Date().getTime();
  var pstartTime = 0;

  var pendTime = 0;


  function appearShape() {

      var top = Math.random() * 400;
      var left = Math.random() * 500;
      var radius = Math.random() * 100;
      var color = Math.floor(Math.random() * 16777215).toString(16);
      document.getElementById("shape").style.display = "block";
      document.getElementById("shape").style.top = top + "px";
      document.getElementById("shape").style.left = left + "px";
      document.getElementById("shape").style.borderRadius = radius + "px";
      document.getElementById("shape").style.backgroundColor = "#" + color;

      startTime = new Date().getTime();

  }

  function delayAppear() {

      setTimeout(appearShape, Math.random() * 2000);
  }
  delayAppear();
  document.getElementById("shape").onclick = function() {

      var endTime = new Date().getTime();

      document.getElementById("shape").style.display = "none";
      var calTime = ((endTime - startTime) - (pendTime - pstartTime)) / 1000;
      pendTime = 0;
      pstartTime = 0;

      document.getElementById("timerTime").innerHTML = calTime + "s";


      delayAppear();

  }
  document.getElementById("restart").onclick = function() {
      startTime = new Date().getTime();
      delayAppear();
  }
  document.getElementById("pause").onclick = function() {
      pstartTime = new Date().getTime();
  }
  document.getElementById("play").onclick = function() {

      pendTime = new Date().getTime();
  }