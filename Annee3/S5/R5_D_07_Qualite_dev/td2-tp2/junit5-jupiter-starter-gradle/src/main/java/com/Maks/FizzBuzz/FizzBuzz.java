package com.Maks.FizzBuzz;

public class FizzBuzz {

    public static String de(int nombre){

        if(nombre % 3 == 0){
            return "Fizz";
        }
        else{
            return "" + nombre + "";
        }
    };
}
