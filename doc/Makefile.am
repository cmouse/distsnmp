dist_doc_DATA=manual.html distsnmptxd.1.html distsnmprxd.1.html
dist_man1_MANS=distsnmptxd.1 distsnmprxd.1

clean-local: 
	rm -f *.1 *.html

manual.html:
	if test $(MARKDOWN) != false; then $(MARKDOWN) manual.md > $@; fi

distsnmptxd.1:
	if test $(RONN) != false; then $(RONN) distsnmptxd.1.ronn; fi

distsnmprxd.1:
	if test $(RONN) != false; then $(RONN) distsnmprxd.1.ronn; fi
