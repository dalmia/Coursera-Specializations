import socket

mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    mysock.connect(('127.0.0.1', 80))
    mysock.send('GET http://data.pr4e.org/intro-short.txt HTTP/1.0\n\n')

    while True:
        data = mysock.recv(512)
        if ( len(data) < 1 ) :
            break
        print data;

except Exception as e:
    print e;

mysock.close()
