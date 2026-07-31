package y2026.m08.week1.d20260731_A;
import java.util.Scanner;

public class codetree_dxdy_2 {

    
        public static int dir = 3; //북쪽 상태에서 시작
        private static int x, y;

        public static int [] dx = new int[]{1, 0, -1, 0};  //E, S, W, N
        public static int [] dy = new int[]{0, -1, 0, 1};

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            String command = sc.next();

            for (int i = 0; i < command.length(); i++) {
                char current = command.charAt(i);
                if (current == 'L') {
                    dir = (dir + 3) % 4;
                } else if (current == 'R') {
                    dir = (dir + 1) % 4;
                }
                if (current == 'F') {
                    x += dx[dir];
                    y += dy[dir];
                }
            }

            System.out.println(x + " " + y);
        }
}
