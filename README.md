It outputs the important Attributes for an IP-Adress and its target subnet. Works only for a CIDR range from /25 - /32

Just enter an IP for Exampe: 10.1.1.55 and the CIDR of /28 and you get the information about this specific subnet. Maybe useful for students I don't know.

The program takes:

- An IPv4 address (e.g. `10.1.1.55`)
- A CIDR value (e.g. `28` for `/28`)

It then outputs:

- Subnet Mask  
- Network ID  
- Broadcast Address  
- First Host Address  
- Last Host Address  
- CIDR  
- Group Size

IP Address: 10.1.1.55  
CIDR: 28  

Output:

IP-Address: 10.1.1.55  
Subnet-Mask: 255.255.255.240  
Network-ID: 10.1.1.48  
Broadcast-IP: 10.1.1.63  
First Host-IP: 10.1.1.49  
Last Host-IP: 10.1.1.62  
CIDR: /28  
Group-Size: 16  
