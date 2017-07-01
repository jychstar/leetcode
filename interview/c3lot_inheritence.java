class A{
    public void printName(){
        System.out.println("Value-A");
    }
}

class B extends A{
    public void printName(){
        System.out.println("Value-B");
    }
}

class C extends A{
    public void printName(){
        System.out.println("Value-C");
    }
}

public class vanilla {

    public static void main(String args[])  {

        B b = new B();
        C c = new C();
        //b = c; // error, incompatible types:  C cannot be converted to B
        newPrint(b); // print value-B
    }
    public static void newPrint(A a){
        a.printName();
    }
}