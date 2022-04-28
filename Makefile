bananafetch: main.c
	$(CC) main.c -o bananafetch

install:
	@cp -p bananafetch $(DESTDIR)$(PREFIX)/bin/bananafetch
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/bananafetch

uninstall:
	@echo "banana will miss you.."
	@rm -rf $(DESTDIR)$(PREFIX)/bin/bananafetch