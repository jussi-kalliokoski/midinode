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

v8::Handle<v8::Value> getDevices(const v8::Arguments& args);

extern "C" void
init (v8::Handle<v8::Object> target)
{
	v8::HandleScope scope;
	SET_METHOD(target, "getDevices", getDevices);
}

v8::Handle<v8::Value> getDevices(const v8::Arguments& args){
	return v8::Integer::New(16);
}
