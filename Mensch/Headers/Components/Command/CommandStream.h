#ifndef COMMANDSTREAM_H
#define COMMANDSTREAM_H

#include "./Command.h"

class CommandStream
{
public:
    ~CommandStream();

    // Instance Method
    static CommandStream &instance();

    // Push command method
    void pushCommand(Command *command);

    // Pop command method
    Command *popCommand();

private:
    // Private Constructor
    CommandStream();
};

#endif