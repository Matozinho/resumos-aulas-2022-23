package codes.prod_cons.java;

// class Buffer {
//   volatile int count;
//   int in, out, N;
//   int[] buffer;
//   Semaphore sem;

//   public Buffer(int N, Semaphore sem) {
//     this.buffer = new int[N];
//     this.N = N;
//     this.in = 0;
//     this.out = 0;
//     this.count = 0;
//     this.sem = sem;
//   }

//   void produz(int v) throws InterruptedException {
//     buffer[in] = v;
//     in = (in + 1) % N;

//     sem.acquire();
//     count++;
//     sem.release();
//   }

//   public int consome() throws InterruptedException {
//     int dout = buffer[out];
//     out = (out + 1) % N;

//     sem.acquire();
//     count--;
//     sem.release();

//     return dout;
//   }
// }

public class BinarySemaphore {
  public static void main(String[] args) throws InterruptedException {
    IBuffer b = new BufferBynarySemaphore(5);

    Thread t1 = new Thread(new Produtor(b));
    Thread t2 = new Thread(new Consumidor(b));

    t1.start();
    t2.start();

    t1.join();
    t2.join();

    System.out.println("Fim do prod/cons");
  }
}