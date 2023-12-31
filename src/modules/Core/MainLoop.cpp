#include "MainLoop.hpp"
#include "EventQueue.hpp"
#include "Renderer.hpp"
#include "RendererDefault.hpp"
#include "RendererPrototype.hpp"
#include "Window.hpp"
#include "raylib.h"
#include <memory>

MainLoop *MainLoop::singleton = nullptr;

void initialize();

MainLoop::MainLoop(){
#ifndef NDEBUG
    SetTraceLogLevel(LOG_DEBUG);
#endif // !NDEBUG
    isRunning = true;
    singleton = this;

    window = std::make_unique<raylib::Window>(screenDim.x,screenDim.y,
                        "raylib [shaders] example - Hybrid render");
    // DisableCursor(); // Limit cursor to relative movement inside the window

    event = std::make_unique<EventQueue>();
    scene = std::make_unique<Scene>();
    renderer = std::make_unique<RendererDefault>();

    initialize();
    return;
}
void MainLoop::Update(){
    float delta = GetFrameTime();
    Scene::getSingleton()->process();
    EventQueue::getSingleton()->process();
    Renderer::getSingleton()->process();
}
MainLoop::~MainLoop(){ // WONT RUN IN WEB. The default is to abort code mid-execution if page closes
    singleton = nullptr;
    return;
}

MainLoop* MainLoop::getSingleton(){
    return singleton;
}