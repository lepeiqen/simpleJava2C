1. javac MyTest.java  -> generate class file

2. javap -s -p MyTest.class : show signature

3 .change following config to locate "jni.h libjvm.so":
 /etc/ld.so.conf.d$ sudo vi libjvm.conf  && sudo ldconfig ; LD_LIBRARY_PATH work not good; don't cp so random;

4 CMakeLists.txt  :need  change
