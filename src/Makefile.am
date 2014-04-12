bin_PROGRAMS=distsnmptxd distsnmprxd

distsnmptxd_SOURCES=distsnmptxd.cc variables.cc

distsnmprxd_SOURCES=distsnmprxd.cc variables.cc

distsnmptxd_CXXFLAGS=$(CXXFLAGS) $(SNMP_CFLAGS) $(libhiredis_CFLAGS) $(libevent_CFLAGS) $(BOOST_CPPFLAGS) -I../include -DSYSCONFDIR=\"$(sysconfdir)\"
distsnmptxd_LDADD=$(SNMP_LDFLAGS) $(libhiredis_LDFLAGS) $(libevent_LDFLAGS) $(SNMP_LIBS) $(libhiredis_LIBS) $(libevent_LIBS) $(BOOST_LDPATH) $(BOOST_PROGRAM_OPTIONS_LDFLAGS) $(BOOST_PROGRAM_OPTIONS_LIBS)

distsnmprxd_CXXFLAGS=$(CXXFLAGS) $(SNMP_CFLAGS) $(libhiredis_CFLAGS) $(libevent_CFLAGS) $(libzmq_CFLAGS) -I../include -DSYSCONFDIR=\"$(sysconfdir)\"
distsnmprxd_LDADD=$(SNMP_LDFLAGS) $(libhiredis_LDFLAGS) $(libevent_LDFLAGS) $(libzmq_LDFLAGS) $(SNMP_LIBS) $(libhiredis_LIBS) $(libevent_LIBS) $(libzmq_LIBS) $(BOOST_LDPATH) $(BOOST_PROGRAM_OPTIONS_LDFLAGS) $(BOOST_PROGRAM_OPTIONS_LIBS)
