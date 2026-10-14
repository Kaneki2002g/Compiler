#include "codeBlock.hpp"

class ifBlock : public codeBlock{ // if(else) statement
public:
    virtual void compile() override;
private:
    std::vector<std::unique_ptr<CodeBlock>> eBlocks; // else code blocks, empty for 'if'
};