#include <cstring>
#include <cassert>
#include <string>
#include <iostream>
#include "erl_interface.h"
#include "ei.h"
#include "erl_comm.h"
#include "gurl.h"

typedef unsigned char byte;

int INITIAL_BUFFER_SIZE = 100;

int main() {
  ETERM *tuplep;
  ETERM *tuple1, *tuple2, *tuple3;
  std::string command_string;
  int res;
  int buffer_size = INITIAL_BUFFER_SIZE;
  byte *buf = new byte[buffer_size];
  long allocated, freed;

  erl_init(NULL, 0); //Required line to initialize erl_interface

  while (read_cmd(&buf, buffer_size) > 0) {
    tuplep = erl_decode(buf);
    tuple1 = erl_element(1, tuplep);

    command_string = std::string((char*)ERL_ATOM_PTR(tuple1));

    if(command_string.compare("canonicalize_links") == 0){
      std::string base_url;
      //Appears to be a canonicalize_links command
      tuple2 = erl_element(2, tuplep);
      tuple3 = erl_element(3, tuplep); //tuple3 is a list of possibly relative URLs
      
      base_url = std::string(erl_iolist_to_string(tuple2));

      GURL url = GURL(base_url);
      ETERM *head, *rest;
      assert(ERL_IS_LIST(tuple3));

      ETERM *result = erl_mk_empty_list(); //Erlang list holding the results

      rest = tuple3;
      while( ! ERL_IS_EMPTY_LIST(rest)){
	head = ERL_CONS_HEAD(rest);
	rest = ERL_CONS_TAIL(rest);
	
	std::string relative_url = std::string(erl_iolist_to_string(head));
	//	std::cerr << relative_url << std::endl;

	GURL result_url = url.Resolve(relative_url);
	
	//	std::cerr << result_url.spec() << std::endl;

	ETERM *result_string = erl_mk_string(result_url.spec().c_str()); //estring of canonicalized url
	result = erl_cons(result_string, result); //build result list up
	
      }

      if(erl_term_len(result) > buffer_size){
	delete[] buf;
	buf = new byte[erl_term_len(result)];
	buffer_size = erl_term_len(result);
      }

      erl_encode(result, buf);
      write_cmd(buf, erl_term_len(result));

      erl_free_term(tuple2);
      erl_free_compound(tuple3);
      erl_free_compound(result);
    }

    erl_free_term(tuple1);
    erl_free_compound(tuplep);

  }
  delete[] buf;

  return 0;
}
