package y2026.m08.week1.d20260731_A;
import java.util.Scanner;

public class codetree_dxdy_1 {
    private static int n, x, y;  //클래스 변수 자동 초기화

    public static int [] dx = new int[]{1, -1, 0, 0}; //E, W, S, N
    public static int [] dy = new int[]{0, 0, -1, 1};

    public static void main(String[] args){
            Scanner sc = new Scanner(System.in);

            n = sc.nextInt();

            while(n-- > 0){
                char cDir = sc.next().charAt(0); //이동방향
                int dist = sc.nextInt(); //이동한 거리

                int dir;
                if(cDir == 'E') dir = 0;
                else if(cDir == 'W') dir = 1;
                else if(cDir == 'S') dir = 2;
                else dir = 3;

                x += dx[dir] * dist;
                y += dy[dir] * dist;
            }
            System.out.print(x + " " + y);
        
    }
}
