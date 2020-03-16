import 'package:flutter/material.dart';

class BottomBar extends StatefulWidget {
  @override
  BottomBarState createState() => BottomBarState();

  BottomBar({Key key}) : super(key: key);
}

class BottomBarState extends State<BottomBar> {
  int _selectedIndex;
  @override
  void initState() {
    super.initState();
    _selectedIndex = 0;
  }

  int get selectedIndex => _selectedIndex;

  @override
  Widget build(BuildContext context) {
    return BottomNavigationBar(
      currentIndex: _selectedIndex,
      items: [
        BottomNavigationBarItem(
          icon: Icon(Icons.settings),
          title: Text("Parametres"),
        ),
        BottomNavigationBarItem(
          icon: Icon(Icons.history),
          title: Text("Historique"),
        )
      ],
      onTap: _onTap,
    );
  }

  void _onTap(int index) {
    setState(() {
      _selectedIndex = index;
    });
  }
}
