import 'dart:io';

import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'package:http/http.dart' as http;
import 'gradient-container.dart';

class CrossLayout extends StatefulWidget {
  @override
  _CrossLayoutState createState() => _CrossLayoutState();
}

class _CrossLayoutState extends State<CrossLayout> {
  Color buttonColor = Colors.black87;
  double buttonSize = 50;
  Socket socket = null;

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
      future: connectSocket(),
      builder: (context, snap) {
        if (snap.hasData) {
          if (snap.data) return screen();
          Navigator.pop(context);
          return null;
        }
        if (snap.hasError) {
          Navigator.pop(context);
          return null;
        } else {
          return Center(
            child:
                CircularProgressIndicator(backgroundColor: Colors.indigo[400]),
          );
        }
      },
    );
  }

  Future connectSocket() async {
    SharedPreferences _prefs = await SharedPreferences.getInstance();
    String ipAdress = _prefs.getString('IP_Adress');
    String port = _prefs.getString('port');
    var url = 'http://' + ipAdress + ':' + port + '/serial/control';
    var response = await http.get(url);
    int tcpPort = 7070;
    try {
      socket = await Socket.connect(ipAdress, tcpPort,
          timeout: Duration(milliseconds: 2000));
      return true;
    } catch (SocketException) {
      return false;
    }
  }

  void pointerDown(String direction) {
    socket.write(direction);
  }

  void pointerUp() {
    socket.write("e");
  }

  void goBack() {
    socket.close();
    Navigator.pop(context);
  }

  Widget screen() {
    return Scaffold(
      body: GradientContainer(
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              Listener(
                onPointerDown: (PointerEvent details) => pointerDown("a"),
                onPointerUp: (PointerEvent details) => pointerUp(),
                child: IconButton(
                  iconSize: buttonSize,
                  onPressed: () => {},
                  icon: Icon(Icons.keyboard_arrow_up),
                  color: buttonColor,
                ),
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: <Widget>[
                  Listener(
                    onPointerDown: (PointerEvent details) => pointerDown("g"),
                    onPointerUp: (PointerEvent details) => pointerUp(),
                    child: IconButton(
                      iconSize: buttonSize,
                      onPressed: () => {},
                      icon: Icon(Icons.keyboard_arrow_left),
                      color: buttonColor,
                    ),
                  ),
                  IconButton(
                    icon: Icon(Icons.radio_button_checked),
                    onPressed: null,
                    iconSize: buttonSize,
                    color: buttonColor,
                  ),
                  Listener(
                    onPointerDown: (PointerEvent details) => pointerDown("d"),
                    onPointerUp: (PointerEvent details) => pointerUp(),
                    child: IconButton(
                      iconSize: buttonSize,
                      onPressed: () => {},
                      icon: Icon(Icons.keyboard_arrow_right),
                      color: buttonColor,
                    ),
                  )
                ],
              ),
              Listener(
                onPointerDown: (PointerEvent details) => pointerDown("r"),
                onPointerUp: (PointerEvent details) => pointerUp(),
                child: IconButton(
                  iconSize: buttonSize,
                  onPressed: () => {},
                  icon: Icon(Icons.keyboard_arrow_down),
                  color: buttonColor,
                ),
              ),
              SizedBox(
                height: 150,
              ),
              RaisedButton(
                onPressed: goBack,
                child: Text("STOP"),
                color: Colors.indigo[400],
              )
            ],
          ),
        ),
      ),
    );
  }
}
