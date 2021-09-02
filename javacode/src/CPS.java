public class CPS {

  public int countPS(String st) {
    return countPSRecursive(st, 0, st.length()-1);
  }

  private int countPSRecursive(String st, int startIndex, int endIndex) {
    if(startIndex > endIndex)
      return 0;

    // every string with one character is a palindrome
    if(startIndex == endIndex)
      return 1;

    int totalPSCount = 0;
    if(isPalindrome(st, startIndex, endIndex))
      totalPSCount = 1;

    // count all palindromes from "startIndex+1" to "endIndex"
    totalPSCount += countPSRecursive(st, startIndex+1, endIndex);
    // count all palindromes from "startIndex" to "endIndex-1"
    totalPSCount += countPSRecursive(st, startIndex, endIndex-1);
    // because of the above two recursive calls, since we have counted twice all
    // palindromes from "startIndex+1" to "endIndex-1", let's subtract one count
    totalPSCount -= countPSRecursive(st, startIndex+1, endIndex-1);

    return totalPSCount;
  }

  private boolean isPalindrome(String st, int x, int y) {
    while(x <= y) {
      if(st.charAt(x++) != st.charAt(y--))
        return false;
    }
    return true;
  }

  public static void main(String[] args) {
    CPS cps = new CPS();
    System.out.println(cps.countPS("abdbca"));
    System.out.println(cps.countPS("cddpd"));
    System.out.println(cps.countPS("pqr"));
    System.out.println(cps.countPS("qqq"));
  }
}