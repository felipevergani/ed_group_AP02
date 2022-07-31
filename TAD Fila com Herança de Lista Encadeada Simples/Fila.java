package javaFila;

public class Fila {
    public Lista fila;
    
    public Fila(){
        fila = new Lista();
    }
    public void insertInit(int x){
        fila.insertInit(x);
    }
    
    public void removeInit(){
        fila.removeInit();
    }
    
    public void insertFinal(int x){
        fila.insertFinal(x);
    }
    
    public int[] search(int x){
        return fila.search(x);
    }
    
    public boolean isEmpty(){
        return fila.isEmpty();
    }
    
    public void removeFinal(){
        fila.removeFinal();
    }
    
    public String printList(){
        return fila.printList();
    }
}
