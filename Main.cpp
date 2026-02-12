#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string IP = "";
    std::string subnet;
    
    int network_id = 0;
    int broadcast_ip = 0;
    int first_host = network_id + 1;
    int last_host = broadcast_ip - 1;
    std::string new_ip;
    
    int CIDR;
    int group_size;
    int subnet_part;

    std::cout << "IP Address: (with dots)";
    std::cin >> IP;
    std::cout << "CIDR (without /): ";
    std::cin >> CIDR;

    // Find Hostpart of the IP
    size_t pos = IP.find_last_of('.');
    std::string hostPart = IP.substr(pos + 1);
    new_ip = IP.substr(0, pos);

    // Create the Data
    // Cheatsheet Lookup
    if(CIDR == 25) { group_size = 128; subnet_part = 128; }
    if(CIDR == 26) { group_size = 64; subnet_part = 192; }
    if(CIDR == 27) { group_size = 32; subnet_part = 224; }
    if(CIDR == 28) { group_size = 16; subnet_part = 240; }
    if(CIDR == 29) { group_size = 8; subnet_part = 248; }
    if(CIDR == 30) { group_size = 4; subnet_part = 252; }
    if(CIDR == 31) { group_size = 2; subnet_part = 254; }
    if(CIDR == 32) { group_size = 1; subnet_part = 255; }

    int host = std::stoi(hostPart);
    network_id = (host/group_size) * group_size;
    int next_network = network_id + group_size;
    broadcast_ip = next_network - 1;

    if(CIDR >= 31) { first_host = network_id; last_host = broadcast_ip; }
    else { first_host = network_id + 1; last_host = broadcast_ip - 1; }

    subnet = "255.255.255." + std::to_string(subnet_part);

    std::cout << std::endl;
    std::cout << std::endl;

    // PRINT DATA
    std::cout << "IP-Address: " << IP << std::endl;
    std::cout << "Subnet-Mask: " << subnet << std::endl;
    std::cout << "Network-ID: " << new_ip + "." + std::to_string(network_id) << std::endl;
    std::cout << "Broadcast-IP: " << new_ip + "." + std::to_string(broadcast_ip) << std::endl;
    std::cout << "First Host-IP: " << new_ip + "." + std::to_string(first_host) << std::endl;
    std::cout << "Last Host-IP: " << new_ip + "." + std::to_string(last_host) << std::endl;
    std::cout << "CIDR: /" << CIDR << std::endl;
    std::cout << "Group-Size: " << group_size << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}