import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class ExecutorExample {
  public static void main(String[] args) throws InterruptedException {
    ExecutorService executor = Executors.newCachedThreadPool();
    // ExecutorService executor = Executors.newFixedThreadPool(10);
    // ExecutorService executor = Executors.newFixedThreadPool(2);
    
    for (int i = 0; i < 10; i++) {
      executor.execute(new ThreadInterface());
    }

    System.out.println("Spleeping...");
    TimeUnit.SECONDS.sleep(5);
    executor.shutdownNow();
    System.out.println("Shutdown solicitado");
  }
}