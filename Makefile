GO15VENDOREXPERIMENT=1

all: install

gx:
	go get github.com/whyrusleeping/gx
	go get github.com/whyrusleeping/gx-go

dep: gx
	gx install

test: 
	go test -race -cpu=5 -v

