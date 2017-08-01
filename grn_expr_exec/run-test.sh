#!/bin/bash

rm -fr testdb
mkdir -p testdb
groonga -n testdb/db < bookmarks.grn
