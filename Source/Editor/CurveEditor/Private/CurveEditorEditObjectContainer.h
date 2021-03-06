// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "UObject/GCObject.h"
#include "CurveEditorKeyProxy.h"

struct FCurveEditorEditObjectContainer : FGCObject
{
	FCurveEditorEditObjectContainer() = default;

	FCurveEditorEditObjectContainer(const FCurveEditorEditObjectContainer&) = delete;
	FCurveEditorEditObjectContainer& operator=(const FCurveEditorEditObjectContainer&) = delete;

	FCurveEditorEditObjectContainer(FCurveEditorEditObjectContainer&&) = delete;
	FCurveEditorEditObjectContainer& operator=(FCurveEditorEditObjectContainer&&) = delete;

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override
	{
		for (auto& Pair : CurveIDToKeyProxies)
		{
			Collector.AddReferencedObjects(Pair.Value);
		}
	}

	/**  */
	TMap<FCurveModelID, TMap<FKeyHandle, UObject*> > CurveIDToKeyProxies;
};