#pragma once

#include "tuple.hpp"
#include "tokenize/syscalls_tokens.hpp"
#include "instructions/ids_vaules.hpp"
#include "containers/values_container.hpp"
#include "eip_change.hpp"

namespace ctai
{
    namespace details
    {
        //sys_write
        template <typename ...rest_of_tokens>
        struct matcher_impl<tuple<
                tokens::tok_sys_write,
                rest_of_tokens...>>
        {
            using instruction = values_container_n::values_container<inst::to_size<inst::id_t::SYS_WRITE>>;
            using instruction_tokens = tuple<tokens::tok_sys_write>;
            static constexpr auto eip_change = get_eip_change<inst::id_t::SYS_WRITE>;
            using rest_of_tokens_t = tuple<rest_of_tokens...>;
        };
    }

    template <typename tokens>
    using instruction_match = typename details::matcher_impl<tokens>;
}