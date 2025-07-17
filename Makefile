CXX = g++
CXXFLAGS = -std=c++17 -fPIC -O2 -I./hnswlib -pthread
SRC = bindings.cpp
OUT = libhnsw.a
HEADERS = hnsw_c.h

.PHONY: all clean

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o bindings.o
	ar rcs $(OUT) bindings.o

install-headers:
	cp $(HEADERS) /usr/local/include/

clean:
	rm -f bindings.o $(OUT)
