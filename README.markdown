An Erlang Spider
================

As far as I know, this is the only free, open source, publicly available web crawler application library in Erlang. Thanks, Michael Melanson. It should be pretty solid 'ere long.

# DONE #
1. We now ask for and uncompress gzip.

# TODO #

1. Jailing to directory, subdomain, and host. Easy to implement on top of regex sandbox.
2. Unit test for regex sandbox to work out general approach.
   * Use framework like eunit?
   * Use test/0 and Mochikit's automatic reload module?
   * Use another spider's result as reference
3. Add interesting examples to Wiki.
4. Switch build process to regular makefile (as Joe Armstrong prefers, but that's not why ;) ).
5. Specify user-agent.
6. Specify from header with email address.
7. Robots.txt parsing.
8. Specify whether to obey robots.txt.
9. Parse html robots commands.
10. Specify whether to obey html robots commands.
12. Specify crawl delay.
13. Specify allowed mime types
14. Specify allowed extensions.
15. Specify allowed page size.
16. Specify how many times to try a failed url.
17. Specify delay between retrying.
18. Use google url parser.
19. User callback to filter links before adding to tasks.
21. User callback to filter links before processing.
22. User callback to process page data structure returned by spider engine.
23. Systematic, configurable logging to discover problems.
24. Specify whether to allow redirects.
25. Specify how many redirects to allow.
26. Decide how to handle redirects exactly.
27. Decide how to handle meta refresh.
28. Add simplest possible quickstart to README.
29. Add simple fun example to README.
30. Cancel crawl.
31. Data to be passed to aftercrawl callback:
    * headers
    * source
    * parsed source
    * last-modified
    * etag
    * httpstatus
    * httpreason
    * content-type
    * content-encoding
    * list of redirect urls (and meta refreshes?)
32. Handle soft 404s.
33. Does google url lop off duplicate url params?


