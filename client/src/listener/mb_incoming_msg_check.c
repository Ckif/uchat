#include "client.h"

extern t_msg *incoming_msg_buffer;

void mb_incoming_msg_check() {
    if (incoming_msg_buffer != NULL) {
        do {
            
        }
        while (incoming_msg_buffer->next_msg);
    }
}