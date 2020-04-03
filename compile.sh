#!/usr/bin/env bash

build_dir="build"

function error()
{
  echo "ERROR: $1" >&2
  exit 1
}

function test_compiler()
{
  which gcc >/dev/null
  if [ $? -eq 1 ]; then
   error "Could not find gcc in path!"
  fi
}

function clean_build_dir()
{
  rm -rf $build_dir
}

function run()
{
  if [ -z "$1" ]; then
    error "No program name specified!"
  fi

  ./$build_dir/$1
}

function compile()
{
  if [ -z "$1" ]; then
    error "No program name specified!"
  fi

  name=$1

  gcc -o $build_dir/$name $name/main.c
}

function compile_all()
{
  for dir in *; do
    if [ -f "$dir/main.c" ]; then
      checkmark="\xE2\x9C\x85"
      crossmark="\xE2\x9D\x8C"

      echo -en "$dir..."
      compile $dir

      if [ $? -eq 0 ]; then
        mark=$checkmark
      else
        mark=$crossmark
      fi

      echo -e "\r$dir $mark"
    fi
  done
}

function create_template_program()
{
  if [ -z "$1" ]; then
    error "No program name specified!"
  fi

  name=$1

  mkdir $2
  cat << EOF > ./$2/main.c
#include <stdio.h>

int main(int argc, char const *argv[]) {
  // Implement $2
  return 0;
}

EOF
}


case $1 in
  clean)
    clean_build_dir
    exit
    ;;
  create)
    create_template_program
    exit
    ;;
  *)
    mkdir -p $build_dir
    if [ -z "$1" ]; then
      compile_all
    else
      compile $1
      run $1
    fi
esac
