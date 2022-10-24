class ThreadInterface implements Runnable {
  public void run() {
    // v1
    // for (int i = 0; i < 200; i++) {
    // System.out.println("Thread[" + Thread.currentThread().getName() + "]=" + i);
    // }

    boolean sair = false;

    while (!sair) {
      System.out.println("Thread[" + Thread.currentThread().getName() + "]");

      if (Thread.currentThread().isInterrupted()) {
        System.out.println("Interrupção solicitada, finalizando a Thread" + Thread.currentThread().getName());
        sair = true;
      }

    }
  }
}