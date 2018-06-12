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

#include "modules/common/math/kalman_filter_1d.h"

#include "gtest/gtest.h"

namespace apollo {
namespace common {
namespace math {

class KalmanFilter1DTest : public ::testing::Test {
 public:
  KalmanFilter1DTest() : kf_() {}

 protected:
  KalmanFilter1D kf_;
};

TEST_F(KalmanFilter1DTest, SyntheticTrackingTest) {
  EXPECT_TRUE(kf_.Init(0.0));
  EXPECT_TRUE(kf_.Predict(1.0));
  EXPECT_TRUE(kf_.Update(1.0));

  EXPECT_DOUBLE_EQ(0.67741930484771729, kf_.GetState()(0, 0));
  EXPECT_DOUBLE_EQ(13.548389434814453, kf_.GetCov()(0, 0));
}

}  // namespace math
}  // namespace common
}  // namespace apollo
