import 'package:application/controle-home.dart';
import 'package:flutter/material.dart';

import 'bottom-bar/tabs/history.dart';
import 'bottom-bar/tabs/settings.dart';
import 'gradient-container.dart';
import 'speech-rec.dart';
import 'cross.dart';

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  int _selectedIndex = 0;
  List<Widget> tabs = <Widget>[TabHistory(), CrossStart()];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      extendBody: true,
      bottomNavigationBar: BottomAppBar(
        clipBehavior: Clip.antiAlias,
        shape: CircularNotchedRectangle(),
        notchMargin: 4.0,
        child: BottomNavigationBar(
          currentIndex: _selectedIndex,
          items: [
            BottomNavigationBarItem(
              icon: Icon(Icons.history),
              title: Text("Historique"),
            ),
            BottomNavigationBarItem(
              icon: Icon(Icons.cast),
              title: Text("Controler"),
            )
          ],
          onTap: _onTap,
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          Navigator.push(
              context, MaterialPageRoute(builder: (context) => VoiceHome()));
        },
        backgroundColor: Colors.grey[800],
        elevation: 4,
        child: Icon(
          Icons.mic,
          color: Colors.white,
        ),
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(30),
          side: BorderSide(width: 1.5, color: Colors.white),
        ),
      ),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,
      body: GradientContainer(child: tabs[_selectedIndex]),
    );
  }

  void _onTap(int index) {
    setState(() {
      _selectedIndex = index;
    });
  }
}
