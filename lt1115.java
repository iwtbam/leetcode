class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(monitor){
                while(tag != 0){
                    monitor.wait();
                }
                printFoo.run();
                tag = 1;
                monitor.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(monitor){
                while(tag != 1){
                    monitor.wait();
                }
                printBar.run();

                tag = 0;
                monitor.notifyAll();
            }
        }
    }

    private Object monitor = new Object();
    private int tag = 0;
}