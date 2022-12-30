import java.util.concurrent.locks.ReentrantLock;

class Buffer {
  volatile int count;
  int in, out, N;
  int[] buffer;
  ReentrantLock lock;

  public Buffer(int N, ReentrantLock lock) {
    this.buffer = new int[N];
    this.N = N;
    this.in = 0;
    this.out = 0;
    this.count = 0;
    this.lock = lock;
  }

  void produz(int v) throws InterruptedException {
    buffer[in] = v;
    in = (in + 1) % N;

    lock.lock();
    count++;
    lock.unlock();
  }

  public int consome() throws InterruptedException {
    int dout = buffer[out];
    out = (out + 1) % N;

    lock.lock();
    count--;
    lock.unlock();

    return dout;
  }
}

public class Mutex {
  public static void main(String[] args) throws InterruptedException {
    ReentrantLock lock = new ReentrantLock();
    Buffer b = new Buffer(5, lock);

    Thread t1 = new Thread(new Produtor(b));
    Thread t2 = new Thread(new Consumidor(b));

    t1.start();
    t2.start();

    t1.join();
    t2.join();

    System.out.println("Fim do prod/cons");
  }
}