#!/bin/sh

make

erl -pa ebin -eval 'inets:start().' -eval 'googleurl:start("googleurl/bin/port").' -eval 'application:start(spider).'
