#include <iostream>
#include "include/EN_TCP_Client.h"


class MyClient : public EN::EN_TCP_Client
{
public:
	MyClient(){}

	// A function to be defined by the user. It is used for logic after connection
	void AfterConnect() {}

	// A function to be defined by the user. It is used to process incoming messages from the server
	void ServerMessageHandler(std::string message)
	{
		std::cout << message << std::endl;
	}

	// A function to be defined by the user. Performed before disconnected from the server
	void BeforeDisconnect() {}
};



int main()
{
	MyClient A;

	if (A.Connect() == false)
	{
		std::cout << "Failed to connect" << std::endl;
		return 0;
	}

	A.Run();

	std::string message;

	while (true)
	{
		getline(std::cin, message);

		if (message == "exit()")
		{
			std::cout << "Exit from server" << std::endl;
			break;
		}

		if (A.IsConnected())
			A.SendToServer(message);

		else 
			break;
	}

	A.Disconnect();

	
	return 0;
}
