package com.producer_consumer;

import java.util.concurrent.locks.ReentrantLock;

public class BufferMutex implements IBuffer {
  volatile int count;
  int in, out, N;
  int[] buffer;
  ReentrantLock lock;

  public BufferMutex(int N) {
    this.buffer = new int[N];
    this.N = N;
    this.in = 0;
    this.out = 0;
    this.count = 0;
    this.lock = new ReentrantLock();
    System.out.println("MUTEX");
  }

  public void produz(int v) {
    buffer[in] = v;
    in = (in + 1) % N;

    lock.lock();
    count++;
    lock.unlock();
  }

  public int consome() {
    int dout = buffer[out];
    out = (out + 1) % N;

    lock.lock();
    count--;
    lock.unlock();

    return dout;
  }
}
