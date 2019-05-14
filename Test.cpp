#include <iostream>
#include <sstream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"


using namespace std;
using namespace itertools;
#include "badkan.hpp"

int main(){
badkan::TestCase testcase;
int grade=0;
int signal = setjmp(badkan::longjmp_buffer);
if (signal == 0) {



	//////range test
	testcase.setname("range check");

	int j=5;
	for (int i: range(5,9)){
		testcase.CHECK_EQUAL(i,j);
		j++;
	}
	 j=0;
	for (int i: range(0,9)){
		testcase.CHECK_EQUAL(i,j);
		j++;
	}
	 j=-5;
	for (int i: range(-5,9)){
		testcase.CHECK_EQUAL(i,j);
		j++;
	}
	double j1 = 5.1;
	for (double i: range(5.1,9.1)){
		testcase.CHECK_EQUAL(i,j1);
		j1+=1;
		}
	j1 = 0.1;
	for (double i: range(0.1,9.1)){
		testcase.CHECK_EQUAL(i,j1);
		j1+=1;
		}
	j1 = -5.1;
	for (double i: range(-5.1,9.1)){
		testcase.CHECK_EQUAL(i,j1);
		j1+=1;
		}
	char j2='a';
	for (char i: range('a','e')){
		testcase.CHECK_EQUAL(i,j2);
		j2++;
	}
	
	
	
	// Chain tests
	
	testcase.setname("chain check");
	int arr [] = {1,2,3,5,6,7}; 
	j=0;
	for (int i: chain(range(1,4), range(5,8))){
		testcase.CHECK_EQUAL(i,arr[j]);    // prints 123567
		j++;
	}
	int arr1 [] = {-5,-4,-3,-2,-1,0,5,6,7}; 
	j=0;
	for (int i: chain(range(-5,1), range(5,8))){
		testcase.CHECK_EQUAL(i,arr1[j]);    // prints 123567
		j++;
	}
	
	double arr2 [] = {-5.1,-4.1,-3.1,5.1,6.1,7.1}; 
	j=0;
	for (int i: chain(range(-5.1,-2.1), range(5.1,8.1))){
		testcase.CHECK_EQUAL(i,arr2[j]);    // prints 123567
		j++;
	}
	
	char str [] = "abchello";
	for (char i: chain(range('a','e'), string("hello"))){
		   testcase.CHECK_EQUAL(i,str[j]); // abcdhello
		   
}
	char str1 [] = "helloabc";
	for (char i: chain( (string("hello")),range('a','e'))){
		   testcase.CHECK_EQUAL(i,str1[j]); // abcdhello
		   }


		  /////zip check 
	testcase.setname("zip check");

  j=0;
  string strArr1 []={"2,0","3,1","4,2","5,3","6,4"};
  for (auto i: zip(range(2,7), range(0,5)))
  {
		testcase.CHECK_OUTPUT(i,strArr1[j]);
		j++;

  }


//   j=0;
//   string strArr []={"1,h","2,e","3,l","4,l","5,o"};
//   for (auto i: zip(range(1,6), string("hello")))
//   {
// 		testcase.CHECK_OUTPUT(i,strArr[j]);
// 		j++;

//   }
// j=0;
// string strArr2 []={"2,n","3,a","4,o","5,r","6,e"};
// for (auto i: zip(range(2,7), string("naore")))
// {
// 		testcase.CHECK_OUTPUT(i,strArr2[j]);
// 		j++;

// }

///product test
testcase.setname(" check product");

	  j=0;
		string productAns []={"1,q","1,w","1,e","2,q","2,w","2,e"};
    for (auto i: product(range(1,3), string("qwe")))
    {
		testcase.CHECK_OUTPUT(i,productAns[j]);
		j++;

    }

    j=0;
		string productAns1 []={"1,4","5,","1,5","2,4","2,5","2,6"};
    for (auto i: product(range(1,3), range(4,7)))
    {
		testcase.CHECK_OUTPUT(i,productAns[j]);
		j++;

    }

    j=0;
		string productAns2 []={"-3,q","-3,w","-3,e","-2,q","-2,w","-2,e", "-1,q", "-1,w", "-1,r"};
    for (auto i: product(range(-3,0), string("qwe")))
    {
		testcase.CHECK_OUTPUT(i,productAns[j]);
		j++;

    }

		////check powerset

		testcase.setname("powerset check");
    j=0;
   string powersetAns [] = {"{}","{1}", "{2}","{1,2}"};
   for (auto i: powerset(range(1,3)))
   {
		testcase.CHECK_OUTPUT(i,productAns[j]);
		j++;

   }

	 j=0;
   string powersetAns1 [] = {"{}","{4}", "{5}","{7}","{6}","{4,7}","{4,8}","{4,5}","{5,7}","{5,8}","{7,8}","{4,7,8}","{5,7,8}","{4,5,7}","{4,5,8}","{4,5,7,8}"};
   for (auto i: powerset(chain(range(4,6),range(7,9))))
   {
		testcase.CHECK_OUTPUT(i,productAns1[j]);
		j++;

   }

	 j=0;
   string powersetAns2 [] = {"{}","{1}", "{2}","{q}", "{w}" ,"{1,2}", "{1,q}", "{1,w}","{2,q}", "{2,w}", "{q,w}","{1,2,q}","{1,2,w}", "{2,q,w}","{1,q,w}","{1,2,q,w}"};
   for (auto i: powerset(chain(range(1,3), string("qw"))))
   {
		testcase.CHECK_OUTPUT(i,powersetAns2[j]);
		j++;

   }










testcase.print(cout, /*show_grade=*/false);
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;


	}

	

