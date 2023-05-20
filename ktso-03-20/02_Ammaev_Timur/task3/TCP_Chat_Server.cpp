#include <iostream>
#include "include/EN_TCP_Server.h"
#include <fstream>

class MyServer : public EN::EN_TCP_Server
{
public:
	MyServer()
	{
		//IpAddress = "192.168.1.69"; Default set to localhost
		// Port = <put int here> to set port. Default port is 1111
	}

	void OnClientConnected(int ClientID)
	{
		std::cout << "Client Connected! id: " << ClientID << std::endl;
		EN::TCP_Send(ClientSockets[ClientID], "Welcome. You are connected to server.");
	}

	void ClientMessageHandler(std::string message, int ClientID)
	{
		// Important. This function is run in a separate thread. 
		// If you want to write data to class variables, you should use mutexes or other algorithms for thread-safe code.
		std::cout << message << std::endl;

		system((message + " >> .tmp.txt").c_str());
		std::ifstream tmp_file(".tmp.txt");

		std::string msg;
		while(getline(tmp_file, msg))
		{
			EN::TCP_Send(ClientSockets[ClientID], msg);
		}
		EN::TCP_Send(ClientSockets[ClientID], "====Command finished====");
		tmp_file.close();
		system("rm .tmp.txt");
	}

	void OnClientDisconnect(int ClientID)
	{
		std::cout << "Client disconnected! ID: " << ClientID << std::endl;
	}
};


int main()
{
	MyServer A;

	std::thread th([&A]() { A.Run(); });
	th.detach();

	std::string message;

	while (true)
	{
		getline(std::cin, message);

		if (message == "stop()")
		{
			std::cout << "Server has been stopped" << std::endl;
			A.Shutdown();
			break;
		}
	}
}
