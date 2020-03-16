import 'dart:math';

import 'package:flutter/material.dart';

class BarList extends StatelessWidget {
  final int nbBar;
  BarList(this.nbBar);

  @override
  Widget build(BuildContext context) {
    List<Widget> list = List.generate(nbBar * 2, (w) {
      //fois 2 parce que il y a des box pour espacer
      if (w % 2 == 0)
        return BarAnimation(50);
      else
        return SizedBox(width: 5);
    });
    return Row(
      mainAxisAlignment: MainAxisAlignment.center,
      children: list,
    );
  }
}

class BarAnimation extends StatefulWidget {
  final double maxSize;

  BarAnimation(this.maxSize);

  @override
  _BarAnimationState createState() => _BarAnimationState();
}

class _BarAnimationState extends State<BarAnimation>
    with TickerProviderStateMixin {
  double size;
  Random rd = Random();
  Animation<double> animation;
  AnimationController animationController;

  @override
  void initState() {
    super.initState();

    animationController = AnimationController(
        vsync: this, duration: Duration(milliseconds: randomDuration()));
    Tween tween = Tween<double>(begin: 30, end: randomSize());
    animation = tween.animate(
        CurvedAnimation(parent: animationController, curve: Curves.ease))
      ..addListener(() {
        setState(() {});
      });

    animation.addStatusListener((AnimationStatus status) {
      if (status == AnimationStatus.completed) {
        animationController.reverse();
      } else if (status == AnimationStatus.dismissed) {
        animationController.forward();
        tween.end = randomSize();
      }
    });

    animationController.forward();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      width: 10,
      height: animation.value,
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.vertical(
            top: Radius.circular(30), bottom: Radius.circular(30)),
      ),
    );
  }

  double randomSize() {
    return 5 + rd.nextInt((widget.maxSize - 5).toInt()).toDouble();
  }

  int randomDuration() {
    return 200 + rd.nextInt(400);
  }

  // @override
  // void dispose() {
  //   animationController.dispose();
  //   super.dispose();
  // }
}
