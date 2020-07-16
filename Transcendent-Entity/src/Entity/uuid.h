#pragma once

namespace TE {
    typedef struct _guid
    {
        uint64_t Data1;
        uint32_t Data2;
        uint16_t Data3;
        char Data4[16];
    } guid;
    
    typedef guid uuid;

    void genuuid(uuid* uuid) {
        static int s1 = 100, s2 = 100, s3 = 100;
        {
            {
                static int s1 = 100, s2 = 100, s3 = 100;

                s1 = (171 * s1) % 30269;
                s2 = (172 * s2) % 30307;
                s3 = (170 * s3) % 30323;

                uuid->Data1 = std::fmod(s1 / 30269.0 + s2 / 30307.0 + s3 / 30323.0, 1.0);
            }
            {
                static int s1 = 100, s2 = 100, s3 = 100;

                s1 = (171 * s1) % 30269;
                s2 = (172 * s2) % 30307;
                s3 = (170 * s3) % 30323;

                uuid->Data2 = std::fmod(s1 / 30269.0 + s2 / 30307.0 + s3 / 30323.0, 1.0);
            }
            {
                static int s1 = 100, s2 = 100, s3 = 100;

                s1 = (171 * s1) % 30269;
                s2 = (172 * s2) % 30307;
                s3 = (170 * s3) % 30323;

                uuid->Data3 = std::fmod(s1 / 30269.0 + s2 / 30307.0 + s3 / 30323.0, 1.0);
            }
            {
                ;
            }
        }
    }
}
