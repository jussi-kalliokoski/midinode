var MidiNode = require('midinode');
console.log(MidiNode.getDevices());
var input = MidiNode.getDefaultInput();
var listener = input.listen(function(e){
	console.log(e);
});
console.log(listener);
console.log(listener());
