#ifndef OMG_SUB_DETAIL_LOANED_SAMPLES_IMPL_HPP_
#define OMG_SUB_DETAIL_LOANED_SAMPLES_IMPL_HPP_

namespace dds
{
namespace sub
{
namespace detail
{

template <typename T>
class LoanedSamples
{
public:

    typedef std::vector< dds::sub::Sample<T, dds::sub::detail::Sample> > LoanedSamplesContainer;
    typedef typename std::vector< dds::sub::Sample<T, dds::sub::detail::Sample> >::iterator iterator;
    typedef typename std::vector< dds::sub::Sample<T, dds::sub::detail::Sample> >::const_iterator const_iterator;

public:
    LoanedSamples() { }

    ~LoanedSamples()
    {

    }

public:

    iterator mbegin()
    {
        return samples_.begin();
    }

    const_iterator begin() const
    {
        return samples_.begin();
    }

    const_iterator end() const
    {
        return samples_.end();
    }

    uint32_t length() const
    {
        return static_cast<uint32_t>(samples_.size());
    }

    void reserve(uint32_t s)
    {
        samples_.reserve(s);
    }

    void resize(uint32_t s)
    {
         samples_.resize(s);
    }

    dds::sub::Sample<T, dds::sub::detail::Sample>& operator[] (uint32_t i)
    {
        return this->samples_[i];
    }

    dds::sub::Sample<T, dds::sub::detail::Sample> * get_buffer() {
        return this->samples_.data();
    }


private:
    LoanedSamplesContainer samples_;
};

}
}
}
#endif /* OMG_SUB_DETAIL_LOANED_SAMPLES_IMPL_HPP_ */
