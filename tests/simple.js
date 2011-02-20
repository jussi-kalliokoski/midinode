var MidiNode = require('midinode');
console.log(MidiNode.getDevices());
var input = MidiNode.getDefaultInput();
input.listen(function(e){
	console.log(e);
});
