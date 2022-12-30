package codes.prod_cons.java;

public class Consumidor implements Runnable {
  IBuffer b;

  public Consumidor(IBuffer b) {
    this.b = b;
  }

  public void run() {
    for (int i = 0; i < 1000; i++) {
      int dout = b.consome();
      // System.out.println("Consumiu " + dout);
    }
  }
}
