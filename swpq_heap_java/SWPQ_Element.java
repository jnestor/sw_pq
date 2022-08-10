/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package swpq_heap;

/**
 *
 * @author nestorj  
 */
public class SWPQ_Element {
    private int key;
    private int value;
    
    public int getKey() { return key; }
    
    public void setKey(int k) { key = k; }
    
    public int getValue() { return value; }
    
    public String toString() {
        return key + "<" + value + ">";
    }
    
    public SWPQ_Element(int k, int v) {
        key = k;
        value = v;
    }
    
    
}
