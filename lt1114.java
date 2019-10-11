class Foo {

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        synchronized(monitor){
            while(tag!= 0)
                monitor.wait();
            printFirst.run();
            tag = (tag + 1) % 3;
            monitor.notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized(monitor){
            while(tag!=1)
                monitor.wait();       
            printSecond.run();
            tag = (tag + 1) % 3;
            monitor.notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized(monitor){
            while(tag!=2)
                monitor.wait();
            printThird.run();
            tag = (tag + 1) % 3;
            monitor.notifyAll();
        }
    }

    private Object monitor = new Object();
    private int tag = 0;
}