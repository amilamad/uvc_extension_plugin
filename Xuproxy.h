#include "Stdafx.h"

#include <ks.h>
#include <ksproxy.h>
#include <ksmedia.h>
#include "C:\Program Files (x86)\Windows Kits\8.0\Include\um\vidcap.h"

DEFINE_GUID(CLSID_ExtensionUnit, 0x910711f5, 0x7e6d, 0x41f3, 0x88, 0xdd, 0x65, 0x37, 0x82, 0x61, 0x9e, 0xdb);

class CNodeControl : public IKsNodeControl
{
public:
    STDMETHOD(put_NodeId) (DWORD dwNodeId);
    STDMETHOD(put_KsControl) (PVOID pKsControl);

    DWORD m_dwNodeId;
    CComPtr<IKsControl> m_pKsControl;
};

class CExtension : public IExtensionUnit, public CComObjectRootEx<CComObjectThreadModel>, public CComCoClass<CExtension, &CLSID_ExtensionUnit>, public CNodeControl
{
   public:

   CExtension();
   STDMETHOD(FinalConstruct)();

   BEGIN_COM_MAP(CExtension)
      COM_INTERFACE_ENTRY(IKsNodeControl)
      COM_INTERFACE_ENTRY(IExtensionUnit)
   END_COM_MAP()

   DECLARE_PROTECT_FINAL_CONSTRUCT()
   DECLARE_NO_REGISTRY()
   DECLARE_ONLY_AGGREGATABLE(CExtension)

   // IExtensionUnit
   public:
   STDMETHOD (get_Info)(
      ULONG ulSize,
      BYTE pInfo[]);
   STDMETHOD (get_InfoSize)(
      ULONG *pulSize);
   STDMETHOD (get_PropertySize)(
      ULONG PropertyId, 
      ULONG *pulSize);
   STDMETHOD (get_Property)(
      ULONG PropertyId, 
      ULONG ulSize, 
      BYTE pValue[]);
   STDMETHOD (put_Property)(
      ULONG PropertyId, 
      ULONG ulSize, 
      BYTE pValue[]);
   STDMETHOD (get_PropertyRange)(
      ULONG PropertyId, 
      ULONG ulSize,
      BYTE pMin[], 
      BYTE pMax[], 
      BYTE pSteppingDelta[], 
      BYTE pDefault[]);
};

#define STATIC_PROPSETID_VIDCAP_EXTENSION_UNIT \
   0x7ca138cf, 0x71f2, 0x4ec5, 0x8d, 0x4c, 0xf0, 0x87, 0x74, 0x1c, 0xab, 0xae
DEFINE_GUIDSTRUCT("7CA138CF-71F2-4EC5-8D4C-F087741CABAE", \ 
   PROPSETID_VIDCAP_EXTENSION_UNIT);
#define PROPSETID_VIDCAP_EXTENSION_UNIT \      
   DEFINE_GUIDNAMED(PROPSETID_VIDCAP_EXTENSION_UNIT)