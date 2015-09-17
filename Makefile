all: install

godep:
	go get github.com/tools/godep

# saves/vendors third-party dependencies to Godeps/_workspace
# -r flag rewrites import paths to use the vendored path
# ./... performs operation on all packages in tree
vendor: godep
	godep save -r ./...

install: dep
	cd multiaddr && go install

test: udt
	go test -race -cpu=5 -v ./...

dep: udt
	cd multiaddr && go get ./...

UDTDIR=vendor/go-udtwrapper-v1.0.0
udt:
	cd $(UDTDIR)/udt4/src && make libudt.a
	cp $(UDTDIR)/udt4/src/libudt.a $(UDTDIR)/udt/
	# also need it in the top dir for running 'go test' 
	cp $(UDTDIR)/udt4/src/libudt.a .
	cp $(UDTDIR)/udt4/src/libudt.a multiaddr/
