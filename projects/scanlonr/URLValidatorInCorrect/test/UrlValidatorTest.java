

import junit.framework.TestCase;
import java.io.*;






public class UrlValidatorTest extends TestCase {

	String[] validSchemes = {"http://", "ftp://", "h3t://", ""};
	String[] invalidSchemes = {"3ht://", "http:/", "http:", "http/", "://"};
	
	String[] validAuthority = {"www.google.com", "google.com", "www.amazon.com", "0.0.0.0", "255.255.255.255"};
	String[] invalidAuthority = {"go.a", "256.256.256.256", "1.2.3.4", "google"};
	
	String[] validPort = {":80", ":0", ""};
	String[] invalidPort = {":-1", ":65a", ":65636"};
	
	String[] validPath = {"/test", "/test/", "/$23", "/test/test"};
	String[] invalidPath = {"/..", "/test//test", "/../"};
	
	
   public UrlValidatorTest(String testName) {
      super(testName);
}

   
   
   public void testManualTest() throws IOException
   {
	   //You can use this function to implement your manual testing
	   //Code suggested by "Java A Beginner's Guid, 6th Edition" by Schildt, Herbert, 2014
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String url;
	   System.out.println("Enter URLs for testing, one per line. Type 'stop' on a line by itself to quit");
	   do {
		   url = br.readLine();
		   try {
			   System.out.println(urlVal.isValid(url));
		   } catch (Throwable t) {
			   t.printStackTrace();
		   }		   
	   } while(!url.equals("stop"));	   
   }

	   
   
   
   // test different schemes
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String url;
	   
	   for(int i = 0; i < validSchemes.length; i++) {
		   
		   url = validSchemes[i] + "www.amazon.com";
		   
		   System.out.println("\nTesting Valid scheme: " + url);
		   
		   try {
			   System.out.println("Expected Result: true; Actual Result: " + urlVal.isValid(url));
		   }
		   catch(Throwable t){
			   t.printStackTrace();
		   }
	   }
	   
	   for(int i = 0; i < invalidSchemes.length; i++) {
		   
		   url = invalidSchemes[i] + "www.amazon.com";
		   
		   System.out.println("\nTesting Invalid scheme: " + url);
		   try {
			   System.out.println("Expected Result: false; Actual Result: " + urlVal.isValid(url));
		   }
		   catch(Throwable t){
			   t.printStackTrace();
		   }
	   }
   }
   
   // test different authority
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String url;
	   
	   for(int i = 0; i < validAuthority.length; i++) {
		   
		   url = "http://" + validAuthority[i];
		   
		   System.out.println("\nTesting Valid authority: " + url);
		   
		   try {
			   System.out.println("Expected Result: true; Actual Result: " + urlVal.isValid(url));
		   }
		   catch(Throwable t){
			   t.printStackTrace();
		   }
	   }
	   
	   for(int i = 0; i < invalidAuthority.length; i++) {
		   
		   url = "http://" + invalidAuthority[i];
		   
		   System.out.println("\nTesting Invalid authority: " + url);
		   
		   try {
			   System.out.println("Expected Result: false; Actual Result: " + urlVal.isValid(url));
		   }
		   catch(Throwable t){
			   t.printStackTrace();
		   }
	   }
   }
   
   public void testYourThirdPartition() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String url;
	   
	   for(int i = 0; i < validPort.length; i++) {
		   
		   url = "http://www.amazon.com" + validPort[i];
		   
		   System.out.println("\nTesting Valid port: " + url);
		   
		   try {
			   System.out.println("Expected Result: true; Actual Result: " + urlVal.isValid(url));
		   }
		   catch(Throwable t){
			   t.printStackTrace();
		   }
	   }
	   
	   for(int i = 0; i < invalidPort.length; i++) {
		   
		   url = "http://www.amazon.com" + invalidPort[i];
		   
		   System.out.println("\nTesting Invalid port: " + url);
		   
		   try {
			   System.out.println("Expected Result: false; Actual Result: " + urlVal.isValid(url));
		   }
		   catch(Throwable t){
			   t.printStackTrace();
		   }
	   }
   }
   
   public void testYourFourthPartition() {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String url;
	   
	   for(int i = 0; i < validPath.length; i++) {
		   
		   url = "http://www.amazon.com" + validPath[i];
		   
		   System.out.println("\nTesting Valid path: " + url);
		   
		   try {
			   System.out.println("Expected Result: true; Actual Result: " + urlVal.isValid(url));
		   }
		   catch(Throwable t){
			   t.printStackTrace();
		   }
	   }
	   
	   for(int i = 0; i < invalidPath.length; i++) {
		   
		   url = "http://www.amazon.com" + invalidPath[i];
		   
		   System.out.println("\nTesting Invalid path: " + url);
		   
		   try {
			   System.out.println("Expected Result: false; Actual Result: " + urlVal.isValid(url));
		   }
		   catch(Throwable t){
			   t.printStackTrace();
		   }
	   }
}
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   
   
   public static void main(String args[]) throws IOException
   {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
	   fct.testManualTest();
	   fct.testYourFirstPartition();
	   fct.testYourSecondPartition();
	   fct.testYourThirdPartition();
	   fct.testYourFourthPartition();
}
	   

}
