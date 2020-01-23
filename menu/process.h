enum process_name {
    WASH,
    RINSE,
    SPIN
};

enum process_type {
    WASH_RINSE_SPIN,
    RINSE_SPIN,
    RINSE,
    SPIN
};

int is_processing();
void set_process_type(enum process_type *);
void increment_process_type();