// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME anamodule_Dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/seaquest/users/xinlongl/projects/DAV-TAV/main/cpp_modules/data_module_src/AnaModule.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *AnaModule_Dictionary();
   static void AnaModule_TClassManip(TClass*);
   static void *new_AnaModule(void *p = nullptr);
   static void *newArray_AnaModule(Long_t size, void *p);
   static void delete_AnaModule(void *p);
   static void deleteArray_AnaModule(void *p);
   static void destruct_AnaModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AnaModule*)
   {
      ::AnaModule *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AnaModule));
      static ::ROOT::TGenericClassInfo 
         instance("AnaModule", "", 19,
                  typeid(::AnaModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &AnaModule_Dictionary, isa_proxy, 3,
                  sizeof(::AnaModule) );
      instance.SetNew(&new_AnaModule);
      instance.SetNewArray(&newArray_AnaModule);
      instance.SetDelete(&delete_AnaModule);
      instance.SetDeleteArray(&deleteArray_AnaModule);
      instance.SetDestructor(&destruct_AnaModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AnaModule*)
   {
      return GenerateInitInstanceLocal(static_cast<::AnaModule*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::AnaModule*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AnaModule_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::AnaModule*>(nullptr))->GetClass();
      AnaModule_TClassManip(theClass);
   return theClass;
   }

   static void AnaModule_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_AnaModule(void *p) {
      return  p ? new(p) ::AnaModule : new ::AnaModule;
   }
   static void *newArray_AnaModule(Long_t nElements, void *p) {
      return p ? new(p) ::AnaModule[nElements] : new ::AnaModule[nElements];
   }
   // Wrapper around operator delete
   static void delete_AnaModule(void *p) {
      delete (static_cast<::AnaModule*>(p));
   }
   static void deleteArray_AnaModule(void *p) {
      delete [] (static_cast<::AnaModule*>(p));
   }
   static void destruct_AnaModule(void *p) {
      typedef ::AnaModule current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::AnaModule

namespace {
  void TriggerDictionaryInitialization_anamodule_Dict_Impl() {
    static const char* headers[] = {
"/seaquest/users/xinlongl/projects/DAV-TAV/main/cpp_modules/data_module_src/AnaModule.h",
nullptr
    };
    static const char* includePaths[] = {
"/seaquest/users/xinlongl/projects/debug/core-inst/include/",
"/include/",
"/exp/seaquest/app/software/osg/software/e1039/share/20240816/root/include/",
"/seaquest/users/xinlongl/projects/DAV-TAV/main/cpp_modules/data_module/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "anamodule_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$/seaquest/users/xinlongl/projects/DAV-TAV/main/cpp_modules/data_module_src/AnaModule.h")))  AnaModule;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "anamodule_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/seaquest/users/xinlongl/projects/DAV-TAV/main/cpp_modules/data_module_src/AnaModule.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"AnaModule", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("anamodule_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_anamodule_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_anamodule_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_anamodule_Dict() {
  TriggerDictionaryInitialization_anamodule_Dict_Impl();
}
