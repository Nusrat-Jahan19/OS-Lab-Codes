/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumer;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.concurrent.Semaphore;

/**
 *
 * @author lenovo
 */
public class ProducerConsumer {

    int bufferSize = 7;    
    private final Queue<Integer> buffer = new LinkedList<>(); 
    Semaphore mutex = new Semaphore(1);   
    Semaphore full = new Semaphore(0);
    Semaphore empty = new Semaphore(bufferSize);  
    Random rand = new Random();
    public String ANSI_BLUE = "\u001B[34m";

    void ProduceProcess() {
        while (true) {
            try {
             
                int produced_item = rand.nextInt(200);            
                empty.acquire();
                mutex.acquire();               
                buffer.add(produced_item);              
                System.out.println(ANSI_BLUE
                        + Thread.currentThread().getName() + " : Data " + produced_item + " is inserted in the buffer");
                System.out.println(ANSI_BLUE + "Empty Space : " + (bufferSize
                        - buffer.size()));
                System.out.println(ANSI_BLUE + "Full Space : "
                        + buffer.size());               
                mutex.release();
                full.release(1);
                Thread.sleep(1000);
            } catch (InterruptedException ex) {

                
            }
        }
    }

   
    void ConsumeProcess() {
        while (true) {
            try {
          
                full.acquire();
                mutex.acquire();
                int consumed_item = buffer.remove();
                System.out.println(Thread.currentThread().getName() + " : Consumed Data " + consumed_item + " from the buffer");
                System.out.println("Full Space : " + buffer.size());
                mutex.release();
                empty.release();
            } catch (InterruptedException ex) {

             
            }
        }
    }

  
    class Producer implements Runnable {

        @Override
        public void run() {
       
            ProduceProcess();
        }
    }

  
    class Consumer implements Runnable {

        @Override
        public void run() {
       
            ConsumeProcess();
        }
    }
   

       
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

     
        ProducerConsumer pc = new ProducerConsumer();      
        Producer p1 = pc.new Producer();
        Producer p2 = pc.new Producer();
        Producer p3 = pc.new Producer();   
        Consumer c1 = pc.new Consumer();
        Consumer c2 = pc.new Consumer();
        Consumer c3 = pc.new Consumer();
     
        Thread t1 = new Thread(p1);
        t1.setName("Producer 1");
        Thread t2 = new Thread(p2);
        t2.setName("Producer 2");
        Thread t5 = new Thread(p3);
        t5.setName("Producer 3");

      
        Thread t3 = new Thread(c1);
        t3.setName("Consumer 1");
        Thread t4 = new Thread(c2);
        t4.setName("Consumer 2");
        Thread t6 = new Thread(c3);
        t6.setName("Consumer 3");
        
        t1.start();
        t2.start();
        t5.start();
        t3.start();
        t4.start();
        t6.start();
    
    }

}
