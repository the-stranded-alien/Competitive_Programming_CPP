// Big Integer Class in Java | Powerful (Lots Of Inbuilt Functions)
/*
Modular Arithmetic
GCD Calculation
Base Conversion
Power Calculation
Bitwise Operators
Prime Generation
and More.
*/

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    
    static void playWithBigInt() {

        Scanner sc = new Scanner(System.in);

        String s1 = sc.next();

        BigInteger b1 = new BigInteger(s1);
        BigInteger b2 = new BigInteger("1222222255555555");

        // Addition & Multiplication
        // b1 = b1.add(b2);
        b1 = b1.multiply(b2);

        //System.out.println(b1);

        // Bit Counts - Total Set Bits
        System.out.println(b1.bitCount());

        // Total Number Of Bits
        System.out.println(b1.bitLength());

        // Convert Integer Into Big Integer
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(a+b);

        BigInteger b3 = BigInteger.valueOf(a);
        BigInteger b4 = BigInteger.valueOf(b);

        // GCD of Big Integers
        System.out.println(b3.gcd(b4));

        // Base Conversion 
        // Interpret The Number In Given Base
        BigInteger b5 = new BigInteger("1001", 2);
        System.out.println(b5);

        // Power Function
        System.out.println(b3.pow(20));


    }

    public static void main(String args[]){
        playWithBigInt();
    }
}