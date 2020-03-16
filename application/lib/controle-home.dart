import 'package:application/cross.dart';
import 'package:flutter/material.dart';

class CrossStart extends StatefulWidget {
  @override
  _CrossStartState createState() => _CrossStartState();
}

class _CrossStartState extends State<CrossStart> {
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Card(
        margin: EdgeInsets.symmetric(horizontal: 30, vertical: 230),
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.all(Radius.circular(10)),
        ),
        elevation: 8.0,
        color: Colors.blueGrey[800],
        child: ConstrainedBox(
          constraints: BoxConstraints(
            maxHeight: 300,
            maxWidth: 300,
            minHeight: 200,
            minWidth: 200,
          ),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: <Widget>[
              Padding(
                child: Text(
                  "Pour controler le robot, appuyez sur START",
                  textAlign: TextAlign.center,
                ),
                padding: EdgeInsets.symmetric(horizontal: 20),
              ),
              RaisedButton(
                child: Text("START"),
                onPressed: onPress,
                color: Colors.indigo[400],
              ),
            ],
          ),
        ),
      ),
    );
  }

  void onPress() {
    Navigator.push(
        context, MaterialPageRoute(builder: (context) => CrossLayout()));
  }
}
