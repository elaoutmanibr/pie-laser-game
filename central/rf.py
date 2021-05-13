from datetime import datetime
import struct
import sys
import time
import traceback

import pigpio
from nrf24 import *

class Rf:
    def __init__(self, hostname, port, adress):
        self.hostname = hostname
        self.port = port
        # Verify that address is between 3 and 5 characters.
        if not (2 < len(address) < 6):
            print(f'Invalid address {address}. Addresses must be between 3 and 5 ASCII characters.')
            sys.exit(1)
        self.address = adress
        # Connect to pigpiod
        print(f'Connecting to GPIO daemon on {hostname}:{port} ...')
        this.pi = pigpio.pi(hostname, port)
        if not this.pi.connected:
            print("Not connected to Raspberry Pi ... goodbye.")
            sys.exit()

        # Create NRF24 object.
        # PLEASE NOTE: PA level is set to MIN, because test sender/receivers are often close to each other, and then MIN works better.
        this.nrf = NRF24(pi, ce=25, payload_size=RF24_PAYLOAD.DYNAMIC, channel=100, data_rate=RF24_DATA_RATE.RATE_250KBPS, pa_level=RF24_PA.MIN)
        this.nrf.set_address_bytes(len(address))


    def listen(this):
        # Listen on the address specified as parameter
        this.nrf.open_reading_pipe(RF24_RX_ADDR.P1, address)
        try:
            print(f'Receive from {address}')
            while True:
                # As long as data is ready for processing, process it.
                while this.nrf.data_ready():
                    # Count message and record time of reception.            
                    now = datetime.now()
                    
                    # Read pipe and payload for message.
                    pipe = this.nrf.data_pipe()
                    payload = this.nrf.get_payload()    

                    # Resolve protocol number.
                    protocol = payload[0] if len(payload) > 0 else -1            

                    hex = ':'.join(f'{i:02x}' for i in payload)

                    # Show message received as hex.
                    print(f"{now:%Y-%m-%d %H:%M:%S.%f}: pipe: {pipe}, len: {len(payload)}, bytes: {hex}, count: {count}")

                    # If the length of the message is 9 bytes and the first byte is 0x01, then we try to interpret the bytes
                    # sent as an example message holding a temperature and humidity sent from the "simple-sender.py" program.
                    if len(payload) == 9 and payload[0] == 0x01:
                        values = struct.unpack("<Bff", payload)
                        print(f'Protocol: {values[0]}, temperature: {values[1]}, humidity: {values[2]}')
        except:
            traceback.print_exc()
            this.nrf.power_down()
            this.pi.stop()

    def send(this, message):
        this.nrf.open_writing_pipe(address)
        try:
            print(f'Send to {address}')
            this.nrf.reset_packages_lost()
            this.nrf.send(message)
            try:
                this.nrf.wait_until_sent()
            except TimeoutError:
                print('Timeout waiting for transmission to complete.')
                # Wait 10 seconds before sending the next reading.
                time.sleep(10)
                return 0
            
            if this.nrf.get_packages_lost() == 0:
                print(f"Success: lost={this.nrf.get_packages_lost()}, retries={this.nrf.get_retries()}")
            else:
                print(f"Error: lost={this.nrf.get_packages_lost()}, retries={this.nrf.get_retries()}")
        except:
            traceback.print_exc()
            this.nrf.power_down()
            this.pi.stop()
