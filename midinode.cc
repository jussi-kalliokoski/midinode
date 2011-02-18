/*

MidiNode.cc

A NodeJS module for access to native MIDI drivers.

*/
#include <v8.h>
#include <ev.h>
#include <portmidi.h>

#define SET_METHOD(obj, name, callback)						\
	obj->Set(	v8::String::NewSymbol(name),				\
			v8::FunctionTemplate::New(callback)->GetFunction())

#define SET_VALUE(obj, name, value, type)					\
	obj->Set(	v8::String::NewSymbol(name),				\
			v8::type::New(value))

#define MIDI_DEVICE_INPUT	0
#define MIDI_DEVICE_OUTPUT	1

v8::Handle<v8::Object> midiDevice(int id);

v8::Handle<v8::Value> getDevices(const v8::Arguments& args);
v8::Handle<v8::Value> getDefaultOutput(const v8::Arguments& args);
v8::Handle<v8::Value> getDefaultInput(const v8::Arguments& args);

extern "C" void
init (v8::Handle<v8::Object> target)
{
	v8::HandleScope scope;
	SET_METHOD(target, "getDevices", getDevices);
	SET_METHOD(target, "getDefaultOutput", getDefaultOutput);
	SET_METHOD(target, "getDefaultInput", getDefaultInput);
}

v8::Handle<v8::Value> getDevices(const v8::Arguments& args){
	int devCount = Pm_CountDevices();
	v8::Handle<v8::Array> devices = v8::Array::New(devCount);
	int i;
	for (i=0; i<devCount; i++){
		devices->Set(i, midiDevice(i));
	}
	return devices;
}

v8::Handle<v8::Value> getDefaultOutput(const v8::Arguments& args){
	return midiDevice(Pm_GetDefaultOutputDeviceID());
}

v8::Handle<v8::Value> getDefaultInput(const v8::Arguments& args){
	return midiDevice(Pm_GetDefaultInputDeviceID());
}

v8::Handle<v8::Object> midiDevice(int id){
	const PmDeviceInfo* devInfo = Pm_GetDeviceInfo(id);
	v8::Handle<v8::Object> devObj = v8::Object::New();
	SET_VALUE(devObj, "name", devInfo->name, String);
	SET_VALUE(devObj, "id", id, Integer);
	if (devInfo->input){
		SET_VALUE(devObj, "type", "input", String);
	} else if (devInfo->output){
		SET_VALUE(devObj, "type", "output", String);
	}
	return devObj;
}
