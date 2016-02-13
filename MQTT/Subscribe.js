var mqtt    = require('mqtt');
var client  = mqtt.connect('mqtt://192.168.1.18');

client.on('connect', function () {
  client.subscribe('your_topic');
});

client.on('message', function (topic, message) { 
  	console.log(message.toString());
});
