all:P1a.o P1b.o P1c.o P1d.o P1e.o P2a.o P2b.o P2c.o P2d.o P2e.o
	g++ -o P1a P1a.o
	g++ -o P1b P1b.o
	g++ -o P1c P1c.o
	g++ -o P1d P1d.o
	g++ -o P1e P1e.o
	g++ -o P2a P2a.o
	g++ -o P2b P2b.o
	g++ -o P2c P2c.o
	g++ -o P2d P2d.o
	g++ -o P2e P2e.o
	rm P1a.o
	rm P1b.o
	rm P1c.o
	rm P1d.o
	rm P1e.o
	rm P2a.o
	rm P2b.o
	rm P2c.o
	rm P2d.o
	rm P2e.o
P1a.o:P1a.cpp
	g++ -c P1a.cpp
P1b.o:P1b.cpp
	g++ -c P1b.cpp
P1c.o:P1c.cpp
	g++ -c P1c.cpp
P1d.o:P1d.cpp
	g++ -c P1d.cpp
P1e.o:P1e.cpp
	g++ -c P1e.cpp
P2a.o:P2a.cpp
	g++ -c P2a.cpp
P2b.o:P2b.cpp
	g++ -c P2b.cpp
P2c.o:P2c.cpp
	g++ -c P2c.cpp
P2d.o:P2d.cpp
	g++ -c P2d.cpp
P2e.o:P2e.cpp
	g++ -c P2e.cpp
