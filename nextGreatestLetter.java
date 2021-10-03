package com.company;

public class nextGreatestLetter {
    public static void main(String[] args) {
        char[] letters= {'c','f','j'};

        char target= 'c';
        System.out.println("the next greater element of the char "+target+" is "+nextgreatestLetter(letters,target));
        //char[] letter= {'f','e','d','c','b'};
        //System.out.println("the next greater element of the char "+target+" is "+ceiling(letter,target));

    }
    static char nextgreatestLetter(char[] array,char target){
        int start=0;
        int end = array.length-1;
        boolean isASC = array[start]<array[end];
        while(start<=end){
            int middle=start+(end-start)/2;    // we could have taken (start+end)/2 but the thing is it can
            // exceed the integer range when we add start and end that why we use


//                if(array[middle]==target)         // middle=start+(end-start)/2; formula
//                    return  array[middle+1];
//                if(target>array[array.length-1])
//                    return array[start];
                if(target<array[middle]){
                   end=middle-1;
                }
                else {
                  start=middle+1 ;

                }
        }
        return array[start%array.length];

    }

}

