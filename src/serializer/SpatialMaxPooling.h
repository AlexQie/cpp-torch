#pragma once
#include "../../include/nn/SpatialMaxPooling.h"


namespace cpptorch
{
    namespace serializer
    {
        template<typename T, bool C>
        class SpatialMaxPooling : public nn::SpatialMaxPooling<T,C>
        {
        public:
            void unserialize(const object_torch *obj, object_reader<T,C> *mb)
            {
                const object_table *obj_tbl = obj->data_->to_table();
                this->kW_ = *obj_tbl->get("kW");
                this->kH_ = *obj_tbl->get("kH");
                this->dW_ = *obj_tbl->get("dW");
                this->dH_ = *obj_tbl->get("dH");
                this->padW_ = *obj_tbl->get("padW");
                this->padH_ = *obj_tbl->get("padH");
                this->ceil_mode_ = *obj_tbl->get("ceil_mode");
            }
        };
    }
}
