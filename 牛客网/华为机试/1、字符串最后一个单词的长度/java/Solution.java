import java.util.Scanner;
public class test_main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String s = "";
        while(input.hasNextLine()){
            s = input.nextLine();

            String[] split = s.split(" ");
            int n = split[split.length-1].length();

            System.out.println(n);
        }
    }
}
