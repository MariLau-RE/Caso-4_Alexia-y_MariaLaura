# docker run -it --rm -v C:\dev\cursostec\genetic:/home gcc bash
all: client
	g++ -osocketWin socketWin.o -lws2_32

client:
	g++ -c socketWin.cpp

# docker run -it --rm --net host -v C:\dev\cursostec\socketclient_c:/home gcc bash