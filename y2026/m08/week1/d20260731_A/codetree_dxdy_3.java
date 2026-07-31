package y2026.m08.week1.d20260731_A;
import java.util.Scanner;

public class codetree_dxdy_3 {
    
    private static int n, answer;

    public static int [] dx = new int[]{1, 0, -1, 0};  //E, S, W, N
    public static int [] dy = new int[]{0, -1, 0, 1};

    private static int [][] combine;

    static boolean inRange(int a, int b){
        if(a < 0 || a >= n || b < 0 || b >= n) return false;
        else return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        combine = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0;j < n;j++) {
                combine[i][j] = sc.nextInt();
            }
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                int count1 = 0;
                for(int dirI = 0;dirI < 4;dirI++){
                    int nx = i + dx[dirI];
                    int ny = j + dy[dirI];
                    if(inRange(nx, ny) && combine[nx][ny] == 1){
                        count1++;
                    }
                }
                if(count1 >= 3){answer += 1;}
            }
        }
        System.out.println(answer);
    }
}