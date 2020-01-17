# Copyright 2019 ADLINK Technology Limited
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

###############################################################################
#
# CMake module for finding Eclipse Cyclone DDS.
#
# Output variables:
#
# - CycloneDDS_FOUND: flag indicating if the package was found
#
# Example usage:
#
#   find_package(CycloneDDS MODULE)
#   # use CycloneDDS_* variables
#
###############################################################################

set(CycloneDDS_FOUND FALSE)

find_package(CycloneDDS REQUIRED CONFIG)
