
ERL = erl -boot start_clean
EFLAGS = -I include
AUTOMAKE_OPTIONS = foreign


#List of erlang modules to compile

MODS = fetcher fetcher_sup googleurl mochiweb_charref mochiweb_html spider_app spider_sup stats_collector task_master url_parse

EBINS = ${MODS:%=ebin/%.beam}

vpath %.erl src

ebin/%.beam : %.erl
	erlc -o ebin $(EFLAGS) $<

all: compile

compile: $(EBINS) subdirs

start: compile
	${ERL} -pa ebin -s inets start -s application spider start

subdirs:
	cd googleurl; make

clean:
	rm -rf ebin/*
