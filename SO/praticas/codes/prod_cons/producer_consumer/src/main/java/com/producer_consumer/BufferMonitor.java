package com.producer_consumer;

public class BufferMonitor implements IBuffer {
  volatile int count;
  int in, out, N;
  int[] buffer;

  public BufferMonitor(int N) {
    this.buffer = new int[N];
    this.N = N;
    this.in = 0;
    this.out = 0;
    this.count = 0;
    System.out.println("MONITOR");
  }

  public void produz(int v) {
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
