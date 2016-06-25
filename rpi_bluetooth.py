import bluetooth

bd_addr = "20:16:01:06:07:18"
sock = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
sock.connect((bd_addr,1))

data = ""
while 1:
	try:
		data += sock.recv(1024)
		data_end = data.find('\n')
		if data_end != -1:
			rec = data[:data_end]
			print data
			data = data[data_end+1:]
	except KeyboardInterrupt:
		break
sock.close()
