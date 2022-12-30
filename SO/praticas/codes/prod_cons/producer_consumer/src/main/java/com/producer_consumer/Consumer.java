package com.producer_consumer;

public class Consumer implements Runnable {
  IBuffer b;

  public Consumer(IBuffer b) {
    this.b = b;
  }

  public void run() {
    for (int i = 0; i < 1000; i++) {
      int dout = b.consome();
      // System.out.println("Consumiu " + dout);
    }
  }
}
