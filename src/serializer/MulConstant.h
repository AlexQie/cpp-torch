#pragma once
#include "../../include/nn/MulConstant.h"


namespace cpptorch
{
    namespace serializer
    {
        template<typename T, bool C>
        class MulConstant : public nn::MulConstant<T,C>
        {
        public:
            void unserialize(const object_torch *obj, object_reader<T,C> *mb)
            {
                const object_table *obj_tbl = obj->data_->to_table();
                this->inplace_ = *obj_tbl->get("inplace");
                this->constant_scalar_ = *obj_tbl->get("constant_scalar");
                assert(this->inplace_ == false && "change input inplace is dangerous");
            }
        };
    }
}
