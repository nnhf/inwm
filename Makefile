objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

%.o: %.cpp
	g++ -c $< -o $@

all: $(objects)
	g++ -o wm $^ -lX11

clean:
	rm -rf wm $(objects) 
