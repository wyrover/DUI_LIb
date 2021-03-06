/*
    Copyright 2011 Google Inc.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */


#ifndef GrInOrderDrawBuffer_DEFINED
#define GrInOrderDrawBuffer_DEFINED

#include "GrDrawTarget.h"
#include "GrAllocPool.h"
#include "GrAllocator.h"
#include "GrClip.h"

class GrVertexBufferAllocPool;
class GrIndexBufferAllocPool;

/**
 * GrInOrderDrawBuffer is an implementation of GrDrawTarget that queues up
 * draws for eventual playback into a GrGpu. In theory one draw buffer could
 * playback into another. When index or vertex buffers are used as geometry
 * sources it is the callers the draw buffer only holds references to the
 * buffers. It is the callers responsibility to ensure that the data is still
 * valid when the draw buffer is played back into a GrGpu. Similarly, it is the
 * caller's responsibility to ensure that all referenced textures, buffers,
 * and rendertargets are associated in the GrGpu object that the buffer is
 * played back into. The buffer requires VB and IB pools to store geometry.
 */

class GrInOrderDrawBuffer : public GrDrawTarget {
public:

    /**
     * Creates a GrInOrderDrawBuffer
     *
     * @param vertexPool pool where vertices for queued draws will be saved when
     *                   the vertex source is either reserved or array.
     * @param indexPool  pool where indices for queued draws will be saved when
     *                   the index source is either reserved or array.
     */
    GrInOrderDrawBuffer(GrVertexBufferAllocPool* vertexPool,
                        GrIndexBufferAllocPool* indexPool);

    virtual ~GrInOrderDrawBuffer();

    /**
     * Copies the draw state and clip from target to this draw buffer.
     *
     * @param target    the target whose clip and state should be copied.
     */
    void initializeDrawStateAndClip(const GrDrawTarget& target);

    /**
     * Provides the buffer with an index buffer that can be used for quad rendering.
     * The buffer may be able to batch consecutive drawRects if this is provided.
     * @param indexBuffer   index buffer with quad indices.
     */
    void setQuadIndexBuffer(const GrIndexBuffer* indexBuffer);

    /**
     * Empties the draw buffer of any queued up draws.
     */
    void reset();

    /**
     * plays the queued up draws to another target. Does not empty this buffer so
     * that it can be played back multiple times.
     * @param target    the target to receive the playback
     */
    void playback(GrDrawTarget* target);
    
    // overrides from GrDrawTarget
    virtual void drawIndexed(GrPrimitiveType primitiveType,
                             int startVertex,
                             int startIndex,
                             int vertexCount,
                             int indexCount);
    virtual void drawNonIndexed(GrPrimitiveType primitiveType,
                                int startVertex,
                                int vertexCount);

    virtual void drawRect(const GrRect& rect, 
                          const GrMatrix* matrix = NULL,
                          int stageEnableMask = 0,
                          const GrRect* srcRects[] = NULL,
                          const GrMatrix* srcMatrices[] = NULL);

    virtual bool geometryHints(GrVertexLayout vertexLayout,
                               int* vertexCount,
                               int* indexCount) const;

private:

    struct Draw {
        GrPrimitiveType         fPrimitiveType;
        int                     fStartVertex;
        int                     fStartIndex;
        int                     fVertexCount;
        int                     fIndexCount;
        bool                    fStateChanged;
        bool                    fClipChanged;
        GrVertexLayout          fVertexLayout;
        const GrVertexBuffer*   fVertexBuffer;
        const GrIndexBuffer*    fIndexBuffer;
    };

    virtual bool acquireGeometryHelper(GrVertexLayout vertexLayout,
                                       void**         vertices,
                                       void**         indices);
    virtual void releaseGeometryHelper();
    virtual void clipWillBeSet(const GrClip& newClip);

    virtual void setVertexSourceToArrayHelper(const void* vertexArray,
                                              int vertexCount);

    virtual void setIndexSourceToArrayHelper(const void* indexArray,
                                             int indexCount);

    bool needsNewState() const;
    bool needsNewClip() const;

    void pushState();
    void pushClip();

    GrTAllocator<Draw>              fDraws;
    GrTAllocator<SavedDrawState>    fStates;

    GrTAllocator<GrClip>            fClips;
    bool                            fClipSet;

    GrVertexLayout                  fLastRectVertexLayout;
    const GrIndexBuffer*            fQuadIndexBuffer;
    int                             fMaxQuads;
    int                             fCurrQuad;

    GrVertexBufferAllocPool&        fVertexPool;
    const GrVertexBuffer*           fCurrPoolVertexBuffer;
    int                             fCurrPoolStartVertex;

    GrIndexBufferAllocPool&         fIndexPool;
    const GrIndexBuffer*            fCurrPoolIndexBuffer;
    int                             fCurrPoolStartIndex;

    // caller may conservatively over reserve vertices / indices.
    // we release unused space back to allocator if possible
    size_t                          fReservedVertexBytes;
    size_t                          fReservedIndexBytes;
    size_t                          fUsedReservedVertexBytes;
    size_t                          fUsedReservedIndexBytes;

    static const uint32_t           STATES_BLOCK_SIZE = 8;
    static const uint32_t           DRAWS_BLOCK_SIZE  = 8;
    static const uint32_t           CLIPS_BLOCK_SIZE  = 8;
    static const uint32_t           VERTEX_BLOCK_SIZE = 1 << 12;
    static const uint32_t           INDEX_BLOCK_SIZE  = 1 << 10;
    int8_t                          fDrawsStorage[sizeof(Draw) *
                                                  DRAWS_BLOCK_SIZE];
    int8_t                          fStatesStorage[sizeof(SavedDrawState) *
                                                   STATES_BLOCK_SIZE];
    int8_t                          fClipsStorage[sizeof(GrClip) *
                                                  CLIPS_BLOCK_SIZE];
    typedef GrDrawTarget INHERITED;
};

#endif
