#ifndef OMG_DDS_CORE_XTYPES_DETAIL_STRUCT_TYPE_HPP_
#define OMG_DDS_CORE_XTYPES_DETAIL_STRUCT_TYPE_HPP_


namespace dds {
  namespace core {
    namespace xtypes {
      namespace detail {


        class StructType { };
        template <typename T>
        bool isFinal(const TStructType<T>& s) { return false; }

        template <typename T>
        bool isExtensible(const TStructType<T>& s) { return false; }

        template <typename T>
        bool isMutable(const TStructType<T>& s) { return false; }

        template <typename T>
        bool isNested(const TStructType<T>& s) { return false; }
      }
    }
  }
}



#endif /* OMG_DDS_CORE_XTYPES_DETAIL_STRUCT_TYPE_HPP_ */
