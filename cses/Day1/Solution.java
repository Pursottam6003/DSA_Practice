import java.io.*;
import java.util.regex.*;

public class Solution {
    public static void main(String[] args) {
        Regex_Test tester = new Regex_Test();
        tester.checker("^(?=(?:[^ac]*[ac][^ac]*[ac])*(?:[^ac]*$))(?=(?:[^bd]*[bd][^bd]*[bd])*(?:[^bd]*$))[abcd]*$"); // Use \\ instead of using \
    }
}

class Regex_Test {
    public void checker(String Regex_Pattern) {
        Scanner input = new Scanner(System.in);
        String Test_String = input.nextLine();
        Pattern p = Pattern.compile(Regex_Pattern);
        Matcher m = p.matcher(Test_String);
        System.out.println(m.find());
    }
}