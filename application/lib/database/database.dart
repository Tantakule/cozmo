import 'dart:async';
import 'dart:io';

import 'package:path/path.dart';
import 'package:path_provider/path_provider.dart';
import 'package:sqflite/sqflite.dart';

class Query {
  final int id;
  final String query;
  final bool error;
  final String dateTime;

  Query({this.id, this.query, this.error, this.dateTime});

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'query': query,
      'error': error,
      'datetime': dateTime.toString(),
    };
  }
}

class LocalDatabase {
  final String databaseName = "test_db2.db";
  Database _database;

  LocalDatabase._privateConstructor();
  static final LocalDatabase instance = LocalDatabase._privateConstructor();

  openDB() async {
    Directory documentsDir = await getApplicationDocumentsDirectory();
    String path = join(documentsDir.path, databaseName);
    return _database = await openDatabase(
      path,
      onCreate: (db, version) {
        return db.execute(
          "CREATE TABLE queries (id INTEGER PRIMARY KEY, query TEXT, error BOOLEAN, datetime TEXT)",
        );
      },
      version: 1,
    );
  }

  Future<Database> get database async {
    if (_database != null) {
      return _database;
    }

    _database = await openDB();

    return _database;
  }

  void insertQuery(Query query) async {
    Database db = await instance.database;
    await db.insert("queries", query.toMap());
  }

  Future<List<Query>> getQueries() async {
    Database db = await instance.database;
    List<Map<String, dynamic>> maps = await db.query("queries");
    Duration(seconds: 1);
    return List.generate(maps.length, (int i) {
      return Query(
          id: maps[i]['id'],
          query: maps[i]['query'],
          error: maps[i]['error'] == 1 ? true : false,
          dateTime: maps[i]['datetime']);
    }).reversed.toList();
  }

  void deleteQuery(int id) async {
    Database db = await instance.database;
    await db.delete('queries', where: 'id = ?', whereArgs: [id]);
  }
}
