import junit.framework.TestCase;

public class isValidRandomTester extends TestCase {
	
	private final long NUM_RUNS = 1000;
	
	@Override
	protected void setUp() {
		
	}
	
	public isValidRandomTester(String testName) {
		super(testName);
	}
	
	public void testisValid() {
		UrlValidator urlVal = new UrlValidator();
		boolean allPassed = true;
		for (int i = 0; i < NUM_RUNS; i++) {
			if (urlVal.isValid("http://www.google.com") == false) {
				allPassed = false;
			}
		}
		assertTrue(allPassed);
	}

	public static void main(String[] args) {
		System.out.println("Hello isValidRandomTester!");
		isValidRandomTester rt = new isValidRandomTester("isValid Random Test");
		rt.setUp();
		rt.testisValid();
	}
}
