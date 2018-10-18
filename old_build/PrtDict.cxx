// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME PrtDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
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

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "../src/PrtHit.h"
#include "../src/PrtEvent.h"
#include "../src/PrtLutNode.h"
#include "../src/PrtTrackInfo.h"
#include "../src/PrtPhotonInfo.h"
#include "../src/PrtAmbiguityInfo.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_PrtHit(void *p = 0);
   static void *newArray_PrtHit(Long_t size, void *p);
   static void delete_PrtHit(void *p);
   static void deleteArray_PrtHit(void *p);
   static void destruct_PrtHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PrtHit*)
   {
      ::PrtHit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PrtHit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PrtHit", ::PrtHit::Class_Version(), "../src/PrtHit.h", 15,
                  typeid(::PrtHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PrtHit::Dictionary, isa_proxy, 4,
                  sizeof(::PrtHit) );
      instance.SetNew(&new_PrtHit);
      instance.SetNewArray(&newArray_PrtHit);
      instance.SetDelete(&delete_PrtHit);
      instance.SetDeleteArray(&deleteArray_PrtHit);
      instance.SetDestructor(&destruct_PrtHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PrtHit*)
   {
      return GenerateInitInstanceLocal((::PrtHit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PrtHit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PrtEvent(void *p = 0);
   static void *newArray_PrtEvent(Long_t size, void *p);
   static void delete_PrtEvent(void *p);
   static void deleteArray_PrtEvent(void *p);
   static void destruct_PrtEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PrtEvent*)
   {
      ::PrtEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PrtEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PrtEvent", ::PrtEvent::Class_Version(), "../src/PrtEvent.h", 16,
                  typeid(::PrtEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PrtEvent::Dictionary, isa_proxy, 4,
                  sizeof(::PrtEvent) );
      instance.SetNew(&new_PrtEvent);
      instance.SetNewArray(&newArray_PrtEvent);
      instance.SetDelete(&delete_PrtEvent);
      instance.SetDeleteArray(&deleteArray_PrtEvent);
      instance.SetDestructor(&destruct_PrtEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PrtEvent*)
   {
      return GenerateInitInstanceLocal((::PrtEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PrtEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PrtLutNode(void *p = 0);
   static void *newArray_PrtLutNode(Long_t size, void *p);
   static void delete_PrtLutNode(void *p);
   static void deleteArray_PrtLutNode(void *p);
   static void destruct_PrtLutNode(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PrtLutNode*)
   {
      ::PrtLutNode *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PrtLutNode >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PrtLutNode", ::PrtLutNode::Class_Version(), "../src/PrtLutNode.h", 18,
                  typeid(::PrtLutNode), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PrtLutNode::Dictionary, isa_proxy, 4,
                  sizeof(::PrtLutNode) );
      instance.SetNew(&new_PrtLutNode);
      instance.SetNewArray(&newArray_PrtLutNode);
      instance.SetDelete(&delete_PrtLutNode);
      instance.SetDeleteArray(&deleteArray_PrtLutNode);
      instance.SetDestructor(&destruct_PrtLutNode);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PrtLutNode*)
   {
      return GenerateInitInstanceLocal((::PrtLutNode*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PrtLutNode*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PrtAmbiguityInfo(void *p = 0);
   static void *newArray_PrtAmbiguityInfo(Long_t size, void *p);
   static void delete_PrtAmbiguityInfo(void *p);
   static void deleteArray_PrtAmbiguityInfo(void *p);
   static void destruct_PrtAmbiguityInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PrtAmbiguityInfo*)
   {
      ::PrtAmbiguityInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PrtAmbiguityInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PrtAmbiguityInfo", ::PrtAmbiguityInfo::Class_Version(), "../src/PrtAmbiguityInfo.h", 18,
                  typeid(::PrtAmbiguityInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PrtAmbiguityInfo::Dictionary, isa_proxy, 4,
                  sizeof(::PrtAmbiguityInfo) );
      instance.SetNew(&new_PrtAmbiguityInfo);
      instance.SetNewArray(&newArray_PrtAmbiguityInfo);
      instance.SetDelete(&delete_PrtAmbiguityInfo);
      instance.SetDeleteArray(&deleteArray_PrtAmbiguityInfo);
      instance.SetDestructor(&destruct_PrtAmbiguityInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PrtAmbiguityInfo*)
   {
      return GenerateInitInstanceLocal((::PrtAmbiguityInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PrtAmbiguityInfo*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PrtPhotonInfo(void *p = 0);
   static void *newArray_PrtPhotonInfo(Long_t size, void *p);
   static void delete_PrtPhotonInfo(void *p);
   static void deleteArray_PrtPhotonInfo(void *p);
   static void destruct_PrtPhotonInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PrtPhotonInfo*)
   {
      ::PrtPhotonInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PrtPhotonInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PrtPhotonInfo", ::PrtPhotonInfo::Class_Version(), "../src/PrtPhotonInfo.h", 19,
                  typeid(::PrtPhotonInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PrtPhotonInfo::Dictionary, isa_proxy, 4,
                  sizeof(::PrtPhotonInfo) );
      instance.SetNew(&new_PrtPhotonInfo);
      instance.SetNewArray(&newArray_PrtPhotonInfo);
      instance.SetDelete(&delete_PrtPhotonInfo);
      instance.SetDeleteArray(&deleteArray_PrtPhotonInfo);
      instance.SetDestructor(&destruct_PrtPhotonInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PrtPhotonInfo*)
   {
      return GenerateInitInstanceLocal((::PrtPhotonInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PrtPhotonInfo*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PrtTrackInfo(void *p = 0);
   static void *newArray_PrtTrackInfo(Long_t size, void *p);
   static void delete_PrtTrackInfo(void *p);
   static void deleteArray_PrtTrackInfo(void *p);
   static void destruct_PrtTrackInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PrtTrackInfo*)
   {
      ::PrtTrackInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PrtTrackInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PrtTrackInfo", ::PrtTrackInfo::Class_Version(), "../src/PrtTrackInfo.h", 19,
                  typeid(::PrtTrackInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PrtTrackInfo::Dictionary, isa_proxy, 4,
                  sizeof(::PrtTrackInfo) );
      instance.SetNew(&new_PrtTrackInfo);
      instance.SetNewArray(&newArray_PrtTrackInfo);
      instance.SetDelete(&delete_PrtTrackInfo);
      instance.SetDeleteArray(&deleteArray_PrtTrackInfo);
      instance.SetDestructor(&destruct_PrtTrackInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PrtTrackInfo*)
   {
      return GenerateInitInstanceLocal((::PrtTrackInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PrtTrackInfo*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr PrtHit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PrtHit::Class_Name()
{
   return "PrtHit";
}

//______________________________________________________________________________
const char *PrtHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtHit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PrtHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtHit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PrtHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtHit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PrtHit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtHit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PrtEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PrtEvent::Class_Name()
{
   return "PrtEvent";
}

//______________________________________________________________________________
const char *PrtEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PrtEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PrtEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PrtEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PrtLutNode::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PrtLutNode::Class_Name()
{
   return "PrtLutNode";
}

//______________________________________________________________________________
const char *PrtLutNode::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtLutNode*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PrtLutNode::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtLutNode*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PrtLutNode::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtLutNode*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PrtLutNode::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtLutNode*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PrtAmbiguityInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PrtAmbiguityInfo::Class_Name()
{
   return "PrtAmbiguityInfo";
}

//______________________________________________________________________________
const char *PrtAmbiguityInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtAmbiguityInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PrtAmbiguityInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtAmbiguityInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PrtAmbiguityInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtAmbiguityInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PrtAmbiguityInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtAmbiguityInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PrtPhotonInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PrtPhotonInfo::Class_Name()
{
   return "PrtPhotonInfo";
}

//______________________________________________________________________________
const char *PrtPhotonInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtPhotonInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PrtPhotonInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtPhotonInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PrtPhotonInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtPhotonInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PrtPhotonInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtPhotonInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PrtTrackInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PrtTrackInfo::Class_Name()
{
   return "PrtTrackInfo";
}

//______________________________________________________________________________
const char *PrtTrackInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtTrackInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PrtTrackInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PrtTrackInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PrtTrackInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtTrackInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PrtTrackInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PrtTrackInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void PrtHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class PrtHit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PrtHit::Class(),this);
   } else {
      R__b.WriteClassBuffer(PrtHit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PrtHit(void *p) {
      return  p ? new(p) ::PrtHit : new ::PrtHit;
   }
   static void *newArray_PrtHit(Long_t nElements, void *p) {
      return p ? new(p) ::PrtHit[nElements] : new ::PrtHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_PrtHit(void *p) {
      delete ((::PrtHit*)p);
   }
   static void deleteArray_PrtHit(void *p) {
      delete [] ((::PrtHit*)p);
   }
   static void destruct_PrtHit(void *p) {
      typedef ::PrtHit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PrtHit

//______________________________________________________________________________
void PrtEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class PrtEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PrtEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(PrtEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PrtEvent(void *p) {
      return  p ? new(p) ::PrtEvent : new ::PrtEvent;
   }
   static void *newArray_PrtEvent(Long_t nElements, void *p) {
      return p ? new(p) ::PrtEvent[nElements] : new ::PrtEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_PrtEvent(void *p) {
      delete ((::PrtEvent*)p);
   }
   static void deleteArray_PrtEvent(void *p) {
      delete [] ((::PrtEvent*)p);
   }
   static void destruct_PrtEvent(void *p) {
      typedef ::PrtEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PrtEvent

//______________________________________________________________________________
void PrtLutNode::Streamer(TBuffer &R__b)
{
   // Stream an object of class PrtLutNode.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PrtLutNode::Class(),this);
   } else {
      R__b.WriteClassBuffer(PrtLutNode::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PrtLutNode(void *p) {
      return  p ? new(p) ::PrtLutNode : new ::PrtLutNode;
   }
   static void *newArray_PrtLutNode(Long_t nElements, void *p) {
      return p ? new(p) ::PrtLutNode[nElements] : new ::PrtLutNode[nElements];
   }
   // Wrapper around operator delete
   static void delete_PrtLutNode(void *p) {
      delete ((::PrtLutNode*)p);
   }
   static void deleteArray_PrtLutNode(void *p) {
      delete [] ((::PrtLutNode*)p);
   }
   static void destruct_PrtLutNode(void *p) {
      typedef ::PrtLutNode current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PrtLutNode

//______________________________________________________________________________
void PrtAmbiguityInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class PrtAmbiguityInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PrtAmbiguityInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(PrtAmbiguityInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PrtAmbiguityInfo(void *p) {
      return  p ? new(p) ::PrtAmbiguityInfo : new ::PrtAmbiguityInfo;
   }
   static void *newArray_PrtAmbiguityInfo(Long_t nElements, void *p) {
      return p ? new(p) ::PrtAmbiguityInfo[nElements] : new ::PrtAmbiguityInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_PrtAmbiguityInfo(void *p) {
      delete ((::PrtAmbiguityInfo*)p);
   }
   static void deleteArray_PrtAmbiguityInfo(void *p) {
      delete [] ((::PrtAmbiguityInfo*)p);
   }
   static void destruct_PrtAmbiguityInfo(void *p) {
      typedef ::PrtAmbiguityInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PrtAmbiguityInfo

//______________________________________________________________________________
void PrtPhotonInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class PrtPhotonInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PrtPhotonInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(PrtPhotonInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PrtPhotonInfo(void *p) {
      return  p ? new(p) ::PrtPhotonInfo : new ::PrtPhotonInfo;
   }
   static void *newArray_PrtPhotonInfo(Long_t nElements, void *p) {
      return p ? new(p) ::PrtPhotonInfo[nElements] : new ::PrtPhotonInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_PrtPhotonInfo(void *p) {
      delete ((::PrtPhotonInfo*)p);
   }
   static void deleteArray_PrtPhotonInfo(void *p) {
      delete [] ((::PrtPhotonInfo*)p);
   }
   static void destruct_PrtPhotonInfo(void *p) {
      typedef ::PrtPhotonInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PrtPhotonInfo

//______________________________________________________________________________
void PrtTrackInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class PrtTrackInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PrtTrackInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(PrtTrackInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PrtTrackInfo(void *p) {
      return  p ? new(p) ::PrtTrackInfo : new ::PrtTrackInfo;
   }
   static void *newArray_PrtTrackInfo(Long_t nElements, void *p) {
      return p ? new(p) ::PrtTrackInfo[nElements] : new ::PrtTrackInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_PrtTrackInfo(void *p) {
      delete ((::PrtTrackInfo*)p);
   }
   static void deleteArray_PrtTrackInfo(void *p) {
      delete [] ((::PrtTrackInfo*)p);
   }
   static void destruct_PrtTrackInfo(void *p) {
      typedef ::PrtTrackInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PrtTrackInfo

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 214,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 214,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETVector3gR_Dictionary();
   static void vectorlETVector3gR_TClassManip(TClass*);
   static void *new_vectorlETVector3gR(void *p = 0);
   static void *newArray_vectorlETVector3gR(Long_t size, void *p);
   static void delete_vectorlETVector3gR(void *p);
   static void deleteArray_vectorlETVector3gR(void *p);
   static void destruct_vectorlETVector3gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TVector3>*)
   {
      vector<TVector3> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TVector3>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TVector3>", -2, "vector", 214,
                  typeid(vector<TVector3>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETVector3gR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TVector3>) );
      instance.SetNew(&new_vectorlETVector3gR);
      instance.SetNewArray(&newArray_vectorlETVector3gR);
      instance.SetDelete(&delete_vectorlETVector3gR);
      instance.SetDeleteArray(&deleteArray_vectorlETVector3gR);
      instance.SetDestructor(&destruct_vectorlETVector3gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TVector3> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TVector3>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETVector3gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TVector3>*)0x0)->GetClass();
      vectorlETVector3gR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETVector3gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETVector3gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVector3> : new vector<TVector3>;
   }
   static void *newArray_vectorlETVector3gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVector3>[nElements] : new vector<TVector3>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETVector3gR(void *p) {
      delete ((vector<TVector3>*)p);
   }
   static void deleteArray_vectorlETVector3gR(void *p) {
      delete [] ((vector<TVector3>*)p);
   }
   static void destruct_vectorlETVector3gR(void *p) {
      typedef vector<TVector3> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TVector3>

namespace ROOT {
   static TClass *vectorlEPrtPhotonInfogR_Dictionary();
   static void vectorlEPrtPhotonInfogR_TClassManip(TClass*);
   static void *new_vectorlEPrtPhotonInfogR(void *p = 0);
   static void *newArray_vectorlEPrtPhotonInfogR(Long_t size, void *p);
   static void delete_vectorlEPrtPhotonInfogR(void *p);
   static void deleteArray_vectorlEPrtPhotonInfogR(void *p);
   static void destruct_vectorlEPrtPhotonInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PrtPhotonInfo>*)
   {
      vector<PrtPhotonInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PrtPhotonInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PrtPhotonInfo>", -2, "vector", 214,
                  typeid(vector<PrtPhotonInfo>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPrtPhotonInfogR_Dictionary, isa_proxy, 0,
                  sizeof(vector<PrtPhotonInfo>) );
      instance.SetNew(&new_vectorlEPrtPhotonInfogR);
      instance.SetNewArray(&newArray_vectorlEPrtPhotonInfogR);
      instance.SetDelete(&delete_vectorlEPrtPhotonInfogR);
      instance.SetDeleteArray(&deleteArray_vectorlEPrtPhotonInfogR);
      instance.SetDestructor(&destruct_vectorlEPrtPhotonInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PrtPhotonInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<PrtPhotonInfo>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPrtPhotonInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<PrtPhotonInfo>*)0x0)->GetClass();
      vectorlEPrtPhotonInfogR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPrtPhotonInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPrtPhotonInfogR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PrtPhotonInfo> : new vector<PrtPhotonInfo>;
   }
   static void *newArray_vectorlEPrtPhotonInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PrtPhotonInfo>[nElements] : new vector<PrtPhotonInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPrtPhotonInfogR(void *p) {
      delete ((vector<PrtPhotonInfo>*)p);
   }
   static void deleteArray_vectorlEPrtPhotonInfogR(void *p) {
      delete [] ((vector<PrtPhotonInfo>*)p);
   }
   static void destruct_vectorlEPrtPhotonInfogR(void *p) {
      typedef vector<PrtPhotonInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<PrtPhotonInfo>

namespace ROOT {
   static TClass *vectorlEPrtHitgR_Dictionary();
   static void vectorlEPrtHitgR_TClassManip(TClass*);
   static void *new_vectorlEPrtHitgR(void *p = 0);
   static void *newArray_vectorlEPrtHitgR(Long_t size, void *p);
   static void delete_vectorlEPrtHitgR(void *p);
   static void deleteArray_vectorlEPrtHitgR(void *p);
   static void destruct_vectorlEPrtHitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PrtHit>*)
   {
      vector<PrtHit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PrtHit>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PrtHit>", -2, "vector", 214,
                  typeid(vector<PrtHit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPrtHitgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<PrtHit>) );
      instance.SetNew(&new_vectorlEPrtHitgR);
      instance.SetNewArray(&newArray_vectorlEPrtHitgR);
      instance.SetDelete(&delete_vectorlEPrtHitgR);
      instance.SetDeleteArray(&deleteArray_vectorlEPrtHitgR);
      instance.SetDestructor(&destruct_vectorlEPrtHitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PrtHit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<PrtHit>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPrtHitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<PrtHit>*)0x0)->GetClass();
      vectorlEPrtHitgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPrtHitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPrtHitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PrtHit> : new vector<PrtHit>;
   }
   static void *newArray_vectorlEPrtHitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PrtHit>[nElements] : new vector<PrtHit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPrtHitgR(void *p) {
      delete ((vector<PrtHit>*)p);
   }
   static void deleteArray_vectorlEPrtHitgR(void *p) {
      delete [] ((vector<PrtHit>*)p);
   }
   static void destruct_vectorlEPrtHitgR(void *p) {
      typedef vector<PrtHit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<PrtHit>

namespace ROOT {
   static TClass *vectorlEPrtAmbiguityInfogR_Dictionary();
   static void vectorlEPrtAmbiguityInfogR_TClassManip(TClass*);
   static void *new_vectorlEPrtAmbiguityInfogR(void *p = 0);
   static void *newArray_vectorlEPrtAmbiguityInfogR(Long_t size, void *p);
   static void delete_vectorlEPrtAmbiguityInfogR(void *p);
   static void deleteArray_vectorlEPrtAmbiguityInfogR(void *p);
   static void destruct_vectorlEPrtAmbiguityInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PrtAmbiguityInfo>*)
   {
      vector<PrtAmbiguityInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PrtAmbiguityInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PrtAmbiguityInfo>", -2, "vector", 214,
                  typeid(vector<PrtAmbiguityInfo>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPrtAmbiguityInfogR_Dictionary, isa_proxy, 0,
                  sizeof(vector<PrtAmbiguityInfo>) );
      instance.SetNew(&new_vectorlEPrtAmbiguityInfogR);
      instance.SetNewArray(&newArray_vectorlEPrtAmbiguityInfogR);
      instance.SetDelete(&delete_vectorlEPrtAmbiguityInfogR);
      instance.SetDeleteArray(&deleteArray_vectorlEPrtAmbiguityInfogR);
      instance.SetDestructor(&destruct_vectorlEPrtAmbiguityInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PrtAmbiguityInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<PrtAmbiguityInfo>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPrtAmbiguityInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<PrtAmbiguityInfo>*)0x0)->GetClass();
      vectorlEPrtAmbiguityInfogR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPrtAmbiguityInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPrtAmbiguityInfogR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PrtAmbiguityInfo> : new vector<PrtAmbiguityInfo>;
   }
   static void *newArray_vectorlEPrtAmbiguityInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PrtAmbiguityInfo>[nElements] : new vector<PrtAmbiguityInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPrtAmbiguityInfogR(void *p) {
      delete ((vector<PrtAmbiguityInfo>*)p);
   }
   static void deleteArray_vectorlEPrtAmbiguityInfogR(void *p) {
      delete [] ((vector<PrtAmbiguityInfo>*)p);
   }
   static void destruct_vectorlEPrtAmbiguityInfogR(void *p) {
      typedef vector<PrtAmbiguityInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<PrtAmbiguityInfo>

namespace {
  void TriggerDictionaryInitialization_PrtDict_Impl() {
    static const char* headers[] = {
"../src/PrtHit.h",
"../src/PrtEvent.h",
"../src/PrtLutNode.h",
"../src/PrtTrackInfo.h",
"../src/PrtPhotonInfo.h",
"../src/PrtAmbiguityInfo.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/fairroot.gsi.de/fairsoft/may18/include/root",
"/lustre/nyx/panda/aali/phs/build/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "PrtDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$../src/PrtHit.h")))  PrtHit;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$../src/PrtEvent.h")))  PrtEvent;
class __attribute__((annotate("$clingAutoload$../src/PrtLutNode.h")))  PrtLutNode;
class __attribute__((annotate("$clingAutoload$../src/PrtTrackInfo.h")))  PrtAmbiguityInfo;
class __attribute__((annotate("$clingAutoload$../src/PrtTrackInfo.h")))  PrtPhotonInfo;
class __attribute__((annotate("$clingAutoload$../src/PrtTrackInfo.h")))  PrtTrackInfo;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "PrtDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "../src/PrtHit.h"
#include "../src/PrtEvent.h"
#include "../src/PrtLutNode.h"
#include "../src/PrtTrackInfo.h"
#include "../src/PrtPhotonInfo.h"
#include "../src/PrtAmbiguityInfo.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"PrtAmbiguityInfo", payloadCode, "@",
"PrtEvent", payloadCode, "@",
"PrtHit", payloadCode, "@",
"PrtLutNode", payloadCode, "@",
"PrtPhotonInfo", payloadCode, "@",
"PrtTrackInfo", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("PrtDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_PrtDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_PrtDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_PrtDict() {
  TriggerDictionaryInitialization_PrtDict_Impl();
}
