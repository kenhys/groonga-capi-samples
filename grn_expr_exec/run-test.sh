#!/bin/bash

rm -fr testdb
mkdir -p testdb
groonga -n testdb/db < bookmarks.grn

./load_one_entry
groonga testdb/db dump

groonga testdb/db truncate bookmarks
./load_at_once
groonga testdb/db dump



