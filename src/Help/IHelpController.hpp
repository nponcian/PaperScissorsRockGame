#ifndef SRC_HELP_IHELPCONTROLLER_HPP
#define SRC_HELP_IHELPCONTROLLER_HPP

namespace src::help
{

class IHelpController
{
public:
    virtual ~IHelpController(){}

    virtual void displayHelp() const = 0;
};

} // namespace src::help

#endif // SRC_HELP_IHELPCONTROLLER_HPP
