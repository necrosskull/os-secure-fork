all: bin/libEasyNetwork.a TCP_Chat_Client.cpp TCP_Chat_Server.cpp
	mkdir -p build
	g++ TCP_Chat_Client.cpp bin/libEasyNetwork.a  -pthread -o build/client.sh 
	g++ TCP_Chat_Server.cpp bin/libEasyNetwork.a  -pthread -o build/server.sh 

clean:
	rm -rf build