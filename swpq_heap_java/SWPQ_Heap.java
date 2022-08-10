/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author nestorj
 */
package swpq_heap;

import swpq_heap.SWPQ_Element;

public class SWPQ_Heap {
    static final int MAXHEAP = 128;
    private SWPQ_Element heap [] = new SWPQ_Element[MAXHEAP];
    private int heap_size = 0;
    
    public int parent(int i) {
        assert (i >= 1);
        return (i/2);
    }
    
    public int left(int i) {
        int lc = 2*i;
        return (lc);
    }
    
    public int right(int i) {
        int rc = 2*i + 1;
        return (rc);
    }
    
    public void maxHeapify(int i) {
        int l, r, largest;
        //System.out.println("heapify(" + i + ")");
        l = left(i);
        r = right(i);
        if ((l <= heap_size) && (heap[l].getKey() > heap[i].getKey())) {
            largest = l;
        } else {
            largest = i;
        }
        if ((r <= heap_size) && (heap[r].getKey() > heap[largest].getKey())) {
            largest = r;
        }
        if (largest != i) {
            //System.out.println("swapping " + i  + ":" + heap[i] + " " + largest + ":" + heap[largest]);
            SWPQ_Element tmp;
            tmp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = tmp;
            maxHeapify(largest);
        }      
    }
    
    
    public SWPQ_Element maximum() {
        return heap[1];
    } 
    
    public void increaseKey(int i, int key) {
        if (key < heap[i].getKey()) {
            System.out.println("Error: heap_increase_key new_key " + key +
                    "smaller than current key " + heap[i].getKey());
            return;
        }
        heap[i].setKey(key);
        while ((i > 1) && (heap[parent(i)].getKey() < heap[i].getKey())) {
            SWPQ_Element temp;
            temp = heap[i];
            heap[i] = heap[parent(i)];
            heap[parent(i)] = temp;
            i = parent(i);
        }
    }
    
    public void maxHeapInsert(int key, int val) {
        if (heap_size >= MAXHEAP) {
            System.out.println("Error: maximum heap size reached!");
            return; // maybe throw an exception here?
        }
        heap_size ++;
        heap[heap_size] = new SWPQ_Element(Integer.MIN_VALUE, val);
        increaseKey(heap_size, key);
    }
    
    SWPQ_Element extractMax() {
        if (heap_size < 1) {
            System.out.println("Error: extract from empty heap!");
            return null;
        }
        SWPQ_Element emax = heap[1];
        heap[1] = heap[heap_size];
        heap_size--;
        maxHeapify(1);
        return emax; 
    }
    
    public void printHeap() {
        System.out.print("Heap Array size=");
        System.out.println(heap_size);
        for (int i=1; i <= heap_size; i++) {
            System.out.print(" "  + heap[i]);
        }
        System.out.println();
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        SWPQ_Heap h = new SWPQ_Heap();
        h.maxHeapInsert(5, 10);
        h.printHeap();
        h.maxHeapInsert(2, 100);
        h.printHeap();
        h.maxHeapInsert(18, 30);
        h.printHeap();
        h.maxHeapInsert(36, 0);
        h.printHeap();
        h.maxHeapInsert(12, 5);
        h.printHeap();
        h.maxHeapInsert(7, 11);
        h.printHeap();
        while (h.heap_size >=1) {
            SWPQ_Element e = h.extractMax();
            System.out.println("Removed " + e);
        }
        h.printHeap();
    }
    
}
