//Andrew Hunter
//CPSC 102

/* sphere.c */

/* sphere_init()
	sphere_load_attributes()
	sphere_print()
	sphere_hits()
*/


#include "ray.h"
#include <math.h>


//**
// Create a new sphere object and initialize it 
void sphere_init(FILE  *in, model_t  *model, int  attrmax)
{
   sphere_t *sph;
   object_t *obj;
   //char attribname[NAME_LEN];
   int count;

   /* Call the object_init()function to create the object_t */
   /* and process the "material" attribute                  */
    object_init(in, model);
   

   /* Use list_get_entity() to make obj point to the newly  */
   /* created object_t structure. Your list_add() function  */
   /* MUST set current to the last element in the list for  */
   /* this to work correctly.                               */
   obj = list_get_entity(model->objs);
   



   /* malloc a sphere_t structure and set the priv pointer  */
   /* in the object_t structure to point to the sphere_t    */
    sph = malloc(sizeof(sphere_t));
    memset(sph,0,sizeof(sphere_t));
    obj->priv = sph;
 

   

   /* Store the word "sphere" in the object_type field of   */
   /* the object_t structure. Use the strcpy() function     */
    strcpy(obj->obj_type, "sphere");
   

 

   /* Ask sphere_load_attributes to load the attributes.    */
   /* Attributes are center and radius.                     */
   count = sphere_load_attributes(in, sph, attrmax);
   assert(count == 2);

   /* Setup polymorphic function pointers in object_t */
	/* Set obj->hits to sphere_hits() function.        */
	/* Set obj->printer to sphere_print() functions.   */

   
   
    obj->hits = sphere_hits;
    obj->printer = sphere_print;



}


//**
// Load attributes as in other load attributes functions 
int sphere_load_attributes(FILE  *in, sphere_t  *sphere, int  attrmax)
{
    char attrib_name[16];
    int count = 0;
    int attrcount = 0;
    
    
    count = fscanf(in, "%s", attrib_name);
    assert(count ==1);

    
    while(attrib_name[0] != '}'){
        
        
        if(strcmp(attrib_name, "center") == 0){
            count = fscanf(in,"%lf %lf %lf",&sphere->center.x, &sphere->center.y, &sphere->center.z);
            assert(count == 3);
            attrcount += 1;
            
        }
        
        else if( strcmp( attrib_name, "radius" ) == 0 ){
            count = fscanf(in,"%lf",&sphere->radius);
            assert(count == 1);
            attrcount += 1;
            
        }
            
        else
        {
            fprintf(stderr, "Bad Sphere attribute: %s", attrib_name);;
            exit(1);
        }	
        
        fscanf(in,"%s", attrib_name);
        
    }
    return(attrcount);


}


//**
// Prints a formatted version of the sphere structure
// The format should be consistent with that produced by
// camera_print() or material_print()
void sphere_print(object_t  *obj,FILE  *out)
{
   sphere_t *sph = obj->priv;

   //  ---  CODE GOES HERE ---
	// Print generic attributes
    object_print(obj,out);

	// Recover sph pointer from object_t and print
	// center and radius in usual format
    fprintf(out, "%-12s %5.1lf %5.1lf %5.1lf\n", "Center", sph->center.x, sph->center.y, sph->center.z);
    fprintf(out, "%-12s %5.1lf\n\n", "Radius", sph->radius);

}


/* Determine if a vector projected from location base   */
/* in direction *dir hits the sphere. If so the return  */
/* value is the distance from the base to the point of  */
/* contact.  It must hit the sphere in negative z-space.*/


/************************************************************
 You do not have to implement this function during this lab.
         This will be implemented at a later time.
 ************************************************************/

double sphere_hits(object_t  *obj, vec_t  *base, vec_t  *dir) 
{ 
    	// extract sph pointer from object structure 
	// see notes for sphere_hits function
   // --- CODE GOES HERE ---


    double a,b,c, disc, distance;
    vec_t newbase;
    vec_t hit;
    sphere_t *sph;
    assert (obj->cookie == OBJ_COOKIE);
    sph = obj->priv;
    vec_diff(&sph->center, base, &newbase);

    vec_t temp, unit_norm;

    a = vec_dot(dir, dir);
    b = 2.0 * vec_dot(&newbase, dir);
    c = vec_dot(&newbase, &newbase) - (sph->radius * sph->radius);

    disc = (b*b) - (4*a*c);

    if(disc > 0.0){
        distance = ((b*(-1.0))-sqrt(disc))/(a*2);
    }

    else{
        return(-1);
    }

        vec_scale(distance, dir, &temp);
        vec_sum(base, &temp, &hit);

    if(hit.z<0.0){
        vec_t n;
        obj->last_hit = hit;
        vec_diff(&sph->center,&hit,&unit_norm);
        vec_unit(&unit_norm,&n);


        obj->last_normal.x = unit_norm.x/n.x;
        obj->last_normal.y = unit_norm.x/n.y;
        obj->last_normal.z = unit_norm.x/n.z;

        return(distance);


    }
	// return distance
    else{
       return -1;  // just for now
    }        
}
