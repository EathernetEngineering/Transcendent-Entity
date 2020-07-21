#pragma once

namespace TE {
    typedef struct _guid
    {
        uint64_t Data1;
        uint32_t Data2;
        uint16_t Data3;
        char Data4[16];

        bool operator==(_guid other) {
            bool isequal = false;
            if (Data1 == other.Data1 && Data2 == other.Data2 && Data3 == other.Data3) isequal = true;
            for (uint8_t i = 0; i < sizeof(Data4) / sizeof(char) - 1; i++)
                if (Data4[i] != other.Data4[i]) isequal = false;
            return isequal;
        }

        bool operator!=(_guid other) {
            return !(*this == other);
        }

    } guid;
    
    typedef guid uuid;

    void genuuid(uuid* uuid) {
        static int s1 = 100, s2 = 100, s3 = 100;
        {
            {
                s1 = (171 * s1) % 30269;
                s2 = (172 * s2) % 30307;
                s3 = (170 * s3) % 30323;

                uuid->Data1 = (uint64_t)(std::fmod(s1 / 30269.0 + s2 / 30307.0 + s3 / 30323.0, 1.0) * 18446744073709551615u);
            }
            {
                s1 = (171 * s1) % 30269;
                s2 = (172 * s2) % 30307;
                s3 = (170 * s3) % 30323;

                uuid->Data2 = (uint32_t)(std::fmod(s1 / 30269.0 + s2 / 30307.0 + s3 / 30323.0, 1.0) * 4294967295u);
            }
            {
                s1 = (171 * s1) % 30269;
                s2 = (172 * s2) % 30307;
                s3 = (170 * s3) % 30323;

                uuid->Data3 = (uint16_t)(std::fmod(s1 / 30269.0 + s2 / 30307.0 + s3 / 30323.0, 1.0) * 65535u);
            }
            {
                for (uint8_t i = 0; i < sizeof(uuid->Data4) / sizeof(char); i++) {
                    s1 = (171 * s1) % 30269;
                    s2 = (172 * s2) % 30307;
                    s3 = (170 * s3) % 30323;

                    uuid->Data4[i] = static_cast<char>((std::fmod(s1 / 30269.0 + s2 / 30307.0 + s3 / 30323.0, 1.0) * 94.0f) + 32.0f);
                }
            }
        }
    }
}
