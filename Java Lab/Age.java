import java.util.*;

class father extends Exception{
    int age;
    father(int fage)
    {
        age = fage;
    }
}

class son extends father{
    int age1;
    son(int age, int sage)
    {
        super(age);
        age1 = sage;
    }
}

class Main{
    static void wrongage() throws ArithmeticException{
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the Father's age: ");
        int fage = in.nextInt();
        if(fage<=0)
        throw new ArithmeticException("age");
        else 
        System.out.println("The Father's age is: " + fage);
        System.out.println();
        System.out.println("Enter the age of Son: ");
        int sage = in.nextInt();
        if(sage>=fage)
        throw new ArithmeticException("sage");
        else
        System.out.println("Son's age is: " + sage);
        System.out.println();
    }
    
    public static void main(String args[]){
        try{
            wrongage();
        }
        catch(ArithmeticException e){
            System.out.println("Incorrect Age!");
        }
        finally{
            System.out.println("***END OF PROGRAM***");
        }
    }
}
