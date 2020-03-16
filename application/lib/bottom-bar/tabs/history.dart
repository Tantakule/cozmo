import 'package:flutter/material.dart';
import 'package:flutter_staggered_animations/flutter_staggered_animations.dart';
import 'package:intl/intl.dart';

import '../../database/database.dart';
import '../../gradient-container.dart';

class TabHistory extends StatelessWidget {
  final db = LocalDatabase.instance;

  @override
  Widget build(BuildContext context) {
    return buildListView();
  }

  Widget buildListView() {
    return GradientContainer(
      child: FutureBuilder(
          future: db.getQueries(),
          builder: (BuildContext context, AsyncSnapshot<List<Query>> snapshot) {
            return AnimationLimiter(
              child: ListView.builder(
                scrollDirection: Axis.vertical,
                shrinkWrap: true,
                itemCount: snapshot.data.length,
                itemBuilder: (BuildContext context, int index) {
                  return AnimationConfiguration.staggeredList(
                    position: index,
                    duration: const Duration(milliseconds: 375),
                    child: SlideAnimation(
                      verticalOffset: 50.0,
                      child: FadeInAnimation(
                        child: buildCard(snapshot.data[index]),
                      ),
                    ),
                  );
                },
              ),
            );
          }),
    );
  }

  Widget buildCard(Query query) {
    return Card(
      shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.all(Radius.circular(10))),
      elevation: 8,
      margin: new EdgeInsets.symmetric(horizontal: 10.0, vertical: 6.0),
      child: Container(
        decoration: BoxDecoration(
            color: Color.fromRGBO(64, 75, 96, .9),
            borderRadius: BorderRadius.all(Radius.circular(10))),
        child: buildTile(query),
      ),
    );
  }

  Widget buildTile(Query query) {
    return ListTile(
      contentPadding: EdgeInsets.symmetric(horizontal: 20.0, vertical: 10.0),
      leading: Container(
        padding: EdgeInsets.only(right: 12.0),
        decoration: new BoxDecoration(
            border: new Border(
                right: new BorderSide(width: 1.0, color: Colors.white24))),
        child: query.error
            ? Icon(Icons.error, color: Colors.red)
            : Icon(
                Icons.check_circle,
                color: Colors.green,
              ),
      ),
      title: Text(
        query.query,
        style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
      ),
      subtitle: Row(
        children: <Widget>[
          Icon(Icons.arrow_right, color: Colors.yellowAccent),
          Text(DateFormat.yMd().add_jm().format(DateTime.parse(query.dateTime)),
              style: TextStyle(color: Colors.white))
        ],
      ),
    );
  }
}
