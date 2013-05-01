system 'rm -rf build' if File.directory? 'build'
Dir.mkdir 'build'
Dir.chdir 'build'

system 'cmake -G"Eclipse CDT4 - Unix Makefiles" ..'
system 'cmake --build .'

if File.exist? './CppTest' then
  File.chmod( 777, 'CppTest')
  system './CppTest'
else
  -1
end

