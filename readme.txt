1. javac MyTest.java  -> generate class file

2. javap -s -p MyTest.class : show signature

3 .change following config to locate "jni.h libjvm.so":
 /etc/ld.so.conf.d$ sudo vi libjvm.conf  && sudo ldconfig ; LD_LIBRARY_PATH work not good; don't cp so random;

4 CMakeLists.txt  : need change according to note

5 in the cur dir(have Cmakelists.txt and src files): mkdir build; cd build ;cmake ..; make ;

6. jdk installed : /usr/lib/jvm/java-1.8.0-openjdk-amd64/

7. run 'ldd testjni' : check the libs this bin/so depend on.
