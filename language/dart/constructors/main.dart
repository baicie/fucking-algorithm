class Point {
  final double x;
  final double y;
  final double distanceFromOrigin;

  Point(double x, double y)
      : x = x,
        y = y,
        distanceFromOrigin = x * x + y * y;
}

void main() {
  final point = Point(3, 4);
  print(point.distanceFromOrigin); // 25.0
}