1. javac MyTest.java  -> generate class file

2. javap -s -p MyTest.class : show signature

3. change the following config to make the bin can find the "libjvm.so":
 3.1 /etc/ld.so.conf.d$ sudo vi libjvm.conf to include libs dir  && sudo ldconfig ; (libjvm.conf attached last)
 3.2 using LD_LIBRARY_PATH work not good; 
 3.3 don't copy the libs randomly;

4. CMakeLists.txt  : need change according to note

5. in the cur dir(have Cmakelists.txt and src files): mkdir build; cd build ;cmake ..; make ;

6. jdk preinstalled : /usr/lib/jvm/java-1.8.0-openjdk-amd64/

7. run 'ldd testjni' : check the libs this bin/so depend on.

8. libs dirs only effective in current diretory, and not desend into child dirs, so you need to name it explicitly


libjvm.conf :
/usr/lib/jvm/java-1.8.0-openjdk-amd64/jre/lib/amd64/server
/usr/lib/jvm/java-1.8.0-openjdk-amd64/jre/lib/amd64
