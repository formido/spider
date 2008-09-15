
ICU_INCLUDE = $(ICU_PREFIX)/include

objects = port.o erl_comm.o gurl.o url_parse.o url_util.o logging.o url_canon_etc.o url_canon_fileurl.o url_canon_host.o url_canon_internal.o url_canon_ip.o url_canon_mailtourl.o url_canon_path.o url_canon_pathurl.o url_canon_query.o url_canon_relative.o url_canon_stdurl.o url_parse_file.o url_canon_icu.o

sources = src/port.cc src/erl_comm.c src/gurl.cc src/url_parse.cc src/url_util.cc src/base/logging.cc src/url_canon_etc.cc src/url_canon_fileurl.cc src/url_canon_host.cc src/url_canon_internal.cc src/url_canon_ip.cc src/url_canon_mailtourl.cc src/url_canon_path.cc src/url_canon_pathurl.cc src/url_canon_query.cc src/url_canon_relative.cc src/url_canon_stdurl.cc src/url_parse_file.cc src/url_canon_icu.cc

# target as port with objects as variable dependencies & command line

all: bin/port

bin/port: $(objects) bin
	g++ -o bin/port -Isrc -I$(ICU_INCLUDE) -I$(ERLANG_LIB_DIR_erl_interface)/include -L$(ERLANG_LIB_DIR_erl_interface)/lib $(ICU_LIBS) -lerl_interface -lei $(objects)

bin:
	mkdir bin

# list the dependencies for object files - those header files which help build objects

src/port.cc: src/erl_comm.h src/gurl.h

src/erl_comm.cc: src/erl_comm.h 

src/gurl.cc: src/url_canon.h src/url_canon_stdstring.h src/url_parse.h src/url_util.h

src/url_parse.cc: src/url_parse.h src/base/logging.h src/url_parse_internal.h

src/url_util.cc: src/url_util.h src/base/logging.h src/url_file.h

src/url_file.cc: src/url_parse_internal.h

# build all object files from all dependent source files


$(objects): $(sources)
	g++ -c $(sources) -Isrc -I.. -I$(ERLANG_LIB_DIR_erl_interface)/include -I$(ICU_INCLUDE)

clean:
	rm $(objects) bin/port
