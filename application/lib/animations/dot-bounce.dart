import 'dart:async';

import 'package:flutter/material.dart';

class DotList extends StatelessWidget {
  final int nbDot;

  DotList(this.nbDot);

  @override
  Widget build(BuildContext context) {
    List<int> delays = List.generate(nbDot, (int w) => w * 320);
    List<Widget> list = List.generate(nbDot * 2, (int w) {
      if (w % 2 == 0)
        return DotAnimation(delays[(w ~/ 2)]);
      else
        return SizedBox(width: 5);
    });
    return Row(
      mainAxisAlignment: MainAxisAlignment.center,
      children: list,
    );
  }
}

class DotAnimation extends StatefulWidget {
  final int delay;
  DotAnimation(this.delay);

  @override
  _DotAnimationState createState() => _DotAnimationState();
}

class _DotAnimationState extends State<DotAnimation>
    with TickerProviderStateMixin {
  Animation<double> animation;
  AnimationController animationController;

  @override
  void initState() {
    super.initState();

    Tween tween = Tween<double>(begin: 0, end: -5);
    animationController =
        AnimationController(vsync: this, duration: Duration(milliseconds: 800));
    CurvedAnimation curvedAnimation = CurvedAnimation(
      parent: animationController,
      curve: Curves.easeInSine,
    );
    animation = tween.animate(curvedAnimation)
      ..addListener(() {
        setState(() {});
      });

    Timer(Duration(milliseconds: widget.delay), () {
      animationController.repeat(reverse: true);
    });
  }

  Widget buildDot(Color color, double size) {
    return Container(
      width: size,
      height: size,
      decoration: BoxDecoration(
        color: color,
        shape: BoxShape.circle,
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Transform.translate(
        offset: Offset(0, animation.value), child: buildDot(Colors.white, 10));
  }

  @override
  void dispose() {
    animationController.dispose();
    super.dispose();
  }
}
