import time, socket

def speed(s1, s2):
    s = socket.socket()
    s.connect(("192.168.137.160", 80))

    PWM_MAX = 1023
    s1 = (int)(s1 * PWM_MAX)
    s2 = (int)(s2 * PWM_MAX)

    cmd = "S:{},{}\r".format(s1, s2)

    #s.send(bytes(cmd, 'utf-8'))    # For python 3.x
    s.send(cmd)                     # For python 2.7
    
    print("Send: {}".format(cmd))
    
    response = s.recv(100)
    print("Recv: {}".format(response))
    s.close()
   
# Move forward for 1.5 sec
speed(0.5, 0.5)
time.sleep(1.5)

# Rotate left for 1 sec
speed(-0.5, 0.5)
time.sleep(1.0)

speed(0, 0) # Stop
