#!/usr/bin/env bash

build_dir="build"

# Clean task - when the argument `clean` was given
if [ "$1" = "clean" ]; then
  rm -rf $build_dir
  exit $?
fi

## BUILD ##

# Require gcc
which gcc >/dev/null
if [ $? -eq 1 ]; then
 echo "Could not find gcc on PATH!" >&2
 exit 1
fi

# Create the build dir
if [ ! -d $build_dir ]; then
  mkdir $build_dir
fi

# Compile and run a single project
if [ -n "$1" ]; then
  gcc -o $build_dir/$1 $1/main.c || exit $?
  ./$build_dir/$1
  exit $?
fi

# Compile every main.c from every directory
for dir in *; do
  in_file="$dir/main.c"

  if [ -f $in_file ]; then
    echo -n "Compiling $dir... "
    gcc -o $build_dir/$dir $in_file
    echo "done"
  fi
done
