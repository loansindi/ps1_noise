    sudo avrdude -c arduino -p t45 -P /dev/ttyACM0 -b 19200 -U flash:w:firmware.hex
