#ifndef RTFF_BUFFER_BUFFER_H_
#define RTFF_BUFFER_BUFFER_H_

#include <Eigen/Core>

namespace rtff {

template <typename T>
class Buffer {
 public:
  using Vector = Eigen::Matrix<T, Eigen::Dynamic, 1>;

  void Init(uint32_t frame_count, uint8_t channel_count) {
    data_.clear();
    for (uint8_t channel_idx = 0; channel_idx < channel_count; channel_idx++) {
      data_.push_back(Vector::Zero(frame_count));
    }
  }

  Vector& channel(uint8_t channel_idx) { return data_[channel_idx]; }
  const Vector& channel(uint8_t channel_idx) const {
    return data_[channel_idx];
  }
  uint8_t channel_count() const { return data_.size(); }

 private:
  std::vector<Vector> data_;
};

using AmplitudeBuffer = Buffer<float>;
using FrequentialBuffer = Buffer<std::complex<float>>;

}  // namespace rtff

#endif  // RTFF_BUFFER_BUFFER_H_