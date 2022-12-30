package praticas.codes.sync;

// implement a semaphore using synchronized methods
public class MySemaphore {
  private int n;

  public MySemaphore(int initial) {
    n = initial;
  }

  public synchronized void acquire() {
    n--;
    if (n < 0) {
      try {
        wait();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }

  public synchronized void release() {
    n++;
    if (n <= 0) {
      notify();
    }
  }
}