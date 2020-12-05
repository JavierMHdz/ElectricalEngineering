import socket
import sys
import time

TRANSPORT_LAYER = "udp"         # What transport layer do you want to use?
SERVER_ADDR = "192.168.1.111"	# What is the IP address of your Raspberry Pi board?
SERVER_PORT = 2000

def open_socket_client():
    
    while(1):
        try:
            print "Opening socket and connecting to " + SERVER_ADDR + " on port " + str(SERVER_PORT) + " using " + TRANSPORT_LAYER.upper() + " ..."
            
            # Create the socket variable
            if TRANSPORT_LAYER.upper() == "TCP":
                s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                s.connect((SERVER_ADDR, SERVER_PORT))
                
            elif TRANSPORT_LAYER.upper() == "UDP":
                s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                
            else:
                sys.exit("Invalid transport layer protocol")
            
            print "Connection established!"
        
            return s
            
        except:
            print "Error trying to connect... "
            time.sleep(1)

def process_response(response):
    print "Response received: " + response
    
    return 

def main_loop():
          
    # Open the socket and connect
    s = open_socket_client()
    
    while(1):
        
        # Read command from user:
        print "Type a command to send: "
        command = sys.stdin.readline()
        
        try:
            # Send command to the server
            if TRANSPORT_LAYER.upper() == "TCP":
                s.sendall(command)
            elif TRANSPORT_LAYER.upper() == "UDP":
                s.sendto(command, (SERVER_ADDR, SERVER_PORT))
            print "Command sent!"
            
            # Receive response
            print "Waiting for a response..."
            response = s.recv(1024)
            
            if not response:
                print "Server disconnected..."
                s.close()
                break
                
            # Process the response received
            process_response(response)
        
        except socket.error:
            print "Socket error..."
            s.close()
            break
        
if __name__ == "__main__":
    while(1):
        main_loop()
