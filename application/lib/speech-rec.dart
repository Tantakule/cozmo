import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'package:speech_recognition/speech_recognition.dart';
import 'package:http/http.dart' as http;

import 'animations/bar-grow.dart';
import 'animations/dot-bounce.dart';
import 'database/database.dart';
import 'home.dart';

class VoiceHome extends StatefulWidget {
  @override
  _VoiceHomeState createState() => _VoiceHomeState();
}

class _VoiceHomeState extends State<VoiceHome> with TickerProviderStateMixin {
  SpeechRecognition _speechRecognition;
  bool _isAvailable = true;
  bool _isListening = false;
  bool _isTalking = false;
  String resultText = "";
  final db = LocalDatabase.instance;
  GlobalKey _scaffoldKey = GlobalKey<ScaffoldState>();

  @override
  void initState() {
    super.initState();
    initSpeechRecognizer();

    _isListening = true;
    _speechRecognition.listen(locale: "fr_FR").then(
          (result) => print('$result'),
        );
  }

  void initSpeechRecognizer() {
    _speechRecognition = SpeechRecognition();

    _speechRecognition.setAvailabilityHandler(
      (bool result) => setState(() => _isAvailable = true),
    );

    _speechRecognition.setRecognitionResultHandler((String speech) {
      setState(() => resultText = speech);
    });

    _speechRecognition.setRecognitionStartedHandler(() {
      _isTalking = true;
      setState(() => _isListening = true);
    });

    _speechRecognition.setRecognitionCompleteHandler(() {
      _speechRecognition.stop().then((reuslt) async {
        SharedPreferences _prefs = await SharedPreferences.getInstance();
        String ipAdress = _prefs.getString('IP_Adress');
        String port = _prefs.getString('port');
        var url = 'http://' + ipAdress + ':' + port + '/serial/vocal';
        // var url = 'http://192.168.43.243:3000/serial/test';
        var response = await http.post(url, body: {'textQuery': resultText});
        print('Response status: ${response.statusCode}');
        print('Response body: ${response.body}');
        Query query = Query(
            dateTime: DateTime.now().toString(),
            error: true,
            query: resultText);
        db.insertQuery(query);
        Navigator.push(
            context, MaterialPageRoute(builder: (context) => Home()));
      });

      _isTalking = false;
      setState(() => _isListening = false);
    });

    _speechRecognition.activate().then(
          (result) => setState(() => _isAvailable = result),
        );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      key: _scaffoldKey,
      bottomSheet: BottomSheet(
        onClosing: () {},
        animationController:
            AnimationController(duration: Duration(seconds: 2), vsync: this),
        builder: (BuildContext bc) {
          return Container(
            decoration: BoxDecoration(
              color: Colors.indigo[400],
              borderRadius: BorderRadius.only(
                  topRight: Radius.circular(10), topLeft: Radius.circular(10)),
            ),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                Container(
                    child: _isTalking ? BarList(10) : DotList(10), height: 100),
                SizedBox(
                  height: 30,
                ),
                FloatingActionButton(
                  elevation: 4,
                  child: Icon(
                    Icons.mic_off,
                    color: Colors.white,
                  ),
                  shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(30),
                      side: BorderSide(width: 1.5, color: Colors.white)),
                  backgroundColor: Colors.grey[800],
                  onPressed: onButtonTap,
                ),
              ],
            ),
            height: 300,
          );
        },
      ),

      // floatingActionButton: FloatingActionButton(
      //   elevation: 4,
      //   child: Icon(
      //     Icons.mic_off,
      //     color: Colors.white,
      //   ),
      //   shape: RoundedRectangleBorder(
      //       borderRadius: BorderRadius.circular(30),
      //       side: BorderSide(width: 1.5, color: Colors.white)),
      //   backgroundColor: Colors.grey[800],
      //   onPressed: onButtonTap,
      // ),
      // floatingActionButtonLocation: FloatingActionButtonLocation.endDocked,
      body: Center(
        child: Text(
          resultText,
          style: TextStyle(color: Colors.white),
        ),
      ),
      // AnimatedContainer(
      //   child: Center(
      //     child: _isTalking ? BarList(10) : DotList(10),
      //   ),
      //   decoration: BoxDecoration(
      //     color: Colors.indigo[400],
      //     borderRadius: BorderRadius.only(
      //         topRight: Radius.circular(10), topLeft: Radius.circular(10)),
      //   ),
      //   height: _isListening ? 300 : 0,
      //   curve: Curves.fastLinearToSlowEaseIn,
      //   duration: Duration(milliseconds: 300),
      // ),
    );
  }

  void onButtonTap() {
    _speechRecognition.stop().then(
          (result) => setState(() {
            _isListening = false;
            resultText = "";
          }),
        );
    Navigator.pop(context);
  }
}
