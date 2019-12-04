
public class main {

	public static void main(String[] args) {
		String text = "TTTTATTATTTCTAACCAA";
		String pattern = "TTATTTCTA";
		
		System.out.println(bruteForce(text, pattern));
	}
	
	private static boolean bruteForce(String text, String pattern) {
		boolean found = false;
		
		for(int i = 0; i < text.length(); i++) {
			int j = 0;
			for(;j < pattern.length(); j++) {
				if(text.charAt(i+j) != pattern.charAt(j)) {
					break;
				}
			}
			
			if(j == pattern.length()) {
				found = true;
				break;
			}
		}
		
		return found;
	}
}
