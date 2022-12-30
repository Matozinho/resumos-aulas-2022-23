package com.producer_consumer;

public class App {
  private static IBuffer getBuffer(String type, int bufferSize) {
    switch (type) {
      case "binary-semaphore":
        return new BufferBynarySemaphore(bufferSize);
      case "counter-semaphore":
        return new BufferCounterSemaphore(bufferSize);
      case "mutex":
        return new BufferMutex(bufferSize);
      case "monitor":
        return new BufferMonitor(bufferSize);
      default:
        return new BufferBynarySemaphore(bufferSize);
    }
  }

  public static void main(String[] args) throws InterruptedException {
    try {
      System.out.println(args[0]);
      IBuffer b = getBuffer("", 5);

      Thread t1 = new Thread(new Producer(b));
      Thread t2 = new Thread(new Consumer(b));

      t1.start();
      t2.start();

      t1.join();
      t2.join();

      System.out.println("Fim do prod/cons");
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

}
