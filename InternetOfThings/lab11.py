import urllib2

# Server address
# Replace the http by https to get the TLS version request
server_addr = 'https://www.google.com'

raw_input('Prepare Wireshark to capture traffic now, then press ENTER')

print 'Submitting request to ' + server_addr
response = urllib2.urlopen(server_addr)

if (response.getcode() == 200): # HTTP OK code
    print 'Request sent and answer received.'
    raw_input('Press ENTER to exit and check Wireshark.')
else:
    print 'No answer received.'
    raw_input('Press ENTER to exit and restart Wireshark.')
