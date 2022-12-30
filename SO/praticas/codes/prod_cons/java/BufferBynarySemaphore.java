package codes.prod_cons.java;

import java.util.concurrent.Semaphore;

public class BufferBynarySemaphore implements IBuffer {
  volatile int count;
  int in, out, N;
  int[] buffer;
  Semaphore sem;

  public BufferBynarySemaphore(int N) {
    this.buffer = new int[N];
    this.N = N;
    this.in = 0;
    this.out = 0;
    this.count = 0;
    this.sem = new Semaphore(1);
  }

  public void produz(int v) {
    buffer[in] = v;
    in = (in + 1) % N;

    try {
      sem.acquire();
      count++;
      sem.release();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }

  public int consome() {
    int dout = buffer[out];
    out = (out + 1) % N;

    try {
      sem.acquire();
      count--;
      sem.release();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    return dout;
  }
}
