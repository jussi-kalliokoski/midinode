all: configure build compile install test

configure:
	node-waf configure

build:
	node-waf build

compile:
	g++ midinode.cc -fPIC -shared -o midinode.node -l v8 -l portmidi
	mv midinode.node build/default/

install:
	node-waf install

test:
	node tests/simple.js

love:
	echo "Sure, but let's compile it first!"
