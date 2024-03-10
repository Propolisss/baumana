# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/aip2_dz_1_2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/aip2_dz_1_2_autogen.dir/ParseCache.txt"
  "aip2_dz_1_2_autogen"
  )
endif()
