import java.util.Arrays;

//To calculate the number of call to the next_permutation function is necessary here

public class Next_Permutation {

    public static void main(String[] args){

        int[] arr = {1,2,3};
        for(int i=0; i<10; i++){
            nextPermutation(arr);
            for(int x: arr){
                System.out.print(x+" ");
            }
            System.out.println();
        }

    }

    public static void nextPermutation(int[] num)
    {
        if(num.length <= 1)
            return ;
        for(int i = num.length - 2; i >= 0; i--)
        {
            if(num[i] < num[i+1])
            {
                int j;
                for(j = num.length - 1; j >= i; j--)
                    if(num[i] < num[j])
                        break;
                // swap the two numbers.
                num[i] = num[i] ^ num[j];
                num[j] = num[i] ^ num[j];
                num[i] = num[i] ^ num[j];
                //sort the rest of arrays after the swap point.
                Arrays.sort(num, i+1, num.length);
                return ;
            }
        }
        //reverse the arrays.
        for(int i = 0; i < num.length / 2; i++)
        {
            int tmp = num[i];
            num[i] = num[num.length - i - 1];
            num[num.length - i - 1] = tmp;
        }
        return ;
    }


}
