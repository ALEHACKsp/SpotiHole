// ==========================================================
// Project: SpotiHole
// 
// Component: SpotiHole.dll
//
// Purpose: Apply quick patches to Spotify
//          
// Initial author: meik97
//
// Started: 28.07.2020
// ==========================================================

#include "..\include\BaseInclude.hpp"

namespace Modules
{
	void QuickPatch::ToggleDeveloperTools(bool active)
	{
		bool* isDev = (bool*)0x19E86B0;
		*isDev = active;
	}

	void QuickPatch::Branding()
	{
		DWORD OldProtection;
		VirtualProtect((LPVOID)0x1274818, sizeof(std::string), PAGE_EXECUTE_READWRITE, &OldProtection);
		*(std::string*)0x1274818 = (std::string)"SpotiHole";
		VirtualProtect((LPVOID)0x1274818, sizeof(std::string), OldProtection, &OldProtection);
	}

	QuickPatch::QuickPatch()
	{
		Utils::Utils::DebugPrint("Applying QuickPatch patch...");
		QuickPatch::ToggleDeveloperTools(1);
		QuickPatch::Branding();
	}
}