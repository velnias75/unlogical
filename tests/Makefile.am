TESTS = unlogical

check_PROGRAMS = $(TESTS)

noinst_HEADERS = arithtest.h gatetest.h

unlogical_SOURCES = arithtest.cpp gatetest.cpp unlogical.cpp
unlogical_CPPFLAGS = -I $(top_srcdir)/src
unlogical_CXXFLAGS = $(CPPUNIT_CFLAGS)
unlogical_LDFLAGS = $(CPPUNIT_LIBS)
unlogical_LDADD = ../src/libunlogical.la

AUTOMAKE_OPTIONS = serial-tests
