enum process_name {
    WASH,
    RINS,
    SPIN
};

enum process_type {
    WASH_RINS_SPIN,
    RINS_SPIN,
    RINS,
    SPIN
};

int is_processing();
void set_process_type(enum process_type *);
void increment_process_type();