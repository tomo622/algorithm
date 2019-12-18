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
		int n; //정점 개수
		int m; //간선 개수
		int ad[][]; //인접행렬
		int v1, v2;
		
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		m = scanner.nextInt();
		ad = new int[n][n];
		for(int i = 0; i < m; i++) {
			v1 = scanner.nextInt() - 1;
			v2 = scanner.nextInt() - 1;
			
			ad[v1][v2] = 1;
			ad[v2][v1] = 1;
		}
		scanner.close();
		
		bfs(ad, 0);
	}

	private static void bfs(int ad[][], int first) {
		MyCircularQueue q = new MyCircularQueue(new int[ad.length + 1], 0); //원형 큐는 항상 한 자리가 빈다.
		int visit[] = new int[ad.length];
		
		int cur = first; //현재 정점
		
		//출발 정점 방문하고 큐에 삽입
		visit[cur] = 1;
		q.pushQueue(cur);
		
		while(true) {
				
			//방문 정점 출력
			System.out.print("visit: ");
			for(int i = 0; i < visit.length; i++) {
				System.out.print(visit[i] + " ");
			}
			System.out.println();
			
			//현재 정점의 자식 정점 방문하고 큐에 삽입(방문하지 않은 정점만)
			for(int i = 0; i < ad.length; i++) {
				if(visit[i] == 0 && ad[cur][i] == 1) {
					q.pushQueue(i);
					visit[i] = 1;
				}
			}
			
			//큐가 비어있다면 중단
			if(q.getCnt() == 0) {
				break;
			}
			else {
				//다음 검사를 위해 큐에 있는 가장 처음 정점을 꺼낸다.
				cur = q.popQueue();
			}
		}
	}
	
	static class MyCircularQueue{
		public int q[];
		public int cnt;
		private int front, rear;
		
		public MyCircularQueue(int[] q, int cnt) {
			this.q = q;
			cnt = 0;
			front = 0;
			rear = 0;
		}
		
		private int getNextIndex(int i) {
			return (i + 1) % q.length;
		}
		
		public boolean isEmpty() {
			if(front == rear) {
				System.out.println("circular queue is empty! current cnt : " + cnt);
				return true;
			}
			else {
				return false;
			}
		}
		
		public boolean isFull() {
			if(getNextIndex(rear) == front) {
				System.out.println("circular queue is full! current cnt : " + cnt);
				return true;
			}
			else {
				return false;
			}
		}
		
		public void pushQueue(int value) {
			if(!isFull()) {
				rear = getNextIndex(rear);
				q[rear] = value;
				cnt++;
				
				printQueue();
			}
		}
		
		public int popQueue() {
			if(!isEmpty()) {
				front = getNextIndex(front);
				int temp = q[front];
				q[front] = 0;
				cnt--;
				
				printQueue();
				return temp;
			}
			else {
				return 0;
			}
		}
		
		public int getCnt() {
			return cnt;
		}
		
		public void printQueue() {
			for(int i = 0; i < q.length; i++) {
				System.out.print(q[i] + " ");
			}
			System.out.println();
		}
	}
}
