package javaFila;
import java.util.Scanner;

public class Lista {
    
        //usado para iniciar a lista
    public Struct init;
    
    //construtor da lista
    public void list(){  
        init = null;
    }
    

    //limpar lista
    public boolean isEmpty(){
        return init == null;
    }
    
    //buscar elementos
    public int[] search(int x){
        Struct nodo = new Struct();
        int i = 0;
        int[] aux = new int[3];
        nodo = init;
        for(nodo = init; nodo != null; nodo = nodo.getNext()){
            i++;
            if (x == nodo.getVal()){
                aux[1] = 1;
                aux[2] = i;
                return aux;
            }
        }
        //caso encontrar elementos
        aux[1] = 0;
        aux[2] = i;
        return aux;         
    }   

    //insercao de elementos
    public void insertInit(int x){ 
        Struct novoNo = new Struct();
        novoNo.setVal(x);
        //novoNo referencia o inicio antigo
        novoNo.setNext(init);
        // inicio referenciao novoNo 
        init = novoNo;     
    }
    
    //remove elementos do inicio
    public void removeInit(){
        //remove o primiero elemento e reposiciona o o tamanho
        init = init.getNext(); 
    }
    
    //insere no fim
    public void insertFinal(int x){
        Struct ex = new Struct();
        Struct aux1 = new Struct();
        Struct aux = new Struct();
        ex.setVal(x);
        ex.setNext(init);
        init = ex;
        
       
        aux = init;
        aux1 = init;
        int aj, ajd;
        for(ex = init; ex.getNext() != null; ){
            aj = aux.getVal();
            aux1 = aux1.getNext();
            ajd = aux1.getVal();
            ex.setVal(ajd);
            ex = ex.getNext();
            ex.setVal(aj);
            aux = aux.getNext();
        }
    }
    
    //remove no fim
    public void removeFinal(){
        Struct exx = new Struct();
        exx = init;
        if(exx.getNext() == null){
            removeInit();
        }else{
            Struct ex = exx;
            exx = init;
            int i = 0;
            for(ex = init;ex.getNext() != null ; ){
                ex = ex.getNext();
                if(i > 0) exx = exx.getNext();
                i++;
                if(ex.getNext() == null){
                    exx.setNext(null);
                    break;
                }
            }
        }
    }
   
    
    //printar os elemntos da lista
    public String printList(){
        //testar se esta vazia antes de printar
        if(isEmpty()) return "Lista vazia\n"; 
        String str = "Fila :";
        for (Struct nodo = init; nodo != null; nodo = nodo.getNext())
            str += " "+ nodo.getVal();
        return str + "\n";
    }
}