var mqtt    = require('mqtt');
var client  = mqtt.connect('mqtt://192.168.1.18');
client.on('connect', function() {
  setInterval(function() {
    client.publish('you_topic', 'demo');
  }, 3000);
});
