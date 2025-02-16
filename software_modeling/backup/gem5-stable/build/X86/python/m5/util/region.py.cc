#include "sim/init.hh"

namespace {

const uint8_t data_m5_util_region[] = {
    120,156,213,90,221,115,27,87,21,63,119,87,146,45,217,178,
    243,233,196,105,72,54,105,147,200,52,181,161,164,20,58,169,
    39,9,129,4,134,134,153,117,134,14,166,97,71,209,94,201,
    107,203,43,121,119,221,216,140,60,48,117,102,120,41,15,60,
    244,161,204,192,240,192,12,51,252,9,188,240,79,240,15,208,
    25,120,128,7,30,224,189,156,115,238,189,171,93,57,159,181,
    228,164,150,247,234,238,221,179,103,207,61,247,119,190,238,170,
    1,250,175,132,199,53,7,32,62,109,1,248,0,18,160,41,
    192,23,240,16,96,23,224,39,203,2,164,160,222,178,5,190,
    101,46,219,233,101,27,164,205,151,11,224,23,64,22,249,114,
    49,189,92,2,191,100,110,26,75,71,199,64,142,131,63,14,
    107,22,68,39,45,57,6,126,153,174,201,50,248,21,240,39,
    192,159,132,93,27,110,238,10,248,24,57,87,128,40,170,121,
    138,169,44,197,4,72,124,208,52,248,135,96,215,130,229,73,
    62,61,12,254,17,62,173,130,127,148,110,94,158,2,137,255,
    22,253,227,184,208,39,133,244,164,144,189,82,200,94,177,232,
    177,153,147,99,217,147,227,230,4,105,250,12,144,38,115,114,
    60,207,58,195,173,144,229,86,24,224,86,200,114,43,100,185,
    233,147,10,220,186,45,39,168,65,234,9,184,134,157,73,60,
    243,103,0,7,214,74,186,59,169,187,83,60,58,70,221,105,
    30,165,46,126,227,157,76,32,171,166,171,123,116,61,68,92,
    156,128,165,218,73,68,74,50,142,141,23,202,150,23,132,205,
    134,193,144,192,227,6,97,232,61,96,0,33,102,124,5,24,
    134,17,98,4,145,243,80,97,132,145,179,92,36,176,80,167,
    164,193,130,144,64,160,80,103,92,3,101,185,12,238,82,141,
    158,23,127,19,155,187,43,65,236,116,238,175,202,70,226,212,
    219,15,234,219,177,211,232,172,119,235,145,140,157,182,140,99,
    39,89,169,135,78,61,220,118,58,201,138,140,52,105,67,104,
    241,232,248,14,137,88,192,14,138,181,84,67,184,195,157,184,
    140,237,85,61,159,197,26,77,166,70,164,9,145,197,178,221,
    84,67,212,196,87,177,89,88,233,172,203,133,53,185,190,46,
    35,249,230,66,75,174,191,197,205,27,113,82,191,223,150,11,
    113,212,88,232,110,39,43,157,112,1,175,108,38,65,123,33,
    146,173,160,19,206,227,40,235,206,139,100,55,242,188,175,16,
    71,98,219,32,57,232,176,141,132,51,244,124,128,30,218,138,
    224,142,160,206,154,141,50,147,104,119,250,2,38,219,93,201,
    243,112,121,168,136,13,79,126,152,66,151,88,232,118,226,121,
    103,246,136,156,83,42,74,186,71,192,187,209,102,70,64,183,
    96,196,26,174,108,210,243,206,62,159,108,164,169,239,213,219,
    241,232,133,107,161,226,156,231,94,107,43,39,174,75,228,163,
    151,20,213,120,238,75,33,169,220,240,188,243,251,180,159,131,
    145,52,68,157,190,106,36,173,85,192,56,80,47,172,175,227,
    165,164,194,39,235,29,127,147,64,156,140,241,169,223,105,120,
    158,203,162,17,78,93,26,117,201,79,185,68,238,78,80,51,
    153,19,119,56,50,187,196,229,21,226,116,8,155,146,40,137,
    114,230,163,4,239,118,226,3,245,252,223,134,39,123,254,86,
    36,235,9,122,251,125,56,127,61,165,140,243,103,68,12,83,
    177,150,102,245,236,30,202,29,31,41,60,25,88,115,47,183,
    177,51,238,191,250,114,155,57,155,229,235,207,183,178,165,209,
    74,68,62,226,242,75,190,178,228,194,222,120,201,87,150,60,
    236,60,100,93,183,91,165,102,138,154,105,106,94,128,135,38,
    199,124,17,30,231,161,9,89,46,211,166,254,153,100,100,255,
    188,3,79,243,207,88,186,233,178,78,144,115,150,198,81,211,
    233,152,241,213,227,198,87,151,141,175,174,80,29,247,144,107,
    48,85,196,97,245,133,149,11,117,170,84,168,169,186,11,253,
    57,41,36,198,135,195,117,71,77,200,169,69,245,176,37,231,
    156,78,211,249,41,206,62,74,46,59,50,244,231,230,43,14,
    254,177,215,15,194,70,123,211,71,63,79,122,8,146,109,167,
    185,25,54,18,188,23,211,253,142,137,2,78,231,67,25,181,
    235,93,226,163,56,199,243,236,250,109,125,220,34,5,196,26,
    84,140,37,159,33,31,45,210,41,42,96,118,199,130,68,64,
    15,91,46,210,162,5,234,47,37,54,125,33,249,142,128,48,
    123,183,77,96,140,26,148,227,162,142,18,174,121,103,62,178,
    152,200,134,213,18,65,151,72,201,170,8,32,119,2,18,39,
    160,5,9,104,69,98,2,214,143,194,54,134,171,16,197,199,
    240,245,160,227,212,163,214,230,186,12,147,24,131,92,187,243,
    64,250,151,157,11,190,211,141,58,31,6,190,244,107,132,177,
    132,102,211,70,26,130,89,16,7,33,106,45,108,72,247,48,
    232,156,54,217,236,182,101,66,16,189,158,36,81,112,127,51,
    145,223,141,162,78,196,201,120,157,238,84,41,70,40,31,120,
    94,205,54,44,27,237,88,81,68,173,152,7,176,51,76,216,
    158,64,6,87,136,211,17,226,39,142,136,138,152,22,5,49,
    109,29,17,182,56,100,165,113,186,144,245,0,184,70,168,70,
    90,29,250,178,97,182,105,193,204,82,141,104,238,196,83,41,
    212,107,23,98,84,84,60,167,180,219,143,220,35,11,228,215,
    137,147,197,19,73,5,183,140,224,20,182,123,44,251,172,78,
    50,2,24,169,72,188,236,108,60,55,83,185,172,103,146,107,
    180,170,98,24,161,53,223,206,72,181,199,209,47,165,54,153,
    176,181,68,111,25,33,123,108,163,179,107,2,58,87,82,24,
    40,91,93,43,194,82,159,138,40,92,226,160,137,214,40,218,
    210,3,226,95,128,174,134,157,32,102,143,66,127,74,190,119,
    28,42,76,157,160,233,80,137,143,121,163,239,24,74,244,48,
    109,180,203,70,39,76,234,65,40,125,231,65,144,172,4,33,
    19,206,167,108,48,103,236,243,72,111,213,164,120,170,159,147,
    193,36,7,139,163,212,28,131,81,198,173,100,146,13,92,203,
    31,123,222,15,137,43,69,6,40,76,139,139,226,139,44,130,
    245,136,69,176,158,109,17,194,47,176,8,228,210,209,229,133,
    73,208,168,183,191,12,58,231,128,127,119,255,122,182,161,187,
    71,207,152,244,104,189,10,214,107,215,205,80,172,9,163,231,
    214,147,244,156,104,165,225,245,109,214,110,216,73,250,26,126,
    138,130,153,246,69,43,152,65,253,52,5,47,12,42,248,92,
    86,193,22,123,147,60,104,181,242,56,205,35,12,82,66,129,
    241,83,162,3,104,203,102,66,9,133,210,67,173,81,15,73,
    17,58,211,152,235,199,243,131,211,1,57,250,213,84,7,214,
    52,134,209,231,213,129,120,164,14,56,35,89,48,58,144,91,
    9,186,109,206,175,104,205,247,234,161,175,132,131,157,255,152,
    154,218,126,230,191,55,122,20,12,6,222,52,243,15,226,44,
    12,162,160,181,242,36,28,188,0,91,160,58,99,103,255,56,
    216,171,7,198,193,149,62,14,60,198,193,125,185,221,73,93,
    179,6,133,210,74,30,12,7,171,4,74,128,127,149,87,66,
    141,139,178,129,26,141,50,79,206,218,120,251,10,147,233,174,
    140,146,109,151,118,185,220,211,212,208,62,124,191,96,123,84,
    57,55,244,34,142,178,245,175,19,39,122,161,82,178,176,136,
    171,150,237,233,194,116,161,60,94,158,192,79,165,92,46,87,
    56,81,87,25,110,188,119,183,141,124,225,16,119,219,116,5,
    87,49,21,220,4,213,107,52,247,248,143,64,245,90,44,147,
    76,113,165,235,182,120,110,222,113,110,212,99,138,33,104,41,
    117,83,213,81,68,118,86,58,109,25,171,216,253,253,39,214,
    112,168,192,150,76,57,83,18,208,12,90,155,84,212,109,98,
    220,105,50,135,24,149,77,81,190,229,112,73,168,138,166,102,
    38,36,233,122,207,88,1,215,123,167,176,211,226,164,215,227,
    118,85,144,53,124,140,74,244,251,27,50,140,12,210,180,230,
    195,37,180,242,128,25,240,206,14,23,0,122,11,56,8,131,
    196,243,126,3,122,155,8,176,130,207,205,130,237,216,81,118,
    188,11,84,131,162,252,56,139,85,75,79,7,43,81,209,19,
    233,92,200,246,93,122,15,226,210,77,238,185,156,1,114,121,
    215,232,116,183,135,9,100,218,217,254,36,53,66,148,255,104,
    127,6,105,221,77,235,208,227,200,133,34,99,121,173,22,129,
    100,207,172,131,109,196,230,5,168,119,187,184,0,108,39,163,
    91,5,247,53,100,240,91,200,215,114,57,201,207,100,37,87,
    22,134,194,211,43,231,84,122,174,164,114,119,210,138,197,175,
    168,59,239,29,166,85,75,183,13,126,44,54,108,240,7,118,
    3,211,73,38,212,204,127,45,161,209,250,16,231,169,54,185,
    91,50,148,91,221,104,241,247,102,194,37,173,218,71,96,101,
    232,154,38,246,191,203,104,218,232,42,141,86,244,156,173,115,
    90,217,55,239,205,192,14,227,164,103,209,171,232,168,66,49,
    108,105,163,2,239,39,214,94,196,240,126,170,218,46,183,83,
    180,179,179,239,196,1,185,25,134,148,18,102,152,147,162,192,
    241,7,208,165,53,136,67,98,82,140,63,162,240,174,130,217,
    203,84,22,155,245,60,238,17,51,137,209,148,224,106,175,167,
    45,67,207,251,211,128,250,9,20,69,35,227,127,133,1,186,
    210,59,117,108,114,158,59,5,194,253,78,145,219,18,108,253,
    85,244,138,188,81,198,6,140,213,72,244,15,209,43,241,136,
    200,140,32,147,34,204,238,140,65,207,6,188,60,187,51,14,
    189,49,85,179,140,155,36,52,250,37,17,225,216,219,200,126,
    227,18,19,136,28,193,89,145,185,73,101,239,209,255,160,87,
    32,7,72,59,115,138,82,211,236,90,202,29,166,44,7,238,
    197,12,232,52,137,202,87,75,176,113,90,108,124,38,246,240,
    26,207,241,234,83,95,2,125,73,75,73,162,92,219,75,32,
    250,4,168,213,101,129,78,247,35,145,189,85,207,226,47,153,
    39,143,61,241,201,123,103,241,89,102,142,56,5,122,242,32,
    175,199,104,4,73,223,71,218,52,32,170,196,247,78,38,133,
    45,166,54,197,192,124,205,248,39,181,161,24,199,152,58,33,
    178,120,67,177,86,78,189,5,191,227,160,222,117,110,111,112,
    235,114,27,112,187,234,94,52,36,247,71,16,70,49,103,240,
    188,63,27,142,192,91,225,148,85,149,196,37,81,193,207,49,
    171,42,142,97,123,198,174,88,199,172,67,246,25,187,74,99,
    214,169,220,216,148,85,238,59,166,212,122,251,193,107,87,25,
    7,219,199,123,170,151,243,227,175,230,28,144,82,138,114,60,
    241,102,59,25,190,85,243,172,255,14,105,240,157,196,153,166,
    129,168,4,153,50,0,49,209,130,212,183,158,210,137,132,217,
    99,80,251,170,63,179,96,163,202,187,216,102,131,149,83,98,
    149,20,213,242,187,171,34,117,90,253,236,130,154,97,254,234,
    132,83,246,127,246,125,22,191,60,24,204,237,207,27,189,43,
    164,82,148,81,233,60,189,216,116,41,195,118,191,1,58,253,
    31,122,18,79,137,214,175,137,19,21,58,37,27,147,248,66,
    185,88,182,241,51,134,199,219,229,162,134,231,122,61,64,247,
    155,174,12,167,97,180,50,103,21,178,238,29,215,235,209,227,
    84,254,4,174,133,74,19,76,97,30,40,140,65,170,239,11,
    212,204,15,119,54,249,28,225,95,144,230,8,106,217,41,17,
    226,247,22,251,152,70,225,192,167,241,239,204,52,200,179,5,
    100,21,1,89,79,64,116,1,213,55,105,225,156,198,194,79,
    192,188,121,232,153,22,221,110,211,134,153,91,183,125,43,63,
    110,155,113,59,63,14,102,188,144,31,23,102,188,152,31,47,
    152,241,82,126,188,168,199,111,115,210,56,198,118,73,134,112,
    33,118,222,125,215,185,16,191,131,135,25,56,55,56,112,213,
    25,28,24,164,88,28,164,88,52,20,253,117,226,186,129,246,
    128,248,61,3,215,253,195,244,101,236,38,101,156,252,135,184,
    77,177,169,159,204,124,130,79,255,246,249,231,65,235,245,20,
    63,100,247,236,86,213,15,60,248,23,43,236,16,245,47,248,
    248,5,41,15,232,95,117,240,62,4,7,49,85,26,85,13,
    131,45,174,97,217,113,109,113,187,205,237,207,185,13,221,111,
    141,192,103,176,71,184,170,126,236,179,200,191,179,249,1,54,
    51,229,178,197,199,7,51,31,76,138,243,248,153,22,211,86,
    185,92,21,252,177,30,215,22,69,17,3,93,209,154,16,230,
    243,127,82,101,150,70,
};

EmbeddedPython embedded_m5_util_region(
    "m5/util/region.py",
    "/home/kemmere2/gem5/gem5-stable/src/python/m5/util/region.py",
    "m5.util.region",
    data_m5_util_region,
    2806,
    11219);

} // anonymous namespace
