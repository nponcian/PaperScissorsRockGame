#ifndef SRC_MAINCONTROLLER_HPP
#define SRC_MAINCONTROLLER_HPP

#include <memory>
#include <string>

#include <ControllersFactory.hpp>

namespace src
{

class MainController
{
public:
    MainController();

    void handle(const std::string& message) const;

private:
    std::unique_ptr<ControllersFactory> controllersFactory_;
};

} // namespace src

#endif // SRC_MAINCONTROLLER_HPP
