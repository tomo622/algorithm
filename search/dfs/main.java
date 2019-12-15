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
			v1 = scanner.nextInt() - 1;
			v2 = scanner.nextInt() - 1;
			
			ad[v1][v2] = 1;
			ad[v2][v1] = 1;
		}
		scanner.close();
		
//		for(int row[] : ad) {
//			for(int cell : row) {
//				System.out.print(cell + " ");
//			}
//			System.out.println();
//		}
		
		System.out.println("<<<<<<<<< dfs - stack >>>>>>>>>");
		dfs(ad, 0);
		
		System.out.println("\n<<<<<<<<< dfs - recursion >>>>>>>>>");
		int visit[] = new int[ad.length];
		dfsRecursion(ad, visit, 0);
		System.out.println();
		for(int i = 0; i < visit.length; i++) {
			System.out.print(visit[i] + " ");
		}
	}
	
	private static void dfsRecursion(int ad[][], int visit[], int start) {
		visit[start] = 1;
		System.out.print(start + " ");
		
		for(int i = 0; i < ad.length; i++) {
			if(ad[start][i] == 1 && visit[i] != 1) {
				dfsRecursion(ad, visit, i);
			}
		}
	}
	
	private static void dfs(int ad[][], int first) {
		MyStack myStack = new MyStack(new int[ad.length], 0);
		int check[] = new int[ad.length];
		
		int visit = first; //방문정점	
		while(true) {
			check[visit] = 1;
			
			boolean found = false;
			for(int i = 0; i < ad.length; i++) { //i는 인접정점
				//방문하지 않은 인접정점인지 확인
				if(ad[visit][i] == 1 && check[i] != 1) {
					myStack.pushStack(visit);
					visit = i;
					found = true;
					break;
				}
			}
			
			//방문하지 않은 인접한 정점이 없는 경우
			if(!found) {	
				//스택이 비어있는지 확인, 비었으면 종료
				//비어있지 않으면 스택을 pop 하고 해당 정점을 방문
				if(myStack.getStackCnt() == 0) {
					break;
				}
				else {
					visit = myStack.popStack();	
				}
			}
		}
		
		System.out.print("visit check: ");
		for(int i = 0; i < check.length; i++) {
			System.out.print(check[i] + " ");
		}
		System.out.println();
	}
	
	static class MyStack{
		public int cnt;
		public int st[];
		
		public MyStack(int st[], int cnt) {
			this.st = st;
			this.cnt = cnt;
		}
		
		public void pushStack(int value) {
			st[cnt++] = value;
			printStack();
		}
		
		public int popStack() {
			int temp = st[cnt-1];
			st[cnt-1] = 0;
			cnt--;
			printStack();
			return temp;
		}
		
		public int getStackCnt() {
			return cnt;
		}
		
		public void printStack() {
			for(int i = 0; i < st.length; i++) {
				System.out.print(st[i] + " ");
			}
			System.out.println();
		}
	}
}
