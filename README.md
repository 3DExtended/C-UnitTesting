# C-UnitTesting
This is a repository containing a cross-platform unit testing framework for C++ programs. It also includes a nanosecond based debugging tool which is used to track the time for each unit test.
Here is a list of the features:

 - Defining Unit-Tests using the lambda C++ pattern
 - Running multiple Unit-Tests in one pass
 - Receiving detailed information for each Unit-Test including it's runtime

# Usage

To use the Unit-Test features you have to follow those steps:

 1. Include the "Tester.h" file:
     ```cpp
    #include "../Tester.h"
    ```
 2. Register your Unit-Test:
    ```cpp
    void registerTests(){
        // Test no. 1
        Test("A test that never fails...", [] {
    		if (1+1 != 2) {     // The operation you wanna check... 
    			return 1;       // Return an error code when something went wrong
    		}
    		return 0;           // Return 0 if everything went well
    	}));
    	
    	// Test no. 2
    	Test("Some Unit-Test that fails...", [] {
    		if (1+1 == 2) {     // The operation you wanna check... 
    			return 1;       // Return an error code when something went wrong
    		}
    		return 0;           // Return 0 if everything went well
    	}));
	}
    ```
