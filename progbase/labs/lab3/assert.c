#include "assert_.h"
#include "header.h"





void test1(void){
   struct Computer_Game test[2] = {
     {"Game1","dsfsd",1231,12.3,{"android","one"}},
   };
   rerecording(test,2,2,1);
   assert(strcmp(test[0].fullname,test[1].fullname)== 0);
   assert(strcmp(test[0].genre,test[1].genre)== 0);
   assert(test[0].year == test[1].year);

   assert(strcmp(test[0].games.platform,test[1].games.platform)== 0);
   assert(strcmp(test[0].games.numbers_of_player,test[1].games.numbers_of_player)== 0);



}

void test2(void){
   struct Computer_Game test[2] = {
     {"Game2","honka",1998,24.3,{"MacOS","two"}},
   };
   remove_array(test,2,1);
   assert(strcmp(test[0].fullname,"")== 0);
   assert(strcmp(test[0].genre,"")== 0);
   assert(test[0].year == 0);
   assert(strcmp(test[0].games.platform,"")== 0);
   assert(strcmp(test[0].games.numbers_of_player,"")== 0);




}
void test3(void){
 char string1 []= "ghghj";
 char string2 []= "1232";
 char string3 []= "1game";
 char string4 []= "G2ame";
 char string5 []= "Need for Speed";

  assert(valid_Computer_Reverse_record2 (string1) == 0);
  assert(valid_Computer_Reverse_record2 (string2) == 1);
  assert(valid_Computer_Reverse_record2 (string3) == 1);
  assert(valid_Computer_Reverse_record2 (string4) == 1);
  assert(valid_Computer_Reverse_record2 (string5) == 0);


}
