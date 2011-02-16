all: configure build install

configure:
	node-waf configure

build:
	node-waf build

install:
	node-waf install
