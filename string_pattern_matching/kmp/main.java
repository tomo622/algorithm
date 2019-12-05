import java.util.Scanner;

/* make pi array test data
AAABAA
012012

abcdabcefabc
000012300123

abacaaba
00101123

abcabbbcabc
00012000123
 */
public class main {

	public static void main(String[] args) {
		String text = null;
		String pattern = null;
		
		Scanner scanner = new Scanner(System.in);
		text = scanner.nextLine();
		pattern = scanner.nextLine();
		scanner.close();

		System.out.println(kmp(text, pattern) + "개 찾았습니다.");
	}
	
	private static int kmp(String text, String pattern) {		
		int foundCnt = 0;
		
		int[] pi = makePiArray(pattern);
		
		int j = 0;
		for(int i = 0; i < text.length(); i++) {
			while(j > 0 && text.charAt(i) != pattern.charAt(j)) {
				j = pi[j - 1];
			}
			
			if(text.charAt(i) == pattern.charAt(j)) {
				if(j == pattern.length() - 1) {
					foundCnt++;
					j = pi[j];
				}
				else {
					j++;
				}
			}
		}
		
		return foundCnt;
	}

	private static int[] makePiArray(String pattern) {
		int[] pi = new int[pattern.length()];
		for(int i = 0; i < pi.length; i++) {
			pi[i] = 0;
		}
		
		int j = 0;
		for(int i = 1; i < pattern.length(); i++) {
			
			while(j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
				j = pi[j - 1];
			}
			
			if(pattern.charAt(i) == pattern.charAt(j)) {
				pi[i] = ++j;
			}
		}
		
		/*
		for(int i = 0; i < pi.length; i++) {
			System.out.print(pi[i]);
		}
		System.out.println();
		*/
		
		return pi;
	}
}
