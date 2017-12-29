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
        Test("Test for 1+1 == 2", [] {
    		if (1+1 != 2) {     // The operation you wanna check... 
    			return 1;       // Return an error code when something went wrong
    		}
    		return 0;           // Return 0 if everything went well
    	}));
	}
    ```

 3. Create a file that registers the tests and calls the tester:
    ```cpp
    int main(int argc, char *argv[]) {
    	registerTests();    // Register your tests

        // Run the Unit-Tester on the tests
    	return Tester::GetInstance()->TestEverthing();      
    }
    ```

 4. Run the file:
    The file above will create following output:
    ```txt
    --------------------------------------
    --------Testing the GameEngine--------
    --------------------------------------
     
	Test 1/1:   Test for 1+1 == 2
	Test number 1 passed!  Microseconds: 16 Nanoseconds: 467

    -----------------------------------
    ---------All tests passed!---------
    -----------------------------------
    ```

# How it works

We defined a macro called "Test(...)" which takes as first argument a string (type: ```std::string```) as a name for the test and  as second parameter a lambda function (type: ```std::function<int(void)>>)```. The Unit-Test itself has to be a lambda function which returns a 0 (zero), when everything went well and some arbitrary integer (not zero) to indicate an error.

Both of these parameters are passed to a singleton class called "Tester" which is essentialy a store for all test which is later used to execute them and builds the output string. The Tester uses ```time.h``` in Linux or MacOS and ```windows.h``` on Windows machines to measure how long a test runs.

# License

MIT
