#include "VoxelWorldPrivatePCH.h"
#include "VoxelGeometry.h"
#include "VoxelChunk.h"

CubeVoxelProxy::CubeVoxelProxy(UCubeVoxelChunk* chunk): FPrimitiveSceneProxy(chunk) {
	material = chunk->GetMaterial(0);
	if(!material) {
		material = UMaterial::GetDefaultMaterial(MD_Surface);
	}
}

void CubeVoxelProxy::DrawStaticElements(FStaticPrimitiveDrawInterface* c) {
	auto materialProxy = material->GetRenderProxy(false);

	FMeshBatch batch;
	batch.VertexFactory = &factory;
	batch.MaterialRenderProxy = materialProxy;
	batch.ReverseCulling = IsLocalToWorldDeterminantNegative();
	FMeshBatchElement& element = batch.Elements[0];
	element.IndexBuffer = &indices;
	element.FirstIndex = 0;
	element.NumPrimitives = primitiveCount;
	element.MinVertexIndex = 0;
	element.MaxVertexIndex = vertexCount;
	element.PrimitiveUniformBuffer = CreatePrimitiveUniformBufferImmediate(GetLocalToWorld(), GetBounds(), GetLocalBounds(), true, UseEditorDepthTest());
	c->DrawMesh(batch, 0.f);
}

FPrimitiveViewRelevance CubeVoxelProxy::GetViewRelevance(const FSceneView* view) {
	FPrimitiveViewRelevance r;
	r.bDrawRelevance = IsShown(view);
	r.bShadowRelevance = IsShadowCast(view);
	r.bStaticRelevance = true;
	return r;
}

void CubeVoxelFactory::Init(const FVertexBuffer* buffer) {
	check(!IsInRenderingThread());

	// Tell the renderer what data a vertex consists of in a really ugly way
	// (this is executed inside the renderer thread).
	ENQUEUE_UNIQUE_RENDER_COMMAND_TWOPARAMETER(
		InitCubeVoxelFactory,
		CubeVoxelFactory*, factory, this,
		const FVertexBuffer*, buffer, buffer,
		{
			DataType dataType;
			dataType.PositionComponent = FVertexStreamComponent(buffer, 0, sizeof(CubeVoxelVertex), VET_Half4);
			dataType.TextureCoordinates.Add(FVertexStreamComponent(buffer, 8, sizeof(CubeVoxelVertex), VET_Half2));
			dataType.TangentBasisComponents[0] = FVertexStreamComponent(buffer, 12, sizeof(CubeVoxelVertex), VET_PackedNormal);
			factory->SetData(dataType);
		}
	);
}

IMPLEMENT_VERTEX_FACTORY_TYPE(CubeVoxelFactory, "CubeVoxelVertexFactory", true, false, true, true, true);