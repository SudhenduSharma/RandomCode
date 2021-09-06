#define TYPE_TRAIT(NM)                                          \
        BOOST_MPL_HAS_XXX_TRAIT_DEF(NM)                         \
        template<typename Policy, typename Enable = void>       \
        struct NM##_type                                        \
        {                                                       \
            typedef void type;                                  \
        };                                                      \
        template<typename Policy>                               \
        struct NM##_type<                                       \
                    Policy,                                     \
                    typename std::enable_if<                    \
                                has_##NM<Policy>::value         \
                    >::type>                                    \
        {                                                       \
            typedef typename Policy::NM type;                   \
        };  


TYPE_TRAIT(char_t)

struct char_t_type
{
    typedef void type;
}

template<typename Policy>                               \
           struct char_t_type<                                       \
                       Policy,                                     \
                       typename std::enable_if<                    \
                                   has_char_t<Policy>::value         \
                       >::type>                                    \
           {                                                       \
               typedef typename Policy::char_t type;                   \
           };



struct A
{
    typedef char char_t;
}

int main()
{
    std::is_same<char_t_type<A>::type,void> 

}
