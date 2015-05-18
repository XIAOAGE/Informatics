
/*
    This template includes how to construct suffix array and build a
    height array to find the height array, which is for find the longest
    prefix of suffixes
 */

import java.util.Scanner;


public class Suffix_Array {

    private String[] text;
    private int length;
    private int[] index;
    private String[] suffix;
    private int[] rank;
    private int[] height;
    static private String word;

    public Suffix_Array(String text)
    {
        this.text = new String[text.length()];

        for (int i = 0; i < text.length(); i++)
        {
            this.text[i] = text.substring(i, i+1);
        }

        this.length = text.length();
        this.index = new int[length];
        for (int i = 0; i < length; i++)
        {
            index[i] = i;
        }

        suffix = new String[length];
    }

    public void createSuffixArray()
    {
        for(int index = 0; index < length; index++)
        {
            String text = "";
            for (int text_index = index; text_index < length; text_index++)
            {
                text+=this.text[text_index];
            }
            suffix[index] = text;
        }

        int back;
        for (int iteration = 1; iteration < length; iteration++)
        {
            String key = suffix[iteration];
            int keyindex = index[iteration];

            for (back = iteration - 1; back >= 0; back--)
            {
                if (suffix[back].compareTo(key) > 0)
                {
                    suffix[back + 1] = suffix[back];
                    index[back + 1] = index[back];
                }
                else
                {
                    break;
                }
            }
            suffix[ back + 1 ] = key;
            index[back + 1 ] = keyindex;
        }

        cal_height();

                                                    //For out out is here
        int max = -1;
        for(int i=0; i<word.length(); i++){
            max = Math.max(max, height[i]);
        }
        System.out.println(max);
		/*
        System.out.println("SUFFIX \t INDEX");
        for (int iterate = 0; iterate < length; iterate++)
        {
            System.out.println(suffix[iterate] + "\t" + index[iterate]);
        }

        for(int x: height){
        	System.out.print(x+" ");
        }
        System.out.println();
		 */

    }

    public void cal_height(){
        rank = new int[length];
        height = new int[length];

        for(int i=0; i<length; i++) rank[index[i]] = i;
        height[0] = 0;
        for(int i=0,h=0; i<length; i++){
            if(rank[i]>0){
                int j = index[rank[i]-1];
                while(i+h<length && j+h<length && word.charAt(i+h)==word.charAt(j+h)) h++;
                height[rank[i]] = h;
                if(h>0) h--;
            }
        }
    }

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        int count = 1;
        while(true){
            word = "";
            word = in.nextLine();
            if(word.equals("END")){break;}
            String temp = word;
            word += "$";
            for(int i=temp.length()-1; i>=0; i--){
                word += temp.charAt(i);
            }
            System.out.printf("Case %d: ", count++);
            Suffix_Array suffixarray = new Suffix_Array(word);
            suffixarray.createSuffixArray();
        }

    }

}

