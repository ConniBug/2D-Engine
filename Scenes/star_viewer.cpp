//
// Created by Conni Bilham on 16/10/2023.
//

#include "star_viewer.h"
#include "logging.h"

void star_viewer::Init(Camera *camera) {
    this->camera = camera;
    camera->type = CAMERA_TYPE::PERSPECTIVE;

    shaders.emplace_back(new Shader("shaders/vertex.glsl", "shaders/fragment.glsl"));
    auto entity = new Entity_t(shaders[0],
                               glm::vec3(0, 0, 0),
                               glm::vec3(0.0f),
                               glm::vec3(0.5f));

    entity_list.push_back(entity);
}

void star_viewer::Update(double deltaTime) {
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = camera->getProjectionMatrix(storage->window.width, storage->window.height);
    view *= camera->view_matrix();

    for (auto &entity: entity_list) {
        {
            entity->shader->apply(view, projection);
            entity->draw();
        }
    }
}
