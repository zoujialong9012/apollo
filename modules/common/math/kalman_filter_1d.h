/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 * @brief Defines a KalmanFilter1D class.
 */

#ifndef MODULES_COMMON_MATH_KALMAN_FILTER_1D_H_
#define MODULES_COMMON_MATH_KALMAN_FILTER_1D_H_

// 1 dimensional constant velocity kalman filter
#include "Eigen/Core"
#include "Eigen/Dense"

#include "modules/common/math/kalman_filter.h"

namespace apollo {
namespace common {
namespace math {

class KalmanFilter1D
    : public ::apollo::common::math::KalmanFilter<float, 2, 1, 1> {
 public:
  bool Init(const float& x);

  bool Predict(const float& time_diff);

  bool Update(const float& z);

  Eigen::Vector2f GetState();

  Eigen::Matrix2f GetCov();
};

}  // namespace math
}  // namespace common
}  // namespace apollo

#endif  // MODULES_COMMON_MATH_KALMAN_FILTER_1D_H_
