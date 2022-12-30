package com.producer_consumer;

public class Producer implements Runnable {
  IBuffer b;

  public Producer(IBuffer b) {
    this.b = b;
  }

  public void run() {
    for (int i = 0; i < 1000; i++) {
      b.produz(i);
      // System.out.println("Produziu " + i);
    }
  }
}
