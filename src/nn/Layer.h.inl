#pragma once
#include "../../include/nn/Layer.h"


namespace cpptorch
{
    namespace nn
    {
        template<typename T, GPUType F = None>
        class Layer
        {
        public:
            Layer() {}
            virtual ~Layer() {}

            virtual const std::string name() const = 0;
            virtual void print(std::ostream &o, int level = 0) const { o << name(); }
            virtual Tensor<T, F> forward(const Tensor<T, F> &input) const = 0;

            friend std::ostream& operator << (std::ostream &o, const Layer &m)
            {
                m.print(o);
                o << std::endl;
                return o;
            }

        protected:
            // copy constructor disallowd
            Layer(const Layer<T, F> &other);
        };
    }
}
