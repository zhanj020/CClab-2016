var x=0;
var y=0;
var address="";
var center;


function initMap() {
     var map = new google.maps.Map(document.getElementById('map'), {
        zoom: 8,
        center: {lat: 40.735507, lng: -73.993545}
     });

     // var myCenter = new google.maps.LatLng(x,y);

    map.addListener('click', function(e) {
    placeMarkerAndPanTo(e.latLng, map);
      alert(e.latlng);
    });

    $(document).keypress(function (e) {
    if (e.which == 13) 
    {
      x = $('#inpt_searchx').val();
      y = $('#inpt_searchy').val();
      myCenter = new google.maps.LatLng(x,y);
      // alert(x+" "+y);
      placeMarkerAndPanTo(myCenter, map);
    }
    });
}

function placeMarkerAndPanTo(latLng, map) {
        var marker = new google.maps.Marker({
          position: latLng,
          map: map
        });
        map.panTo(latLng);
      }


