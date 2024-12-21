import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class FizzBuzz {
  private int n;
  private final Semaphore fSem = new Semaphore(0);
  private final Semaphore bSem = new Semaphore(0);
  private final Semaphore fbSem = new Semaphore(0);
  private final Semaphore nSem = new Semaphore(1);
  private boolean done = false;

  public FizzBuzz(int n) {
    this.n = n;
  }

  // printFizz.run() outputs "fizz".
  public void fizz(Runnable printFizz) throws InterruptedException {
    while (!done) {
      fSem.acquire();
      if (!done)
        printFizz.run();
      nSem.release();
    }
  }

  // printBuzz.run() outputs "buzz".
  public void buzz(Runnable printBuzz) throws InterruptedException {
    while (!done) {
      bSem.acquire();
      if (!done)
        printBuzz.run();
      nSem.release();
    }
  }

  // printFizzBuzz.run() outputs "fizzbuzz".
  public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
    while (!done) {
      fbSem.acquire();
      if (!done)
        printFizzBuzz.run();
      nSem.release();
    }
  }

  // printNumber.accept(x) outputs "x", where x is an integer.
  public void number(IntConsumer printNumber) throws InterruptedException {
    for (int i = 1; i <= this.n; i++) {
      nSem.acquire();
      if (i % 15 == 0) {
        fbSem.release();
      } else if (i % 3 == 0) {
        fSem.release();
      } else if (i % 5 == 0) {
        bSem.release();
      } else {
        if (!done)
          printNumber.accept(i);
        nSem.release();
      }
    }
    nSem.acquire();
    done = true;
    fSem.release();
    bSem.release();
    fbSem.release();
    nSem.release();
  }
}