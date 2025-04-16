#include "askIp.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

std::string stringInterface;
std::string ip;
std::string stringMask;
std::string stringGateway;
std::string stringDns;


void askIp() {

	//Hago una booleana que true sera idioma español y false idioma ingles, son los dos idiomas que voy a soportar en este programa
	bool lang;
	int keyLang;
	std::cout << "Press 1 to choose English as your system language" << std::endl;
	std::cout << "Presiona 2 para elegir el Español como el idioma de tu sistema" << std::endl << "Selection / Seleccion: ";
	std::cin >> keyLang;
	keyLang--;

	if (keyLang == 0)
	{
		lang = false;
	}
	else
	{
		lang = true;
	}
	//Ejecución del programa dependiendo del idioma false=ingles true=español
	if (lang == false)
	{
		system("netsh interface ipv4 show config | find \"the interface\"");

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Write down the interface that you want to change the ip: ";
		std::getline(std::cin, stringInterface);

		//Buscar IP libre solon funciona con redes 192.168.1 *Aun no se como solucionar para que funcione en cualquiera*
		int freeIp = -1;
		for (int ip = 1; ip < 256; ip++)
		{
			std::string formatIp = "192.168.1." + std::to_string(ip);
			std::string checkIp = "ping -n 1 -w 1000 " + formatIp + " > nul";
			std::cout << ip;
			int result = system(checkIp.c_str());

			if (result != 0) {
				freeIp = ip;
				break;
			}
		}

		while (true)
		{
			std::cout << std::endl << "Enter de IP direction: ";
			std::cin >> ip;

			std::string checkIp = "ping -n 1 -w 1000 " + ip + " > nul";

			int result = system(checkIp.c_str());
			char ipAutomatic;
			if (result != 0) {
				break;
			}
			else {
				std::cout << "This IP is in use, please choose a free one" << std::endl;
				std::cout << "If you don't know a free ip i suggest this one 192.168.1." << freeIp << " its free." << std::endl;
				std::cout << "You want to add it automatically (Y) or manualy (N)";
				std::cin >> ipAutomatic;
				if (ipAutomatic == 'Y' || ipAutomatic == 'y')
				{
					ip = "192.168.1." + std::to_string(freeIp);
					std::cout << "The ip " << ip << " has been asignet automatically.";
				}
			}
		}

		std::cout << std::endl << "Enter the submask direction: ";
		std::cin >> stringMask;

		std::cout << std::endl << "Enter the gateway: ";
		std::cin >> stringGateway;

		//std::cout << std::endl << "Enter the DNS: ";
		//std::cin >> stringDns;

		system(("netsh interface ipv4 set address name=\"" + stringInterface + "\" static " + ip + " " + stringMask + " " + stringGateway).c_str());
		//system(("netsh interface ipv4 set dns name = \"" + stringInterface + "\" static " + stringDns).c_str());
	}
	else
	{
		system("netsh interface ipv4 show config | find \"la interfaz\"");

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Escribe la interfaz que quieres cambiarle la ip: ";
		std::getline(std::cin, stringInterface);

		//Buscar IP libre solon funciona con redes 192.168.1 *Aun no se como solucionar para que funcione en cualquiera*
		int freeIp = -1;
		for (int ip = 1; ip < 256; ip++)
		{
			std::string formatIp = "192.168.1." + std::to_string(ip);
			std::string checkIp = "ping -n 1 -w 1000 " + formatIp + " > nul";
			std::cout << ip;
			int result = system(checkIp.c_str());

			if (result != 0) {
				freeIp = ip;
				break;
			}
		}

		while (true)
		{
			std::cout << std::endl << "Ingresa la direccion IP: ";
			std::cin >> ip;

			std::string checkIp = "ping -n 1 -w 1000 " + ip + " > nul";

			int result = system(checkIp.c_str());
			char ipAutomatic;
			if (result != 0) {
				break;
			}
			else {
				std::cout << "Esa ip esta en uso, elige otra que no este en uso" << std::endl;
				std::cout << "Sino sabes ninguna te sugiero la ip 192.168.1." << freeIp << " que esta libre." << std::endl;
				std::cout << "Quieres añadir la ip automaticamente (Y) o manualmente(N)";
				std::cin >> ipAutomatic;
				if (ipAutomatic == 'Y' || ipAutomatic == 'y')
				{
					ip = "192.168.1." + std::to_string(freeIp);
					std::cout << "La ip " << ip << " se a asignado automaticamente.";
				}
			}
		}

		std::cout << std::endl << "Ingresa la mascara de subred: ";
		std::cin >> stringMask;

		std::cout << std::endl << "Ingresa la puerta de enlace: ";
		std::cin >> stringGateway;

		//std::cout << std::endl << "Ingresa el DNS: ";
		//std::cin >> stringDns;

		system(("netsh interface ipv4 set address name=\"" + stringInterface + "\" static " + ip + " " + stringMask + " " + stringGateway).c_str());
		//system(("netsh interface ipv4 set dns name = \"" + stringInterface + "\" static " + stringDns).c_str());
	}
}