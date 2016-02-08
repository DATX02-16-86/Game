#pragma once

#include <Engine.h>

class UCubeVoxelChunk;

/** A single vertex of a cubic voxel. */
struct CubeVoxelVertex {
	// Position as half floats.
	uint16 x, y, z, light;

	// Texture coordinates as half floats.
	uint16 u, v;

	// Normal vector with normalized components.
	int8 nx, ny, nz, nw;
};

/**
 * The vertex factory for cubic voxels.
 * Determines how vertex data is sent to and interpreted by the GPU.
 */
struct CubeVoxelFactory : FLocalVertexFactory {
	DECLARE_VERTEX_FACTORY_TYPE(CubeVoxelFactory);

	void Init(const FVertexBuffer* buffer);
};

/**
 * The chunk scene proxy for cubic voxels.
 * This manages the renderer data of a single chunk.
 */
struct CubeVoxelProxy : FPrimitiveSceneProxy {
	CubeVoxelProxy(UCubeVoxelChunk* chunk);

	virtual ~CubeVoxelProxy() {
		vertices.ReleaseResource();
		indices.ReleaseResource();
	}

	virtual void DrawStaticElements(FStaticPrimitiveDrawInterface* c) override;
	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* view) override;
	virtual uint32 GetMemoryFootprint() const override { return sizeof(*this) + GetAllocatedSize(); }

private:
	UMaterialInterface* material;
	FVertexBuffer vertices;
	FIndexBuffer indices;
	CubeVoxelFactory factory;
	uint32 primitiveCount;
	uint32 vertexCount;
};