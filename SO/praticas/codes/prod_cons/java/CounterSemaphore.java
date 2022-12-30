import java.util.concurrent.Semaphore;

class Buffer {
  volatile int count;
  int in, out, N;
  int[] buffer;
  Semaphore full, empty, mutex;

  public Buffer(int N) {
    this.buffer = new int[N];
    this.N = N;
    this.in = 0;
    this.out = 0;
    this.count = 0;
    this.full = new Semaphore(0);
    this.empty = new Semaphore(N);
    this.mutex = new Semaphore(1);
  }

  void produz(int v) throws InterruptedException {
    empty.acquire();
    mutex.acquire();

    buffer[in] = v;
    in = (in + 1) % N;

    count++;
    mutex.release();
    full.release();
  }

  public int consome() throws InterruptedException {
    full.acquire();
    mutex.acquire();

    int dout = buffer[out];
    out = (out + 1) % N;

    count--;
    mutex.release();
    empty.release();

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
      try {
        b.produz(i);
        // System.out.println("produziu " + i);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
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
      try {
        int dout = b.consome();
        // System.out.println("Consumiu " + dout);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}

public class CounterSemaphore {
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