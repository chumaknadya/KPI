
#include <stdlib.h>
#include <stdio.h>
#include "include/events.h"
#include "include/list.h"
#include <pbconsole.h>

/* custom constant event type ids*/
enum {
    KeyInputEventTypeId,
	LeftChatTypeId,
	AddToChatTypeId

};

/* event handler functions prototypes */
void KeyInputHandler_update(EventHandler * self, Event * event);
void KeyInputListener_update(EventHandler * self, Event * event);
void RoomChat_update(EventHandler * self, Event * event);
void ListHandler_update(EventHandler * self, Event * event);
void PeopleListHandler_update(EventHandler * self, Event * event);


int main(void) {
    // startup event system
    EventSystem_init();
	List * list = List_new();
    int  * identifier = (int *)malloc(sizeof(int));
	*identifier = 0;
   
    // add event handlers
    EventSystem_addHandler(EventHandler_new(NULL, NULL, KeyInputHandler_update));
    EventSystem_addHandler(EventHandler_new(NULL, NULL, KeyInputListener_update));
    EventSystem_addHandler(EventHandler_new(identifier, free, RoomChat_update));
    EventSystem_addHandler(EventHandler_new(list,free, ListHandler_update));



    // start infinite event loop
    EventSystem_loop();
    // cleanup event system
    EventSystem_cleanup();
    return 0;
}

/* event handlers functions implementations */

void KeyInputHandler_update(EventHandler * self, Event * event) {
    if (conIsKeyDown()) {  // non-blocking key input check
        char * keyCode = malloc(sizeof(char));
		 fflush(stdin);
        *keyCode = getchar();
         EventSystem_raiseEvent(Event_new(self, KeyInputEventTypeId, keyCode, free));
	  
    }
}

void KeyInputListener_update(EventHandler * self, Event * event) {
    switch(event->type) {
        case StartEventTypeId: {
            puts("Program Started!Press [1-5] or ESC to exit ");
            break;
        }
        case ExitEventTypeId: {
            puts("Oh,Bye!");
            puts("");
            break;
        }
       case KeyInputEventTypeId: {
            char keyCode = *(char *)event->data;
           if (keyCode == 27) {  // Escape key code
                puts("\nExit program call");
                EventSystem_exit(); 
            }
            break;
        }
    }
}

void RoomChat_update(EventHandler * self, Event * event) {
	switch (event->type) {
		case KeyInputEventTypeId: {
			char * keyCodePtr = (char *)event->data;
            char keyCode = *keyCodePtr;
		    if (keyCode == '1' || keyCode == '2' || keyCode == '3') {
			   //int * counterPtr = (int *)self->data; 
               // (*counterPtr)++;
	           // printf("\nУчасник %i приєднався до чату \n", *counterPtr);
			   // printf("\nДо чату приєднались\n");
 			     EventSystem_raiseEvent(Event_new(self, AddToChatTypeId, NULL, NULL));
			 }
			 if (keyCode == '4' || keyCode == '5') {
				 //printf("\nХтось залишив чат \n");
                 EventSystem_raiseEvent(Event_new(self, LeftChatTypeId, NULL, NULL));
			 }
		 	
		}break;
		
     }
}

void ListHandler_update(EventHandler * self, Event * event) {
	switch(event->type) {
		 case AddToChatTypeId: {
		 	List * list =(List *) self->data;
		    int * number =(int *) malloc(sizeof(int));
            *number = rand() % 100 ;
			
             List_add(self->data,number);
             printf("\nУчасник(ID %i) приєднався до чату\n", *number);
             printf("Зараз у чаті:");
             List_print(self->data);
             puts(" ");
			 
			
   	        
		 }break;	
		 case LeftChatTypeId: {
			   if(List_isEmpty(self->data)){
                    printf("\nУ чаті нікого немає\n");
               } else {
			        int* randomNumber = malloc(sizeof(int));
			        if(List_count(self->data) == 1){
                         *randomNumber = 0;
                    } else {
                         *randomNumber = rand()%(List_count(self->data) - 1);
                    }
                    printf("\n Учасник (ID %i ) покинув чат\n", *((int*)List_get(self->data, *randomNumber)));
                    List_removeAt(self->data, *randomNumber);
                    printf("Зараз у чаті:");
                    List_print(self->data);
                    puts(" ");
            
                    free(randomNumber);
			   }
           }break;
		 }
	}

