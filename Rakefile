require 'rake/clean'
require 'rake/classic_namespace'

PROG = "sexp" 
LIBNAME = PROG
LIBFILE = "lib#{LIBNAME}.a" 
CC = "clang++ -g" #TODO: when clang++ is not found, default to g++

LIB_DIR = "lib"

BOOST_DIR = ENV['BOOST_INC']
I_FLAGS = "-I/opt/local/include -I#{BOOST_DIR}"
L_FLAGS = "-L. -L#{LIB_DIR} -l#{LIBNAME} -L/opt/local/lib -lgtest"
W_FLAGS = "-Wall -Wextra" #TODO: -pedantic couses problems with long long and google test

SRC = FileList['src/*.cpp']
TST = FileList['tst/*.cpp']
ALL = SRC | TST

OBJDIR = 'obj'
SRC_OBJ = SRC.collect { |fn| File.join(OBJDIR, File.basename(fn).ext('o')) }
TST_OBJ = TST.collect { |fn| File.join(OBJDIR, File.basename(fn).ext('o')) }

CLEAN.include(PROG, SRC_OBJ, TST_OBJ, OBJDIR, LIBFILE)
CLOBBER.include(PROG)

task :default => [:lib, :test, :run]

task :lib => [LIBFILE]

task :test => [:lib, PROG]

task :run => [PROG] do
  sh "./#{PROG}" 
end

task :docs do
  puts "Making doxygen docs!"
  sh "doxygen doc/Doxyfile"
end

file PROG => TST_OBJ do
  sh "#{CC} #{W_FLAGS} -o #{PROG} #{TST_OBJ} #{L_FLAGS}"
end

file LIBFILE => SRC_OBJ do
  sh "ar cr #{LIB_DIR}/#{LIBFILE} #{SRC_OBJ}" 
  sh "ranlib #{LIB_DIR}/#{LIBFILE}" 
end

directory OBJDIR

rule '.o' => lambda{ |objfile| find_source(objfile) } do |t|
  Task[OBJDIR].invoke
  sh "#{CC} #{W_FLAGS} #{I_FLAGS} -c -o #{t.name} #{t.source}" 
end

def find_source(objfile)
  base = File.basename(objfile, '.o')
  ALL.find { |s| File.basename(s, '.cpp') == base }
end

