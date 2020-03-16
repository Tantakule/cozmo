import 'dart:io';
import 'dart:convert';
import 'dart:async';

main() async {
  Socket socket;
  try {
    socket = await Socket.connect('192.168.0.43', 7070,
        timeout: Duration(milliseconds: 2000));
  } catch (SocketException) {
    print('ERROR');
  }

  // listen to the received data event stream
  socket.listen((List<int> event) {
    print(utf8.decode(event));
  });

  // send hello
  socket.add(utf8.encode('hello'));

  // .. and close the socket
  socket.close();
}
