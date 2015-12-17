//Andrew Hunter
//CPSC 102

/* list.c */

#include "list.h"


/**/
/* malloc() a new list header and initialize it */
list_t *list_init(void)
{
	list_t *newlist = malloc(sizeof(list_t)); //malloc a new instance of link_t
	newlist -> first = NULL; //set the first pointer of the structure to NULL
	newlist -> current = NULL; //set the current pointer of the structure to NULL
	newlist -> last = NULL; // set the last pointer of the structure to NULL
	return(newlist); //return the pointer to list_t
	
}


/**/
/* add an element to the end of a list */
void list_add(list_t *list, void *entity)
{
	link_t *newlink = malloc(sizeof(link_t)); //malloc a new instance of link_t
	newlink -> entity = entity; // data is insert into new link
	newlink -> next = NULL; // set the next pointer of the new link to null
	
	if((list -> first) == NULL){
	
		list -> first = newlink; 
                list -> current = newlink;
                list -> last = newlink;
	}
	
	else{
	
                list->last->next = newlink;
                list->last = newlink;
                list->current = newlink;
	}
	
	
        
}


/**/
/* set current pointer to first pointer */
void list_reset(list_t *list)
{
	list -> current = list -> first; //set the current pointer to the first pointer.
	
}


/**/
/* return 1 if current pointer is pointing at a valid link */
/* return 0 if current pointer is NULL                     */
int list_not_end(list_t *list)
{
	if((list -> current == NULL)){  //return 0 if the current pointer is null
		return(0);
	}
	
	else  // return 1 if there are more links in the list
	{
		return(1);
	}
}


/**/
/* advance current pointer to next link */
void list_next_link(list_t *list)
{
        assert(list->current != NULL);
	list -> current = list -> current -> next;

}


/**/
/* return address of entity pointed to by current link */
void *list_get_entity(list_t *list)
{
        assert(list->current != NULL);
   
        return(list -> current -> entity);
   


}


/**/
/* free() all entities, links, and then the list header */
void list_del(list_t *list)
{
        while((list -> current = list -> first) != NULL){
                
                free(list -> current -> entity);
                list -> first = list -> current -> next;
                free(list -> current);
                
                
        }        
        
        free(list);  


}
  

