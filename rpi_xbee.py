import XBee
import string
from time import sleep

xbee = XBee.XBee("/dev/ttyUSB1")


while 1:
        try:
                Msg = xbee.Receive()
                
                if Msg:
                        content = Msg[7:-1]
                        formatted = xbee.format(content)
                        
                        
                        print("Temperature: " + formatted + "\n")

                        analog_temperature = open("analog_temperature.txt", "a")
                        analog_temperature.write("%s\n" %formatted)
                
        except KeyboardInterrupt:
                break
