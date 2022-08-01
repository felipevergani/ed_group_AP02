package javaFila;

public class Struct {
    public Struct next;
    public int val;

    /**
     * @return the next
     */
    public Struct getNext() {
        return next;
    }

    /**
     * @param next the next to set
     */
    public void setNext(Struct next) {
        this.next = next;
    }

    /**
     * @return the val
     */
    public int getVal() {
        return val;
    }

    /**
     * @param val the val to set
     */
    public void setVal(int val) {
        this.val = val;
    }
    
}
