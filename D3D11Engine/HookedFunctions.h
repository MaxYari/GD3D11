#pragma once
#include "pch.h"
#include "detours.h"
#include "GothicMemoryLocations.h"
#include "zTypes.h"
#include "HookExceptionFilter.h"

/** This file stores the original versions of the hooked functions and the function declerations */

class zCFileBIN;
class zCCamera;
class zCVob;
class zSTRING;
class zCBspBase;
class oCNPC;
class zCPolygon;

template <class T> 
class zCTree;
class zCVisual;

typedef int (__thiscall* zCBspTreeLoadBIN)(void*,zCFileBIN&, int);
typedef void (__thiscall* zCWorldRender)(void*,zCCamera&);
typedef void (__thiscall* zCWorldVobAddedToWorld)(void*, zCVob*);
typedef void (__thiscall* oCNPCEnable)(void*, D3DXVECTOR3&);
typedef void (__thiscall* oCWorldInsertVobInWorld)(void*, zCVob*);
typedef void (__thiscall* zCBspTreeAddVob)(void*, zCVob*);
typedef void (__thiscall* zCWorldLoadWorld)(void*, const zSTRING& fileName, const int loadMode);
typedef void (__thiscall* oCGameEnterWorld)(void*, oCNPC* playerVob, int changePlayerPos, const zSTRING& startpoint);
typedef void (__thiscall* zCWorldVobRemovedFromWorld)(void*, zCVob*);
typedef D3DXMATRIX (__cdecl* Alg_Rotation3DNRad)(const D3DXVECTOR3& axis, const float angle);
typedef int (__cdecl* vidGetFPSRate)(void);
typedef void (__thiscall* GenericDestructor)(void *);
typedef void (__thiscall* GenericThiscall)(void *);
typedef void (__thiscall* zCMaterialConstruktor)(void *);
typedef void (__thiscall* zCMaterialInitValues)(void *);
typedef void (__fastcall* zCBspNodeRenderIndoor)(void *, int);
typedef void (__fastcall* zCBspNodeRenderOutdoor)(void *, zCBspBase*, zTBBox3D, int, int);

typedef int (__fastcall* zCBspBaseCollectPolysInBBox3D)(void*, const zTBBox3D&, zCPolygon **&, int&);

typedef int (__fastcall* zCBspBaseCheckRayAgainstPolys)(void*, const D3DXVECTOR3&, const D3DXVECTOR3&, D3DXVECTOR3&);

typedef int (__thiscall* zFILEOpen)(void*,zSTRING&, bool);
typedef void (__thiscall* zCRnd_D3DVid_SetScreenMode)(void*, int);
typedef void (__thiscall* zCRnd_D3D_DrawPoly)(void*, zCPolygon*);
typedef int (__thiscall* zCOptionReadInt)(void*,zSTRING const&, char const*, int);
typedef int (__thiscall* zCOptionReadBool)(void*,zSTRING const&, char const*, int);
typedef unsigned long (__thiscall* zCOptionReadDWORD)(void*,zSTRING const&, char const*, unsigned long);
typedef void (__cdecl* zCViewSetMode)(int, int, int, HWND*);
typedef int (__stdcall* HandledWinMain)(HINSTANCE, HINSTANCE, LPSTR, int);
typedef int (__thiscall* CGameManagerExitGame)(void*);
typedef const zSTRING* (__thiscall* zCVisualGetFileExtension)(void*, int);
typedef long (__stdcall* zCExceptionHandlerUnhandledExceptionFilter)(void*);
typedef void (__thiscall* zCWorldDisposeVobs)(void *, zCTree<zCVob> *);
typedef void (__thiscall* oCSpawnManagerSpawnNpc)(void*, oCNPC *, const D3DXVECTOR3&, float);
typedef void (__thiscall* oCSpawnManagerInsertNpc)(void*, oCNPC *, const D3DXVECTOR3&);
typedef void (__thiscall* zCVobSetVisual)(void*, zCVisual*);


typedef int (__thiscall* zCTex_D3DXTEX_BuildSurfaces)(void*, int);
typedef int (__thiscall* zCTextureLoadResourceData)(void*);
typedef int (__thiscall* zCThreadSuspendThread)(void*);
typedef void (__thiscall* zCResourceManagerCacheOut)(void*,class zCResource*);
typedef void (__thiscall* zCQuadMarkCreateQuadMark)(void*, zCPolygon*, const D3DXVECTOR3&, const D3DXVECTOR2&, struct zTEffectParams*);
typedef void (__thiscall* oCWorldEnableVob)(void*, zCVob*,zCVob*);
typedef void (__thiscall* oCWorldDisableVob)(void*, zCVob*);
typedef void (__fastcall* oCWorldRemoveFromLists)(void*, zCVob*);
typedef int (__thiscall* zCBinkPlayerOpenVideo)(void*, class zSTRING);
typedef int (__thiscall* zCModelPrototypeLoadModelASC)(void*, class zSTRING const &);
typedef int (__thiscall* zCModelPrototypeReadMeshAndTreeMSB)(void*,int &, class zCFileBIN &);

typedef void (__thiscall* zCActiveSndAutoCalcObstruction)(void*, int);

#ifdef BUILD_GOTHIC_1_08k
typedef void (__thiscall* zCVobEndMovement)(void*);
#else
typedef void (__thiscall* zCVobEndMovement)(void*, int);
#endif
struct zTRndSurfaceDesc;
struct HookedFunctionInfo
{

	/** Init all hooks here */
	void InitHooks();

	zCBspTreeLoadBIN original_zCBspTreeLoadBIN;
	zCWorldRender original_zCWorldRender;
	zCWorldVobAddedToWorld original_zCWorldVobAddedToWorld;
	zCBspTreeAddVob original_zCBspTreeAddVob;
	oCWorldInsertVobInWorld original_oCWorldInsertVobInWorld;
	zCWorldLoadWorld original_zCWorldLoadWorld;
	oCGameEnterWorld original_oCGameEnterWorld;
	zCWorldVobRemovedFromWorld original_zCWorldVobRemovedFromWorld;
	Alg_Rotation3DNRad original_Alg_Rotation3DNRad;
	GenericDestructor original_zCMaterialDestructor;
	GenericDestructor original_zCParticleFXDestructor;
	GenericDestructor original_zCVisualDestructor;
	zCMaterialConstruktor original_zCMaterialConstruktor;
	zCMaterialInitValues original_zCMaterialInitValues;
	zFILEOpen original_zFILEOpen;
	zCRnd_D3DVid_SetScreenMode original_zCRnd_D3DVid_SetScreenMode;
	zCRnd_D3D_DrawPoly original_zCRnd_D3D_DrawPoly;
	zCOptionReadInt original_zCOptionReadInt;
	zCOptionReadBool original_zCOptionReadBool;
	zCOptionReadDWORD original_zCOptionReadDWORD;
	zCViewSetMode original_zCViewSetMode;
	HandledWinMain original_HandledWinMain;
	CGameManagerExitGame original_CGameManagerExitGame;
	zCExceptionHandlerUnhandledExceptionFilter original_zCExceptionHandler_UnhandledExceptionFilter;
	GenericThiscall original_zCWorldDisposeWorld;
	zCWorldDisposeVobs original_zCWorldDisposeVobs;
	oCSpawnManagerSpawnNpc original_oCSpawnManagerSpawnNpc;
	zCVobSetVisual original_zCVobSetVisual;
	GenericDestructor original_zCVobDestructor;
	zCTex_D3DXTEX_BuildSurfaces original_zCTex_D3DXTEX_BuildSurfaces;
	zCTextureLoadResourceData ofiginal_zCTextureLoadResourceData;
	zCThreadSuspendThread original_zCThreadSuspendThread;
	zCResourceManagerCacheOut original_zCResourceManagerCacheOut;
	zCQuadMarkCreateQuadMark original_zCQuadMarkCreateQuadMark;
	GenericDestructor original_zCQuadMarkDestructor;
	GenericThiscall original_zCQuadMarkConstructor;
	oCSpawnManagerInsertNpc original_oCSpawnManagerInsertNpc;
	oCNPCEnable original_oCNPCEnable;
	GenericThiscall original_oCNPCDisable;
	GenericThiscall original_oCNPCInitModel;
	oCWorldDisableVob original_oCWorldDisableVob;
	oCWorldEnableVob original_oCWorldEnableVob;
	oCWorldRemoveFromLists original_oCWorldRemoveFromLists;
	zCBinkPlayerOpenVideo original_zCBinkPlayerOpenVideo;
	zCVobEndMovement original_zCVobEndMovement;
	zCBspBaseCollectPolysInBBox3D original_zCBspBaseCollectPolysInBBox3D;
	zCBspBaseCheckRayAgainstPolys original_zCBspBaseCheckRayAgainstPolys;
	zCBspBaseCheckRayAgainstPolys original_zCBspBaseCheckRayAgainstPolysCache;
	zCBspBaseCheckRayAgainstPolys original_zCBspBaseCheckRayAgainstPolysNearestHit;
	//zCActiveSndAutoCalcObstruction original_zCActiveSndAutoCalcObstruction;
	zCModelPrototypeLoadModelASC original_zCModelPrototypeLoadModelASC;
	zCModelPrototypeReadMeshAndTreeMSB original_zCModelPrototypeReadMeshAndTreeMSB;

	/** Function hooks */
	static int __stdcall hooked_HandledWinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR szCmdLine, int sw);
	static void __cdecl hooked_ExitGameFunc();

	/** Unhandled exception handler */
	static long __stdcall hooked_zCExceptionHandlerUnhandledExceptionFilter(EXCEPTION_POINTERS* exceptionPtrs);

	/** Single function for making the bink-player working again */
	/** Returns the pixelformat of a bink-surface */
	static long __fastcall hooked_zBinkPlayerGetPixelFormat(void* thisptr, void* unknwn, zTRndSurfaceDesc& desc);
	static int __fastcall hooked_zBinkPlayerOpenVideo(void* thisptr, void* unknwn, zSTRING str);
	static void __fastcall hooked_zCActiveSndAutoCalcObstruction(void* thisptr, void* unknwn, int i);
};

namespace HookedFunctions
{
	/** Holds all the original functions */
	__declspec( selectany ) HookedFunctionInfo OriginalFunctions;
};