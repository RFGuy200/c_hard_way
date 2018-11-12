#include "minunit.h"
#include <bstrlib.h>

#define CSR_PATH(filename) <common/csr/clockmatrix/fpga/filename>
#define FOLDER_PATH(argument) <argument>

#include FOLDER_PATH(string.h)

char *test_demo()
{
  return NULL;
}

/*char *testBsplit()
{
  bstring longString = bfromcstr( "First Second Third");
  bstrList stringList = bsplit( longString, ' ');
  
  return NULL;
}*/

char *testBfromCstr()
{
  char *cString = "This is a string from C";
  bstring betterString = bfromcstr( cString);

  
  MU_ASSERT( (strcmp((char*) betterString->data, cString) == 0),\
   "bfromcstr function does not work");

  return NULL;
}

char *testBstrcpy()
{
  bstring betterStringOne = bfromcstr( "This is string number one.");
  bstring betterStringTwo = bstrcpy( betterStringOne );

  MU_ASSERT( (!bstrcmp( betterStringOne, betterStringTwo)), \
    "bstring one is not equal to bstring two." );

  return NULL;
}

char *testBstrassign()
{
  bstring betterStringOne = bfromcstr( "This is string number one.");
  bstring betterStringTwo = bfromcstr( "This is string number two.");

  bassign( betterStringTwo, betterStringOne);
  MU_ASSERT( (!bstrcmp( betterStringOne, betterStringTwo)), \
    "bstring one is not equal to bstring two." );

  return NULL;
}

char *all_tests(){

  MU_SUITE_START();

  MU_RUN_TEST(test_demo);
  MU_RUN_TEST(testBfromCstr);
  MU_RUN_TEST(testBstrcpy);
  MU_RUN_TEST(testBstrassign);
  
  return NULL;
}

RUN_TESTS(all_tests);


