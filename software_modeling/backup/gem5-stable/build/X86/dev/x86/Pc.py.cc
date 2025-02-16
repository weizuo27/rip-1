#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Pc[] = {
    120,156,173,85,193,110,219,70,16,29,146,18,37,74,178,229,
    196,113,156,84,45,208,91,136,22,181,106,183,46,114,40,138,
    38,41,10,248,98,27,84,122,40,47,196,138,92,89,116,184,
    162,64,174,3,169,104,129,2,206,63,244,214,239,203,165,151,
    158,122,107,247,13,197,88,108,143,41,73,141,230,205,112,87,
    187,239,205,172,98,218,92,142,249,124,251,49,81,249,155,113,
    18,243,88,148,17,189,220,120,86,229,217,148,217,164,28,10,
    29,178,128,29,202,90,164,218,20,182,43,220,162,204,37,229,
    82,232,86,184,77,89,135,84,135,194,78,133,93,202,186,164,
    186,20,118,43,220,161,204,35,213,163,176,103,112,151,222,16,
    133,125,74,60,146,46,205,44,74,122,136,220,18,253,24,14,
    40,233,211,196,31,152,181,165,127,155,203,183,140,167,97,62,
    169,220,142,49,103,165,248,94,188,146,85,0,175,94,198,233,
    139,124,49,75,175,158,101,89,21,237,34,154,9,61,203,11,
    85,69,250,198,76,242,27,61,127,94,164,201,149,188,123,237,
    165,44,84,186,16,91,3,127,16,133,126,122,114,250,121,140,
    136,189,249,188,0,103,187,196,52,253,98,209,207,230,33,58,
    156,248,200,157,103,109,186,187,186,228,227,139,51,186,101,204,
    50,47,180,62,192,194,47,34,145,36,133,44,203,168,92,138,
    88,70,83,81,202,234,101,152,242,216,152,241,60,87,114,252,
    74,42,37,11,121,50,190,146,234,148,205,103,165,22,211,76,
    142,203,34,30,39,242,245,120,245,244,171,241,101,124,180,92,
    51,3,6,157,93,60,171,230,126,130,169,240,187,100,185,150,
    182,153,159,184,94,28,22,250,28,91,193,118,165,209,193,66,
    17,132,54,182,101,212,150,45,186,110,67,150,235,14,170,224,
    214,134,132,210,131,56,70,59,217,103,103,64,114,7,53,33,
    119,81,9,183,22,244,55,146,223,146,29,14,183,82,157,102,
    106,111,43,213,173,83,30,167,238,145,188,207,51,239,115,182,
    135,172,220,167,232,1,201,3,196,225,63,220,26,222,111,14,
    63,220,74,13,154,169,71,91,169,157,102,234,241,86,106,183,
    78,13,57,245,1,93,25,157,247,232,141,225,100,68,193,196,
    191,103,88,11,122,224,117,7,21,176,161,127,25,31,205,231,
    218,69,120,93,106,169,184,120,150,105,206,34,167,191,214,229,
    132,72,153,254,36,83,148,83,250,7,204,95,70,179,180,203,
    158,3,99,68,74,223,194,123,11,239,79,120,208,45,118,54,
    13,235,212,5,248,187,113,76,221,93,155,167,170,65,214,200,
    50,222,181,205,9,135,162,22,221,193,118,19,186,77,216,105,
    194,110,19,122,77,216,107,194,126,13,7,12,119,0,77,37,
    77,184,141,206,253,221,186,55,75,244,92,52,229,166,99,58,
    132,214,34,158,159,93,48,113,74,24,226,10,13,86,211,40,
    201,23,58,146,171,180,212,199,218,169,136,251,79,230,68,67,
    134,169,156,167,139,36,90,198,169,70,65,199,185,138,142,57,
    49,51,231,66,4,120,210,132,95,52,225,151,124,28,48,156,
    101,249,210,52,81,135,117,157,137,155,76,107,15,191,29,167,
    49,31,41,190,83,183,113,41,179,25,175,107,122,83,242,59,
    137,18,17,122,187,124,223,22,14,134,56,28,48,252,1,183,
    237,190,53,252,215,237,127,88,87,83,20,45,132,146,81,196,
    27,138,34,149,39,55,25,32,86,168,215,75,201,241,120,181,
    138,230,82,36,134,90,240,115,41,10,161,152,239,73,85,168,
    110,21,148,11,205,27,18,139,117,0,66,2,20,93,48,130,
    193,116,1,68,12,160,103,128,237,6,220,5,251,48,88,102,
    128,73,2,28,107,1,116,14,218,245,10,245,230,64,13,30,
    34,124,8,243,8,230,49,204,176,102,234,189,57,195,62,63,
    197,112,211,23,228,90,184,15,108,207,246,156,145,53,106,141,
    28,207,176,54,128,111,141,156,145,125,238,163,144,88,53,117,
    122,180,4,31,37,47,22,168,200,87,107,166,228,59,249,58,
    141,37,239,152,121,49,255,43,21,37,206,59,74,218,117,53,
    224,79,162,162,192,171,15,135,255,101,95,188,170,175,43,89,
    191,249,8,211,220,55,166,103,245,236,61,235,221,109,123,173,
    127,0,84,207,118,145,
};

EmbeddedPython embedded_m5_objects_Pc(
    "m5/objects/Pc.py",
    "/home/kemmere2/gem5/gem5-stable/src/dev/x86/Pc.py",
    "m5.objects.Pc",
    data_m5_objects_Pc,
    950,
    2001);

} // anonymous namespace
