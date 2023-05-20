import socket

# create TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# retrieve local hostname
local_hostname = socket.gethostname()

# get fully qualified hostname
local_fqdn = socket.getfqdn()

# get the according IP address
ip_address = socket.gethostbyname(local_hostname)

# output hostname, domain name and IP address
print ("working on %s (%s) with %s" % (local_hostname, local_fqdn, ip_address))


server_address = ('', 23456)
print ('starting up on %s port %s' % server_address)
sock.bind(server_address)


sock.listen(10)

while True:
    
    print ('waiting for a connection')
    connection, client_address = sock.accept()

    try:
        
        print ('connection from', client_address)

        
        while True:
            data = connection.recv(64)
            if data:
                
                print ("Data: %s" % data)
            else:
                
                print ("no more data.")
                break
    finally:
        
        connection.close()
