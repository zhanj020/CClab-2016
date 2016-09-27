document.addEventListener("DOMContentLoaded",function(){
	// console.log(13);

	var startDegree = 0;
	var degreeIncrement = 0.1;
	var timerWaitTime = 10;
	var parentDiv = document.getElementsByClassName("circle");
	var div1 = document.getElementById("cir1");
	var div2 = document.getElementById("cir2");
	var div3 = document.getElementById("cir3");
	// var div4 = document.getElementById("sd1");
	// var div5 = document.getElementById("sd2");
	// var div6 = document.getElementById("sd3");

	// div1.style.backgroundColor = "red";

console.log(parentDiv.length)
	// for (var i =0;i< parentDiv.length; i++){
	// 	parentDiv[i].style.backgroundColor="red";
	// }

//parentdiv is an array!!
// parentDiv[0].style.backgroundColor="red";
 
 var rotateDiv = function(){
 	parentDiv[0].style.transform = "rotate("+ startDegree +"deg)"; //put a number inside of a string
 	startDegree+= degreeIncrement;
 }

 // rotateDiv();

 window.setInterval(rotateDiv,timerWaitTime) //1000 is a second
})