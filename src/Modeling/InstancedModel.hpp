
/******************************************************************************\
                     This file is part of Folding Atomata,
          a program that displays 3D views of Folding@home proteins.

                      Copyright (c) 2013, Jesse Victors

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see http://www.gnu.org/licenses/

                For information regarding this software email:
                                Jesse Victors
                         jvictors@jessevictors.com
\******************************************************************************/

#ifndef INSTANCED_MODEL
#define INSTANCED_MODEL

#include "Modeling/Mesh/Mesh.hpp"
#include "Modeling/DataBuffers/OptionalDataBuffer.hpp"
#include <vector>
#include <memory>

typedef std::vector<std::shared_ptr<OptionalDataBuffer>> BufferList;

class InstancedModel
{
    public:
        InstancedModel(const std::shared_ptr<Mesh>& mesh);
        InstancedModel(const std::shared_ptr<Mesh>& mesh,
                       const glm::mat4& modelMatrix);
        InstancedModel(const std::shared_ptr<Mesh>& mesh,
                       const BufferList& optionalDBs);
        InstancedModel(const std::shared_ptr<Mesh>& mesh,
                       const glm::mat4& modelMatrix,
                       const BufferList& optionalDBs);
        InstancedModel(const std::shared_ptr<Mesh>& mesh,
                       const std::vector<glm::mat4>& modelMatrices,
                       const BufferList& optionalDBs);

        virtual void saveAs(GLuint programHandle);
        void addInstance(const glm::mat4& instanceModelMatrix);
        void render(GLuint programHandle);
        void setModelMatrix(std::size_t index, const glm::mat4& matrix);
        void setVisible(bool visible);
        BufferList getOptionalDataBuffers();
        std::size_t getInstanceCount();

    private:
        void enableDataBuffers();
        void disableDataBuffers();

    protected:
        std::shared_ptr<Mesh> mesh_;
        std::vector<glm::mat4> modelMatrices_;
        BufferList optionalDBs_;
        GLuint cachedHandle_;
        GLint matrixModelLocation_;
        bool isVisible_;
};

typedef std::shared_ptr<InstancedModel> InstancedModelPtr;

#endif
