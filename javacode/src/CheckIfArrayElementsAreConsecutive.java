
/**
 * http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/
 */
public class CheckIfArrayElementsAreConsecutive {

    public boolean areConsecutive(int input[]){
        int min = Integer.MAX_VALUE;
        for(int i=0; i < input.length; i++){
            if(input[i] < min){
                min = input[i];
            }
        }
        for(int i=0; i < input.length; i++){
            if(Math.abs(input[i]) - min >= input.length){
                return false;
            }
            if(input[Math.abs(input[i]) - min] < 0){
                return false;
            }
            input[Math.abs(input[i]) - min] = -input[Math.abs(input[i]) - min];
        }
        for(int i=0; i < input.length ; i++){
            input[i] = Math.abs(input[i]);
        }
        return true;
    }
    
    public static void main(String args[]){
        int input[] = {-1,-2,-3,-4};
        CheckIfArrayElementsAreConsecutive cia = new CheckIfArrayElementsAreConsecutive();
        System.out.println(cia.areConsecutive(input));
    }
}

