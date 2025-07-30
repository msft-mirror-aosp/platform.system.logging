/*
 * Copyright (C) 2025 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <ranges>
#include <string>
#include <string_view>

#include <log/logprint.h>

using std::operator""sv;

/**
 * filterString: a comma/whitespace-separated set of filter expressions
 *
 * eg "AT:d *:i"
 */
static bool addFilterString(AndroidLogFormat* format, const std::string& filter_str) {
  for (const auto& range : std::views::split(filter_str, " \t,"sv)) {
    std::string expr(range.begin(), range.end());
    if (android_log_addFilterRule(format, expr.c_str()) < 0) return false;
  }
  return true;
}
