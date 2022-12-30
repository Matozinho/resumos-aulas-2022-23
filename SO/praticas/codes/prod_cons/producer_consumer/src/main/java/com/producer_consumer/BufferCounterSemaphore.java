package com.producer_consumer;

import java.util.concurrent.Semaphore;

public class BufferCounterSemaphore implements IBuffer {
  volatile int count;
  int in, out, N;
  int[] buffer;
  Semaphore full, empty, mutex;

  public BufferCounterSemaphore(int N) {
    this.buffer = new int[N];
    this.N = N;
    this.in = 0;
    this.out = 0;
    this.count = 0;
    this.full = new Semaphore(0);
    this.empty = new Semaphore(N);
    this.mutex = new Semaphore(1);
    System.out.println("COUNTER SEMAPHORE");
  }

  public void produz(int v) {
    try {
      empty.acquire();
      mutex.acquire();

      buffer[in] = v;
      in = (in + 1) % N;

      count++;

      mutex.release();
      full.release();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }

  public int consome() {
    try {
      full.acquire();
      mutex.acquire();

      int dout = buffer[out];
      out = (out + 1) % N;

      count--;

      mutex.release();
      empty.release();

      return dout;
    } catch (InterruptedException e) {
      e.printStackTrace();
      return -1;
    }
  }
}
