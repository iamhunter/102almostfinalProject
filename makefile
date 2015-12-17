RAYOBJS = main.o model.o camera.o list.o material.o plane.o \
          object.o sphere.o raytrace.o image.o pixel.o vector.o

INCLUDE = ray.h rayhdrs.h pixel.h vector.h rayfuns.h
CFLAGS  =

ray: $(RAYOBJS) 
	gcc -Wall -o ray -g $(RAYOBJS) -lm

$(RAYOBJS): $(INCLUDE) makefile

.c.o: $<
	gcc -c -Wall $(CFLAGS) -c -g $<  2> $(@:.o=.err)
	cat $*.err

clean:
	rm *.o  *.err *.ppm

