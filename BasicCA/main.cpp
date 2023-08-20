
#include "stdafx.h"

#include <wcautil.h>

HINSTANCE g_hInstance = NULL;


extern "C" BOOL WINAPI DllMain( 
    HINSTANCE hInstance,
    DWORD     dwReason,
    LPVOID    lpReserved
					 )
{
    LPVOID lpJunk = NULL;

    g_hInstance = hInstance;
    lpJunk = lpReserved;

    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
		WcaGlobalInitialize(hInstance);
		break;

    case DLL_PROCESS_DETACH:
		WcaGlobalFinalize();
        break;
    }
    return TRUE;

}
