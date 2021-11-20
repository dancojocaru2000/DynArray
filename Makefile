CXX?=g++

.PHONY: debug run clean

example: obj/example.o
	${CXX} $^ -o $@

run: example
	./example

debug:
	COMPILE_FLAGS="-D DEBUG" make -B example

obj:
	@if [ ! -d obj ]; then mkdir obj; fi

obj/%.o: %.cpp | obj
	${CXX} ${COMPILE_FLAGS} -c $^ -o $@

clean:
	@if [ -d obj ]; then echo rm -r obj; rm -r obj; fi
	@if [ -f example ]; then echo rm example; rm example; fi
