var myIndex = 0;
carousel();

function carousel() {
    var i;
    var x = document.getElementsByClassName("slides1");
    for (i = 0; i < x.length; i++) {
       x[i].style.display = "none";
    }
    myIndex++;
    if (myIndex > x.length) {myIndex = 1}
    x[myIndex-1].style.display = "block";
    setTimeout(carousel, 2000);
}


var myIndex2 = 0;
carouse2();

function carouse2() {
    var i;
    var x = document.getElementsByClassName("slides2");
    for (i = 0; i < x.length; i++) {
       x[i].style.display = "none";
    }
    myIndex2++;
    if (myIndex2 > x.length) {myIndex2 = 1}
    x[myIndex2-1].style.display = "block";
    setTimeout(carouse2, 2000);
}