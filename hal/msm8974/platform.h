/*
 * Copyright (c) 2013-2020, 2022, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef QCOM_AUDIO_PLATFORM_H
#define QCOM_AUDIO_PLATFORM_H
#include <sound/voice_params.h>

#define TRUMPET_TOPOLOGY 0x11000099
#define ACDB_ID_STEREO_SPEAKER_DEVICE 15

enum {
    FLUENCE_NONE,
    FLUENCE_DUAL_MIC = 0x1,
    FLUENCE_TRI_MIC = 0x2,
    FLUENCE_QUAD_MIC = 0x4,
    FLUENCE_HEX_MIC = 0x8,
};

enum {
    FLUENCE_ENDFIRE = 0x1,
    FLUENCE_BROADSIDE = 0x2,
};

enum {
    SOURCE_MONO_MIC  = 0x1,            /* Target contains 1 mic */
    SOURCE_DUAL_MIC  = 0x2,            /* Target contains 2 mics */
    SOURCE_THREE_MIC = 0x4,            /* Target contains 3 mics */
    SOURCE_QUAD_MIC  = 0x8,            /* Target contains 4 mics */
    SOURCE_HEX_MIC   = 0x16,           /* Target contains 6 mics */
    SOURCE_OCT_MIC   = 0x20,           /* Target contains 8 mics */
    SOURCE_DEC_MIC   = 0x40,
};

enum {
    SPKR_1,
    SPKR_2
};

enum {
    AUDIO_LOCATION_NONE = 0x00000000, // Mono/Unspecified
    AUDIO_LOCATION_FRONT_LEFT = 0x00000001,
    AUDIO_LOCATION_FRONT_RIGHT = 0x00000002,
    AUDIO_LOCATION_FRONT_CENTER = 0x00000004,
    AUDIO_LOCATION_LOW_FREQUENCY = 0x00000008,
    AUDIO_LOCATION_BACK_LEFT = 0x00000010,
    AUDIO_LOCATION_BACK_RIGHT = 0x00000020,
    AUDIO_LOCATION_FRONT_LEFT_OF_CENTER = 0x00000040,
    AUDIO_LOCATION_FRONT_RIGHT_OF_CENTER = 0x00000080,
    AUDIO_LOCATION_BACK_CENTER = 0x00000100,
    AUDIO_LOCATION_LOW_FREQUENCY_2 = 0x00000200,
    AUDIO_LOCATION_SIDE_LEFT = 0x00000400,
    AUDIO_LOCATION_SIDE_RIGHT = 0x00000800,
    AUDIO_LOCATION_TOP_FRONT_LEFT = 0x00001000,
    AUDIO_LOCATION_TOP_FRONT_RIGHT = 0x00002000,
    AUDIO_LOCATION_TOP_FRONT_CENTER = 0x00004000,
    AUDIO_LOCATION_TOP_CENTER = 0x00008000,
    AUDIO_LOCATION_TOP_BACK_LEFT = 0x00010000,
    AUDIO_LOCATION_TOP_BACK_RIGHT = 0x00020000,
    AUDIO_LOCATION_TOP_SIDE_LEFT = 0x00040000,
    AUDIO_LOCATION_TOP_SIDE_RIGHT = 0x00080000,
    AUDIO_LOCATION_TOP_BACK_CENTER = 0x00100000,
    AUDIO_LOCATION_BOTTOM_FRONT_CENTER = 0x00200000,
    AUDIO_LOCATION_BOTTOM_FRONT_LEFT = 0x00400000,
    AUDIO_LOCATION_BOTTOM_FRONT_RIGHT = 0x00800000,
    AUDIO_LOCATION_FRONT_LEFT_WIDE = 0x01000000,
    AUDIO_LOCATION_FRONT_RIGHT_WIDE = 0x02000000,
    AUDIO_LOCATION_LEFT_SURROUND = 0x04000000,
    AUDIO_LOCATION_RIGHT_SURROUND = 0x08000000,
    AUDIO_LOCATION_RESERVED_1 = 0x10000000,
    AUDIO_LOCATION_RESERVED_2 = 0x20000000,
    AUDIO_LOCATION_RESERVED_3 = 0x40000000,
    AUDIO_LOCATION_RESERVED_4 = 0x80000000,
};

/* Sound devices specific to the platform
 * The DEVICE_OUT_* and DEVICE_IN_* should be mapped to these sound
 * devices to enable corresponding mixer paths
 */
enum {
    SND_DEVICE_NONE = 0,

    /* Playback devices */
    SND_DEVICE_MIN,
    SND_DEVICE_OUT_BEGIN = SND_DEVICE_MIN,
    SND_DEVICE_OUT_HANDSET = SND_DEVICE_OUT_BEGIN,
    SND_DEVICE_OUT_SPEAKER,
    SND_DEVICE_OUT_SPEAKER_EXTERNAL_1,
    SND_DEVICE_OUT_SPEAKER_EXTERNAL_2,
    SND_DEVICE_OUT_SPEAKER_REVERSE,
    SND_DEVICE_OUT_SPEAKER_SAFE,
    SND_DEVICE_OUT_SPEAKER_VBAT,
    SND_DEVICE_OUT_LINE,
    SND_DEVICE_OUT_HEADPHONES,
    SND_DEVICE_OUT_HEADPHONES_DSD,
    SND_DEVICE_OUT_HEADPHONES_HIFI_FILTER,
    SND_DEVICE_OUT_HEADPHONES_44_1,
    SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES,
    SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_HIFI_FILTER,
    SND_DEVICE_OUT_SPEAKER_SAFE_AND_HEADPHONES,
    SND_DEVICE_OUT_SPEAKER_AND_LINE,
    SND_DEVICE_OUT_SPEAKER_SAFE_AND_LINE,
    SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_EXTERNAL_1,
    SND_DEVICE_OUT_SPEAKER_AND_HEADPHONES_EXTERNAL_2,
    SND_DEVICE_OUT_VOICE_HANDSET,
    SND_DEVICE_OUT_VOICE_SPEAKER,
    SND_DEVICE_OUT_VOICE_SPEAKER_STEREO,
    SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_VBAT,
    SND_DEVICE_OUT_VOICE_SPEAKER_VBAT,
    SND_DEVICE_OUT_VOICE_SPEAKER_2,
    SND_DEVICE_OUT_VOICE_SPEAKER_2_VBAT,
    SND_DEVICE_OUT_VOICE_HEADPHONES,
    SND_DEVICE_OUT_VOICE_HEADSET,
    SND_DEVICE_OUT_VOICE_LINE,
    SND_DEVICE_OUT_HDMI,
    SND_DEVICE_OUT_SPEAKER_AND_HDMI,
    SND_DEVICE_OUT_DISPLAY_PORT,
    SND_DEVICE_OUT_DISPLAY_PORT1,
    SND_DEVICE_OUT_SPEAKER_AND_DISPLAY_PORT,
    SND_DEVICE_OUT_SPEAKER_AND_DISPLAY_PORT1,
    SND_DEVICE_OUT_BT_SCO,
    SND_DEVICE_OUT_BT_SCO_WB,
    SND_DEVICE_OUT_BT_SCO_SWB,
    SND_DEVICE_OUT_BT_A2DP,
    SND_DEVICE_OUT_SPEAKER_AND_BT_A2DP,
    SND_DEVICE_OUT_SPEAKER_SAFE_AND_BT_A2DP,
    SND_DEVICE_OUT_VOICE_HANDSET_TMUS,
    SND_DEVICE_OUT_SPEAKER_AND_BT_SCO,
    SND_DEVICE_OUT_SPEAKER_SAFE_AND_BT_SCO,
    SND_DEVICE_OUT_SPEAKER_AND_BT_SCO_WB,
    SND_DEVICE_OUT_SPEAKER_SAFE_AND_BT_SCO_WB,
    SND_DEVICE_OUT_SPEAKER_AND_BT_SCO_SWB,
    SND_DEVICE_OUT_SPEAKER_SAFE_AND_BT_SCO_SWB,
    SND_DEVICE_OUT_SPEAKER_WSA_AND_BT_SCO,
    SND_DEVICE_OUT_SPEAKER_WSA_AND_BT_SCO_WB,
    SND_DEVICE_OUT_SPEAKER_WSA_AND_BT_SCO_SWB,
    SND_DEVICE_OUT_VOICE_TTY_FULL_HEADPHONES,
    SND_DEVICE_OUT_VOICE_TTY_FULL_HEADSET,
    SND_DEVICE_OUT_VOICE_TTY_VCO_HEADPHONES,
    SND_DEVICE_OUT_VOICE_TTY_VCO_HEADSET,
    SND_DEVICE_OUT_VOICE_TTY_HCO_HANDSET,
    SND_DEVICE_OUT_VOICE_TTY_FULL_USB,
    SND_DEVICE_OUT_VOICE_TTY_VCO_USB,
    SND_DEVICE_OUT_VOICE_HAC_HANDSET,
    SND_DEVICE_OUT_VOICE_TX,
    SND_DEVICE_OUT_VOICE_MUSIC_TX,
    SND_DEVICE_OUT_VOICE_SPEAKER_HFP,
    SND_DEVICE_OUT_AFE_PROXY,
    SND_DEVICE_OUT_USB_HEADSET,
    SND_DEVICE_OUT_USB_HEADPHONES,
    SND_DEVICE_OUT_SPEAKER_AND_USB_HEADSET,
    SND_DEVICE_OUT_SPEAKER_SAFE_AND_USB_HEADSET,
    SND_DEVICE_OUT_VOICE_USB_HEADPHONES,
    SND_DEVICE_OUT_VOICE_USB_HEADSET,
    SND_DEVICE_OUT_USB_HEADSET_SPEC,
    SND_DEVICE_OUT_TRANSMISSION_FM,
    SND_DEVICE_OUT_ANC_HEADSET,
    SND_DEVICE_OUT_ANC_FB_HEADSET,
    SND_DEVICE_OUT_VOICE_ANC_HEADSET,
    SND_DEVICE_OUT_VOICE_ANC_FB_HEADSET,
    SND_DEVICE_OUT_SPEAKER_AND_ANC_HEADSET,
    SND_DEVICE_OUT_SPEAKER_AND_ANC_FB_HEADSET,
    SND_DEVICE_OUT_ANC_HANDSET,
    SND_DEVICE_OUT_SPEAKER_PROTECTED,
    SND_DEVICE_OUT_VOICE_SPEAKER_PROTECTED,
    SND_DEVICE_OUT_VOICE_SPEAKER_2_PROTECTED,
    SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_PROTECTED,
    SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_PROTECTED_VBAT,
    SND_DEVICE_OUT_SPEAKER_PROTECTED_VBAT,
    SND_DEVICE_OUT_VOICE_SPEAKER_PROTECTED_VBAT,
    SND_DEVICE_OUT_VOICE_SPEAKER_2_PROTECTED_VBAT,
    SND_DEVICE_OUT_SPEAKER_WSA,
    SND_DEVICE_OUT_VOICE_SPEAKER_WSA,
    SND_DEVICE_OUT_VOICE_SPEAKER_2_WSA,
    SND_DEVICE_OUT_SPEAKER_PROTECTED_RAS,
    SND_DEVICE_OUT_SPEAKER_PROTECTED_VBAT_RAS,
    SND_DEVICE_OUT_VOIP_HANDSET,
    SND_DEVICE_OUT_VOIP_SPEAKER,
    SND_DEVICE_OUT_VOIP_HEADPHONES,
    SND_DEVICE_OUT_VOICE_SPEAKER_AND_VOICE_HEADPHONES,
    SND_DEVICE_OUT_VOICE_SPEAKER_AND_VOICE_ANC_HEADSET,
    SND_DEVICE_OUT_VOICE_SPEAKER_AND_VOICE_ANC_FB_HEADSET,
    SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_AND_VOICE_HEADPHONES,
    SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_AND_VOICE_ANC_HEADSET,
    SND_DEVICE_OUT_VOICE_SPEAKER_STEREO_AND_VOICE_ANC_FB_HEADSET,
    SND_DEVICE_OUT_VOICE_HEARING_AID,
    SND_DEVICE_OUT_BUS_MEDIA,
    SND_DEVICE_OUT_BUS_SYS,
    SND_DEVICE_OUT_BUS_NAV,
    SND_DEVICE_OUT_BUS_PHN,
    SND_DEVICE_OUT_BUS_ALR,
    SND_DEVICE_OUT_BUS_PAX,
    SND_DEVICE_OUT_BUS_RSE,
    SND_DEVICE_OUT_CALL_PROXY,
    SND_DEVICE_OUT_HAPTICS,
    SND_DEVICE_OUT_ICC,
    SND_DEVICE_OUT_SYNTH_SPKR,
    SND_DEVICE_OUT_END,

    /*
     * Note: IN_BEGIN should be same as OUT_END because total number of devices
     * SND_DEVICES_MAX should not exceed MAX_RX + MAX_TX devices.
     */
    /* Capture devices */
    SND_DEVICE_IN_BEGIN = SND_DEVICE_OUT_END,
    SND_DEVICE_IN_HANDSET_MIC  = SND_DEVICE_IN_BEGIN,
    SND_DEVICE_IN_HANDSET_MIC_SB,
    SND_DEVICE_IN_HANDSET_MIC_EXTERNAL,
    SND_DEVICE_IN_HANDSET_MIC_NN,
    SND_DEVICE_IN_HANDSET_MIC_AEC,
    SND_DEVICE_IN_HANDSET_MIC_AEC_SB,
    SND_DEVICE_IN_HANDSET_MIC_AEC_NN,
    SND_DEVICE_IN_HANDSET_MIC_NS,
    SND_DEVICE_IN_HANDSET_MIC_NS_NN,
    SND_DEVICE_IN_HANDSET_MIC_NS_SB,
    SND_DEVICE_IN_HANDSET_MIC_AEC_NS,
    SND_DEVICE_IN_HANDSET_MIC_AEC_NS_NN,
    SND_DEVICE_IN_HANDSET_MIC_AEC_NS_SB,
    SND_DEVICE_IN_HANDSET_DMIC,
    SND_DEVICE_IN_HANDSET_DMIC_AEC,
    SND_DEVICE_IN_HANDSET_DMIC_AEC_SB,
    SND_DEVICE_IN_HANDSET_DMIC_NS,
    SND_DEVICE_IN_HANDSET_DMIC_NS_SB,
    SND_DEVICE_IN_HANDSET_DMIC_AEC_NS,
    SND_DEVICE_IN_HANDSET_DMIC_AEC_NS_SB,
    SND_DEVICE_IN_SPEAKER_MIC,
    SND_DEVICE_IN_SPEAKER_MIC_SB,
    SND_DEVICE_IN_SPEAKER_MIC_NN,
    SND_DEVICE_IN_SPEAKER_MIC_AEC,
    SND_DEVICE_IN_SPEAKER_MIC_AEC_SB,
    SND_DEVICE_IN_SPEAKER_MIC_AEC_NN,
    SND_DEVICE_IN_SPEAKER_MIC_NS,
    SND_DEVICE_IN_SPEAKER_MIC_NS_SB,
    SND_DEVICE_IN_SPEAKER_MIC_NS_NN,
    SND_DEVICE_IN_SPEAKER_MIC_AEC_NS,
    SND_DEVICE_IN_SPEAKER_MIC_AEC_NS_SB,
    SND_DEVICE_IN_SPEAKER_MIC_AEC_NS_NN,
    SND_DEVICE_IN_SPEAKER_DMIC,
    SND_DEVICE_IN_SPEAKER_DMIC_AEC,
    SND_DEVICE_IN_SPEAKER_DMIC_AEC_SB,
    SND_DEVICE_IN_SPEAKER_DMIC_NS,
    SND_DEVICE_IN_SPEAKER_DMIC_NS_SB,
    SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS,
    SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS_SB,
    SND_DEVICE_IN_HEADSET_MIC,
    SND_DEVICE_IN_HEADSET_MIC_AEC,
    SND_DEVICE_IN_HEADSET_MIC_FLUENCE,
    SND_DEVICE_IN_VOICE_SPEAKER_MIC,
    SND_DEVICE_IN_VOICE_SPEAKER_MIC_SB,
    SND_DEVICE_IN_VOICE_SPEAKER_MIC_NN,
    SND_DEVICE_IN_VOICE_SPEAKER_MIC_HFP,
    SND_DEVICE_IN_VOICE_SPEAKER_MIC_HFP_MMSECNS,
    SND_DEVICE_IN_VOICE_HEADSET_MIC,
    SND_DEVICE_IN_SPDIF,
    SND_DEVICE_IN_HDMI_MIC,
    SND_DEVICE_IN_HDMI_ARC,
    SND_DEVICE_IN_BT_SCO_MIC,
    SND_DEVICE_IN_BT_SCO_MIC_NREC,
    SND_DEVICE_IN_BT_SCO_MIC_WB,
    SND_DEVICE_IN_BT_SCO_MIC_WB_NREC,
    SND_DEVICE_IN_BT_SCO_MIC_SWB,
    SND_DEVICE_IN_BT_SCO_MIC_SWB_NREC,
    SND_DEVICE_IN_BT_A2DP,
    SND_DEVICE_IN_CAMCORDER_LANDSCAPE,
    SND_DEVICE_IN_VOICE_DMIC,
    SND_DEVICE_IN_VOICE_DMIC_SB,
    SND_DEVICE_IN_VOICE_DMIC_TMUS,
    SND_DEVICE_IN_VOICE_SPEAKER_DMIC,
    SND_DEVICE_IN_VOICE_SPEAKER_DMIC_SB,
    SND_DEVICE_IN_VOICE_SPEAKER_TMIC,
    SND_DEVICE_IN_VOICE_SPEAKER_QMIC,
    SND_DEVICE_IN_VOICE_TTY_FULL_HEADSET_MIC,
    SND_DEVICE_IN_VOICE_TTY_VCO_HANDSET_MIC,
    SND_DEVICE_IN_VOICE_TTY_HCO_HEADSET_MIC,
    SND_DEVICE_IN_VOICE_TTY_FULL_USB_MIC,
    SND_DEVICE_IN_VOICE_TTY_HCO_USB_MIC,
    SND_DEVICE_IN_VOICE_REC_MIC,
    SND_DEVICE_IN_VOICE_REC_MIC_NS,
    SND_DEVICE_IN_VOICE_REC_MIC_AEC,
    SND_DEVICE_IN_VOICE_REC_MIC_AEC_NS,
    SND_DEVICE_IN_VOICE_REC_DMIC_STEREO,
    SND_DEVICE_IN_VOICE_REC_DMIC_FLUENCE,
    SND_DEVICE_IN_VOICE_REC_HEADSET_MIC,
    SND_DEVICE_IN_VOICE_RX,
    SND_DEVICE_IN_USB_HEADSET_MIC,
    SND_DEVICE_IN_USB_HEADSET_MIC_AEC,
    SND_DEVICE_IN_VOICE_USB_HEADSET_MIC,
    SND_DEVICE_IN_UNPROCESSED_USB_HEADSET_MIC,
    SND_DEVICE_IN_VOICE_RECOG_USB_HEADSET_MIC,
    SND_DEVICE_IN_USB_HEADSET_MULTI_CHANNEL_MIC,
    SND_DEVICE_IN_USB_HEADSET_MULTI_CHANNEL_MIC_AEC,
    SND_DEVICE_IN_UNPROCESSED_USB_HEADSET_MULTI_CHANNEL_MIC,
    SND_DEVICE_IN_VOICE_RECOG_USB_HEADSET_MULTI_CHANNEL_MIC,
    SND_DEVICE_IN_CAPTURE_FM,
    SND_DEVICE_IN_AANC_HANDSET_MIC,
    SND_DEVICE_IN_QUAD_MIC,
    SND_DEVICE_IN_HANDSET_DMIC_STEREO,
    SND_DEVICE_IN_SPEAKER_DMIC_STEREO,
    SND_DEVICE_IN_CAPTURE_VI_FEEDBACK,
    SND_DEVICE_IN_CAPTURE_VI_FEEDBACK_MONO_1,
    SND_DEVICE_IN_CAPTURE_VI_FEEDBACK_MONO_2,
    SND_DEVICE_IN_VOICE_SPEAKER_DMIC_BROADSIDE,
    SND_DEVICE_IN_SPEAKER_DMIC_BROADSIDE,
    SND_DEVICE_IN_SPEAKER_DMIC_AEC_BROADSIDE,
    SND_DEVICE_IN_SPEAKER_DMIC_NS_BROADSIDE,
    SND_DEVICE_IN_SPEAKER_DMIC_AEC_NS_BROADSIDE,
    SND_DEVICE_IN_VOICE_FLUENCE_DMIC_AANC,
    SND_DEVICE_IN_HANDSET_QMIC,
    SND_DEVICE_IN_HANDSET_QMIC_AEC,
    SND_DEVICE_IN_SPEAKER_QMIC_AEC,
    SND_DEVICE_IN_SPEAKER_QMIC_NS,
    SND_DEVICE_IN_SPEAKER_QMIC_AEC_NS,
    SND_DEVICE_IN_VOICE_REC_QMIC_FLUENCE,
    SND_DEVICE_IN_THREE_MIC,
    SND_DEVICE_IN_HANDSET_TMIC_FLUENCE_PRO,
    SND_DEVICE_IN_HANDSET_TMIC,
    SND_DEVICE_IN_HANDSET_TMIC_AEC,
    SND_DEVICE_IN_HANDSET_TMIC_NS,
    SND_DEVICE_IN_HANDSET_TMIC_AEC_NS,
    SND_DEVICE_IN_SPEAKER_TMIC_AEC,
    SND_DEVICE_IN_SPEAKER_TMIC_NS,
    SND_DEVICE_IN_SPEAKER_TMIC_AEC_NS,
    SND_DEVICE_IN_VOICE_REC_TMIC,
    SND_DEVICE_IN_UNPROCESSED_MIC,
    SND_DEVICE_IN_UNPROCESSED_STEREO_MIC,
    SND_DEVICE_IN_UNPROCESSED_THREE_MIC,
    SND_DEVICE_IN_UNPROCESSED_QUAD_MIC,
    SND_DEVICE_IN_UNPROCESSED_HEADSET_MIC,
    SND_DEVICE_IN_HANDSET_6MIC,
    SND_DEVICE_IN_HANDSET_8MIC,
    SND_DEVICE_IN_EC_REF_LOOPBACK_MONO,
    SND_DEVICE_IN_EC_REF_LOOPBACK_STEREO,
    SND_DEVICE_IN_HANDSET_GENERIC_QMIC,
    SND_DEVICE_IN_INCALL_REC_RX,
    SND_DEVICE_IN_INCALL_REC_TX,
    SND_DEVICE_IN_INCALL_REC_RX_TX,
    SND_DEVICE_IN_LINE,
    SND_DEVICE_IN_CAMCORDER_INVERT_LANDSCAPE,
    SND_DEVICE_IN_CAMCORDER_PORTRAIT,
    SND_DEVICE_IN_CAMCORDER_SELFIE_LANDSCAPE,
    SND_DEVICE_IN_CAMCORDER_SELFIE_INVERT_LANDSCAPE,
    SND_DEVICE_IN_CAMCORDER_SELFIE_PORTRAIT,
    SND_DEVICE_IN_VOICE_HEARING_AID,
    SND_DEVICE_IN_BUS,
    SND_DEVICE_IN_BUS_PAX,
    SND_DEVICE_IN_BUS_RSE,
    SND_DEVICE_IN_EC_REF_LOOPBACK,
    SND_DEVICE_IN_HANDSET_DMIC_AND_EC_REF_LOOPBACK,
    SND_DEVICE_IN_HANDSET_QMIC_AND_EC_REF_LOOPBACK,
    SND_DEVICE_IN_HANDSET_6MIC_AND_EC_REF_LOOPBACK,
    SND_DEVICE_IN_HANDSET_8MIC_AND_EC_REF_LOOPBACK,
    SND_DEVICE_IN_CALL_PROXY,
    SND_DEVICE_IN_ICC,
    SND_DEVICE_IN_SYNTH_MIC,
    SND_DEVICE_IN_ECHO_REFERENCE,
    SND_DEVICE_IN_HANDSET_GENERIC_DMIC,
    SND_DEVICE_IN_HANDSET_GENERIC_6MIC,
    SND_DEVICE_IN_HANDSET_GENERIC_8MIC,
    SND_DEVICE_IN_HANDSET_GENERIC_DMIC_AND_EC_REF_LOOPBACK,
    SND_DEVICE_IN_HANDSET_GENERIC_QMIC_AND_EC_REF_LOOPBACK,
    SND_DEVICE_IN_HANDSET_GENERIC_6MIC_AND_EC_REF_LOOPBACK,
    SND_DEVICE_IN_HANDSET_GENERIC_8MIC_AND_EC_REF_LOOPBACK,
    SND_DEVICE_IN_HDMI_MIC_DSD,
    SND_DEVICE_IN_ECALL,
    SND_DEVICE_IN_SPEAKER_MIC2,
    SND_DEVICE_IN_SPEAKER_MIC3,
    SND_DEVICE_IN_HANDSET_GENERIC_6MIC_AND_SPEAKER_MIC2,
    SND_DEVICE_IN_END,

    SND_DEVICE_MAX = SND_DEVICE_IN_END,
    /* For legacy xml file parsing */
    SND_DEVICE_IN_CAMCORDER_MIC = SND_DEVICE_IN_CAMCORDER_LANDSCAPE,
};

#define INPUT_SAMPLING_RATE_DSD64       2822400
#define INPUT_SAMPLING_RATE_DSD128      5644800
#define INPUT_SAMPLING_RATE_11025       11025
#define DEFAULT_OUTPUT_SAMPLING_RATE    48000
#define OUTPUT_SAMPLING_RATE_44100      44100
#define OUTPUT_SAMPLING_RATE_DSD64       176400
#define OUTPUT_SAMPLING_RATE_DSD128      352800
enum {
    DEFAULT_CODEC_BACKEND,
    SLIMBUS_0_RX = DEFAULT_CODEC_BACKEND,
    DSD_NATIVE_BACKEND,
    SLIMBUS_2_RX = DSD_NATIVE_BACKEND,
    HEADPHONE_44_1_BACKEND,
    SLIMBUS_5_RX = HEADPHONE_44_1_BACKEND,
    HEADPHONE_BACKEND,
    SLIMBUS_6_RX = HEADPHONE_BACKEND,
    HDMI_RX_BACKEND,
    DISP_PORT_RX_BACKEND,
    DISP_PORT1_RX_BACKEND,
    USB_AUDIO_RX_BACKEND,
    CALL_PROXY_RX_BACKEND,
    MAX_RX_CODEC_BACKENDS = USB_AUDIO_RX_BACKEND,
    /* TX BE follows RX BE */
    SLIMBUS_0_TX,
    DEFAULT_CODEC_TX_BACKEND = SLIMBUS_0_TX,
    USB_AUDIO_TX_BACKEND,
    BT_SCO_TX_BACKEND,
    SPDIF_TX_BACKEND,
    HDMI_TX_BACKEND,
    HDMI_ARC_TX_BACKEND,
    HEADSET_TX_BACKEND,
    CALL_PROXY_TX_BACKEND,
    SEC_MI2S_RX_BACKEND,
    TERT_MI2S_RX_BACKEND,
    TERT_MI2S_TX_BACKEND,
    QUAT_MI2S_RX_BACKEND,
    QUAT_TDM_TX_BACKEND,
    SEN_TDM_TX_BACKEND,
    MAX_CODEC_BACKENDS
};

#define AUDIO_PARAMETER_KEY_NATIVE_AUDIO "audio.nat.codec.enabled"
#define AUDIO_PARAMETER_KEY_NATIVE_AUDIO_MODE "native_audio_mode"

#define AUDIO_PARAMETER_KEY_TRUE_32_BIT "true_32_bit"

#define AUDIO_PARAMETER_SPKR_HPH_SINGLE_BE_NATIVE_CONCURRENCY "spkr_hph_single_be_native_concurrency"

#define AUDIO_MAX_DSP_CHANNELS 32

#define ALL_SESSION_VSID                0xFFFFFFFF
#define DEFAULT_MUTE_RAMP_DURATION_MS   20
#define DEFAULT_VOLUME_RAMP_DURATION_MS 20
#define MIXER_PATH_MAX_LENGTH 128
#define CODEC_VERSION_MAX_LENGTH 100
#define CODEC_VARIANT_MAX_LENGTH 100

#define MAX_VOL_INDEX 5
#define MIN_VOL_INDEX 0
#define percent_to_index(val, min, max) \
            ((val) * ((max) - (min)) * 0.01 + (min) + .5)

/*
 * tinyAlsa library interprets period size as number of frames
 * one frame = channel_count * sizeof (pcm sample)
 * so if format = 16-bit PCM and channels = Stereo, frame size = 2 ch * 2 = 4 bytes
 * DEEP_BUFFER_OUTPUT_PERIOD_SIZE = 1024 means 1024 * 4 = 4096 bytes
 * We should take care of returning proper size when AudioFlinger queries for
 * the buffer size of an input/output stream
 */

/* for 384Khz output below period size corresponds to 20ms worth duration of buffer,
 * current implementation can support buffer size of 40ms duration
 * for 32b/384Khz/stereo output.
 */
#define DEEP_BUFFER_OUTPUT_PERIOD_SIZE 1920
#define DEEP_BUFFER_OUTPUT_PERIOD_DURATION 40 /* 40 milisecs */

#define DEEP_BUFFER_OUTPUT_PERIOD_COUNT 2
#define LOW_LATENCY_OUTPUT_PERIOD_SIZE 240
#define LOW_LATENCY_OUTPUT_PERIOD_COUNT 2

#define HDMI_MULTI_PERIOD_SIZE  336
#define HDMI_MULTI_PERIOD_COUNT 8
#define HDMI_MULTI_DEFAULT_CHANNEL_COUNT 6
#define HDMI_MULTI_PERIOD_BYTES (HDMI_MULTI_PERIOD_SIZE * HDMI_MULTI_DEFAULT_CHANNEL_COUNT * 2)

#define HIFI_BUFFER_OUTPUT_PERIOD_SIZE 1920
#define HIFI_BUFFER_OUTPUT_PERIOD_DURATION 40 /* 40 milisecs */
#define HIFI_BUFFER_OUTPUT_PERIOD_COUNT 2

/* Used in calculating fragment size for pcm offload */
#if defined (PLATFORM_MSMFALCON) || defined (PLATFORM_MSM8937) || \
    defined (PLATFORM_MSM8953)
#define PCM_OFFLOAD_BUFFER_DURATION 40 /* 40 millisecs */
#else
#define PCM_OFFLOAD_BUFFER_DURATION 80 /* 80 millisecs */
#endif

/* MAX PCM fragment size cannot be increased  further due
 * to flinger's cblk size of 1mb,and it has to be a multiple of
 * 24 - lcm of channels supported by DSP
 */
#define MAX_PCM_OFFLOAD_FRAGMENT_SIZE (240 * 1024)
#define MIN_PCM_OFFLOAD_FRAGMENT_SIZE 512

#define AUDIO_CAPTURE_PERIOD_DURATION_MSEC 20
#define AUDIO_CAPTURE_PERIOD_COUNT 2

#define VOIP_CAPTURE_PERIOD_DURATION_MSEC 20
#define VOIP_CAPTURE_PERIOD_COUNT 2

#define VOIP_PLAYBACK_PERIOD_DURATION_MSEC 20
#define VOIP_PLAYBACK_PERIOD_COUNT 2

#define LOW_LATENCY_CAPTURE_SAMPLE_RATE 48000
#define LOW_LATENCY_CAPTURE_PERIOD_SIZE 240
#define LOW_LATENCY_CAPTURE_USE_CASE 1

#define DEVICE_NAME_MAX_SIZE 128
#define HW_INFO_ARRAY_MAX_SIZE 32

#define DEEP_BUFFER_PCM_DEVICE 0
#define AUDIO_RECORD_PCM_DEVICE 0
#define MULTIMEDIA2_PCM_DEVICE 1
#define MULTIMEDIA3_PCM_DEVICE 4
#define MULTIMEDIA9_PCM_DEVICE 32
#define MULTIMEDIA31_PCM_DEVICE 59
#define FM_PLAYBACK_PCM_DEVICE 5
#define FM_CAPTURE_PCM_DEVICE  6

#ifdef PLATFORM_AUTO
#define HFP_PCM_RX 29
#else
#define HFP_PCM_RX 5
#endif

#define INCALL_MUSIC_UPLINK_PCM_DEVICE 1

#ifdef PLATFORM_MSM8610
#define INCALL_MUSIC_UPLINK2_PCM_DEVICE 14
#elif PLATFORM_MSM8x26
#define INCALL_MUSIC_UPLINK2_PCM_DEVICE 16
#elif PLATFORM_BEAR_FAMILY
#define INCALL_MUSIC_UPLINK2_PCM_DEVICE 16
#elif PLATFORM_APQ8084
#define INCALL_MUSIC_UPLINK2_PCM_DEVICE 34
#elif PLATFORM_MSMNILE
#define INCALL_MUSIC_UPLINK2_PCM_DEVICE 27
#elif PLATFORM_KONA || PLATFORM_HOLI || PLATFORM_LAHAINA
#define INCALL_MUSIC_UPLINK2_PCM_DEVICE 23
#else
#define INCALL_MUSIC_UPLINK2_PCM_DEVICE 35
#endif

#define SPKR_PROT_CALIB_RX_PCM_DEVICE 5
#ifdef PLATFORM_APQ8084
#define SPKR_PROT_CALIB_TX_PCM_DEVICE 35
#elif PLATFORM_MSM8996
#define SPKR_PROT_CALIB_TX_PCM_DEVICE 42
#elif PLATFORM_BEAR_FAMILY
#define SPKR_PROT_CALIB_TX_PCM_DEVICE 26
#else
#define SPKR_PROT_CALIB_TX_PCM_DEVICE 25
#endif
#define PLAYBACK_OFFLOAD_DEVICE 9
#define QUAT_MI2S_PCM_DEVICE    44

// Direct_PCM
#if defined (PLATFORM_MSM8994) || defined (PLATFORM_MSM8996) || \
    defined (PLATFORM_APQ8084) || defined (PLATFORM_MSM8998) || \
    defined (PLATFORM_SDM845) || defined (PLATFORM_SDM710) || \
    defined (PLATFORM_QCS605) ||defined (PLATFORM_SDX24) || \
    defined (PLATFORM_MSMNILE) || defined (PLATFORM_KONA) || \
    defined (PLATFORM_MSMSTEPPE) || defined (PLATFORM_QCS405) || \
    defined (PLATFORM_TRINKET) || defined (PLATFORM_LITO) || \
    defined (PLATFORM_ATOLL) || defined (PLATFORM_BENGAL) || \
    defined (PLATFORM_HOLI) || defined (PLATFORM_LAHAINA)
#define PLAYBACK_OFFLOAD_DEVICE2 17
#elif defined (PLATFORM_MSMFALCON) || defined (PLATFORM_MSM8937) || \
      defined (PLATFORM_MSM8953)
#define PLAYBACK_OFFLOAD_DEVICE2 24
#endif

#if defined (PLATFORM_APQ8084) || defined (PLATFORM_MSM8996) || \
    defined (PLATFORM_MSM8998) || defined (PLATFORM_SDM845) || \
    defined (PLATFORM_SDM710) || defined(PLATFORM_QCS605) || \
    defined (PLATFORM_SDX24) || defined (PLATFORM_MSMNILE) || \
    defined (PLATFORM_KONA) || defined (PLATFORM_MSMSTEPPE) || \
    defined (PLATFORM_QCS405) || defined (PLATFORM_TRINKET) || \
    defined (PLATFORM_LITO) || defined (PLATFORM_MSMFALCON) || \
    defined (PLATFORM_MSM8937) || defined (PLATFORM_ATOLL) || \
    defined (PLATFORM_BENGAL) || defined (PLATFORM_MSM8953) || \
    defined (PLATFORM_HOLI) || defined (PLATFORM_LAHAINA)
#define PLAYBACK_OFFLOAD_DEVICE3 18
#define PLAYBACK_OFFLOAD_DEVICE4 34
#define PLAYBACK_OFFLOAD_DEVICE5 35
#define PLAYBACK_OFFLOAD_DEVICE6 36
#define PLAYBACK_OFFLOAD_DEVICE7 37
#define PLAYBACK_OFFLOAD_DEVICE8 38
#define PLAYBACK_OFFLOAD_DEVICE9 39
#endif
#ifdef PLATFORM_MSM8994
#define PLAYBACK_OFFLOAD_DEVICE3 18
#define PLAYBACK_OFFLOAD_DEVICE4 37
#define PLAYBACK_OFFLOAD_DEVICE5 38
#define PLAYBACK_OFFLOAD_DEVICE6 39
#define PLAYBACK_OFFLOAD_DEVICE7 40
#define PLAYBACK_OFFLOAD_DEVICE8 41
#define PLAYBACK_OFFLOAD_DEVICE9 42
#endif

#define COMPRESS_VOIP_CALL_PCM_DEVICE 3
#define AUDIO_PLAYBACK_VOIP_PCM_DEVICE 16
#define AUDIO_RECORD_VOIP_PCM_DEVICE 16

// Update based on haptic device id
#define AUDIO_HAPTICS_PCM_DEVICE 43
#define HAPTICS_PCM_DEVICE 44

#ifdef PLATFORM_MSM8610
#define LOWLATENCY_PCM_DEVICE 12
#define EC_REF_RX "SEC_I2S_RX"
#elif defined (PLATFORM_MSMFALCON) || defined (PLATFORM_MSM8937) || \
      defined (PLATFORM_MSM8953)
#define LOWLATENCY_PCM_DEVICE 12
#define EC_REF_RX "I2S_RX"
#define MMAP_PLAYBACK_PCM_DEVICE 2
#define MMAP_RECORD_PCM_DEVICE 2
#elif PLATFORM_BEAR_FAMILY
#define EC_REF_RX "I2S_RX"
#else
#define LOWLATENCY_PCM_DEVICE 15
#define MMAP_PLAYBACK_PCM_DEVICE 18
#define MMAP_RECORD_PCM_DEVICE 18
#define EC_REF_RX "SLIM_RX"
#endif

#ifdef PLATFORM_MSM8x26
#define COMPRESS_CAPTURE_DEVICE 20
#else
#define COMPRESS_CAPTURE_DEVICE 19
#endif

#ifdef PLATFORM_MSM8x26
#define VOICE_CALL_PCM_DEVICE 2
#define VOICE2_CALL_PCM_DEVICE 14
#define VOLTE_CALL_PCM_DEVICE 17
#define QCHAT_CALL_PCM_DEVICE 18
#define VOWLAN_CALL_PCM_DEVICE 30
#elif defined (PLATFORM_APQ8084) || defined (PLATFORM_MSM8084)
#define VOICE_CALL_PCM_DEVICE 20
#define VOICE2_CALL_PCM_DEVICE 25
#define VOLTE_CALL_PCM_DEVICE 21
#define QCHAT_CALL_PCM_DEVICE 33
#define VOWLAN_CALL_PCM_DEVICE -1
#elif PLATFORM_MSM8610
#define VOICE_CALL_PCM_DEVICE 2
#define VOICE2_CALL_PCM_DEVICE 13
#define VOLTE_CALL_PCM_DEVICE 15
#define QCHAT_CALL_PCM_DEVICE 14
#define VOWLAN_CALL_PCM_DEVICE -1
#elif PLATFORM_MSM8994
#define VOICE_CALL_PCM_DEVICE 2
#define VOICE2_CALL_PCM_DEVICE 22
#define VOLTE_CALL_PCM_DEVICE 14
#define QCHAT_CALL_PCM_DEVICE 20
#define VOWLAN_CALL_PCM_DEVICE 36
#elif PLATFORM_MSM8996
#define VOICE_CALL_PCM_DEVICE 40
#define VOICE2_CALL_PCM_DEVICE 41
#define VOLTE_CALL_PCM_DEVICE 14
#define QCHAT_CALL_PCM_DEVICE 20
#define VOWLAN_CALL_PCM_DEVICE 33
#elif PLATFORM_BEAR_FAMILY
#define VOICE_CALL_PCM_DEVICE 2
#define VOICE2_CALL_PCM_DEVICE 13
#define VOLTE_CALL_PCM_DEVICE 15
#define QCHAT_CALL_PCM_DEVICE 37
#define VOWLAN_CALL_PCM_DEVICE 16
#elif defined (PLATFORM_MSMFALCON) || defined (PLATFORM_MSM8937) || \
      defined (PLATFORM_MSM8953)
#define VOICE_CALL_PCM_DEVICE 2
#define VOICE2_CALL_PCM_DEVICE 13
#define VOLTE_CALL_PCM_DEVICE 15
#define QCHAT_CALL_PCM_DEVICE 37
#define VOWLAN_CALL_PCM_DEVICE 16
#elif PLATFORM_AUTO
#define HOST_LESS_RX_ID 41
#define HOST_LESS_TX_ID 42
#define VOICE_CALL_PCM_DEVICE 8
#define VOICE2_CALL_PCM_DEVICE -1
#define VOLTE_CALL_PCM_DEVICE -1
#define QCHAT_CALL_PCM_DEVICE -1
#define VOWLAN_CALL_PCM_DEVICE -1
#else
#define VOICE_CALL_PCM_DEVICE 2
#define VOICE2_CALL_PCM_DEVICE 22
#define VOLTE_CALL_PCM_DEVICE 14
#define QCHAT_CALL_PCM_DEVICE 20
#define VOWLAN_CALL_PCM_DEVICE 36
#endif

#ifdef PLATFORM_MSM8996
#define VOICEMMODE1_CALL_PCM_DEVICE 2
#define VOICEMMODE2_CALL_PCM_DEVICE 22
#else
#define VOICEMMODE1_CALL_PCM_DEVICE 44
#define VOICEMMODE2_CALL_PCM_DEVICE 45
#endif

#define AFE_PROXY_PLAYBACK_PCM_DEVICE 7
#define AFE_PROXY_RECORD_PCM_DEVICE 8
#define AFE_PROXY_RECORD2_PCM_DEVICE 40

#ifdef PLATFORM_MSM8x26
#ifdef EXTERNAL_BT_SUPPORTED
#define HFP_SCO_RX 10 // AUXPCM Hostless
#else
#define HFP_SCO_RX 28
#endif
#define HFP_ASM_RX_TX 29
#define HFP_SEC_SCO_RX -1
#define HFP_SEC_ASM_RX_TX -1
#elif PLATFORM_BEAR_FAMILY
#define HFP_SCO_RX 17
#define HFP_ASM_RX_TX 18
#define HFP_SEC_SCO_RX -1
#define HFP_SEC_ASM_RX_TX -1
#elif PLATFORM_AUTO
#define HFP_SCO_RX 29
#define HFP_ASM_RX_TX 36
#elif defined (PLATFORM_MSMFALCON) || defined (PLATFORM_MSM8937) || \
      defined (PLATFORM_MSM8953)
#define HFP_SCO_RX 17
#define HFP_ASM_RX_TX 18
#define HFP_SEC_SCO_RX -1
#define HFP_SEC_ASM_RX_TX -1
#elif PLATFORM_MSMSTEPPE
#define HFP_SCO_RX 12
#define HFP_ASM_RX_TX 37
#define HFP_SEC_SCO_RX -1
#define HFP_SEC_ASM_RX_TX -1
#else
#define HFP_SCO_RX 23
#define HFP_ASM_RX_TX 24
#define HFP_SEC_SCO_RX -1
#define HFP_SEC_ASM_RX_TX -1
#endif

#define TRANSCODE_LOOPBACK_RX_DEV_ID 43
#define TRANSCODE_LOOPBACK_TX_DEV_ID 44

#define PLAYBACK_INTERACTIVE_STRM_DEVICE1 0
#define PLAYBACK_INTERACTIVE_STRM_DEVICE2 1
#define PLAYBACK_INTERACTIVE_STRM_DEVICE3 27
#define PLAYBACK_INTERACTIVE_STRM_DEVICE4 45
#define PLAYBACK_INTERACTIVE_STRM_DEVICE5 46
#define PLAYBACK_INTERACTIVE_STRM_DEVICE6 47
#define PLAYBACK_INTERACTIVE_STRM_DEVICE7 48
#define PLAYBACK_INTERACTIVE_STRM_DEVICE8 49

#define MEDIA_PCM_DEVICE DEEP_BUFFER_PCM_DEVICE
#define SYS_NOTIFICATION_PCM_DEVICE 9
#define NAV_GUIDANCE_PCM_DEVICE MULTIMEDIA2_PCM_DEVICE
#define PHONE_PCM_DEVICE 12
#define ALERTS_PCM_DEVICE MULTIMEDIA31_PCM_DEVICE
#define FRONT_PASSENGER_PCM_DEVICE 55
#define REAR_SEAT_PCM_DEVICE 54

#ifdef PLATFORM_APQ8084
#define FM_RX_VOLUME "Quat MI2S FM RX Volume"
#elif PLATFORM_MSM8994
#define FM_RX_VOLUME "PRI MI2S LOOPBACK Volume"
#elif defined (PLATFORM_MSM8996) || defined (PLATFORM_KONA) || defined (PLATFORM_LAHAINA)
#define FM_RX_VOLUME "Tert MI2S LOOPBACK Volume"
#elif defined (PLATFORM_MSM8998) || defined (PLATFORM_SDM845) || defined (PLATFORM_MSMFALCON) || defined (PLATFORM_SDM710) || defined (PLATFORM_QCS605) || defined (PLATFORM_MSMNILE) || defined (PLATFORM_MSMSTEPPE) || defined (PLATFORM_QCS405) || defined (PLATFORM_TRINKET) || defined (PLATFORM_LITO) || defined (PLATFORM_ATOLL) ||defined (PLATFORM_BENGAL) ||    defined (PLATFORM_HOLI)
#define FM_RX_VOLUME "SLIMBUS_8 LOOPBACK Volume"
#else
#define FM_RX_VOLUME "Internal FM RX Volume"
#endif

#ifdef PLATFORM_AUTO
#define ICC_PCM_DEVICE 33
#else
#define ICC_PCM_DEVICE -1
#endif

#define PLATFORM_MAX_MIC_COUNT "input_mic_max_count"
#define PLATFORM_DEFAULT_MIC_COUNT 2

#define TX_VOICE_FLUENCE_PROV2 0x10F17
#define TX_VOICE_TM_FLUENCE_PRO_VC 0x10F35
#define TX_VOICE_TM_FLUENCE_EF 0x10F33
#define TX_VOICE_DM_FV5_BROADSIDE 0x10F18
#define TX_VOICE_FV5ECNS_SM 0x10F09
#define TX_VOICE_SMECNS_V2 0x10F31
#define TX_VOICE_FV5ECNS_DM 0x10F0A
#define TX_VOICE_FLUENCE_SM_SB 0x10F38
#define TX_VOICE_FLUENCE_MM_SB 0x10F39
#define TX_VOICE_FLUENCE_SM_NN 0x10B0F
#define TX_VOICE_FLUENCEV5_SM 0x10F32

/* multi-mic surround ECNS zone control */
#define TOPOLOGY_ID_MM_HFP_ECNS 0x1FFF0002
#define MODULE_ID_MM_HFP_ECNS   0x10F3B
#define PARAM_ID_MM_HFP_ZONE    0x109F0
#define INSTANCE_ID_MM_HFP_ECNS 0x8000

#define LIB_CSD_CLIENT "libcsd-client.so"

#define AUDIO_MAKE_STRING_FROM_ENUM(X)   { #X, X }

/* CSD-CLIENT related functions */
typedef int (*init_t)(bool);
typedef int (*deinit_t)();
typedef int (*disable_device_t)();
typedef int (*enable_device_config_t)(int, int);
typedef int (*enable_device_t)(int, int, uint32_t);
typedef int (*volume_t)(uint32_t, int, uint16_t);
typedef int (*mic_mute_t)(uint32_t, int, uint16_t);
typedef int (*slow_talk_t)(uint32_t, uint8_t);
typedef int (*start_voice_t)(uint32_t);
typedef int (*stop_voice_t)(uint32_t);
typedef int (*start_playback_t)(uint32_t);
typedef int (*stop_playback_t)(uint32_t);
typedef int (*set_lch_t)(uint32_t, enum voice_lch_mode);
typedef int (*start_record_t)(uint32_t, int);
typedef int (*stop_record_t)(uint32_t);
typedef int (*get_sample_rate_t)(uint32_t *);
/* CSD Client structure */
struct csd_data {
    void *csd_client;
    init_t init;
    deinit_t deinit;
    disable_device_t disable_device;
    enable_device_config_t enable_device_config;
    enable_device_t enable_device;
    volume_t volume;
    mic_mute_t mic_mute;
    slow_talk_t slow_talk;
    start_voice_t start_voice;
    stop_voice_t stop_voice;
    start_playback_t start_playback;
    stop_playback_t stop_playback;
    set_lch_t set_lch;
    start_record_t start_record;
    stop_record_t stop_record;
    get_sample_rate_t get_sample_rate;
};

/* HDMI Passthrough defines */
enum {
    LEGACY_PCM = 0,
    PASSTHROUGH,
    PASSTHROUGH_CONVERT,
    PASSTHROUGH_DSD,
    LISTEN,
    PASSTHROUGH_GEN,
    PASSTHROUGH_IEC61937
};
/*
 * ID for setting mute and lateny on the device side
 * through Device PP Params mixer control.
 */
#define DEVICE_PARAM_MUTE_ID    0
#define DEVICE_PARAM_LATENCY_ID 1
#define DEVICE_PARAM_LIMITER_ID 2

#define ENUM_TO_STRING(X) #X

struct audio_device_to_audio_interface {
    audio_devices_t device;
    char device_name[100];
    char interface_name[100];
};

#endif // QCOM_AUDIO_PLATFORM_H
