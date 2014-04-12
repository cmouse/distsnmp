#!/bin/sh

aclocal --install -Im4
automake -ac
autoreconf
