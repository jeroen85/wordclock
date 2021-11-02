const char webpagina[] PROGMEM = R"=====(
<!DOCTYPE html PUBLIC '-//WAPFORUM//DTD XHTML Mobile 1.0//EN' 'http://www.wapforum.org/DTD/xhtml-mobile10.dtd'>
<html xmlns='http://www.w3.org/1999/xhtml'>
<head>
 <title>Woordklok</title>
    <style>
      body { background-color: #cccccc; font-family: Arial; Color: #000088; }
    </style>
  <script src='/iro.min.js'></script>
</head>
<body>
    <h1>Woordklok</h1>
    <h2>Huidige gegevens</h2>
      <table border='0'>
    <tr><td><b>Tijd:</b></td><td>%tijd%</td></tr>
    <tr><td><b>Datum:</b></td><td>%datum%</td></tr>
    <tr><td><b>Weergavemodus:</b></td><td><span id='timemodus'>%modus%</span> (<a href='#' onclick='change("timemodus");return false;'>Verander</a>)</td></tr>
    <tr><td><b>Kleur:</b></td><td><span id='colormodus'>%kleurrotatie%</span> (<a href='#' onclick='change("colormodus");return false;'>Verander</a>)</td></tr>
    <tr><td><b>Brightness:</b></td><td><span id='brightness'>%brightness%</span><input id='Bvalue' type='range' min='0' max='255' step='5' value='%brightness%' style='display: %showslider%;'></td></tr>
    <tr><td><b>Auto Brightness:</b></td><td><span id='AB'>%autobrightness%</span> (<a href='#' onclick='change("AB");return false;'>Verander</a>)</td></tr>
    <tr><td><a href='/restart'>Restart</a></td><td></td></tr>
    </table>
  <h2>Diversen</h2>
  <p><a href='#' onclick='load("demo");return false;'>Demo</a></p>
  <p><a href='#' onclick='load("donja");return false;'>Donja</a></p>
  <p><a href='#' onclick='load("arthur");return false;'>Arthur</a></p>
  <h2>Kleur</h2>
        <p>
        <a href='#' onclick='CP.color.hexString = "#ffffff";return false;'>Wit</a>
<div id="colorpick"></div></p>
<script>
var CP = new iro.ColorPicker("#colorpick", {
  width: 320,
  height: 320,
  color: "#%kleur_hex%",
  markerRadius: 8,
  padding: 4,
  sliderMargin: 24,
  borderWidth: 2,
  borderColor: "#000",
  });

CP.on("color:change", onColorChange); 
var slider = document.getElementById("Bvalue");
var output = document.getElementById("brightness");

slider.oninput = function() {
  output.innerHTML = this.value;
} 
slider.onchange = function() {
  load("brightness?B="+ this.value);
}

function onColorChange(color) {
  var colorhex = color.hexString.substring(1);
  if (colorhex.length==3){colorhex=colorhex[0]+colorhex[0]+colorhex[1]+colorhex[1]+colorhex[2]+colorhex[2]};
  update(colorhex);
}

function update(jscolor) {
  var request  = new XMLHttpRequest(  );
  var params = encodeURI("c="+jscolor);
  request.open("GET", "color?" + params);
  request.send("");
}
function load(url) {
  var request  = new XMLHttpRequest(  );
  request.open("GET", url);
  request.send("");
}

function change(what) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById(what).innerHTML = this.responseText;

      if(what == "AB") {
        var slider = document.getElementById("Bvalue");
        if(this.responseText == "Aan") {
          slider.style.display = "none";    
        } else{
          slider.style.display = "inline";  
        }
      }
      
    }
  };
  xhttp.open("GET", what, true);
  xhttp.send();
}

setInterval(function() {
  getData();
}, 2000); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("brightness").innerHTML = this.responseText;
      document.getElementById("Bvalue").value = this.responseText;
    }
  };
  xhttp.open("GET", "readBrightness", true);
  xhttp.send();
}

</script> 

</body>
</html>
)=====";
