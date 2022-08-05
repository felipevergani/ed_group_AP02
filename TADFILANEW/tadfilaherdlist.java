import java.util.Scanner;

/* 	
Felipe Brun Vergani
compilar javac tadfilaherdlist.java
executar java tadfilaherdlist
*/

public class tadfilaherdlist{
	public static void main(String[] agrs){
		Scanner ler = new Scanner(System.in);
        // TODO code application logic here
        Fila fil = new Fila();
    
        boolean para = true;
        while(para){
            int x, escolha;
            System.out.print("Inserir 1\nProcurar 2\nRemover 3\nPrint 4\nInserir no final 5\nRemove no Final 6\nSair 0\n>>");
            escolha = ler.nextInt();	
            switch(escolha){
                case 1:
                    System.out.print("Valor = ");
                    x = ler.nextInt();
                    fil.inserirInicio(x);
                    break;
                case 2:
                    if(fil.isEmpty())System.out.println("Lista vazia");
                    else{
                        System.out.print("Valor procurado = ");
                        x = ler.nextInt();
                        int[] a = new int[2];
                        a = fil.search(x);
                        if(a[1]==0) System.out.println("Valor não encontrado");
                        else System.out.println("Valor encontrado na posição "+a[2]);
                    }
                    break;
                case 3:
                    if(fil.isEmpty())System.out.println("\n\nLista vazia\n\n");else fil.removeInicio();
                    break;
                case 4:
                    if(fil.isEmpty())System.out.println("\n\nLista vazia\n\n");else System.out.print(fil.printFirstList());
                    break;
                case 5:
                    System.out.print("Valor = ");
                    x = ler.nextInt();
                    fil.insereFinal(x);
                    break;
                case 6:
                    if(fil.isEmpty())System.out.println("\n\nLista vazia\n\n");else fil.removeFinal();
                    break;
                case 0:
                    para = false;
                    break;
            }
        }
    }
}


class Struct{
    public Struct next;
    public int val;

    public Struct getNext() {
        return next;
    }

    public void setNext(Struct next) {
        this.next = next;
    }

   
    public int getVal() {
        return val;
    }

  
    public void setVal(int val) {
        this.val = val;
    }
}

class Lista{
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

		
		public void inserirInicio(int x){ 
			Struct novoNo = new Struct();
			novoNo.setVal(x);
			
			novoNo.setNext(init);
			
			init = novoNo;     
		}
		
		
		public void removeInicio(){
			
			init = init.getNext(); 
		}
		
		
		public void insereFinal(int x){
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
		
		
		public void removeFinal(){
			Struct exx = new Struct();
			exx = init;
			if(exx.getNext() == null){
				removeInicio();
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
		public String printFirstList(){
			//testar se esta vazia antes de printar
			if(isEmpty()) return "\n\nLista vazia\n\n"; 
			String str = "\nFila :";
			for (Struct nodo = init; nodo != null; nodo = nodo.getNext())
				str += " "+ nodo.getVal();
			return str + "\n\n";
		}
}

class Fila{
	public Lista fila;
    
    public Fila(){
        fila = new Lista();
    }
    public void inserirInicio(int x){
        fila.inserirInicio(x);
    }
    
    public void removeInicio(){
        fila.removeInicio();
    }
    
    public void insereFinal(int x){
        fila.insereFinal(x);
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
    
    public String printFirstList(){
        return fila.printFirstList();
    }
}
