all: configure build install test

configure:
	node-waf configure

build:
	node-waf build
	g++ midinode.cc -fPIC -shared -o build/default/midinode.node -l v8 -l portmidi

install:
	node-waf install

test:
	node tests/simple.js
