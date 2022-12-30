class Buffer {
  volatile int count;
  int in, out, N;
  int[] buffer;

  public Buffer(int N) {
    this.buffer = new int[N];
    this.N = N;
    this.in = 0;
    this.out = 0;
    this.count = 0;
  }

  void produz(int v) {
    buffer[in] = v;
    in = (in + 1) % N;
    synchronized (this) {
      count++;
    }
  }

  public int consome() {
    int dout = buffer[out];
    out = (out + 1) % N;

    synchronized (this) {
      count--;
    }

    return dout;
  }
}

class Produtor implements Runnable {
  Buffer b;

  public Produtor(Buffer b) {
    this.b = b;
  }

  public void run() {
    for (int i = 0; i < 1000; i++) {
      b.produz(i);
      // System.out.println("Produziu " + i);
    }
  }
}

class Consumidor implements Runnable {
  Buffer b;

  public Consumidor(Buffer b) {
    this.b = b;
  }

  public void run() {
    for (int i = 0; i < 1000; i++) {
      int dout = b.consome();
      // System.out.println("Consumiu " + dout);
    }
  }
}

public class Monitor {
  public static void main(String[] args) throws InterruptedException {
    Buffer b = new Buffer(5);

    Thread t1 = new Thread(new Produtor(b));
    Thread t2 = new Thread(new Consumidor(b));

    t1.start();
    t2.start();

    t1.join();
    t2.join();

    System.out.println("Fim do prod/cons");
  }
}