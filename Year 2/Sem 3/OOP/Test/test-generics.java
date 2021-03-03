
public class Main {
    public static void main(String args[]){
        Integer arrInt[] = new Integer[]{1, 2, 3, 4, 5};
        Character arrChar[] = new Character[]{'1', '2', '3', '4', '5'};
        Float arrFloat[] = new Float[]{1.5f, 2.5f, 3.5f, 4.5f, 5.5f};

        printArr(arrInt);
        printArr(arrChar);
        printArr(arrFloat);
        
        revEle(arrInt, 2, 3);
        revEle(arrChar, 3, 2);
        revEle(arrFloat, 0, 2);
        
        printArr(arrInt);
        printArr(arrChar);
        printArr(arrFloat);

        System.out.println("");

        try{
            validate(9);
            validate(20);
        } catch (InvalidException e){
            e.printStackTrace();
        }
    }    

    public static <E> void revEle(E[] arr, int pos1, int pos2){
        if(pos1>arr.length || pos2>arr.length){
            System.out.println("Wrong Inputs");
            return;
        }

        E temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }

    public static <E> void printArr(E[] arr){
        System.out.print("The Array is : ");
        for(int i=0; i<arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println("");
    }

    public static void validate(int x) throws InvalidException{
        if (x>10)
            throw new InvalidException("NON VALID");
        else
            System.out.println("Very Good");
    }
}

@SuppressWarnings("serial")
class InvalidException extends Exception {
    InvalidException(String s){
        super(s);
    }
}

