#include <avr/pgmspace.h>
const char FUNCTIONS[] PROGMEM = R"=====(

setInterval(
    function() {
        getJson();
    }, 1000);

function getJson() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            var obj = JSON.parse(xhttp.responseText);
            document.getElementById('AI').innerHTML = obj.AI_read;
            document.getElementById('AO').innerHTML = obj.AO_read;
            document.getElementById('DI').innerHTML = obj.DI_read;
            document.getElementById('DO').innerHTML = obj.DO_read;
        }
    };
    xhttp.open('GET', '/ConfigJSON', true);
    xhttp.send();
}

function button1() {
    var xhttp = new XMLHttpRequest();

    document.getElementById('div1').innerHTML =
        "<p> <input class='form-control w-100' disabled size='40' type='number' step='0.1' title='Anolog Input' placeholder='[  not write ]' name='num' id='num' style='height:50px; font-size: 150% '></p>";
    document.getElementById('div2').innerHTML =
        "<p> <input class='btn btn-primary rounded w-100' size='10' type='submit' value='Установить' style='height:50px; width: 650px; font-size: 150% '> </p>";

    document.querySelector("#btn1").style.backgroundColor = "#FFFFFF";
    document.querySelector("#btn1").style.color = "#000000";
    document.querySelector("#btn1").style.color = "#000000";
    document.querySelector("#btn2").style.backgroundColor = "#000000";
    document.querySelector("#btn2").style.color = "#FFFFFF";
    document.querySelector("#btn3").style.backgroundColor = "#000000";
    document.querySelector("#btn3").style.color = "#FFFFFF";
    document.querySelector("#btn4").style.backgroundColor = "#000000";
    document.querySelector("#btn4").style.color = "#FFFFFF";

    xhttp.open('GET', '/Button_Uout', true);
    xhttp.send();
}

function button2() {
    var xhttp = new XMLHttpRequest();

    document.getElementById('div1').innerHTML =
        "<p> <input class='form-control w-100' min='0' max='9999' size='40' type='number' step='1' title='Analog Output' placeholder='[ 0 - 9999, шаг 1 ]' name='num' id='num' style='height:50px; font-size: 150% '> </p>"
    document.getElementById('div2').innerHTML =
        "<p> <input class='btn btn-primary rounded w-100' size='10' type='submit' value='Установить' style='height:50px; width: 650px; font-size: 150% '> </p> </p>";

    document.querySelector("#btn1").style.backgroundColor = "#000000";
    document.querySelector("#btn1").style.color = "#FFFFFF";
    document.querySelector("#btn2").style.backgroundColor = "#FFFFFF";
    document.querySelector("#btn2").style.color = "#000000";
    document.querySelector("#btn3").style.backgroundColor = "#000000";
    document.querySelector("#btn3").style.color = "#FFFFFF";
    document.querySelector("#btn4").style.backgroundColor = "#000000";
    document.querySelector("#btn4").style.color = "#FFFFFF";

    xhttp.open('GET', '/Button_Iout', true);
    xhttp.send();
}

function button3() {
    var xhttp = new XMLHttpRequest();

    document.getElementById('div1').innerHTML =
        "<p> <input class='form-control w-100' disabled size='40' type='number' step='0.01' title='Discrete Input' placeholder='[ not write ]' name='num' id='num' style='height:50px; font-size: 150% '></p>"
    document.getElementById('div2').innerHTML =
        "<p> <input class='btn btn-primary rounded w-100' size='10' type='submit' value='Установить' style='height:50px; width: 650px; font-size: 150% '> </p>";
    document.querySelector("#btn1").style.backgroundColor = "#000000";
    document.querySelector("#btn1").style.color = "#FFFFFF";
    document.querySelector("#btn2").style.backgroundColor = "#000000";
    document.querySelector("#btn2").style.color = "#FFFFFF";
    document.querySelector("#btn3").style.backgroundColor = "#FFFFFF";
    document.querySelector("#btn3").style.color = "#000000";
    document.querySelector("#btn4").style.backgroundColor = "#000000";
    document.querySelector("#btn4").style.color = "#FFFFFF";

    xhttp.open('GET', '/Button_Upp', true);
    xhttp.send();
}

function button4() {
    var xhttp = new XMLHttpRequest();

    document.getElementById('div1').innerHTML = 
        "<p> <input class='form-control w-100' min='0' max='1' size='40' type='number' step='0.01' title='Discrete Output' ' placeholder='[0 or 1]' name='num' id='num' style='height:50px; font-size: 150% '></p>"
    document.getElementById('div2').innerHTML =
        "<p> <input class='btn btn-primary rounded w-100' size='10' type='submit' value='Установить' style='height:50px; width: 650px; font-size: 150% '> </p>";
    document.querySelector("#btn1").style.backgroundColor = "#000000";
    document.querySelector("#btn1").style.color = "#FFFFFF";
    document.querySelector("#btn2").style.backgroundColor = "#000000";
    document.querySelector("#btn2").style.color = "#FFFFFF";
    document.querySelector("#btn3").style.backgroundColor = "#000000";
    document.querySelector("#btn3").style.color = "#FFFFFF";
    document.querySelector("#btn4").style.backgroundColor = "#FFFFFF";
    document.querySelector("#btn4").style.color = "#000000";

    xhttp.open('GET', '/Button_Usp', true);
    xhttp.send();
}
)=====";