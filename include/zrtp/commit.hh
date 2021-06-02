#pragma once


#include "zrtp/defines.hh"

#include "util.hh"

namespace uvgrtp {

    namespace frame {
        struct zrtp_frame;
    }

    class socket;

    typedef struct zrtp_session zrtp_session_t;

    namespace zrtp_msg {

        class receiver;


        /* DH Commit Message */
        PACK(struct zrtp_commit {
            zrtp_msg msg_start;

            uint32_t hash[8];
            uint32_t zid[3];
            uint32_t hash_algo;
            uint32_t cipher_algo;
            uint32_t auth_tag_type;
            uint32_t key_agreement_type;
            uint32_t sas_type;

            uint32_t hvi[8];
            uint32_t mac[2];
            uint32_t crc;
        });

        class commit {
            public:
                commit(zrtp_session_t& session);
                ~commit();

                /* TODO:  */
                rtp_error_t send_msg(uvgrtp::socket *socket, sockaddr_in& addr);

                /* TODO:  */
                rtp_error_t parse_msg(uvgrtp::zrtp_msg::receiver& receiver, zrtp_session_t& session);

            private:
                uvgrtp::frame::zrtp_frame *frame_;
                uvgrtp::frame::zrtp_frame *rframe_;
                size_t len_, rlen_;

        };
    };
};

namespace uvg_rtp = uvgrtp;
