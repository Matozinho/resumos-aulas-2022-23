package praticas.codes.sync;
public class SyncClass {
  public static void main(String[] args) {
    syncClass sc = new syncClass();

    Thread t1 = new Thread(new workers(sc));
    Thread t2 = new Thread(new workers(sc));
    Thread t3 = new Thread(new workers(sc));
    Thread t4 = new Thread(new workers(sc));
    Thread t5 = new Thread(new workers(sc));

    t1.start();
    t2.start();
    t3.start();
    t4.start();
    t5.start();
  }
}

class workers implements Runnable {
  syncClass sc;

  public workers(syncClass _sc) {
    sc = _sc;
  }

  public void run() {
    sc.methodSync();
  }

}

class syncClass {
  static int N;

  public syncClass() {
    N = 0;
  }

  public synchronized void methodSync() {
    N++;

    if (N < 5) {
      try {
        wait();
      } catch (Exception e) {
      }

      System.out.println("Saindo do wait " + Thread.currentThread().getName());
    } else {
      notify();
      // notifyAll();
    }
  }
}
