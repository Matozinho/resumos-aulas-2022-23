int main() {
  int N = 1000000000;
  int x = 4, y = 2;
  double z = 0.0;

  double denom = 1.0 / y;
  for (int i = 0; i < N; i++) {
    z += x * denom;
  }
}
