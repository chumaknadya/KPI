#include "json.h"

void JsonLoader_loadFromString(Pensioner * pensioner, const char * jsonString) {
  
    json_error_t err;
	json_t * jsonArr = json_loads(jsonString, 0, &err);
    json_t * value = NULL;

    char * buff;
    int index = 0;
   
    buff = (char *)json_string_value(json_object_get(jsonArr, "name"));
    pensioner->name = (char *)malloc(sizeof(char)*(strlen(buff)+1));
	strcpy(pensioner->name, buff);
    buff = (char *)json_string_value(json_object_get(jsonArr, "surname"));
    pensioner->surname = (char *)malloc(sizeof(char)*(strlen(buff)+1));
	strcpy(pensioner->surname, buff);
    pensioner->year = json_integer_value(json_object_get(jsonArr, "year"));
	pensioner->GPA = json_real_value(json_object_get(jsonArr, "GPA"));

    json_t * grandchildrenObj = json_object_get(jsonArr, "grandchildren");
    json_array_foreach(grandchildrenObj, index, value) {
         Grandchildren * grandchildren = Grandchildren_new();
         buff = (char *)json_string_value(json_object_get(value, "name"));
         grandchildren->name = (char *)malloc(sizeof(char)*(strlen(buff)+1));
	     strcpy(grandchildren->name, buff);
         pensioner = Pensioner_addNewGrandchildren(pensioner,grandchildren );

    }
	
	json_decref(jsonArr);
     
}
char * JsonLoader_saveToString(const Pensioner * pensioner,char * jsonString) {

	json_t * json = json_object();

	json_object_set_new(json, "name", json_string(pensioner->name));
    json_object_set_new(json, "surname", json_string(pensioner->surname));
	json_object_set_new(json, "year", json_integer(pensioner->year));
	json_object_set_new(json, "GPA", json_real(pensioner->GPA));
    json_t * grandchildrenObj = json_array();
	for (int i = 0;i < pensioner->grandchildren_length;i++) {
		json_t * grandchildren = json_object();
	    json_object_set_new(grandchildren, "name", json_string(pensioner->grandchildren[i]->name));
        json_array_append_new(grandchildrenObj,grandchildren);
	}
	json_object_set_new(json , " grandchildren", grandchildrenObj);
	jsonString = json_dumps(json, JSON_INDENT(2));
    
    
     json_decref(json);
return jsonString;
}

/*void JsonLoader_loadFromString(Pensioner * pensioner, const char * jsonString) {
  
    json_error_t err;
	json_t * jsonArr = json_loads(jsonString, 0, &err);
    json_t * value = NULL;
    char *data ;
    int val;
    char * buff;
    int index = 0;
   
    buff = (char *)json_string_value(json_object_get(jsonArr, "name"));
    data =  Get_name(pensioner);
    data = (char *)malloc(sizeof(char)*(strlen(buff)+1));
	strcpy(data, buff);
    free(data);
    buff = (char *)json_string_value(json_object_get(jsonArr, "surname"));
    data =  Get_surname(pensioner);
    data = (char *)malloc(sizeof(char)*(strlen(buff)+1));
	strcpy(data, buff);
    val  = Get_year(pensioner);
    val = json_integer_value(json_object_get(jsonArr, "year"));
    val  = Get_GPA(pensioner);
	val = json_real_value(json_object_get(jsonArr, "GPA"));

    json_t * grandchildrenObj = json_object_get(jsonArr, "grandchildren");
    json_array_foreach(grandchildrenObj, index, value) {
         Grandchildren * grandchildren = Grandchildren_new();
         buff = (char *)json_string_value(json_object_get(value, "name"));
         data =  Get_grandchildren_name(grandchildren) ;
         data = (char *)malloc(sizeof(char)*(strlen(buff)+1));
	     strcpy( data, buff);
         pensioner = Pensioner_addNewGrandchildren(pensioner,grandchildren );

    }
    free(data);
	
	json_decref(jsonArr);
     
}
/*char * JsonLoader_saveToString(const Pensioner * pensioner,char * jsonString) {

	json_t * json = json_object();

	json_object_set_new(json, "name", json_string(Get_name(pensioner)));
    json_object_set_new(json, "surname", json_string(Get_surname(pensioner)));
	json_object_set_new(json, "year", json_integer(Get_year(pensioner)));
	json_object_set_new(json, "GPA", json_real(Get_GPA(pensioner)));
    json_t * grandchildrenObj = json_array();
	for (int i = 0;i < pensioner->grandchildren_length;i++) {
		json_t * grandchildren = json_object();
	//    json_object_set_new(grandchildren, "name", json_string(pensioner->grandchildren[i]->name));
        json_array_append_new(grandchildrenObj,grandchildren);
	}
	json_object_set_new(json , " grandchildren", grandchildrenObj);
	jsonString = json_dumps(json, JSON_INDENT(2));
    
    
     json_decref(json);
return jsonString;
*/
