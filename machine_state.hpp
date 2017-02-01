#pragma once

#include "register.hpp"
#include "flags.hpp"
#include "stack.hpp"

namespace cai
{
    template <typename stack_type, typename flags_type, typename registers_state_type>
    struct machine_state
    {
        using stack_t = stack_type;
        using flags_t = flags_type;
        using registers_state_t = registers_state_type;

        static constexpr to_flags<flags_t> flags{};
        static constexpr to_register_state <registers_state_t> reg_state{};
    };

    namespace details
    {
        template <typename>
        struct to_machine_state_impl;


        template <uint8_t ...stack_vals, bool ...flags_bools, uint32_t ...regs_values>
        struct to_machine_state_impl<machine_state<stack<stack_vals...>,
                flags<flags_bools...>,
                registers_state<regs_values...>>>
        {
            using type = machine_state<stack<stack_vals...>,
                    flags<flags_bools...>,
                    registers_state<regs_values...>>;
        };
    }

    template <typename state>
    using to_machine_state = typename details::to_machine_state_impl<state>::type;

    using startup_machine_state = machine_state<startup_stack, startup_flags_state, startup_registers_state>;
}