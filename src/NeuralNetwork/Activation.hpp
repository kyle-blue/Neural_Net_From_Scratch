#pragma once

class Activation {
public:
    enum Value {
        SIGMOID,
        RELU
    };

    Activation() = delete;
    Activation(Value value): value(value) {}


    float getOutput(float activationInput);

    // Member functions of the form operator TypeName() are conversion operators
    constexpr operator Value() const { return value; } // Allow comparison to Value
    explicit operator bool() = delete; // Disallow implicit conversion to bool
    
    Value value;

};