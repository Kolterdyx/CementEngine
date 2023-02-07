//
// Created by kolterdyx on 7/02/23.
//

#ifndef CEMENTENGINE_MYAPP_HPP
#define CEMENTENGINE_MYAPP_HPP


#include "Application.hpp"

class MyApp : public Cement::Application {

public:
    MyApp(const std::string &title, unsigned int width, unsigned int height);

    void onCreate() override;


};


#endif //CEMENTENGINE_MYAPP_HPP
