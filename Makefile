# Makefile for CS 360 example code

CXX=		g++ $(CCFLAGS)
EXAMPLE=	example.o
OBJS =		$(EXAMPLE) 

LIBS=		-pthread

CCFLAGS= -g

all:		example

example:	$(EXAMPLE)
		$(CXX) -o example $(EXAMPLE) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
		rm -f $(OBJS) $(OBJS:.o=.d) example


# These lines ensure that dependencies are handled automatically.
%.d:	%.cc
	$(SHELL) -ec '$(CC) -M $(CPPFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'

include	$(OBJS:.o=.d)
