#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

class Node;

typedef const Node* NodePtr;

enum varDoWhat
{
    constructor,
    assignment,
    initialize,
    function,
    call,
    param,
    array,
    sizeOf,
    increment,
    array_assign,
    switc,
    enumer,
    decrement,
    none
};

struct Context{
    std::map<std::string, int32_t> bindings;  // bindings would have the offset of the $fp, store everything to stack [offset]$fp , incrementing offset by 4
    std::map<std::string, std::string> varSize; 
    int offset; // used for $fp offset, signifies the end of the program
    int currentOffset;
    bool assign;
    varDoWhat type;
    int stackPointer;
    int returnStack;
    int callPointer;
    bool funcCall;
    bool returnCall;
    bool arrGlobal;
    int arraySize;
    std::string typeSpec;
    bool ext_func;
    int function_count;
    int functionnum;
    bool ext_params;
    int paramNum;
    int switchOffset;
    bool swcase;
    bool enumer;
    std::vector <std::string> enumprints;
};

static int uniqLabel = 0;

static std::string makeUniqLabel(){
    uniqLabel = uniqLabel + 1;
    return std::to_string(uniqLabel);
}

// add an argument for compile function 


class Node
{
private:
    Node* root;

public:
    virtual ~Node() // destructor
    {}

    Node() {}

    Node(Node* _root)
        : root(_root) 
    {}

    virtual void print(std::ostream &dst) const {
        std::cout << "node" << std::endl;
    }

    virtual std::string getIden() {

    }

    virtual void Compile(std::ostream &dst, Context &program, int destination) const{
        root -> Compile(dst, program, destination);
    }

    virtual void Compile(std::ostream &dst, int destination) const{}
};

static int *Count = new int(0);

class translation_unit
    :public Node
{
public: 
    std::vector<Node*> ext_declarations;
    int *count;

    virtual ~translation_unit() {} // destructor

    translation_unit (){
        ext_declarations = {}; //creating the ext dec vector
        count = Count;
    };

    translation_unit (Node* _ext_declarations){
        ext_declarations.push_back(_ext_declarations); //adding the ext dec into the vector
    }

    unsigned getCount() const{
        return *count;
    }

    void AddCount(){
        (*count)++;
    }


    virtual void addExtDec (Node* _ext_declarations){
        ext_declarations.push_back(_ext_declarations); //adding the ext dec into the vector
    }

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
        program.swcase = false;
        program.funcCall = false;
        program.returnCall = false;
        program.arrGlobal = false;
        program.ext_func = false;
        program.ext_params = false;
        program.enumer = false;
        for (int i = 0; i < ext_declarations.size(); i++){
            ext_declarations[i] -> Compile(dst, program, destination);
        }

        if (program.swcase){
            dst << "#RETURNNODE" << std::endl;
            
            dst << "RETURN1:" << std::endl;
            dst << "move $sp, $fp" << std::endl;
            if (program.returnCall){
                dst << "lw $31, " << program.callPointer << "($sp)" << std::endl;
            }
            int frameOffset = program.returnStack - 4;
            dst << "lw $fp, " << frameOffset << "($sp)" << std::endl;
            dst << "addiu $sp, $sp, " << program.returnStack << std::endl;
            dst << "jr $31" << std::endl;
            dst << "nop" << std::endl;
        }
    }
};

#endif
