#include "const.h"
#include "askIp.h"
#include <iostream>
#include <string>
#include <sstream>
 
std::string stringInterface;
std::string stringIp;
std::string stringMask;
std::string stringGateway;
std::string stringDns;


void askIp() {

	system("netsh interface ipv4 show config | find \"la interfaz\"");

	std::cout << std::endl << "Escribe la interfaz que quieres cambiarle la ip: ";
	std::getline(std::cin, stringInterface);

	std::cout << std::endl << "Ingresa la direccion IP: ";
	std::cin >> stringIp;

	std::cout << std::endl << "Ingresa la mascara de subred: ";
	std::cin >> stringMask;

	std::cout << std::endl << "Ingresa la puerta de enlace: ";
	std::cin >> stringGateway;

	std::cout << std::endl << "Ingresa el primer dns: ";
	std::cin >> stringDns;

	system(("netsh interface ipv4 set address name=\"" + stringInterface + "\" static " + stringIp + " " + stringMask + " " + stringGateway).c_str());
	system(("netsh interface ipv4 set dns name = \"" + stringInterface + "\" static " + stringDns).c_str());
}