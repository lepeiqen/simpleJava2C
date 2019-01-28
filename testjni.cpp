#include <iostream>
#include <jni.h>
#include <memory.h>

int main()
{
    char opt1[] = "-Djava.compiler=NONE"; /** 暂时不知道啥意思，网上抄来的 */
    char opt2[] = "-Djava.class.path=.";  /** 指定Java类编译后.class文件所在的目录 */
    char opt3[] = "-verbose:NONE";        /** 暂时不知道啥意思，网上抄来的 */

    JavaVMOption options[3];
    options[0].optionString = opt1; options[0].extraInfo = NULL;
    options[1].optionString = opt2; options[1].extraInfo = NULL;
    options[2].optionString = opt3; options[2].extraInfo = NULL;

    JavaVMInitArgs jargv;
    jargv.version = JNI_VERSION_1_6; /** JDK JNI VERSION*/
    jargv.nOptions = 3;
    jargv.options = options;
    jargv.ignoreUnrecognized = JNI_TRUE;

    JavaVM* jvm = NULL;
    JNIEnv* jenv = NULL;
    jint res = JNI_CreateJavaVM( &jvm, (void**)&jenv, &jargv );
    if ( 0 != res )
        return 1;

    jclass jc = jenv->FindClass( "MyTest" );
    if ( NULL == jc )
        return 1;

    jmethodID jmid = jenv->GetStaticMethodID( jc, "callback", "()V" );
    if ( NULL == jmid )
        return 1;

    jenv->CallStaticVoidMethod( jc, jmid );


    /** 在网上没有找到任何关于空间相关 JavaVM 和 JNIEnv 资源释放的描述 */
    std::cout << "Hello, World!" << std::endl;
    jvm->DestroyJavaVM();
    return 0;
}
