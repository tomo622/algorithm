import java.util.Scanner;
/* test data
7
7
1 2
1 3
2 4
2 5
4 6
5 6
3 7

9
8
1 2
1 4
1 8
2 3
4 5
4 7
5 6
8 9

5
7
1 2
1 3
1 5
2 3 
3 4
4 5
3 5
 */
public class main {

	public static void main(String[] args) {
		int ad[][] = null; //인접행렬
		int vertexCnt = 0; //정점 개수
		int edgeCnt = 0; //간선 개수
		int v1, v2;
		
		Scanner scanner = new Scanner(System.in);
		vertexCnt = scanner.nextInt();
		ad = new int[vertexCnt][vertexCnt];
		edgeCnt = scanner.nextInt();
		for(int i = 0; i < edgeCnt; i++) {
			v1 = scanner.nextInt() - 1 ;
			v2 = scanner.nextInt() - 1;
			
			ad[v1][v2] = 1;
			ad[v2][v1] = 1;
		}
		scanner.close();
		
		int visit[] = new int[ad.length];
		dfs(ad, visit, 0);
		System.out.println();
		for(int i = 0; i < visit.length; i++) {
			System.out.print(visit[i] + " ");
		}
		
	}

	private static void dfs(int ad[][], int visit[], int start) {
		visit[start] = 1;
		System.out.print(start + " ");
		
		for(int i = 0; i < ad.length; i++) {
			if(ad[start][i] == 1 && visit[i] != 1) {
				dfs(ad, visit, i);
			}
		}
	}
}
