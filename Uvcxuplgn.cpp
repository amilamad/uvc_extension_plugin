#include "stdafx.h"
CComModule _Module;
#include <initguid.h>
#include "interface.h"
#include "xuproxy.h"
BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_ExtensionUnit, CExtension)
END_OBJECT_MAP()

STDAPI DllRegisterServer(void)
{
	return _Module.RegisterServer(FALSE, NULL);
}

STDAPI DllUnregisterServer(void)
{
	return _Module.UnregisterServer();
}

EXTERN_C
BOOL
DllMain(
	HINSTANCE   hinst,
	DWORD       dwReason,
	LPVOID      lpReserved)
{
	switch (dwReason) {
		case DLL_PROCESS_ATTACH:

			_Module.Init (ObjectMap, hinst);
			break;

		case DLL_PROCESS_DETACH:
			_Module.Term();
			break;
	}
	return TRUE;
}

extern "C" STDMETHODIMP DllCanUnloadNow(void)
{
	return _Module.GetLockCount()==0 ? S_OK : S_FALSE;
}

extern "C" STDAPI DllGetClassObject(
	REFCLSID    rclsid,
	REFIID      riid,
	LPVOID      *ppv)
{
	return _Module.GetClassObject(rclsid, riid, ppv);
}