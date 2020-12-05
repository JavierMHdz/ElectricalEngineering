import paho.mqtt.client as mqtt
import time

debug = 0

# MQTT variables
broker_name = '192.168.1.179'
broker_port = 1883
topics_prefix = 'sensors_ee499/raspberry1/d'

# Signal
signal_d1 = []
signal_d2 = []

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    for i in range(2):
        client.subscribe(topics_prefix + str(i+1))

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg): 
    
    if debug == 1:
        print(msg.topic + " " + str(msg.payload))
    
    if msg.topic.split('/')[2][1] == '1':
        signal_d1.append(int(msg.payload))
    elif msg.topic.split('/')[2][1] == '2':
        signal_d2.append(int(msg.payload))

# Connect to broker and start loop    
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
if broker_name == '':
	print "Change the broker address"
	exit()
client.connect(broker_name, broker_port, 60)

threshold = 100
detector1 = False
detector2 = False
move = False
one = False
one2 = False

client.loop_start()

while True:
    
    # You have two lists (signal_d1 and signal_d2), which are your two signals
    # The signals are published with interval of 200 ms (5 samples per second each signal)
    # The values are the distance in cm to the closest object. Expect values between 0 and 512

    signal_d1_test = signal_d1[-10:]
    signal_d2_test = signal_d2[-10:]

    count1 = 0
    count2 = 0
    ave1 = 0
    ave2 = 0

    #for values in signal_d1_test:
     #   if values <= threshold:
     #       print "We found an intruder!"
      #      checker = True
      #  else:
            #print "There is no one here"
      #      checker = False

    #if checker == False:
     #   for values in signal_d2_test:
      #      if values <= threshold:
       #         print "We found an intruder!"
        #        checker = True
        #    else:
                #print "There is no one here"
         #       checker = False

    #for i in signal_d1_test:
     #   if 

    #I have the following print statements for debugging purposes
    #print "Signal 1" + str(signal_d1)
    #print "Signal 2" + str(signal_d2)
    
    if (len(signal_d1_test) == 10):
        for i in range(10):
            count1 += signal_d1_test[i]
            count2 += signal_d2_test[i]

    ave1 = count1/10
    ave2 = count2/10

    print "ave1" + str(ave1)
    print "ave2" + str(ave2)

    if ave1 <= 100:
        print "We found an intruder!"
        detector1 = True
        if ave2 <= 100:
            print "The intruder is moving left"
            detector2 = True

    else:
        detector1 = False

    if ave2 <= 100:
        print "We found an intruder!"
        detector2 = True
        if ave1 <= 100:
            print "The intruder is moving right"
            detector1 = True

    else:
        detector2 = False

    # TO-DO - Detect when a person pass by and what direction he/she is going
    
    time.sleep(0.02)

