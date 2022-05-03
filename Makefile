objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

%.o: %.cpp
	g++ -c $< -o $@ -std=c++1y

all: $(objects)
	g++ -o wm $^ -lX11

clean:
	rm -rf wm $(objects) 
