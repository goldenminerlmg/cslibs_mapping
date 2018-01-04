#ifndef CSLIBS_MAPPING_NDT_VISUAL_3D_H
#define CSLIBS_MAPPING_NDT_VISUAL_3D_H

#include <memory>

namespace Ogre {
class Vector3;
class Quaternion;
class SceneManager;
class SceneNode;
}

namespace rviz {
class Shape;
}

namespace cslibs_mapping {
class NDTVisual3D
{
public:
    using Ptr = std::shared_ptr<NDTVisual3D>;

    NDTVisual3D(Ogre::SceneManager * scene_manager, Ogre::SceneNode *parent_node);
    virtual ~NDTVisual3D();

    virtual void setScale(const Ogre::Vector3 &scale) = 0;
    virtual void setFramePosition(const Ogre::Vector3 &pos) = 0;
    virtual void setFrameOrientation(const Ogre::Quaternion &quaternion) = 0;
    virtual void setColor(const std::array<float,4> &color) = 0;
    virtual void setColorScale(const float s) = 0;

protected:
    float                         color_scale_;
    Ogre::SceneManager           *scene_manager_;
    Ogre::SceneNode              *frame_node_;

};
}

#endif // CSLIBS_MAPPING_NDT_VISUAL_3D_H
