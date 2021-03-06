import paho.mqtt.client as mqtt

# MQTT variables
broker_name = '192.168.1.105'
broker_port = 1883
topics_prefix = 'sensors_ee499/raspberry11/'
sensors = ['temperature', 'light', 'grove']

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))

    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
	
    client.subscribe(topics_prefix + '#')

    #for sensor in sensors:
    #    client.subscribe(topics_prefix + sensor)


# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.payload))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(broker_name, broker_port, 60)

# Blocking call that processes network traffic, dispatches callbacks and
# handles reconnecting.
# Other loop*() functions are available that give a threaded interface and a
# manual interface.
client.loop_forever()