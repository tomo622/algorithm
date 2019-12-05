
public class main {

	public static void main(String[] args) {
		String text = "ABABA";//"TTTTATTATTTCTAACCAA";
		String pattern = "ABA";//"TTATTTCTA";
		
		System.out.println(bruteForce(text, pattern) + "개 찾았습니다.");
	}
	
	private static int bruteForce(String text, String pattern) {
		int foundCnt = 0;
		
		for(int i = 0; i < text.length(); i++) {
			if(i + pattern.length() > text.length()) {
				break;
			}
			
			int j = 0;
			for(;j < pattern.length(); j++) {
				if(text.charAt(i+j) != pattern.charAt(j)) {
					break;
				}
			}
			
			if(j == pattern.length()) {
				foundCnt++;
			}
		}
		
		return foundCnt;
	}
}
