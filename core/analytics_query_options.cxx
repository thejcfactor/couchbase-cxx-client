/* -*- Mode: C++; tab-width: 4; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
 * Copyright 2022-Present Couchbase, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF
 * ANY KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include "analytics_query_options.hxx"

#include <cstddef>
#include <memory>
#include <optional>
#include <system_error>
#include <vector>

namespace couchbase::core
{
class analytics_query_row_reader_impl
{
public:
  auto next_row() -> std::vector<std::byte>
  {
    return {};
  }

  auto error() -> std::error_code
  {
    return {};
  }

  auto meta_data() -> std::optional<std::vector<std::byte>>
  {
    return {};
  }

  auto close() -> std::error_code
  {
    return {};
  }
};

analytics_query_row_reader::analytics_query_row_reader()
  : impl_{ std::make_shared<analytics_query_row_reader_impl>() }
{
}

auto
analytics_query_row_reader::next_row() -> std::vector<std::byte>
{
  return impl_->next_row();
}

auto
analytics_query_row_reader::error() -> std::error_code
{
  return impl_->error();
}

auto
analytics_query_row_reader::meta_data() -> std::optional<std::vector<std::byte>>
{
  return impl_->meta_data();
}

auto
analytics_query_row_reader::close() -> std::error_code
{
  return impl_->close();
}
} // namespace couchbase::core
