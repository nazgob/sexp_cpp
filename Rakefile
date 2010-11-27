require 'rake/clean'

PROG = "sexp" 
LIBNAME = PROG
LIBFILE = "lib#{LIBNAME}.a" 

BOOST_DIR = "/opt/local/var/macports/software/boost/1.44.0_0/opt/local/include"
I_FLAGS = "-I/opt/local/include -I#{BOOST_DIR}"
#L_FLAGS = -L/opt/local/lib -lgtest -L./$(LIB_DIR) -lsexp_cpp

SRC = FileList['src/*.cpp']
TST = FileList['tst/*.cpp']
ALL = SRC | TST

OBJDIR = 'obj'
SRC_OBJ = SRC.collect { |fn| File.join(OBJDIR, File.basename(fn).ext('o')) }
TST_OBJ = TST.collect { |fn| File.join(OBJDIR, File.basename(fn).ext('o')) }

CLEAN.include(PROG, SRC_OBJ, TST_OBJ, OBJDIR, LIBFILE)
CLOBBER.include(PROG)

task :default => [:lib, :test]

task :test => [PROG]

task :lib => [LIBFILE]

file PROG do
#file PROG => TST_OBJ do
  TST_OBJ.each do |t|
    sh "g++ #{I_FLAGS} -c -o #{t} #{find_source(t)}" 
    puts file
  end
  sh "g++ -o #{PROG} #{TST_OBJ} -L. -l#{LIBNAME} -L/opt/local/lib -lgtest" 
end

file LIBFILE => SRC_OBJ do
  sh "ar cr #{LIBFILE} #{SRC_OBJ}" 
  sh "ranlib #{LIBFILE}" 
end

directory OBJDIR

rule '.o' => lambda{ |objfile| find_source(objfile) } do |t|
  Task[OBJDIR].invoke
  sh "g++ #{I_FLAGS} -c -o #{t.name} #{t.source}" 
end

def find_source(objfile)
  base = File.basename(objfile, '.o')
  ALL.find { |s| File.basename(s, '.cpp') == base }
end

