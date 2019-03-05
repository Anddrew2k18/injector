
#define HACK_MODULE_FILE_NAME	"\\HK.CHEAT.DLL"	// THE NAME OF THE HACK MODULE

#include <Windows.h>
#include <Psapi.h>

#include <vector>
#include <string>

using namespace std;

#include "XorString.h"

VOID main (VOID)
{
	DWORD dwProcs[XS_RANDOM_SIZE_256_4] = { }, dwSize = { };
	CHAR szName[XS_RANDOM_SIZE] = { };
	HANDLE pProc = { }, pPatch = { }, pLoadLibAddr = (HANDLE)GetProcAddress (GetModuleHandle (XorString ("KERNEL32.DLL")), XorString ("LoadLibraryA"));
	SIZE_T uIter = XS_RANDOM_SIZE_192_4, uPos = XS_RANDOM_SIZE_4_4;
	string Data = { };

	while (TRUE)
	{
		if (EnumProcesses (dwProcs, sizeof dwProcs, &dwSize))
		{
			for (uIter = NULL; uIter < dwSize / sizeof DWORD; uIter++)
			{
				if (dwProcs[uIter] < 1 || dwProcs[uIter] == GetCurrentProcessId () || !(pProc = OpenProcess (PROCESS_ALL_ACCESS, NULL, dwProcs[uIter])))
					continue;

				GetProcessImageFileName (pProc, szName, ARRAYSIZE (szName));

				if (strstr (szName, XorString ("csgo.exe")))
				{
					GetModuleFileName (NULL, szName, ARRAYSIZE (szName)), Data.assign (szName), uPos = Data.find_last_of (XorString ("\\"));

					if (uPos >= NULL)
						Data.erase (uPos);

					Data.append (XorString (HACK_MODULE_FILE_NAME)), pPatch = (HANDLE)VirtualAllocEx (pProc, NULL, Data.length (), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE), \
						WriteProcessMemory (pProc, pPatch, Data.c_str (), Data.length (), NULL), CreateRemoteThread (pProc, NULL, NULL, PTHREAD_START_ROUTINE (pLoadLibAddr), pPatch, NULL, NULL), \
						Sleep (XS_RANDOM_SIZE_4_4), CloseHandle (pProc);

					return;
				};

				CloseHandle (pProc);
			};
		};

		Sleep (XS_RANDOM_SIZE_4_4);
	};
};
