package codes.prod_cons.java;

public class Produtor implements Runnable {
  IBuffer b;

  public Produtor(IBuffer b) {
    this.b = b;
  }

  public void run() {
    for (int i = 0; i < 1000; i++) {
      b.produz(i);
      // System.out.println("Produziu " + i);
    }
  }
}
