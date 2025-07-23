#define MOCK(return_type, func_name, arg1_type, arg2_type) \
    extern return_type (*func_name ## _ptr) (arg1_type, arg2_type); \
    static struct { \
        arg1_type arg1; \
        arg2_type arg2; \
        int invocations; \
        return_type return_val; \
        return_type (*func_name ## _mock) (arg1_type, arg2_type); \
    } _ ## func_name ## _mock_st = { .invocations = 0, .func_name ## _mock = NULL }; \
    static return_type _ ## func_name ## _mock (arg1_type arg1, arg2_type arg2) { \
        _ ## func_name ## _mock_st.arg1 = arg1; \
        _ ## func_name ## _mock_st.arg2 = arg2; \
        _ ## func_name ## _mock_st.invocations++; \
        if (_ ## func_name ## _mock_st.func_name ## _mock == NULL) { \
            return _ ## func_name ## _mock_st.return_val; \
        } else { \
            return (*_ ## func_name ## _mock_st.func_name ## _mock)(arg1, arg2); \
        } \
    }

#define MOCK_VAL(func_name, mock_val) \
    func_name ## _ptr = _ ## func_name ## _mock; \
    _ ## func_name ## _mock_st.return_val = mock_val; \
    _ ## func_name ## _mock_st.func_name ## _mock = NULL;

#define MOCK_FUNC(func_name, mock_func) \
    func_name ## _ptr = _ ## func_name ## _mock; \
    _ ## func_name ## _mock_st.func_name ## _mock = mock_func;

#define MOCK_REAL(func_name) \
    func_name ## _ptr = _ ## func_name ## _mock; \
    _ ## func_name ## _mock_st.func_name ## _mock = func_name;

#define ASSERT_FUNC_CALLED_WITH_ARGS(func_name, assert_arg1, assert_arg2) \
    (_ ## func_name ## _mock_st.arg1 == assert_arg1 && _ ## func_name ## _mock_st.arg2 == assert_arg2)
