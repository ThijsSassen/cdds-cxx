#ifndef OMG_DDS_CORE_XTYPES_DETAIL_ANNOTATIONS_HPP_
#define OMG_DDS_CORE_XTYPES_DETAIL_ANNOTATIONS_HPP_

namespace dds {
  namespace core {
    namespace xtypes {
      namespace detail {
        class Annotation { };

        class IdAnnotation : public  Annotation { };

        class KeyAnnotation : public  Annotation { };

        class SharedAnnotation : public  Annotation  { };

        class NestedAnnotation : public  Annotation  { };

        class ExtensibilityAnnotation : public  Annotation  { };

        class MustUnderstandAnnotation : public  Annotation { };

        class VerbatimAnnotation : public  Annotation { };

        class BitsetAnnotation : public  Annotation { };

        class BitBoundAnnotation : public  Annotation  { };
      }
    }
  }
}
#endif /* OMG_DDS_CORE_XTYPES_DETAIL_ANNOTATIONS_HPP_ */
