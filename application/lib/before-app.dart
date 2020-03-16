import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';

import 'gradient-container.dart';
import 'home.dart';
import 'services/local-prefs.dart';

class DataServer {
  String port;
  String ipAdress;
}

class SettingServer extends StatefulWidget {
  @override
  SettingServerState createState() => SettingServerState();
}

class SettingServerState extends State<SettingServer> {
  final _formKey = GlobalKey<FormState>();
  Color _textFieldColor = Colors.blueGrey[800];
  DataServer data = DataServer();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: GradientContainer(
        child: Center(
          child: SingleChildScrollView(
            child: Form(
              key: _formKey,
              child: Card(
                margin: EdgeInsets.symmetric(horizontal: 30, vertical: 230),
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.all(Radius.circular(10)),
                ),
                elevation: 8.0,
                color: _textFieldColor,
                child: ConstrainedBox(
                  constraints: BoxConstraints(
                    maxHeight: 300,
                    maxWidth: 300,
                    minHeight: 200,
                    minWidth: 200,
                  ),
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.center,
                    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                    children: <Widget>[
                      Padding(
                        padding: EdgeInsets.symmetric(horizontal: 20),
                        child: TextFormField(
                          decoration: const InputDecoration(
                            border: OutlineInputBorder(
                              borderSide: BorderSide(color: Colors.black12),
                            ),
                            hintText: 'Adresse IP',
                          ),
                          onSaved: (value) => this.data.ipAdress = value,
                          validator: (value) {
                            if (value.isEmpty) {
                              return 'Champ obligatoire';
                            }
                            return null;
                          },
                        ),
                      ),
                      Padding(
                        padding: EdgeInsets.symmetric(horizontal: 20),
                        child: TextFormField(
                          decoration: const InputDecoration(
                            border: OutlineInputBorder(
                              borderSide: BorderSide(color: Colors.black12),
                            ),
                            hintText: 'Port',
                          ),
                          onSaved: (value) => this.data.port = value,
                          validator: (value) {
                            if (value.isEmpty) {
                              return 'Champ obligatoire';
                            }

                            return null;
                          },
                        ),
                      ),
                      RaisedButton(
                        shape: RoundedRectangleBorder(
                            borderRadius:
                                BorderRadius.all(Radius.circular(40))),
                        onPressed: () async {
                          // Validate will return true if the form is valid, or false if
                          // the form is invalid.
                          if (_formKey.currentState.validate()) {
                            SharedPreferences _prefs =
                                await SharedPreferences.getInstance();
                            _formKey.currentState.save();
                            _prefs.setString('IP_Adress', this.data.ipAdress);
                            _prefs.setString('port', this.data.port);
                            Navigator.push(
                                context,
                                MaterialPageRoute(
                                    builder: (context) => Home()));
                          }
                        },
                        child: Text('OK'),
                        color: Colors.indigo[400],
                      ),
                    ],
                  ),
                ),
              ),
            ),
          ),
        ),
      ),
    );

    @override
    void dispose() {
      super.dispose();
    }
  }
}
