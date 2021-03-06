// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

typedef int/*NTSTATUS*/ (__stdcall *NtRaiseHardError)(
	IN int/*NTSTATUS*/ ErrorStatus, IN ULONG NumberOfParameters,
	IN ULONG UnicodeStringParameterMask, IN PULONG_PTR Parameters,
	IN ULONG ValidResponseOptions,
	OUT int/*HardErrorResponse*/ *Response);


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
	{

		MessageBoxA(NULL, "NotePad", "Inside a CIG Enabled Process!", MB_OK);
	}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

