var mqtt    = require('mqtt');
var client  = mqtt.connect('mqtt://192.168.1.18');
var a=0
client.on('connect', function() {
  setInterval(function() {
    client.publish('you_topic', a);
    a++;
  }, 3000);
});