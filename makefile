.PHONY: build
build:
	mkdir build
	cmake -B build -S cmake
	${MAKE} -C build VERBOSE=1

.PHONY: googletest
googletest:
	rm -rf build-googletest
	mkdir build-googletest
	cmake -B build-googletest -S googletest
	${MAKE} -C build-googletest

.PHONY: runtest
runtest:
	./bin/unit-test-app

.PHONY: clean
clean:
	rm -rf build
	rm -rf bin
	rm -rf lib
