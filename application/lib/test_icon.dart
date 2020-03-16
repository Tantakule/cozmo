import 'package:flutter/material.dart';

class TestIcon extends StatefulWidget {
  @override
  _TestIconState createState() => _TestIconState();
}

class _TestIconState extends State<TestIcon> {
  bool _iconDisplay = false;
  @override
  Widget build(BuildContext context) {
    return Center(
        child: _iconDisplay
            ? IconButton(
                icon: Icon(Icons.keyboard_voice),
                onPressed: () {
                  setState(() {
                    _iconDisplay = !_iconDisplay;
                  });
                },
              )
            : IconButton(
                icon: Icon(Icons.keyboard),
                onPressed: () {
                  setState(() {
                    _iconDisplay = !_iconDisplay;
                  });
                },
              ));
  }
}
