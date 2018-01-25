#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <check.h>
#include "../module.h"

START_TEST (Computer_Game_newFromString_IfStringIsValid_ShouldReturnEqual)
{
  Computer_Game * game = 	Computer_Game_newFromString("game1 genre1 1232 123.20 Mac one");
	ck_assert(Computer_Game_is_equals(game, Computer_Game_new("game1","genre1",1232,123.20,"Mac","one")));
  Computer_Game_free(&game);
}
END_TEST
START_TEST (Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualNumberOfPlayer)
{
  Computer_Game * game = 	Computer_Game_newFromString("game1 genre1 1232 123.20 Mac one");
	ck_assert(!Computer_Game_is_equals_numbers_of_player(game, Computer_Game_new("game1","genre1",1232,123.20,"Mac","two")));
  Computer_Game_free(&game);

}
END_TEST
START_TEST (Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualPlatform)
{
  Computer_Game * game = 	Computer_Game_newFromString("game1 genre1 1232 123.20 Mac one");
	ck_assert(!Computer_Game_is_equals_platform(game, Computer_Game_new("game1","genre1",1232,123.20,"Android","one")));
  Computer_Game_free(&game);

}
END_TEST
START_TEST (Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualRating)
{
  Computer_Game * game = 	Computer_Game_newFromString("game1 genre1 1232 123.28 Mac one");
	ck_assert(!Computer_Game_is_equals_rating(game, Computer_Game_new("game1","genre1",1232,123.20,"Mac","one")));
  Computer_Game_free(&game);

}
END_TEST
START_TEST (Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualYear)
{
  Computer_Game * game = 	Computer_Game_newFromString("game1 genre1 1232 123.20 Mac one");
	ck_assert(!Computer_Game_is_equals_year(game, Computer_Game_new("game1","genre1",1238,123.20,"Mac","one")));
   Computer_Game_free(&game);
}
END_TEST
START_TEST (Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualGenre)
{
  Computer_Game * game = 	Computer_Game_newFromString("game1 genre1 1232 123.20 Mac one");
	ck_assert(!Computer_Game_is_equals_genre(game, Computer_Game_new("game1","genre3",1232,123.20,"Mac","one")));
  Computer_Game_free(&game);
}
END_TEST

START_TEST (Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualName)
{
  Computer_Game * game = 	Computer_Game_newFromString("game4 genre1 1232 123.20 Mac one");
	ck_assert(!Computer_Game_is_equals_fullname(game, Computer_Game_new("game1","genre1",1232,123.20,"Mac","one")));
  Computer_Game_free(&game);
}
END_TEST

START_TEST (Computer_Game_toString_IfComputerGameIsValid_ShouldReturnString)
{
	Computer_Game * game = Computer_Game_new("game1","genre1",1232,123.2,"Mac","one");
	char string[100];
	Computer_Game_toString(game, string);
	ck_assert_str_eq(string, "game1 genre1 1232 123.20 Mac one");
	Computer_Game_free(&game);
}
END_TEST
START_TEST (Computer_Game_toString_IfComputerGameIsNull_ShouldReturnNULL)
{

	char string[100];
	char * res =  Computer_Game_toString(NULL, string);
  ck_assert_ptr_null(res);

}
END_TEST
START_TEST (Computer_Game_toString_IfComputerGameBufferIsNull_ShouldReturnNULL)
{
  Computer_Game * game = Computer_Game_new("game1","genre1",1232,123.2,"Mac","one");
	char * res =  Computer_Game_toString(game, NULL);
  ck_assert_ptr_null(res);

}
END_TEST

START_TEST (listfree_emptyList_passes)
{
	List * list = List_new();
	List_free(&list);
  ck_assert_ptr_null(list);
}
END_TEST

START_TEST (listfree_oneItem_passes)
{
  const int testValue = 3;
	List * list = List_new();
	List_add(list, (int *)&testValue);
	List_free(&list);
}
END_TEST
START_TEST (listadd_checkIsEmpty_passes)
{
  const int testValue = 4;
	List * list = List_new();
  List_add(list, (int *)&testValue);
  ck_assert( !List_isEmpty(list));
	List_free(&list);
}
END_TEST
START_TEST (listadd_addElement_passes)
{
  const int testValue1 = 4;
	const int testValue2 = 5;
	const int testValue3 = 5;

	List * list = List_new();
  List_add(list, (int *)&testValue1);
	List_add(list, (int *)&testValue2);
	List_add(list, (int *)&testValue3);

	int result = List_count(list);
	ck_assert_int_eq(result,3 );

	List_free(&list);
}
END_TEST
START_TEST (listremove_SomeElements_passes)
{
  const int testValue1 = 3;
	List * list = List_new();
	List_add(list, (int *)&testValue1);
	List_add(list, (int *)&testValue1);
	List_remove(list,(int *)&testValue1);
	int result = List_count(list);
  ck_assert_int_eq(result,1 );
	List_free(&list);
}
END_TEST
START_TEST (listremove_NULLElement_passes)
{
  const int testValue1 = 3;
	List * list = List_new();
	List_remove(list,(int *)&testValue1);
	int result = List_count(list);
  ck_assert_int_eq(result,0);
	List_free(&list);
}
END_TEST


START_TEST (listcount_SomeElements_passes)
{
  const int testValue1 = 3;
	List * list = List_new();
  List_insert(list,0,(int *)&testValue1);
	int result = List_count(list);
  ck_assert_int_eq(result,1);
	List_free(&list);
}
END_TEST
START_TEST (listcount_NULLElement_passes)
{
  const int testValue1 = 3;
	List * list = List_new();
  List_insert(list,0,(int *)&testValue1);
	List_removeAt(list,0);
	int result = List_count(list);
  ck_assert_int_eq(result,0);
	List_free(&list);
}
END_TEST
START_TEST (listisEmpty_NULLElement_passes)
{
  const int testValue1 = 3;
	List * list = List_new();
	List_remove(list,(int *)&testValue1);
  ck_assert( List_isEmpty(list));
	List_free(&list);
}
END_TEST
START_TEST (listisEmpty_SomeElements_passes)
{
  const int testValue1 = 3;
	const int testValue2 = 12;
	List * list = List_new();
	List_add(list, (int *)&testValue1);
	List_add(list, (int *)&testValue2);
  ck_assert(!List_isEmpty(list));
	List_free(&list);
}
END_TEST
START_TEST (listinsert_SomeElements_passes)
{
  const int testValue1 = 3;
	const int testValue2 = 12;
	List * list = List_new();
	List_insert(list, 0,(int *)&testValue1);
	List_insert(list, 1,(int *)&testValue2);
	int result = List_count(list);
  ck_assert_int_eq(result,2);
	List_free(&list);
}
END_TEST
START_TEST (listinsert_NULLElement_passes)
{
  const int testValue2 = 12;
	List * list = List_new();
  List_insert(list, 0,(int *)&testValue2);
	List_removeAt(list,0);
	int result = List_count(list);
  ck_assert_int_eq(result,0);
	List_free(&list);
}
END_TEST
START_TEST (listnew_NewList_passes)
{

	List * list = List_new();
  int result = List_count(list);
  ck_assert_int_eq(result,0);
	List_free(&list);
}
END_TEST
START_TEST (listremoveAt_IndexOfDeleteElements_passes)
{
  const int testValue1 = 3;
	const int testValue2 = 12;
	List * list = List_new();
	List_insert(list, 0,(int *)&testValue1);
	List_insert(list, 1,(int *)&testValue2);
	List_removeAt(list,0);
	int i = List_indexOf(list,(int *)&testValue1);
  ck_assert_int_eq(i,-1);
	List_free(&list);
}
END_TEST
START_TEST (listremoveAt_DeleteOneElement_passes)
{


	const int testValue1 = 3;
	const int testValue2 = 12;
	List * list = List_new();
	List_insert(list, 0,(int *)&testValue1);
	List_insert(list, 1,(int *)&testValue2);
	List_removeAt(list,0);
	int result = List_count(list);
  ck_assert_int_eq(result,1);

	List_free(&list);
}
END_TEST
START_TEST (listset_OneElement_passes)
{
  const int testValue1 = 3;
	const int testValue2 = 4;

	List * list = List_new();
	List_insert(list, 0,(int *)&testValue1);
  List_set(list,0,(int *)&testValue2);
	int i = List_indexOf(list,(int *)&testValue2);
  ck_assert_int_eq(i,0);


	List_free(&list);
}
END_TEST



Suite *test_suite() {
  Suite *s = suite_create("Module");
  TCase * tc_structure = tcase_create("Structure");
	tcase_add_test(tc_structure, Computer_Game_toString_IfComputerGameIsValid_ShouldReturnString);
	tcase_add_test(tc_structure,Computer_Game_toString_IfComputerGameIsNull_ShouldReturnNULL);
  tcase_add_test(tc_structure,Computer_Game_toString_IfComputerGameBufferIsNull_ShouldReturnNULL);

  tcase_add_test(tc_structure,Computer_Game_newFromString_IfStringIsValid_ShouldReturnEqual);
  tcase_add_test(tc_structure,Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualName);
  tcase_add_test(tc_structure,Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualYear);
  tcase_add_test(tc_structure,Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualGenre);
  tcase_add_test(tc_structure,Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualRating);
  tcase_add_test(tc_structure,Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualPlatform);
  tcase_add_test(tc_structure,Computer_Game_newFromString_IfStringIsValid_ShouldReturnNotEqualNumberOfPlayer);


  TCase * tc_list = tcase_create("List");
  tcase_add_test(tc_list, listfree_oneItem_passes);
  tcase_add_test(tc_list, listfree_emptyList_passes);

  tcase_add_test(tc_list, listadd_checkIsEmpty_passes);
	tcase_add_test(tc_list, listadd_addElement_passes);

	tcase_add_test(tc_list, listremove_SomeElements_passes);
	tcase_add_test(tc_list, listremove_NULLElement_passes);

	tcase_add_test(tc_list, listcount_SomeElements_passes);
	tcase_add_test(tc_list, listcount_NULLElement_passes);

	tcase_add_test(tc_list, listisEmpty_NULLElement_passes);
	tcase_add_test(tc_list, listisEmpty_SomeElements_passes);

	tcase_add_test(tc_list, listinsert_SomeElements_passes);
	tcase_add_test(tc_list, listinsert_NULLElement_passes);

	tcase_add_test(tc_list, listnew_NewList_passes);

	tcase_add_test(tc_list, listremoveAt_DeleteOneElement_passes);
	tcase_add_test(tc_list,listremoveAt_IndexOfDeleteElements_passes);

	tcase_add_test(tc_list, listset_OneElement_passes);




  suite_add_tcase(s, tc_structure);
	suite_add_tcase(s, tc_list);

  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_VERBOSE);

  int num_tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return num_tests_failed;
}
