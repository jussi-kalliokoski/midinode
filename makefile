all: configure build install test

configure:
	node-waf configure

build:
	node-waf build

install:
	node-waf install

test:
	node tests/simple.js
