#include <memory>

class CodeBlock{
public:
    virutal void compile();
    void setLineNumber(int line);
private:
    int code_line; // line of source code where block appears
};

class CodeNode : public CodeBlock{
public:
    virtual void compile() override;
    virtual void setChildren(/* TODO set cBlocks*/)
private:
    std::vector<std::unique_ptr<CodeBlock>> cBlocks; // children code blocks
};

class CodeLeaf : public CodeBlock{
public:
    virtual void compile() override;
};