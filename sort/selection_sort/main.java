import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		int dataSize = 0;
		int[] dataList = null;
		
		Scanner scanner = new Scanner(System.in);
		dataSize = scanner.nextInt();
		dataList = new int[dataSize];
		for(int i = 0; i < dataSize; i++) {
			dataList[i] = scanner.nextInt();
		}
		scanner.close();
		
		selectionSort(dataList);
		
		for(int data : dataList) {
			System.out.println(data);
		}
	}

	private static void selectionSort(int[] dataList) {
		int minIndex = 0;
		
		for(int i = 0; i < dataList.length - 1; i++) {
			minIndex = i;
			
			for(int j = i + 1; j < dataList.length; j++) {
				if(dataList[minIndex] > dataList[j]) {
					minIndex = j;
				}
			}
			
			if(minIndex != i) {
				swap(dataList, minIndex, i);
			}
		}
	}
	
	private static void swap(int[] arr, int a, int b) {
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
}
