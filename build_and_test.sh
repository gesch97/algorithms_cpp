#!/bin/sh

DIR="build"

if [ -d "$DIR" ]; then
  echo "Directory $DIR already exists."
else
  echo "Directory $DIR does not exist. Creating it now..."
  mkdir "$DIR"
  echo "Directory $DIR created."
fi

cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DLLDB_EXPORT_ALL_SYMBOLS=ON .. || { echo "CMake configuration failed"; cd .. ; exit 1; }
make || { echo "Make failed"; cd ..; exit 1; }

./tests/MyTests

cd ..

