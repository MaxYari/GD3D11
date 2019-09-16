#pragma once
#include "pch.h"
#include "HookedFunctions.h"
#include "zCPolygon.h"
#include "Engine.h"
#include "GothicAPI.h"
#include "zCObject.h"

struct zCPolyStripInstance {
	zCMaterial *material;

	zCVertex *vertList;
	zCPolygon *polyList;

	int numPoly;
	int numVert;

	float3 *centerPointList;
	float *alphaList;
	float width;
	zCVob *connectedVob;
	zTBBox3D bbox3D;
	int camAlign;
	int heightCheck;
	int everyFrameUpdate;
	float heightBound;

	int firstSeg;
	int lastSeg;
	int numSeg;

	float visLastFrac;
	float visFirstFrac;

	float alphaFadeSpeed;
	float newAlphaFadeSpeed;
	float newAlpha;
	int lastDirSeg;
	float3 lastDirNormal;

	unsigned char localFOR : 1;
};

class zCPolyStrip : public zCObject
{
public:
//#ifndef BUILD_GOTHIC_1_08k

//#endif

	zCPolyStripInstance GetInstanceData() {
		return *(zCPolyStripInstance*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_Material);
	}

	zCMaterial* GetMaterial() {
		return *(zCMaterial**)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_Material);
	}

	zCVertex* GetVertList() {
		return *(zCVertex**)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_VertList);
	}

	zCPolygon* GetPolyList()
	{
		return *(zCPolygon**)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_PolyList);
	}

	float* GetAlphaList() {
		return *(float**)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_AlphaList);

	}

	float GetWidth() {
		return *(float*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_Width);

	}


	int GetNumPolys()
	{
		return *(int*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_NumPolys);
	}

	int GetNumVerts()
	{
		return *(int*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_NumVerts);
	}

	zCVob* GetConntectedVob() {
		return *(zCVob**)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_ConnectedVob);
	}

	float3* GetCenterPointsList() {
		return *(float3**)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_CenterPointList);
	}

	int GetEveryFrameUpdate() {
		return *(int*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_EveryFrameUpdate);
		
	}

	int GetFirstSeg() {
		return *(int*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_FirstSeg);
	}

	int GetLastSeg() {
		return *(int*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_LastSeg);
	}

	int GetNumSeg() {
		return *(int*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_NumSeg);
	}

	float GetVisLastFrac() {
		return *(float*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_VisLastFrac);
	}

	float GetVisFirstFrac() {
		return *(float*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_VisFirstFrac);
	}

	float GetAlphaFadeSpeed() {
		return *(float*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_AlphaFadeSpeed);
	}

	float GetNewAlphaFadeSpeed() {
		return *(float*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_NewAlphaFadeSpeed);
	}

	float GetNewAlpha() {
		return *(float*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_NewAlpha);
	}

	int GetLastDirSeg() {
		return *(int*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_LastDirSeg);
	}

	float3 GetLastDirNormal() {
		return *(float3*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_LastDirNormal);
	}

	unsigned char GetLocalFOR() {
		return *(unsigned char*)THISPTR_OFFSET(GothicMemoryLocations::zCPolyStrip::Offset_LocalFOR);
	}


	void SetVisibleSegments(float visibleFirst, float visibleLast) {
		XCALL(GothicMemoryLocations::zCPolyStrip::SetVisibleSegments);
	}

	void AlighToCamera() {
		XCALL(GothicMemoryLocations::zCPolyStrip::AlignToCamera);
	}

	/*
	struct zCClassDef* _GetClassDef() {
		XCALL(GothicMemoryLocations::zCPolyStrip::GetClassDef);
	}
	*/

};