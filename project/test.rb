require "fileutils"

#system 'rm -rf build' if File.directory? 'build'
FileUtils.rm_rf 'build'
Dir.mkdir 'build'
Dir.chdir 'build'

system 'cmake -G"Eclipse CDT4 - Unix Makefiles" ..'
system 'cmake --build .'

if File.exist? 'CppTest' then
  system 'chmod 777, CppTest'
  system './CppTest'
else
  puts "Failure!"
  -1
end

