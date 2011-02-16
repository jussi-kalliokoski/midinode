/*

MidiNode.cc

A NodeJS module for access to native MIDI drivers.

*/
#include <v8.h>

using namespace v8;

extern "C" void
init (Handle<Object> target)
{
	HandleScope scope;
	target->Set(String::New("version"), String::New("0.0.1"));
}
