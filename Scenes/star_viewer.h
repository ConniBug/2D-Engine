//
// Created by Conni Bilham on 16/10/2023.
//

#ifndef INC_2D_ENGINE_STAR_VIEWER_H
#define INC_2D_ENGINE_STAR_VIEWER_H

#include "Scene.h"

class star_viewer : public Scene {
public:
    void Init(Camera *camera) override;
    void Update(double deltaTime) override;
};

#endif//INC_2D_ENGINE_STAR_VIEWER_H
