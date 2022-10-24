class Data {
  private volatile int valor;

  public int getValor() {
    return valor;
  }

  public void setValor(int valor) {
    this.valor = valor;
  }
}

class MyThread implements Runnable {
  Data d;

  public MyThread(Data d) {
    this.d = d;
  }

  public void run() {
    System.out.println("Thread[" + Thread.currentThread().getName() + "]=" + d.getValor());
    d.setValor(20);
  }
}

public class DataTest {
  public static void main(String[] args) {
    Data data = new Data();
    data.setValor(0);

    Thread t1 = new Thread(new MyThread(data));
    Thread t2 = new Thread(new MyThread(data));

    t1.start();

    // se comentar o trecho, ambas as threads executam ao mesmo tempo
    // try {
    // TimeUnit.SECONDS.sleep(5);
    // } catch (InterruptedException err) {
    // err.printStackTrace();
    // }

    t2.start();
  }
}
