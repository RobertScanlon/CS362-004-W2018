

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
   
   private class testUrlPiece {
	   String urlPiece;
	   Boolean valid;
	   public testUrlPiece(String piece, Boolean vld) {
		   urlPiece = piece;
		   valid = vld;
	   }
   }
   
   public void testIsValid() throws FileNotFoundException, UnsupportedEncodingException
   {
	   // set up schemes to include in testing
	   testUrlPiece testSchemes[] = {
			   new testUrlPiece("http://", true),
			   new testUrlPiece("https://", true),
			   new testUrlPiece("ftp://", true),
			   new testUrlPiece("abcd://", true),
			   new testUrlPiece("a45b://", true),
			   new testUrlPiece("4ttp://", false),
			   new testUrlPiece("http//", false),
			   new testUrlPiece("http:/", false),
			   new testUrlPiece("http/", false),
			   new testUrlPiece("://", false),
	   };
	   
	   testUrlPiece testAuthorities[] = {
			   new testUrlPiece("www.awebsite.com", true), 
			   new testUrlPiece("www.com", true),
			   new testUrlPiece("www.1.com", true),
			   new testUrlPiece("awebsite.com", true),
			   new testUrlPiece("AAA.awebsite.com", true),
			   new testUrlPiece("0.0.0.0", true),
			   new testUrlPiece("1.1.1.1", true),
			   new testUrlPiece("255.255.255.255", true),
			   new testUrlPiece("255.255.255.256", false),
			   new testUrlPiece("www.a.website.com", false),
			   new testUrlPiece("www.a.website.cmm", false),
			   new testUrlPiece("", false),
			   new testUrlPiece("abcde", false),
			   new testUrlPiece("12345", false),
			   new testUrlPiece("-1", false),	   
	   };
	   
	   testUrlPiece testPorts[] = {
			   new testUrlPiece(":80", true),
			   new testUrlPiece(":8080", true),
			   new testUrlPiece(":0", true),
			   new testUrlPiece(":65535", true),
			   new testUrlPiece("", true),
			   new testUrlPiece("-1", false),
			   new testUrlPiece("abc", false),
			   new testUrlPiece("65536", false),
	   };
	   
	   testUrlPiece testPaths[] = {
			   new testUrlPiece("", true),
			   new testUrlPiece("/abc", true),
			   new testUrlPiece("/.abc", true),
			   new testUrlPiece("/abc/", true),
			   new testUrlPiece("/ab.c", true),
			   new testUrlPiece("/123", true),
			   new testUrlPiece("/123/abc", true),
			   new testUrlPiece("/abc/123/efd", true),
			   new testUrlPiece("/..", false),
			   new testUrlPiece("/...", false),
			   new testUrlPiece("/..", false),
			   new testUrlPiece("//", false),
			   new testUrlPiece("/abc//", false),
	   };
	   
	   testUrlPiece testQueries[] = {
			   new testUrlPiece("", true),
			   new testUrlPiece("?name=value", true),
			   new testUrlPiece("?name=~value", true),
			   new testUrlPiece("?name=value&othername=123", true),
			   new testUrlPiece("?name=value&other name=123", false),
	   };
	   
	   // output log files
	   PrintWriter logFile = new PrintWriter("./testIsValid.log", "UTF-8");
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   // flag to tell whether validator should return true or false
	   Boolean urlIsValid = false;
	   
	   // the final url to be tested
	   String testUrl = "";
	   
	   // return value from isValid
	   Boolean returnFromIsValid = false;
	   
	   // is code crashed
	   Boolean crashed = false;
	   
	   // loop through all schemas
	   for (int schIdx = 0; schIdx < testSchemes.length - 1; schIdx++) {
		   
		   // all authorities
		   for (int authIdx = 0; authIdx < testAuthorities.length; authIdx++) {
			   
			   // all ports
			   for (int portIdx = 0; portIdx < testPorts.length; portIdx++) {
				   
				   // all paths
				   for (int pathIdx = 0; pathIdx < testPaths.length; pathIdx++) {
					   
					   // all queries
					   for (int qryIdx = 0; qryIdx < testQueries.length; qryIdx++) {
						   
						   // if any part of the url is invalid, the whole is invalid,
						   // otherwise it is valid
						   if (     testSchemes[schIdx].valid == false ||
							   testAuthorities[authIdx].valid == false ||
							         testPorts[portIdx].valid == false ||
							         testPaths[pathIdx].valid == false ||
							        testQueries[qryIdx].valid == false) {
							   urlIsValid = false;
						   } else {
							   urlIsValid = true;
						   }
						   
						   // build final test url
						   testUrl = testSchemes[schIdx].urlPiece +
								     testAuthorities[authIdx].urlPiece +
								     testPorts[portIdx].urlPiece +
								     testPaths[pathIdx].urlPiece +
								     testQueries[qryIdx].urlPiece;
						   
						   // call isValid with test url
						   crashed = false;
						   try {
							   returnFromIsValid = urlVal.isValid(testUrl);
						   } catch (Throwable err) {
							   crashed = true;
						   }
						   
						   if (crashed == false) {
						   
							   if ((returnFromIsValid == true && urlIsValid == true) ||
								   (returnFromIsValid == false && urlIsValid == false)) {
								   logFile.println("PASSED " + testUrl + " isValid=" + returnFromIsValid.toString() + " urlIsValid=" + urlIsValid.toString());
							   } else {
								   logFile.println("FAILED " + testUrl + " isValid=" + returnFromIsValid.toString() + " urlIsValid=" + urlIsValid.toString());
							   }
						   } else {
							   logFile.println("URLVALIDATOR CRASHED " + testUrl);
						   }
					   }
				   }
			   }
		   }
	   }
	   
	   logFile.close();
   }
   
   
   public static void main(String args[]) throws IOException
   {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
//	   fct.testManualTest();
//	   fct.testYourFirstPartition();
//	   fct.testYourSecondPartition();
//	   fct.testYourThirdPartition();
//	   fct.testYourFourthPartition();
	   fct.testIsValid();
}
	   

}
