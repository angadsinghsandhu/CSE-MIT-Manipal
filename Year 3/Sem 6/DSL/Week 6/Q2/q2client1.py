import socket
import datetime
import time
from dateutil import parser
from timeit import default_timer as timer

def synchronizeTime():
    print("MOBILE APP\n")
    s = socket.socket()
    port = 8011
    s.connect(('127.0.0.1', port))
    request_time = timer()
    server_time = parser.parse(s.recv(1024).decode())
    response_time = timer()
    actual_time = datetime.datetime.now()
    print("Time returned by server: " + str(server_time))
    process_delay_latency = response_time - request_time
    print("Process Delay latency: " + str(process_delay_latency) + " seconds")
    print("Actual clock time at client side: " + str(actual_time))
    client_time = server_time + datetime.timedelta(seconds=(process_delay_latency) / 2)
    print("Synchronized process client time: " + str(client_time))
    time.sleep(10)
    s.close()

if __name__ == '__main__':
    synchronizeTime()