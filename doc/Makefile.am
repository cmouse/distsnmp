dist_doc_DATA=manual.html distsnmptxd.1.html distsnmprxd.1.html
dist_man1_MANS=distsnmptxd.1 distsnmprxd.1

manual.html:
	$(MARKDOWN) manual.md > $@

distsnmptxd.1:
	$(RONN) distsnmptxd.md

distsnmprxd.1:
	$(RONN) distsnmprxd.md
