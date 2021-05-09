#ifndef TSYNTH_AUDIO_PATCHING_H
#define TSYNTH_AUDIO_PATCHING_H

//waveformX      -->   waveformMixerX   -->   voiceMixer1-3   -->   voiceMixerM  --> volumeMixer
//WAVEFORMLEVEL        oscA/BLevel             VELOCITY    VOICEMIXERLEVEL/UNISONVOICEMIXERLEVEL    volume

// Make the visual audio design tool work by substituting the *TS locally changed classes by those it knows: 
// but also ensure all redefined class names are undefined within this scope, if lingering defines exist, raise an error:
#if defined(AudioSynthWaveform) || defined(AudioSynthWaveformModulated)
# error "Either AudioSynthWaveform or AudioSynthWaveformModulated are already redefined!"
#endif
#define AudioSynthWaveform          AudioSynthWaveformTS
#define AudioSynthWaveformModulated AudioSynthWaveformModulatedTS

// Oscillator configurations.
struct Patch {
    AudioEffectEnvelope filterEnvelope_;

    AudioMixer4 pwMixer_a;
    AudioMixer4 pwMixer_b;

    AudioSynthWaveformDc glide_;

    AudioSynthWaveformDc keytracking_;

    AudioMixer4 oscModMixer_a;
    AudioMixer4 oscModMixer_b;

    AudioSynthWaveform filterLfo_;
    AudioSynthWaveformModulated waveformMod_a;
    AudioSynthWaveformModulated waveformMod_b;

    AudioEffectDigitalCombine oscFX_;

    AudioMixer4 waveformMixer_;

    AudioMixer4 filterModMixer_;

    AudioFilterStateVariable filter_;

    AudioMixer4 filterMixer_;

    AudioEffectEnvelope ampEnvelope_;

    // When added to a voice group, connect PWA/PWB.
    AudioConnection *pitchMixerAConnection;
    AudioConnection *pitchMixerBConnection;
    AudioConnection *pwmLfoAConnection;
    AudioConnection *pwmLfoBConnection;
    AudioConnection *filterLfoConnection;
    AudioConnection *pwaConnection;
    AudioConnection *pwbConnection;
    AudioConnection *noiseMixerConnection;
    AudioConnection *ampConnection;
};

struct PatchShared {
    AudioSynthWaveformDc pitchBend;
    AudioSynthWaveform pitchLfo;
    AudioMixer4 pitchMixer;
    AudioSynthWaveform pwmLfoA;
    AudioSynthWaveform pwmLfoB;
    AudioSynthWaveform filterLfo;
    AudioSynthWaveformDc pwa;
    AudioSynthWaveformDc pwb;
    AudioMixer4 noiseMixer;

    AudioMixer4 voiceMixer1;
    AudioMixer4 voiceMixer2;
    AudioMixer4 voiceMixer3;
    AudioMixer4 voiceMixerM;

    AudioEffectEnsemble ensemble;
};

// GUItool: begin automatically generated code
AudioOutputUSB           usbAudio;       //xy=3197,1821
AudioSynthWaveformDc     constant1Dc;    //xy=69,1781
AudioSynthNoisePink      pink;           //xy=1462
AudioSynthNoiseWhite     white;          //xy=1460
AudioAnalyzePeak         peak;           //xy=2756,1817
AudioMixer4              voiceMixer1L;    //xy=2233,581
AudioMixer4              voiceMixer2L;    //xy=2240,1791
AudioMixer4              voiceMixer3L;    //xy=2237,2976
AudioMixer4              voiceMixerML;    //xy=2431,1798
AudioMixer4              voiceMixer1R;    //xy=2233,581
AudioMixer4              voiceMixer2R;    //xy=2240,1791
AudioMixer4              voiceMixer3R;    //xy=2237,2976
AudioMixer4              voiceMixerMR;    //xy=2431,1798
AudioFilterStateVariable dcOffsetFilterL; //xy=2591,1804
AudioFilterStateVariable dcOffsetFilterR; //xy=2591,1804
AudioMixer4              volumeMixerL;    //xy=2774,1756
AudioMixer4              volumeMixerR;    //xy=2774,1756
Oscilloscope             scope;
AudioMixer4              effectMixerR;   //xy=2984,1823
AudioMixer4              effectMixerL;   //xy=2985,1728
AudioOutputI2S           i2s;            //xy=3190,1737

/*
AudioMixer4              voiceMixer1_1;
AudioMixer4              voiceMixer2_1;
AudioMixer4              voiceMixer3_1;
AudioMixer4              voiceMixerM_1;

AudioMixer4              voiceMixer1_2;
AudioMixer4              voiceMixer2_2;
AudioMixer4              voiceMixer3_2;
AudioMixer4              voiceMixerM_2;

AudioMixer4              voiceMixer1_3;
AudioMixer4              voiceMixer2_3;
AudioMixer4              voiceMixer3_3;
AudioMixer4              voiceMixerM_3;

AudioMixer4              voiceMixer1_4;
AudioMixer4              voiceMixer2_4;
AudioMixer4              voiceMixer3_4;
AudioMixer4              voiceMixerM_4;

AudioMixer4              voiceMixer1_5;
AudioMixer4              voiceMixer2_5;
AudioMixer4              voiceMixer3_5;
AudioMixer4              voiceMixerM_5;

AudioMixer4              voiceMixer1_6;
AudioMixer4              voiceMixer2_6;
AudioMixer4              voiceMixer3_6;
AudioMixer4              voiceMixerM_6;

AudioMixer4              voiceMixer1_7;
AudioMixer4              voiceMixer2_7;
AudioMixer4              voiceMixer3_7;
AudioMixer4              voiceMixerM_7;

AudioMixer4              voiceMixer1_8;
AudioMixer4              voiceMixer2_8;
AudioMixer4              voiceMixer3_8;
AudioMixer4              voiceMixerM_8;

AudioMixer4              voiceMixer1_9;
AudioMixer4              voiceMixer2_9;
AudioMixer4              voiceMixer3_9;
AudioMixer4              voiceMixerM_9;

AudioMixer4              voiceMixer1_10;
AudioMixer4              voiceMixer2_10;
AudioMixer4              voiceMixer3_10;
AudioMixer4              voiceMixerM_10;

AudioMixer4              voiceMixer1_11;
AudioMixer4              voiceMixer2_11;
AudioMixer4              voiceMixer3_11;
AudioMixer4              voiceMixerM_11;

AudioMixer4              voiceMixer1_12;
AudioMixer4              voiceMixer2_12;
AudioMixer4              voiceMixer3_12;
AudioMixer4              voiceMixerM_12;

AudioSynthWaveformDc     pitchBend1; //xy=472,342
AudioSynthWaveformDc     pitchBend2; //xy=441.5,661
AudioSynthWaveformDc     pitchBend3; //xy=439.5,946
AudioSynthWaveformDc     pitchBend4; //xy=442.5,1254
AudioSynthWaveformDc     pitchBend5; //xy=440.5,1559
AudioSynthWaveformDc     pitchBend6; //xy=441.5,1855
AudioSynthWaveformDc     pitchBend7; //xy=442.5,2163
AudioSynthWaveformDc     pitchBend8; //xy=439.5,2457
AudioSynthWaveformDc     pitchBend9; //xy=437.5,2744
AudioSynthWaveformDc     pitchBend10; //xy=440,3051
AudioSynthWaveformDc     pitchBend11; //xy=436.5,3361
AudioSynthWaveformDc     pitchBend12; //xy=441.5,3656

AudioSynthWaveform       pitchLfo1; //xy=466.5,382
AudioSynthWaveform       pitchLfo2; //xy=436,701
AudioSynthWaveform       pitchLfo3; //xy=434,986
AudioSynthWaveform       pitchLfo4; //xy=437,1294
AudioSynthWaveform       pitchLfo5; //xy=435,1599
AudioSynthWaveform       pitchLfo6; //xy=436,1895
AudioSynthWaveform       pitchLfo7; //xy=437,2203
AudioSynthWaveform       pitchLfo8; //xy=434,2497
AudioSynthWaveform       pitchLfo9; //xy=432,2784
AudioSynthWaveform       pitchLfo10; //xy=434.5,3091
AudioSynthWaveform       pitchLfo11; //xy=431,3401
AudioSynthWaveform       pitchLfo12; //xy=436,3696

AudioMixer4              oscPitchMixer1; //xy=647,373
AudioMixer4              oscPitchMixer2; //xy=616.5,692
AudioMixer4              oscPitchMixer3; //xy=614.5,977
AudioMixer4              oscPitchMixer4; //xy=617.5,1285
AudioMixer4              oscPitchMixer5; //xy=615.5,1590
AudioMixer4              oscPitchMixer6; //xy=616.5,1886
AudioMixer4              oscPitchMixer7; //xy=617.5,2194
AudioMixer4              oscPitchMixer8; //xy=614.5,2488
AudioMixer4              oscPitchMixer9; //xy=612.5,2775
AudioMixer4              oscPitchMixer10; //xy=615,3082
AudioMixer4              oscPitchMixer11; //xy=611.5,3392
AudioMixer4              oscPitchMixer12; //xy=616.5,3687

AudioSynthWaveformDc     pwa1;  //xy=783,715
AudioSynthWaveformDc     pwa2;  //xy=783,1028
AudioSynthWaveformDc     pwa3;  //xy=783,1319
AudioSynthWaveformDc     pwa4;  //xy=783,1617
AudioSynthWaveformDc     pwa5;  //xy=783,1911
AudioSynthWaveformDc     pwa6;  //xy=783,2205
AudioSynthWaveformDc     pwa7;  //xy=783,2508
AudioSynthWaveformDc     pwa8;  //xy=783,2806
AudioSynthWaveformDc     pwa9;  //xy=783,3118
AudioSynthWaveformDc     pwa10; //xy=783,3418
AudioSynthWaveformDc     pwa11; //xy=783,3716
AudioSynthWaveformDc     pwa12; //xy=783,4013

AudioSynthWaveformDc     pwb1;  //xy=783,786
AudioSynthWaveformDc     pwb2;  //xy=783,1094
AudioSynthWaveformDc     pwb3;  //xy=783,1394
AudioSynthWaveformDc     pwb4;  //xy=783,1695
AudioSynthWaveformDc     pwb5;  //xy=783,1986
AudioSynthWaveformDc     pwb6;  //xy=783,2291
AudioSynthWaveformDc     pwb7;  //xy=783,2575
AudioSynthWaveformDc     pwb8;  //xy=783,2875
AudioSynthWaveformDc     pwb9;  //xy=783,3192
AudioSynthWaveformDc     pwb10; //xy=783,3492
AudioSynthWaveformDc     pwb11; //xy=783,3790
AudioSynthWaveformDc     pwb12; //xy=783,4089

AudioSynthWaveform       pwmLfoA1;  //xy=773,678
AudioSynthWaveform       pwmLfoA2;  //xy=782,987
AudioSynthWaveform       pwmLfoA3;  //xy=777,1283
AudioSynthWaveform       pwmLfoA4;  //xy=786,1582
AudioSynthWaveform       pwmLfoA5;  //xy=776,1876
AudioSynthWaveform       pwmLfoA6;  //xy=768,2170
AudioSynthWaveform       pwmLfoA7;  //xy=773,2470
AudioSynthWaveform       pwmLfoA8;  //xy=778,2770
AudioSynthWaveform       pwmLfoA9;  //xy=787,3081
AudioSynthWaveform       pwmLfoA10; //xy=781,3381
AudioSynthWaveform       pwmLfoA11; //xy=785,3682
AudioSynthWaveform       pwmLfoA12; //xy=781,3976

AudioSynthWaveform       pwmLfoB1;  //xy=776,751
AudioSynthWaveform       pwmLfoB2;  //xy=777,1058
AudioSynthWaveform       pwmLfoB3;  //xy=773,1360
AudioSynthWaveform       pwmLfoB4;  //xy=783,1655
AudioSynthWaveform       pwmLfoB5;  //xy=782,1950
AudioSynthWaveform       pwmLfoB6;  //xy=784,2257
AudioSynthWaveform       pwmLfoB7;  //xy=780,2542
AudioSynthWaveform       pwmLfoB8;  //xy=784,2841
AudioSynthWaveform       pwmLfoB9;  //xy=786,3152
AudioSynthWaveform       pwmLfoB10; //xy=781,3452
AudioSynthWaveform       pwmLfoB11; //xy=782,3753
AudioSynthWaveform       pwmLfoB12; //xy=785,4051

AudioMixer4              noiseMixer1;  //xy=1207,621
AudioMixer4              noiseMixer2;  //xy=1205,930
AudioMixer4              noiseMixer3;  //xy=1189,1239
AudioMixer4              noiseMixer4;  //xy=1198,1521
AudioMixer4              noiseMixer5;  //xy=1198,1824
AudioMixer4              noiseMixer6;  //xy=1195,2116
AudioMixer4              noiseMixer7;  //xy=1191,2425
AudioMixer4              noiseMixer8;  //xy=1198,2724
AudioMixer4              noiseMixer9;  //xy=1199,3021
AudioMixer4              noiseMixer10; //xy=1184,3326
AudioMixer4              noiseMixer11; //xy=1190,3619
AudioMixer4              noiseMixer12; //xy=1178,3928

AudioSynthWaveform       filterLfo1;  //xy=1335,693
AudioSynthWaveform       filterLfo2;  //xy=1342,997
AudioSynthWaveform       filterLfo3;  //xy=1343,1288
AudioSynthWaveform       filterLfo4;  //xy=1331,1587
AudioSynthWaveform       filterLfo5;  //xy=1330,1892
AudioSynthWaveform       filterLfo6;  //xy=1336,2188
AudioSynthWaveform       filterLfo7;  //xy=1336,2482
AudioSynthWaveform       filterLfo8;  //xy=1333,2785
AudioSynthWaveform       filterLfo9;  //xy=1333,3084
AudioSynthWaveform       filterLfo10; //xy=1327,3388
AudioSynthWaveform       filterLfo11; //xy=1335,3686
AudioSynthWaveform       filterLfo12; //xy=1341,3988

AudioEffectEnvelope      filterEnvelope1; //xy=611,145
AudioEffectEnvelope      filterEnvelope2; //xy=611,445
AudioEffectEnvelope      filterEnvelope3; //xy=611,745
AudioEffectEnvelope      filterEnvelope4; //xy=611,1045
AudioEffectEnvelope      filterEnvelope5; //xy=611,1345
AudioEffectEnvelope      filterEnvelope6; //xy=611,1645
AudioEffectEnvelope      filterEnvelope7; //xy=611,1945
AudioEffectEnvelope      filterEnvelope8; //xy=611,2245
AudioEffectEnvelope      filterEnvelope9; //xy=611,2545
AudioEffectEnvelope      filterEnvelope10; //xy=611,2845
AudioEffectEnvelope      filterEnvelope11; //xy=611,3145
AudioEffectEnvelope      filterEnvelope12; //xy=611,3445

AudioMixer4              pwMixer1a;      //xy=941,185
AudioMixer4              pwMixer1b;      //xy=941,255
AudioMixer4              pwMixer2a;      //xy=941,485
AudioMixer4              pwMixer2b;      //xy=941,555
AudioMixer4              pwMixer3a;      //xy=941,785
AudioMixer4              pwMixer3b;      //xy=941,855
AudioMixer4              pwMixer4a;      //xy=941,1085
AudioMixer4              pwMixer4b;      //xy=941,1155
AudioMixer4              pwMixer5a;      //xy=941,1385
AudioMixer4              pwMixer5b;      //xy=941,1455
AudioMixer4              pwMixer6a;      //xy=941,1685
AudioMixer4              pwMixer6b;      //xy=941,1755
AudioMixer4              pwMixer7a;      //xy=941,1985
AudioMixer4              pwMixer7b;      //xy=941,2055
AudioMixer4              pwMixer8a;      //xy=941,2285
AudioMixer4              pwMixer8b;      //xy=941,2355
AudioMixer4              pwMixer9a;      //xy=941,2585
AudioMixer4              pwMixer9b;      //xy=941,2655
AudioMixer4              pwMixer10a;     //xy=941,2885
AudioMixer4              pwMixer10b;     //xy=941,2955
AudioMixer4              pwMixer11a;     //xy=941,3185
AudioMixer4              pwMixer11b;     //xy=941,3255
AudioMixer4              pwMixer12a;     //xy=941,3485
AudioMixer4              pwMixer12b;     //xy=941,3555

AudioSynthWaveformDc     glide1;         //xy=619,430
AudioSynthWaveformDc     glide2;         //xy=588,741
AudioSynthWaveformDc     glide3;         //xy=586,1036
AudioSynthWaveformDc     glide4;         //xy=591,1340
AudioSynthWaveformDc     glide5;         //xy=588,1640
AudioSynthWaveformDc     glide6;         //xy=589,1939
AudioSynthWaveformDc     glide7;         //xy=588,2243
AudioSynthWaveformDc     glide8;         //xy=584,2541
AudioSynthWaveformDc     glide9;         //xy=587,2834
AudioSynthWaveformDc     glide10;        //xy=582,3138
AudioSynthWaveformDc     glide11;        //xy=582,3442
AudioSynthWaveformDc     glide12;        //xy=584,3739

AudioSynthWaveformDc     keytracking1;   //xy=1326,172
AudioSynthWaveformDc     keytracking2;   //xy=1326,472
AudioSynthWaveformDc     keytracking3;   //xy=1326,772
AudioSynthWaveformDc     keytracking4;   //xy=1326,1072
AudioSynthWaveformDc     keytracking5;   //xy=1326,1372
AudioSynthWaveformDc     keytracking6;   //xy=1326,1672
AudioSynthWaveformDc     keytracking7;   //xy=1326,1972
AudioSynthWaveformDc     keytracking8;   //xy=1326,2272
AudioSynthWaveformDc     keytracking9;   //xy=1326,2572
AudioSynthWaveformDc     keytracking10;  //xy=1326,2872
AudioSynthWaveformDc     keytracking11;  //xy=1326,3172
AudioSynthWaveformDc     keytracking12;  //xy=1326,3472

AudioMixer4              oscModMixer1a;  //xy=956,35
AudioMixer4              oscModMixer1b;  //xy=956,105
AudioMixer4              oscModMixer2a;  //xy=956,335
AudioMixer4              oscModMixer2b;  //xy=956,405
AudioMixer4              oscModMixer3a;  //xy=956,635
AudioMixer4              oscModMixer3b;  //xy=956,705
AudioMixer4              oscModMixer4a;  //xy=956,935
AudioMixer4              oscModMixer4b;  //xy=956,1005
AudioMixer4              oscModMixer5a;  //xy=956,1235
AudioMixer4              oscModMixer5b;  //xy=956,1305
AudioMixer4              oscModMixer6a;  //xy=956,1535
AudioMixer4              oscModMixer6b;  //xy=956,1605
AudioMixer4              oscModMixer7a;  //xy=956,1835
AudioMixer4              oscModMixer7b;  //xy=956,1905
AudioMixer4              oscModMixer8a;  //xy=956,2135
AudioMixer4              oscModMixer8b;  //xy=956,2205
AudioMixer4              oscModMixer9a;  //xy=956,2435
AudioMixer4              oscModMixer9b;  //xy=956,2505
AudioMixer4              oscModMixer10a; //xy=956,2735
AudioMixer4              oscModMixer10b; //xy=956,2805
AudioMixer4              oscModMixer11a; //xy=956,3035
AudioMixer4              oscModMixer11b; //xy=956,3105
AudioMixer4              oscModMixer12a; //xy=956,3335
AudioMixer4              oscModMixer12b; //xy=956,3405

AudioSynthWaveformModulated waveformMod1a;  //xy=1171,35
AudioSynthWaveformModulated waveformMod1b;  //xy=1171,255
AudioSynthWaveformModulated waveformMod2a;  //xy=1171,335
AudioSynthWaveformModulated waveformMod2b;  //xy=1171,555
AudioSynthWaveformModulated waveformMod3a;  //xy=1171,635
AudioSynthWaveformModulated waveformMod3b;  //xy=1171,855
AudioSynthWaveformModulated waveformMod4a;  //xy=1171,935
AudioSynthWaveformModulated waveformMod4b;  //xy=1171,1155
AudioSynthWaveformModulated waveformMod5a;  //xy=1171,1235
AudioSynthWaveformModulated waveformMod5b;  //xy=1171,1455
AudioSynthWaveformModulated waveformMod6a;  //xy=1171,1535
AudioSynthWaveformModulated waveformMod6b;  //xy=1171,1755
AudioSynthWaveformModulated waveformMod7a;  //xy=1171,1835
AudioSynthWaveformModulated waveformMod7b;  //xy=1171,2055
AudioSynthWaveformModulated waveformMod8a;  //xy=1171,2135
AudioSynthWaveformModulated waveformMod8b;  //xy=1171,2355
AudioSynthWaveformModulated waveformMod9a;  //xy=1171,2435
AudioSynthWaveformModulated waveformMod9b;  //xy=1171,2655
AudioSynthWaveformModulated waveformMod10a; //xy=1171,2735
AudioSynthWaveformModulated waveformMod10b; //xy=1171,2955
AudioSynthWaveformModulated waveformMod11a; //xy=1171,3035
AudioSynthWaveformModulated waveformMod11b; //xy=1171,3255
AudioSynthWaveformModulated waveformMod12a; //xy=1171,3335
AudioSynthWaveformModulated waveformMod12b; //xy=1171,3555

AudioEffectDigitalCombine oscFX1;         //xy=1336,115
AudioEffectDigitalCombine oscFX2;         //xy=1336,415
AudioEffectDigitalCombine oscFX3;         //xy=1336,715
AudioEffectDigitalCombine oscFX4;         //xy=1336,1015
AudioEffectDigitalCombine oscFX5;         //xy=1336,1315
AudioEffectDigitalCombine oscFX6;         //xy=1336,1615
AudioEffectDigitalCombine oscFX7;         //xy=1336,1915
AudioEffectDigitalCombine oscFX8;         //xy=1336,2215
AudioEffectDigitalCombine oscFX9;         //xy=1336,2515
AudioEffectDigitalCombine oscFX10;        //xy=1336,2815
AudioEffectDigitalCombine oscFX11;        //xy=1336,3115
AudioEffectDigitalCombine oscFX12;        //xy=1336,3415

AudioMixer4              waveformMixer1; //xy=1516,95
AudioMixer4              waveformMixer2; //xy=1516,395
AudioMixer4              waveformMixer3; //xy=1516,695
AudioMixer4              waveformMixer4; //xy=1516,995
AudioMixer4              waveformMixer5; //xy=1516,1295
AudioMixer4              waveformMixer6; //xy=1516,1595
AudioMixer4              waveformMixer7; //xy=1516,1895
AudioMixer4              waveformMixer8; //xy=1516,2195
AudioMixer4              waveformMixer9; //xy=1516,2495
AudioMixer4              waveformMixer10; //xy=1516,2795
AudioMixer4              waveformMixer11; //xy=1516,3095
AudioMixer4              waveformMixer12; //xy=1516,3395

AudioMixer4              filterModMixer1; //xy=1516,165
AudioMixer4              filterModMixer2; //xy=1516,465
AudioMixer4              filterModMixer3; //xy=1516,765
AudioMixer4              filterModMixer4; //xy=1516,1065
AudioMixer4              filterModMixer5; //xy=1516,1365
AudioMixer4              filterModMixer6; //xy=1516,1665
AudioMixer4              filterModMixer7; //xy=1516,1965
AudioMixer4              filterModMixer8; //xy=1516,2265
AudioMixer4              filterModMixer9; //xy=1516,2565
AudioMixer4              filterModMixer10; //xy=1516,2865
AudioMixer4              filterModMixer11; //xy=1516,3165
AudioMixer4              filterModMixer12; //xy=1516,3465

AudioFilterStateVariable filter1;        //xy=1681,145
AudioFilterStateVariable filter2;        //xy=1681,445
AudioFilterStateVariable filter3;        //xy=1681,745
AudioFilterStateVariable filter4;        //xy=1681,1045
AudioFilterStateVariable filter5;        //xy=1681,1345
AudioFilterStateVariable filter6;        //xy=1681,1645
AudioFilterStateVariable filter7;        //xy=1681,1945
AudioFilterStateVariable filter8;        //xy=1681,2245
AudioFilterStateVariable filter9;        //xy=1681,2545
AudioFilterStateVariable filter10;       //xy=1681,2845
AudioFilterStateVariable filter11;       //xy=1681,3145
AudioFilterStateVariable filter12;       //xy=1681,3445

AudioMixer4              filterMixer1;   //xy=1821,145
AudioMixer4              filterMixer2;   //xy=1821,445
AudioMixer4              filterMixer3;   //xy=1821,745
AudioMixer4              filterMixer4;   //xy=1821,1045
AudioMixer4              filterMixer5;   //xy=1821,1345
AudioMixer4              filterMixer6;   //xy=1821,1645
AudioMixer4              filterMixer7;   //xy=1821,1945
AudioMixer4              filterMixer8;   //xy=1821,2245
AudioMixer4              filterMixer9;   //xy=1821,2545
AudioMixer4              filterMixer10;  //xy=1821,2845
AudioMixer4              filterMixer11;  //xy=1821,3145
AudioMixer4              filterMixer12;  //xy=1821,3445

AudioEffectEnvelope      ampEnvelope1;   //xy=1996,145
AudioEffectEnvelope      ampEnvelope2;   //xy=1996,445
AudioEffectEnvelope      ampEnvelope3;   //xy=1996,745
AudioEffectEnvelope      ampEnvelope4;   //xy=1996,1045
AudioEffectEnvelope      ampEnvelope5;   //xy=1996,1345
AudioEffectEnvelope      ampEnvelope6;   //xy=1996,1645
AudioEffectEnvelope      ampEnvelope7;   //xy=1996,1945
AudioEffectEnvelope      ampEnvelope8;   //xy=1996,2245
AudioEffectEnvelope      ampEnvelope9;   //xy=1996,2545
AudioEffectEnvelope      ampEnvelope10;  //xy=1996,2845
AudioEffectEnvelope      ampEnvelope11;  //xy=1996,3145
AudioEffectEnvelope      ampEnvelope12;  //xy=1996,3445
*/

PatchShared SharedAudio[12];
Patch Oscillators[12];

AudioConnection          patchCord4(constant1Dc, Oscillators[0].filterEnvelope_);
AudioConnection          patchCord1(constant1Dc, Oscillators[1].filterEnvelope_);
AudioConnection          patchCord2(constant1Dc, Oscillators[2].filterEnvelope_);
AudioConnection          patchCord3(constant1Dc, Oscillators[3].filterEnvelope_);
AudioConnection          patchCord199(constant1Dc, Oscillators[4].filterEnvelope_);
AudioConnection          patchCord200(constant1Dc, Oscillators[5].filterEnvelope_);
AudioConnection          patchCord228(constant1Dc, Oscillators[6].filterEnvelope_);
AudioConnection          patchCord229(constant1Dc, Oscillators[7].filterEnvelope_);
AudioConnection          patchCord230(constant1Dc, Oscillators[8].filterEnvelope_);
AudioConnection          patchCord231(constant1Dc, Oscillators[9].filterEnvelope_);
AudioConnection          patchCord232(constant1Dc, Oscillators[10].filterEnvelope_);
AudioConnection          patchCord233(constant1Dc, Oscillators[11].filterEnvelope_);

// These are now dynamic.
// pwmLfoA_ -> pwMixer_a, 0
// pwmLfoB_ -> pwMixer_b, 0
// pwa_ -> pwMixer_a
// pwb_ -> pwMixer_b
// oscPitchMixer -> oscModMixer_a, 0
// oscPitchMixer -> oscModMixer_b, 0

AudioConnection          patchCord21(SharedAudio[0].pitchLfo, 0, SharedAudio[0].pitchMixer, 1);
AudioConnection          patchCord23(SharedAudio[1].pitchLfo, 0, SharedAudio[1].pitchMixer, 1);
AudioConnection          patchCord485(SharedAudio[2].pitchLfo, 0, SharedAudio[2].pitchMixer, 1);
AudioConnection          patchCord486(SharedAudio[3].pitchLfo, 0, SharedAudio[3].pitchMixer, 1);
AudioConnection          patchCord464(SharedAudio[4].pitchLfo, 0, SharedAudio[4].pitchMixer, 1);
AudioConnection          patchCord465(SharedAudio[5].pitchLfo, 0, SharedAudio[5].pitchMixer, 1);
AudioConnection          patchCord466(SharedAudio[6].pitchLfo, 0, SharedAudio[6].pitchMixer, 1);
AudioConnection          patchCord467(SharedAudio[7].pitchLfo, 0, SharedAudio[7].pitchMixer, 1);
AudioConnection          patchCord469(SharedAudio[8].pitchLfo, 0, SharedAudio[8].pitchMixer, 1);
AudioConnection          patchCord470(SharedAudio[9].pitchLfo, 0, SharedAudio[9].pitchMixer, 1);
AudioConnection          patchCord471(SharedAudio[10].pitchLfo, 0, SharedAudio[10].pitchMixer, 1);
AudioConnection          patchCord472(SharedAudio[11].pitchLfo, 0, SharedAudio[11].pitchMixer, 1);

AudioConnection          patchCord473(SharedAudio[0].pitchBend, 0, SharedAudio[0].pitchMixer, 0);
AudioConnection          patchCord474(SharedAudio[1].pitchBend, 0, SharedAudio[1].pitchMixer, 0);
AudioConnection          patchCord475(SharedAudio[2].pitchBend, 0, SharedAudio[2].pitchMixer, 0);
AudioConnection          patchCord476(SharedAudio[3].pitchBend, 0, SharedAudio[3].pitchMixer, 0);
AudioConnection          patchCord477(SharedAudio[4].pitchBend, 0, SharedAudio[4].pitchMixer, 0);
AudioConnection          patchCord478(SharedAudio[5].pitchBend, 0, SharedAudio[5].pitchMixer, 0);
AudioConnection          patchCord479(SharedAudio[6].pitchBend, 0, SharedAudio[6].pitchMixer, 0);
AudioConnection          patchCord480(SharedAudio[7].pitchBend, 0, SharedAudio[7].pitchMixer, 0);
AudioConnection          patchCord481(SharedAudio[8].pitchBend, 0, SharedAudio[8].pitchMixer, 0);
AudioConnection          patchCord482(SharedAudio[9].pitchBend, 0, SharedAudio[9].pitchMixer, 0);
AudioConnection          patchCord483(SharedAudio[10].pitchBend, 0, SharedAudio[10].pitchMixer, 0);
AudioConnection          patchCord484(SharedAudio[11].pitchBend, 0, SharedAudio[11].pitchMixer, 0);

AudioConnection          patchCord28(Oscillators[0].keytracking_, 0, Oscillators[0].filterModMixer_, 2);
AudioConnection          patchCord29(Oscillators[1].keytracking_, 0, Oscillators[1].filterModMixer_, 2);
AudioConnection          patchCord30(Oscillators[2].keytracking_, 0, Oscillators[2].filterModMixer_, 2);
AudioConnection          patchCord31(Oscillators[3].keytracking_, 0, Oscillators[3].filterModMixer_, 2);
AudioConnection          patchCord149(Oscillators[4].keytracking_, 0, Oscillators[4].filterModMixer_, 2);
AudioConnection          patchCord150(Oscillators[5].keytracking_, 0, Oscillators[5].filterModMixer_, 2);
AudioConnection          patchCord264(Oscillators[6].keytracking_, 0, Oscillators[6].filterModMixer_, 2);
AudioConnection          patchCord265(Oscillators[7].keytracking_, 0, Oscillators[7].filterModMixer_, 2);
AudioConnection          patchCord266(Oscillators[8].keytracking_, 0, Oscillators[8].filterModMixer_, 2);
AudioConnection          patchCord267(Oscillators[9].keytracking_, 0, Oscillators[9].filterModMixer_, 2);
AudioConnection          patchCord268(Oscillators[10].keytracking_, 0, Oscillators[9].filterModMixer_, 2);
AudioConnection          patchCord269(Oscillators[11].keytracking_, 0, Oscillators[11].filterModMixer_, 2);


AudioConnection          patchCord36(Oscillators[0].pwMixer_a, 0, Oscillators[0].waveformMod_a, 1);
AudioConnection          patchCord37(Oscillators[0].pwMixer_b, 0, Oscillators[0].waveformMod_b, 1);
AudioConnection          patchCord49(Oscillators[1].pwMixer_a, 0, Oscillators[1].waveformMod_a, 1);
AudioConnection          patchCord50(Oscillators[1].pwMixer_b, 0, Oscillators[1].waveformMod_b, 1);
AudioConnection          patchCord51(Oscillators[2].pwMixer_a, 0, Oscillators[2].waveformMod_a, 1);
AudioConnection          patchCord38(Oscillators[2].pwMixer_b, 0, Oscillators[2].waveformMod_b, 1);
AudioConnection          patchCord47(Oscillators[3].pwMixer_b, 0, Oscillators[3].waveformMod_b, 1);
AudioConnection          patchCord48(Oscillators[3].pwMixer_a, 0, Oscillators[3].waveformMod_a, 1);
AudioConnection          patchCord165(Oscillators[4].pwMixer_a, 0, Oscillators[4].waveformMod_a, 1);
AudioConnection          patchCord166(Oscillators[4].pwMixer_b, 0, Oscillators[4].waveformMod_b, 1);
AudioConnection          patchCord167(Oscillators[5].pwMixer_a, 0, Oscillators[5].waveformMod_a, 1);
AudioConnection          patchCord168(Oscillators[5].pwMixer_b, 0, Oscillators[5].waveformMod_b, 1);
AudioConnection          patchCord276(Oscillators[6].pwMixer_a, 0, Oscillators[6].waveformMod_a, 1);
AudioConnection          patchCord277(Oscillators[6].pwMixer_b, 0, Oscillators[6].waveformMod_b, 1);
AudioConnection          patchCord278(Oscillators[7].pwMixer_a, 0, Oscillators[7].waveformMod_a, 1);
AudioConnection          patchCord279(Oscillators[7].pwMixer_b, 0, Oscillators[7].waveformMod_b, 1);
AudioConnection          patchCord280(Oscillators[8].pwMixer_a, 0, Oscillators[8].waveformMod_a, 1);
AudioConnection          patchCord281(Oscillators[8].pwMixer_b, 0, Oscillators[8].waveformMod_b, 1);
AudioConnection          patchCord282(Oscillators[9].pwMixer_b, 0, Oscillators[9].waveformMod_b, 1);
AudioConnection          patchCord283(Oscillators[9].pwMixer_a, 0, Oscillators[9].waveformMod_a, 1);
AudioConnection          patchCord284(Oscillators[10].pwMixer_a, 0, Oscillators[10].waveformMod_a, 1);
AudioConnection          patchCord285(Oscillators[10].pwMixer_b, 0, Oscillators[10].waveformMod_b, 1);
AudioConnection          patchCord286(Oscillators[11].pwMixer_a, 0, Oscillators[11].waveformMod_a, 1);
AudioConnection          patchCord287(Oscillators[11].pwMixer_b, 0, Oscillators[11].waveformMod_b, 1);


AudioConnection          patchCord52(Oscillators[0].waveformMod_b, 0,   Oscillators[0].waveformMixer_, 1);
AudioConnection          patchCord53(Oscillators[0].waveformMod_b, 0,   Oscillators[0].oscFX_, 1);
AudioConnection          patchCord54(Oscillators[0].waveformMod_a, 0,   Oscillators[0].waveformMixer_, 0);
AudioConnection          patchCord55(Oscillators[0].waveformMod_a, 0,   Oscillators[0].oscFX_, 0);
AudioConnection          patchCord56(Oscillators[1].waveformMod_b, 0,   Oscillators[1].waveformMixer_, 1);
AudioConnection          patchCord57(Oscillators[1].waveformMod_b, 0,   Oscillators[1].oscFX_, 1);
AudioConnection          patchCord60(Oscillators[1].waveformMod_a, 0,   Oscillators[1].waveformMixer_, 0);
AudioConnection          patchCord61(Oscillators[1].waveformMod_a, 0,   Oscillators[1].oscFX_, 0);
AudioConnection          patchCord64(Oscillators[2].waveformMod_a, 0,   Oscillators[2].oscFX_, 0);
AudioConnection          patchCord65(Oscillators[2].waveformMod_a, 0,   Oscillators[2].waveformMixer_, 0);
AudioConnection          patchCord66(Oscillators[2].waveformMod_b, 0,   Oscillators[2].oscFX_, 1);
AudioConnection          patchCord67(Oscillators[2].waveformMod_b, 0,   Oscillators[2].waveformMixer_, 1);
AudioConnection          patchCord58(Oscillators[3].waveformMod_a, 0,   Oscillators[3].waveformMixer_, 0);
AudioConnection          patchCord59(Oscillators[3].waveformMod_a, 0,   Oscillators[3].oscFX_, 0);
AudioConnection          patchCord62(Oscillators[3].waveformMod_b, 0,   Oscillators[3].waveformMixer_, 1);
AudioConnection          patchCord63(Oscillators[3].waveformMod_b, 0,   Oscillators[3].oscFX_, 1);
AudioConnection          patchCord169(Oscillators[4].waveformMod_a, 0,  Oscillators[4].waveformMixer_, 0);
AudioConnection          patchCord170(Oscillators[4].waveformMod_a, 0,  Oscillators[4].oscFX_, 0);
AudioConnection          patchCord171(Oscillators[4].waveformMod_b, 0,  Oscillators[4].waveformMixer_, 1);
AudioConnection          patchCord172(Oscillators[4].waveformMod_b, 0,  Oscillators[4].oscFX_, 1);
AudioConnection          patchCord173(Oscillators[5].waveformMod_a, 0,  Oscillators[5].waveformMixer_, 0);
AudioConnection          patchCord174(Oscillators[5].waveformMod_a, 0,  Oscillators[5].oscFX_, 0);
AudioConnection          patchCord175(Oscillators[5].waveformMod_b, 0,  Oscillators[5].waveformMixer_, 1);
AudioConnection          patchCord176(Oscillators[5].waveformMod_b, 0,  Oscillators[5].oscFX_, 1);
AudioConnection          patchCord300(Oscillators[6].waveformMod_b, 0,  Oscillators[6].waveformMixer_, 1);
AudioConnection          patchCord301(Oscillators[6].waveformMod_b, 0,  Oscillators[6].oscFX_, 1);
AudioConnection          patchCord302(Oscillators[6].waveformMod_a, 0,  Oscillators[6].waveformMixer_, 0);
AudioConnection          patchCord303(Oscillators[6].waveformMod_a, 0,  Oscillators[6].oscFX_, 0);
AudioConnection          patchCord304(Oscillators[7].waveformMod_b, 0,  Oscillators[7].waveformMixer_, 1);
AudioConnection          patchCord305(Oscillators[7].waveformMod_b, 0,  Oscillators[7].oscFX_, 1);
AudioConnection          patchCord308(Oscillators[7].waveformMod_a, 0,  Oscillators[7].waveformMixer_, 0);
AudioConnection          patchCord309(Oscillators[7].waveformMod_a, 0,  Oscillators[7].oscFX_, 0);
AudioConnection          patchCord312(Oscillators[8].waveformMod_a, 0,  Oscillators[8].oscFX_, 0);
AudioConnection          patchCord313(Oscillators[8].waveformMod_a, 0,  Oscillators[8].waveformMixer_, 0);
AudioConnection          patchCord314(Oscillators[8].waveformMod_b, 0,  Oscillators[8].oscFX_, 1);
AudioConnection          patchCord315(Oscillators[8].waveformMod_b, 0,  Oscillators[8].waveformMixer_, 1);
AudioConnection          patchCord306(Oscillators[9].waveformMod_a, 0, Oscillators[9].waveformMixer_, 0);
AudioConnection          patchCord307(Oscillators[9].waveformMod_a, 0, Oscillators[9].oscFX_, 0);
AudioConnection          patchCord310(Oscillators[9].waveformMod_b, 0, Oscillators[9].waveformMixer_, 1);
AudioConnection          patchCord311(Oscillators[8].waveformMod_b, 0, Oscillators[9].oscFX_, 1);
AudioConnection          patchCord316(Oscillators[10].waveformMod_a, 0, Oscillators[10].waveformMixer_, 0);
AudioConnection          patchCord317(Oscillators[10].waveformMod_a, 0, Oscillators[10].oscFX_, 0);
AudioConnection          patchCord318(Oscillators[10].waveformMod_b, 0, Oscillators[10].waveformMixer_, 1);
AudioConnection          patchCord319(Oscillators[10].waveformMod_b, 0, Oscillators[10].oscFX_, 1);
AudioConnection          patchCord320(Oscillators[11].waveformMod_a, 0, Oscillators[11].waveformMixer_, 0);
AudioConnection          patchCord321(Oscillators[11].waveformMod_a, 0, Oscillators[11].oscFX_, 0);
AudioConnection          patchCord322(Oscillators[11].waveformMod_b, 0, Oscillators[11].waveformMixer_, 1);
AudioConnection          patchCord323(Oscillators[11].waveformMod_b, 0, Oscillators[11].oscFX_, 1);


AudioConnection          patchCord71(Oscillators[0].filterEnvelope_, 0,   Oscillators[0].filterModMixer_, 0);
AudioConnection          patchCord72(Oscillators[0].filterEnvelope_, 0,   Oscillators[0].pwMixer_a, 2);
AudioConnection          patchCord73(Oscillators[0].filterEnvelope_, 0,   Oscillators[0].pwMixer_b, 2);
AudioConnection          patchCord77(Oscillators[1].filterEnvelope_, 0,   Oscillators[1].filterModMixer_, 0);
AudioConnection          patchCord78(Oscillators[1].filterEnvelope_, 0,   Oscillators[1].pwMixer_a, 2);
AudioConnection          patchCord79(Oscillators[1].filterEnvelope_, 0,   Oscillators[1].pwMixer_b, 2);
AudioConnection          patchCord74(Oscillators[2].filterEnvelope_, 0,   Oscillators[2].filterModMixer_, 0);
AudioConnection          patchCord75(Oscillators[2].filterEnvelope_, 0,   Oscillators[2].pwMixer_a, 2);
AudioConnection          patchCord76(Oscillators[2].filterEnvelope_, 0,   Oscillators[2].pwMixer_b, 2);
AudioConnection          patchCord68(Oscillators[3].filterEnvelope_, 0,   Oscillators[3].filterModMixer_, 0);
AudioConnection          patchCord69(Oscillators[3].filterEnvelope_, 0,   Oscillators[3].pwMixer_a, 2);
AudioConnection          patchCord70(Oscillators[3].filterEnvelope_, 0,   Oscillators[3].pwMixer_b, 2);
AudioConnection          patchCord177(Oscillators[4].filterEnvelope_, 0,  Oscillators[4].filterModMixer_, 0);
AudioConnection          patchCord178(Oscillators[4].filterEnvelope_, 0,  Oscillators[4].pwMixer_a, 2);
AudioConnection          patchCord179(Oscillators[4].filterEnvelope_, 0,  Oscillators[4].pwMixer_b, 2);
AudioConnection          patchCord180(Oscillators[5].filterEnvelope_, 0,  Oscillators[5].filterModMixer_, 0);
AudioConnection          patchCord181(Oscillators[5].filterEnvelope_, 0,  Oscillators[5].pwMixer_a, 2);
AudioConnection          patchCord182(Oscillators[5].filterEnvelope_, 0,  Oscillators[5].pwMixer_b, 2);
AudioConnection          patchCord327(Oscillators[6].filterEnvelope_, 0,  Oscillators[6].filterModMixer_, 0);
AudioConnection          patchCord328(Oscillators[6].filterEnvelope_, 0,  Oscillators[6].pwMixer_a, 2);
AudioConnection          patchCord329(Oscillators[6].filterEnvelope_, 0,  Oscillators[6].pwMixer_b, 2);
AudioConnection          patchCord333(Oscillators[7].filterEnvelope_, 0,  Oscillators[7].filterModMixer_, 0);
AudioConnection          patchCord334(Oscillators[7].filterEnvelope_, 0,  Oscillators[7].pwMixer_a, 2);
AudioConnection          patchCord335(Oscillators[7].filterEnvelope_, 0,  Oscillators[7].pwMixer_b, 2);
AudioConnection          patchCord330(Oscillators[8].filterEnvelope_, 0,  Oscillators[8].filterModMixer_, 0);
AudioConnection          patchCord331(Oscillators[8].filterEnvelope_, 0,  Oscillators[8].pwMixer_a, 2);
AudioConnection          patchCord332(Oscillators[8].filterEnvelope_, 0,  Oscillators[8].pwMixer_b, 2);
AudioConnection          patchCord324(Oscillators[9].filterEnvelope_, 0, Oscillators[9].filterModMixer_, 0);
AudioConnection          patchCord325(Oscillators[9].filterEnvelope_, 0, Oscillators[9].pwMixer_a, 2);
AudioConnection          patchCord326(Oscillators[9].filterEnvelope_, 0, Oscillators[9].pwMixer_b, 2);
AudioConnection          patchCord336(Oscillators[10].filterEnvelope_, 0, Oscillators[10].filterModMixer_, 0);
AudioConnection          patchCord337(Oscillators[10].filterEnvelope_, 0, Oscillators[10].pwMixer_a, 2);
AudioConnection          patchCord338(Oscillators[10].filterEnvelope_, 0, Oscillators[10].pwMixer_b, 2);
AudioConnection          patchCord339(Oscillators[11].filterEnvelope_, 0, Oscillators[11].filterModMixer_, 0);
AudioConnection          patchCord340(Oscillators[11].filterEnvelope_, 0, Oscillators[11].pwMixer_a, 2);
AudioConnection          patchCord341(Oscillators[11].filterEnvelope_, 0, Oscillators[11].pwMixer_b, 2);


AudioConnection          patchCord80(Oscillators[0].oscFX_, 0, Oscillators[0].waveformMixer_, 3);
AudioConnection          patchCord81(Oscillators[1].oscFX_, 0, Oscillators[1].waveformMixer_, 3);
AudioConnection          patchCord83(Oscillators[2].oscFX_, 0, Oscillators[2].waveformMixer_, 3);
AudioConnection          patchCord82(Oscillators[3].oscFX_, 0, Oscillators[3].waveformMixer_, 3);
AudioConnection          patchCord183(Oscillators[4].oscFX_, 0, Oscillators[4].waveformMixer_, 3);
AudioConnection          patchCord184(Oscillators[5].oscFX_, 0, Oscillators[5].waveformMixer_, 3);
AudioConnection          patchCord342(Oscillators[6].oscFX_, 0, Oscillators[6].waveformMixer_, 3);
AudioConnection          patchCord343(Oscillators[7].oscFX_, 0, Oscillators[7].waveformMixer_, 3);
AudioConnection          patchCord344(Oscillators[8].oscFX_, 0, Oscillators[8].waveformMixer_, 3);
AudioConnection          patchCord345(Oscillators[9].oscFX_, 0, Oscillators[9].waveformMixer_, 3);
AudioConnection          patchCord346(Oscillators[10].oscFX_, 0, Oscillators[10].waveformMixer_, 3);
AudioConnection          patchCord347(Oscillators[11].oscFX_, 0, Oscillators[11].waveformMixer_, 3);

AudioConnection          patchCord84(Oscillators[0].waveformMixer_, 0, Oscillators[0].filter_, 0);
AudioConnection          patchCord86(Oscillators[0].filterModMixer_, 0, Oscillators[0].filter_, 1);
AudioConnection          patchCord85(Oscillators[1].waveformMixer_, 0, Oscillators[1].filter_, 0);
AudioConnection          patchCord88(Oscillators[1].filterModMixer_, 0, Oscillators[1].filter_, 1);
AudioConnection          patchCord87(Oscillators[2].waveformMixer_, 0, Oscillators[2].filter_, 0);
AudioConnection          patchCord89(Oscillators[2].filterModMixer_, 0, Oscillators[2].filter_, 1);
AudioConnection          patchCord90(Oscillators[3].waveformMixer_, 0, Oscillators[3].filter_, 0);
AudioConnection          patchCord91(Oscillators[3].filterModMixer_, 0, Oscillators[3].filter_, 1);
AudioConnection          patchCord185(Oscillators[4].waveformMixer_, 0, Oscillators[4].filter_, 0);
AudioConnection          patchCord186(Oscillators[4].filterModMixer_, 0, Oscillators[4].filter_, 1);
AudioConnection          patchCord187(Oscillators[5].waveformMixer_, 0, Oscillators[5].filter_, 0);
AudioConnection          patchCord188(Oscillators[5].filterModMixer_, 0, Oscillators[5].filter_, 1);
AudioConnection          patchCord348(Oscillators[6].waveformMixer_, 0, Oscillators[6].filter_, 0);
AudioConnection          patchCord350(Oscillators[6].filterModMixer_, 0, Oscillators[6].filter_, 1);
AudioConnection          patchCord349(Oscillators[7].waveformMixer_, 0, Oscillators[7].filter_, 0);
AudioConnection          patchCord352(Oscillators[7].filterModMixer_, 0, Oscillators[7].filter_, 1);
AudioConnection          patchCord351(Oscillators[8].waveformMixer_, 0, Oscillators[8].filter_, 0);
AudioConnection          patchCord354(Oscillators[8].filterModMixer_, 0, Oscillators[8].filter_, 1);
AudioConnection          patchCord355(Oscillators[9].waveformMixer_, 0, Oscillators[9].filter_, 0);
AudioConnection          patchCord356(Oscillators[9].filterModMixer_, 0, Oscillators[9].filter_, 1);
AudioConnection          patchCord357(Oscillators[10].waveformMixer_, 0, Oscillators[10].filter_, 0);
AudioConnection          patchCord358(Oscillators[10].filterModMixer_, 0, Oscillators[10].filter_, 1);
AudioConnection          patchCord359(Oscillators[11].waveformMixer_, 0, Oscillators[11].filter_, 0);
AudioConnection          patchCord360(Oscillators[11].filterModMixer_, 0, Oscillators[11].filter_, 1);

AudioConnection          patchCord95(Oscillators[0].filter_, 0, Oscillators[0].filterMixer_, 0);
AudioConnection          patchCord96(Oscillators[0].filter_, 1, Oscillators[0].filterMixer_, 1);
AudioConnection          patchCord97(Oscillators[0].filter_, 2, Oscillators[0].filterMixer_, 2);
AudioConnection          patchCord92(Oscillators[1].filter_, 0, Oscillators[1].filterMixer_, 0);
AudioConnection          patchCord93(Oscillators[1].filter_, 1, Oscillators[1].filterMixer_, 1);
AudioConnection          patchCord94(Oscillators[1].filter_, 2, Oscillators[1].filterMixer_, 2);
AudioConnection          patchCord98(Oscillators[2].filter_, 0, Oscillators[2].filterMixer_, 0);
AudioConnection          patchCord99(Oscillators[2].filter_, 1, Oscillators[2].filterMixer_, 1);
AudioConnection          patchCord100(Oscillators[2].filter_, 2, Oscillators[2].filterMixer_, 2);
AudioConnection          patchCord101(Oscillators[3].filter_, 0, Oscillators[3].filterMixer_, 0);
AudioConnection          patchCord102(Oscillators[3].filter_, 1, Oscillators[3].filterMixer_, 1);
AudioConnection          patchCord103(Oscillators[3].filter_, 2, Oscillators[3].filterMixer_, 2);
AudioConnection          patchCord201(Oscillators[4].filter_, 0, Oscillators[4].filterMixer_, 0);
AudioConnection          patchCord189(Oscillators[4].filter_, 1, Oscillators[4].filterMixer_, 1);
AudioConnection          patchCord190(Oscillators[4].filter_, 2, Oscillators[4].filterMixer_, 2);
AudioConnection          patchCord202(Oscillators[5].filter_, 0, Oscillators[5].filterMixer_, 0);
AudioConnection          patchCord191(Oscillators[5].filter_, 1, Oscillators[5].filterMixer_, 1);
AudioConnection          patchCord192(Oscillators[5].filter_, 2, Oscillators[5].filterMixer_, 2);
AudioConnection          patchCord364(Oscillators[6].filter_, 0, Oscillators[6].filterMixer_, 0);
AudioConnection          patchCord365(Oscillators[6].filter_, 1, Oscillators[6].filterMixer_, 1);
AudioConnection          patchCord366(Oscillators[6].filter_, 2, Oscillators[6].filterMixer_, 2);
AudioConnection          patchCord361(Oscillators[7].filter_, 0, Oscillators[7].filterMixer_, 0);
AudioConnection          patchCord362(Oscillators[7].filter_, 1, Oscillators[7].filterMixer_, 1);
AudioConnection          patchCord363(Oscillators[7].filter_, 2, Oscillators[7].filterMixer_, 2);
AudioConnection          patchCord367(Oscillators[8].filter_, 0, Oscillators[8].filterMixer_, 0);
AudioConnection          patchCord368(Oscillators[8].filter_, 1, Oscillators[8].filterMixer_, 1);
AudioConnection          patchCord369(Oscillators[8].filter_, 2, Oscillators[8].filterMixer_, 2);
AudioConnection          patchCord370(Oscillators[9].filter_, 0, Oscillators[9].filterMixer_, 0);
AudioConnection          patchCord371(Oscillators[9].filter_, 1, Oscillators[9].filterMixer_, 1);
AudioConnection          patchCord372(Oscillators[9].filter_, 2, Oscillators[9].filterMixer_, 2);
AudioConnection          patchCord373(Oscillators[10].filter_, 0, Oscillators[10].filterMixer_, 0);
AudioConnection          patchCord374(Oscillators[10].filter_, 1, Oscillators[10].filterMixer_, 1);
AudioConnection          patchCord375(Oscillators[10].filter_, 2, Oscillators[10].filterMixer_, 2);
AudioConnection          patchCord376(Oscillators[11].filter_, 0, Oscillators[11].filterMixer_, 0);
AudioConnection          patchCord377(Oscillators[11].filter_, 1, Oscillators[11].filterMixer_, 1);
AudioConnection          patchCord378(Oscillators[11].filter_, 2, Oscillators[11].filterMixer_, 2);


AudioConnection          patchCord106(Oscillators[0].filterMixer_, Oscillators[0].ampEnvelope_);
AudioConnection          patchCord104(Oscillators[1].filterMixer_, Oscillators[1].ampEnvelope_);
AudioConnection          patchCord105(Oscillators[2].filterMixer_, Oscillators[2].ampEnvelope_);
AudioConnection          patchCord107(Oscillators[3].filterMixer_, Oscillators[3].ampEnvelope_);
AudioConnection          patchCord193(Oscillators[4].filterMixer_, Oscillators[4].ampEnvelope_);
AudioConnection          patchCord194(Oscillators[5].filterMixer_, Oscillators[5].ampEnvelope_);
AudioConnection          patchCord222(Oscillators[6].filterMixer_, Oscillators[6].ampEnvelope_);
AudioConnection          patchCord223(Oscillators[7].filterMixer_, Oscillators[7].ampEnvelope_);
AudioConnection          patchCord224(Oscillators[8].filterMixer_, Oscillators[8].ampEnvelope_);
AudioConnection          patchCord225(Oscillators[9].filterMixer_, Oscillators[9].ampEnvelope_);
AudioConnection          patchCord226(Oscillators[10].filterMixer_, Oscillators[10].ampEnvelope_);
AudioConnection          patchCord227(Oscillators[11].filterMixer_, Oscillators[11].ampEnvelope_);

AudioConnection          patchCord1000(SharedAudio[0].voiceMixer1, 0, SharedAudio[0].voiceMixerM, 0);
AudioConnection          patchCord1001(SharedAudio[0].voiceMixer2, 0, SharedAudio[0].voiceMixerM, 1);
AudioConnection          patchCord1002(SharedAudio[0].voiceMixer3, 0, SharedAudio[0].voiceMixerM, 2);
AudioConnection          patchCord1003(SharedAudio[1].voiceMixer1, 0, SharedAudio[1].voiceMixerM, 0);
AudioConnection          patchCord1004(SharedAudio[1].voiceMixer2, 0, SharedAudio[1].voiceMixerM, 1);
AudioConnection          patchCord1005(SharedAudio[1].voiceMixer3, 0, SharedAudio[1].voiceMixerM, 2);
/*
AudioConnection          patchCord1006(voiceMixer1_3, 0, voiceMixerM_3, 0);
AudioConnection          patchCord1007(voiceMixer2_3, 0, voiceMixerM_3, 1);
AudioConnection          patchCord1008(voiceMixer3_3, 0, voiceMixerM_3, 2);
AudioConnection          patchCord1009(voiceMixer1_4, 0, voiceMixerM_4, 0);
AudioConnection          patchCord1010(voiceMixer2_4, 0, voiceMixerM_4, 1);
AudioConnection          patchCord1011(voiceMixer3_4, 0, voiceMixerM_4, 2);
AudioConnection          patchCord1012(voiceMixer1_5, 0, voiceMixerM_5, 0);
AudioConnection          patchCord1013(voiceMixer2_5, 0, voiceMixerM_5, 1);
AudioConnection          patchCord1014(voiceMixer3_5, 0, voiceMixerM_5, 2);
AudioConnection          patchCord1015(voiceMixer1_6, 0, voiceMixerM_6, 0);
AudioConnection          patchCord1016(voiceMixer2_6, 0, voiceMixerM_6, 1);
AudioConnection          patchCord1017(voiceMixer3_6, 0, voiceMixerM_6, 2);
AudioConnection          patchCord1018(voiceMixer1_7, 0, voiceMixerM_7, 0);
AudioConnection          patchCord1019(voiceMixer2_7, 0, voiceMixerM_7, 1);
AudioConnection          patchCord1020(voiceMixer3_7, 0, voiceMixerM_7, 2);
AudioConnection          patchCord1021(voiceMixer1_8, 0, voiceMixerM_8, 0);
AudioConnection          patchCord1022(voiceMixer2_8, 0, voiceMixerM_8, 1);
AudioConnection          patchCord1023(voiceMixer3_8, 0, voiceMixerM_8, 2);
AudioConnection          patchCord1024(voiceMixer1_9, 0, voiceMixerM_9, 0);
AudioConnection          patchCord1025(voiceMixer2_9, 0, voiceMixerM_9, 1);
AudioConnection          patchCord1026(voiceMixer3_9, 0, voiceMixerM_9, 2);
AudioConnection          patchCord1027(voiceMixer1_10, 0, voiceMixerM_10, 0);
AudioConnection          patchCord1028(voiceMixer2_10, 1, voiceMixerM_10, 2);
AudioConnection          patchCord1029(voiceMixer3_10, 1, voiceMixerM_10, 3);
AudioConnection          patchCord1030(voiceMixer1_11, 0, voiceMixerM_11, 0);
AudioConnection          patchCord1031(voiceMixer2_11, 1, voiceMixerM_11, 2);
AudioConnection          patchCord1032(voiceMixer3_11, 1, voiceMixerM_11, 3);
AudioConnection          patchCord1033(voiceMixer1_12, 0, voiceMixerM_12, 0);
AudioConnection          patchCord1034(voiceMixer2_12, 1, voiceMixerM_12, 2);
AudioConnection          patchCord1035(voiceMixer3_12, 1, voiceMixerM_12, 3);
*/

AudioConnection          patchCord2001(SharedAudio[0].voiceMixerM, 0, SharedAudio[0].ensemble, 0);
AudioConnection          patchCord2002(SharedAudio[1].voiceMixerM, 0, SharedAudio[1].ensemble, 0);
/*
AudioConnection          patchCord2003(voiceMixerM_3, 0, ensemble3, 0);
AudioConnection          patchCord2004(voiceMixerM_4, 0, ensemble4, 0);
AudioConnection          patchCord2005(voiceMixerM_5, 0, ensemble5, 0);
AudioConnection          patchCord2006(voiceMixerM_6, 0, ensemble6, 0);
AudioConnection          patchCord2007(voiceMixerM_7, 0, ensemble7, 0);
AudioConnection          patchCord2008(voiceMixerM_8, 0, ensemble8, 0);
AudioConnection          patchCord2009(voiceMixerM_9, 0, ensemble9, 0);
AudioConnection          patchCord2010(voiceMixerM_10, 0, ensemble10, 0);
AudioConnection          patchCord2011(voiceMixerM_11, 0, ensemble11, 0);
AudioConnection          patchCord2012(voiceMixerM_12, 0, ensemble12, 0);
*/

AudioConnection          patchCord111(SharedAudio[0].ensemble, 0, voiceMixer1L, 0);
AudioConnection          patchCord3111(SharedAudio[0].ensemble, 0, voiceMixer1R, 0);
AudioConnection          patchCord108(SharedAudio[1].ensemble, 0, voiceMixer1L, 1);
AudioConnection          patchCord3108(SharedAudio[1].ensemble, 0, voiceMixer1R, 1);
/*
AudioConnection          patchCord109(ensemble3, 0, voiceMixer1L, 2);
AudioConnection          patchCord3109(ensemble3, 0, voiceMixer1R, 2);
AudioConnection          patchCord110(ensemble4, 0, voiceMixer1L, 3);
AudioConnection          patchCord3110(ensemble4, 0, voiceMixer1R, 3);
AudioConnection          patchCord195(ensemble5, 0, voiceMixer2L, 0);
AudioConnection          patchCord3195(ensemble5, 0, voiceMixer2R, 0);
AudioConnection          patchCord196(ensemble6, 0, voiceMixer2L, 1);
AudioConnection          patchCord3196(ensemble6, 0, voiceMixer2R, 1);
AudioConnection          patchCord216(ensemble7, 0, voiceMixer2L, 2);
AudioConnection          patchCord3216(ensemble7, 0, voiceMixer2R, 2);
AudioConnection          patchCord217(ensemble8, 0, voiceMixer2L, 3);
AudioConnection          patchCord3217(ensemble8, 0, voiceMixer2R, 3);
AudioConnection          patchCord218(ensemble9, 0, voiceMixer3L, 0);
AudioConnection          patchCord3218(ensemble9, 0, voiceMixer3R, 0);
AudioConnection          patchCord219(ensemble10, 0, voiceMixer3L, 1);
AudioConnection          patchCord3219(ensemble10, 0, voiceMixer3R, 1);
AudioConnection          patchCord220(ensemble11, 0, voiceMixer3L, 2);
AudioConnection          patchCord3220(ensemble11, 0, voiceMixer3R, 2);
AudioConnection          patchCord221(ensemble12, 0, voiceMixer3L, 3);
AudioConnection          patchCord3221(ensemble12, 0, voiceMixer3R, 3);
*/

//Mod sources
AudioConnection          patchCord121(Oscillators[0].oscModMixer_a, 0, Oscillators[0].waveformMod_a, 0);
AudioConnection          patchCord122(Oscillators[0].oscModMixer_b, 0, Oscillators[0].waveformMod_b, 0);
AudioConnection          patchCord123(Oscillators[1].oscModMixer_a, 0, Oscillators[1].waveformMod_a, 0);
AudioConnection          patchCord124(Oscillators[1].oscModMixer_b, 0, Oscillators[1].waveformMod_b, 0);
AudioConnection          patchCord125(Oscillators[2].oscModMixer_a, 0, Oscillators[2].waveformMod_a, 0);
AudioConnection          patchCord126(Oscillators[2].oscModMixer_b, 0, Oscillators[2].waveformMod_b, 0);
AudioConnection          patchCord127(Oscillators[3].oscModMixer_a, 0, Oscillators[3].waveformMod_a, 0);
AudioConnection          patchCord128(Oscillators[3].oscModMixer_b, 0, Oscillators[3].waveformMod_b, 0);
AudioConnection          patchCord157(Oscillators[4].oscModMixer_a, 0, Oscillators[4].waveformMod_a, 0);
AudioConnection          patchCord158(Oscillators[4].oscModMixer_b, 0, Oscillators[4].waveformMod_b, 0);
AudioConnection          patchCord159(Oscillators[5].oscModMixer_a, 0, Oscillators[5].waveformMod_a, 0);
AudioConnection          patchCord160(Oscillators[5].oscModMixer_b, 0, Oscillators[5].waveformMod_b, 0);
AudioConnection          patchCord379(Oscillators[6].oscModMixer_a, 0, Oscillators[6].waveformMod_a, 0);
AudioConnection          patchCord380(Oscillators[6].oscModMixer_b, 0, Oscillators[6].waveformMod_b, 0);
AudioConnection          patchCord381(Oscillators[7].oscModMixer_a, 0, Oscillators[7].waveformMod_a, 0);
AudioConnection          patchCord382(Oscillators[7].oscModMixer_b, 0, Oscillators[7].waveformMod_b, 0);
AudioConnection          patchCord383(Oscillators[8].oscModMixer_a, 0, Oscillators[8].waveformMod_a, 0);
AudioConnection          patchCord384(Oscillators[8].oscModMixer_b, 0, Oscillators[8].waveformMod_b, 0);
AudioConnection          patchCord385(Oscillators[9].oscModMixer_a, 0, Oscillators[9].waveformMod_a, 0);
AudioConnection          patchCord386(Oscillators[9].oscModMixer_b, 0, Oscillators[9].waveformMod_b, 0);
AudioConnection          patchCord387(Oscillators[10].oscModMixer_a, 0, Oscillators[10].waveformMod_a, 0);
AudioConnection          patchCord388(Oscillators[10].oscModMixer_b, 0, Oscillators[10].waveformMod_b, 0);
AudioConnection          patchCord389(Oscillators[11].oscModMixer_a, 0, Oscillators[11].waveformMod_a, 0);
AudioConnection          patchCord390(Oscillators[11].oscModMixer_b, 0, Oscillators[11].waveformMod_b, 0);

//Pitch env
AudioConnection          patchCord129(Oscillators[0].filterEnvelope_, 0, Oscillators[0].oscModMixer_a, 1);
AudioConnection          patchCord130(Oscillators[0].filterEnvelope_, 0, Oscillators[0].oscModMixer_b, 1);
AudioConnection          patchCord131(Oscillators[1].filterEnvelope_, 0, Oscillators[1].oscModMixer_a, 1);
AudioConnection          patchCord132(Oscillators[1].filterEnvelope_, 0, Oscillators[1].oscModMixer_b, 1);
AudioConnection          patchCord133(Oscillators[2].filterEnvelope_, 0, Oscillators[2].oscModMixer_a, 1);
AudioConnection          patchCord134(Oscillators[2].filterEnvelope_, 0, Oscillators[2].oscModMixer_b, 1);
AudioConnection          patchCord135(Oscillators[3].filterEnvelope_, 0, Oscillators[3].oscModMixer_a, 1);
AudioConnection          patchCord136(Oscillators[3].filterEnvelope_, 0, Oscillators[3].oscModMixer_b, 1);
AudioConnection          patchCord161(Oscillators[4].filterEnvelope_, 0, Oscillators[4].oscModMixer_a, 1);
AudioConnection          patchCord162(Oscillators[4].filterEnvelope_, 0, Oscillators[4].oscModMixer_b, 1);
AudioConnection          patchCord163(Oscillators[5].filterEnvelope_, 0, Oscillators[5].oscModMixer_a, 1);
AudioConnection          patchCord164(Oscillators[5].filterEnvelope_, 0, Oscillators[5].oscModMixer_b, 1);
AudioConnection          patchCord391(Oscillators[6].filterEnvelope_, 0, Oscillators[6].oscModMixer_a, 1);
AudioConnection          patchCord392(Oscillators[6].filterEnvelope_, 0, Oscillators[6].oscModMixer_b, 1);
AudioConnection          patchCord393(Oscillators[7].filterEnvelope_, 0, Oscillators[7].oscModMixer_a, 1);
AudioConnection          patchCord394(Oscillators[7].filterEnvelope_, 0, Oscillators[7].oscModMixer_b, 1);
AudioConnection          patchCord395(Oscillators[8].filterEnvelope_, 0, Oscillators[8].oscModMixer_a, 1);
AudioConnection          patchCord396(Oscillators[8].filterEnvelope_, 0, Oscillators[8].oscModMixer_b, 1);
AudioConnection          patchCord397(Oscillators[9].filterEnvelope_, 0, Oscillators[9].oscModMixer_a, 1);
AudioConnection          patchCord398(Oscillators[9].filterEnvelope_, 0, Oscillators[9].oscModMixer_b, 1);
AudioConnection          patchCord399(Oscillators[10].filterEnvelope_, 0, Oscillators[10].oscModMixer_a, 1);
AudioConnection          patchCord400(Oscillators[10].filterEnvelope_, 0, Oscillators[10].oscModMixer_b, 1);
AudioConnection          patchCord401(Oscillators[11].filterEnvelope_, 0, Oscillators[11].oscModMixer_a, 1);
AudioConnection          patchCord402(Oscillators[11].filterEnvelope_, 0, Oscillators[11].oscModMixer_b, 1);

//Glide
AudioConnection          patchCord22(Oscillators[0].glide_, 0, Oscillators[0].oscModMixer_a, 2);
AudioConnection          patchCord204(Oscillators[0].glide_, 0, Oscillators[0].oscModMixer_b, 2);
AudioConnection          patchCord205(Oscillators[1].glide_, 0, Oscillators[1].oscModMixer_a, 2);
AudioConnection          patchCord206(Oscillators[1].glide_, 0, Oscillators[1].oscModMixer_b, 2);
AudioConnection          patchCord207(Oscillators[2].glide_, 0, Oscillators[2].oscModMixer_a, 2);
AudioConnection          patchCord208(Oscillators[2].glide_, 0, Oscillators[2].oscModMixer_b, 2);
AudioConnection          patchCord209(Oscillators[3].glide_, 0, Oscillators[3].oscModMixer_a, 2);
AudioConnection          patchCord210(Oscillators[3].glide_, 0, Oscillators[3].oscModMixer_b, 2);
AudioConnection          patchCord211(Oscillators[4].glide_, 0, Oscillators[4].oscModMixer_a, 2);
AudioConnection          patchCord212(Oscillators[4].glide_, 0, Oscillators[4].oscModMixer_b, 2);
AudioConnection          patchCord213(Oscillators[5].glide_, 0, Oscillators[5].oscModMixer_a, 2);
AudioConnection          patchCord214(Oscillators[5].glide_, 0, Oscillators[5].oscModMixer_b, 2);
AudioConnection          patchCord403(Oscillators[6].glide_, 0, Oscillators[6].oscModMixer_a, 2);
AudioConnection          patchCord404(Oscillators[6].glide_, 0, Oscillators[6].oscModMixer_b, 2);
AudioConnection          patchCord405(Oscillators[7].glide_, 0, Oscillators[7].oscModMixer_a, 2);
AudioConnection          patchCord406(Oscillators[7].glide_, 0, Oscillators[7].oscModMixer_b, 2);
AudioConnection          patchCord407(Oscillators[8].glide_, 0, Oscillators[8].oscModMixer_a, 2);
AudioConnection          patchCord408(Oscillators[8].glide_, 0, Oscillators[8].oscModMixer_b, 2);
AudioConnection          patchCord409(Oscillators[9].glide_, 0, Oscillators[9].oscModMixer_a, 2);
AudioConnection          patchCord410(Oscillators[9].glide_, 0, Oscillators[9].oscModMixer_b, 2);
AudioConnection          patchCord411(Oscillators[10].glide_, 0, Oscillators[10].oscModMixer_a, 2);
AudioConnection          patchCord412(Oscillators[10].glide_, 0, Oscillators[10].oscModMixer_b, 2);
AudioConnection          patchCord413(Oscillators[11].glide_, 0, Oscillators[11].oscModMixer_a, 2);
AudioConnection          patchCord414(Oscillators[11].glide_, 0, Oscillators[11].oscModMixer_b, 2);

//X Mod
AudioConnection          patchCord417(Oscillators[0].waveformMod_b, 0, Oscillators[0].oscModMixer_a, 3);
AudioConnection          patchCord429(Oscillators[0].waveformMod_a, 0, Oscillators[0].oscModMixer_b, 3);
AudioConnection          patchCord418(Oscillators[1].waveformMod_b, 0, Oscillators[1].oscModMixer_a, 3);
AudioConnection          patchCord430(Oscillators[1].waveformMod_a, 0, Oscillators[1].oscModMixer_b, 3);
AudioConnection          patchCord419(Oscillators[2].waveformMod_b, 0, Oscillators[2].oscModMixer_a, 3);
AudioConnection          patchCord431(Oscillators[2].waveformMod_a, 0, Oscillators[2].oscModMixer_b, 3);
AudioConnection          patchCord420(Oscillators[3].waveformMod_b, 0, Oscillators[3].oscModMixer_a, 3);
AudioConnection          patchCord432(Oscillators[3].waveformMod_a, 0, Oscillators[3].oscModMixer_b, 3);
AudioConnection          patchCord421(Oscillators[4].waveformMod_b, 0, Oscillators[4].oscModMixer_a, 3);
AudioConnection          patchCord433(Oscillators[4].waveformMod_a, 0, Oscillators[4].oscModMixer_b, 3);
AudioConnection          patchCord422(Oscillators[5].waveformMod_b, 0, Oscillators[5].oscModMixer_a, 3);
AudioConnection          patchCord434(Oscillators[5].waveformMod_a, 0, Oscillators[5].oscModMixer_b, 3);
AudioConnection          patchCord423(Oscillators[6].waveformMod_b, 0, Oscillators[6].oscModMixer_a, 3);
AudioConnection          patchCord435(Oscillators[6].waveformMod_a, 0, Oscillators[6].oscModMixer_b, 3);
AudioConnection          patchCord424(Oscillators[7].waveformMod_b, 0, Oscillators[7].oscModMixer_a, 3);
AudioConnection          patchCord436(Oscillators[7].waveformMod_a, 0, Oscillators[7].oscModMixer_b, 3);
AudioConnection          patchCord425(Oscillators[8].waveformMod_b, 0, Oscillators[8].oscModMixer_a, 3);
AudioConnection          patchCord437(Oscillators[8].waveformMod_a, 0, Oscillators[8].oscModMixer_b, 3);
AudioConnection          patchCord426(Oscillators[9].waveformMod_b, 0, Oscillators[9].oscModMixer_a, 3);
AudioConnection          patchCord438(Oscillators[9].waveformMod_a, 0, Oscillators[9].oscModMixer_b, 3);
AudioConnection          patchCord427(Oscillators[10].waveformMod_b, 0, Oscillators[10].oscModMixer_a, 3);
AudioConnection          patchCord439(Oscillators[10].waveformMod_a, 0, Oscillators[10].oscModMixer_b, 3);
AudioConnection          patchCord428(Oscillators[11].waveformMod_b, 0, Oscillators[11].oscModMixer_a, 3);
AudioConnection          patchCord440(Oscillators[11].waveformMod_a, 0, Oscillators[11].oscModMixer_b, 3);

//Noise
AudioConnection          patchCord452(pink, 0, SharedAudio[0].noiseMixer, 0);
AudioConnection          patchCord453(pink, 0, SharedAudio[1].noiseMixer, 0);
AudioConnection          patchCord454(pink, 0, SharedAudio[2].noiseMixer, 0);
AudioConnection          patchCord455(pink, 0, SharedAudio[3].noiseMixer, 0);
AudioConnection          patchCord456(pink, 0, SharedAudio[4].noiseMixer, 0);
AudioConnection          patchCord457(pink, 0, SharedAudio[5].noiseMixer, 0);
AudioConnection          patchCord458(pink, 0, SharedAudio[6].noiseMixer, 0);
AudioConnection          patchCord459(pink, 0, SharedAudio[7].noiseMixer, 0);
AudioConnection          patchCord460(pink, 0, SharedAudio[8].noiseMixer, 0);
AudioConnection          patchCord461(pink, 0, SharedAudio[9].noiseMixer, 0);
AudioConnection          patchCord462(pink, 0, SharedAudio[10].noiseMixer, 0);
AudioConnection          patchCord463(pink, 0, SharedAudio[11].noiseMixer, 0);

AudioConnection          patchCord137(white, 0, SharedAudio[0].noiseMixer, 1);
AudioConnection          patchCord138(white, 0, SharedAudio[1].noiseMixer, 1);
AudioConnection          patchCord442(white, 0, SharedAudio[2].noiseMixer, 1);
AudioConnection          patchCord443(white, 0, SharedAudio[3].noiseMixer, 1);
AudioConnection          patchCord444(white, 0, SharedAudio[4].noiseMixer, 1);
AudioConnection          patchCord445(white, 0, SharedAudio[5].noiseMixer, 1);
AudioConnection          patchCord446(white, 0, SharedAudio[6].noiseMixer, 1);
AudioConnection          patchCord447(white, 0, SharedAudio[7].noiseMixer, 1);
AudioConnection          patchCord448(white, 0, SharedAudio[8].noiseMixer, 1);
AudioConnection          patchCord449(white, 0, SharedAudio[9].noiseMixer, 1);
AudioConnection          patchCord450(white, 0, SharedAudio[10].noiseMixer, 1);
AudioConnection          patchCord451(white, 0, SharedAudio[11].noiseMixer, 1);

AudioConnection          patchCord197(voiceMixer1L, 0, voiceMixerML, 0);
AudioConnection          patchCord198(voiceMixer2L, 0, voiceMixerML, 1);
AudioConnection          patchCord215(voiceMixer3L, 0, voiceMixerML, 2);
AudioConnection          patchCord3197(voiceMixer1R, 0, voiceMixerMR, 0);
AudioConnection          patchCord3198(voiceMixer2R, 0, voiceMixerMR, 1);
AudioConnection          patchCord3215(voiceMixer3R, 0, voiceMixerMR, 2);
//AudioConnection          patchCord203(voiceMixerM, 0, dcOffsetFilter, 0);
//AudioConnection          patchCord203(voiceMixerM, 0, ensemble, 0);

AudioConnection          patchCord2203(voiceMixerML, 0, dcOffsetFilterL, 0);
AudioConnection          patchCord2204(voiceMixerMR, 1, dcOffsetFilterR, 0);

AudioConnection          patchCord441(dcOffsetFilterL, 2, volumeMixerL, 0);
AudioConnection          patchCord4441(dcOffsetFilterR, 2, volumeMixerR, 0);

//AudioConnection          patchCord441(dcOffsetFilter, 2, volumeMixer, 0);
//AudioConnection          patchCord112(volumeMixer, 0, ensemble, 0);
AudioConnection          patchCord415(dcOffsetFilterL, 2, scope, 0);
AudioConnection          patchCord416(dcOffsetFilterL, 2, peak, 0);
//AudioConnection          patchCord113(ensemble, 0, effectMixerL, 1);
//AudioConnection          patchCord114(ensemble, 1, effectMixerR, 1);
AudioConnection          patchCord115(volumeMixerL, 0, effectMixerL, 0);
AudioConnection          patchCord116(volumeMixerR, 0, effectMixerR, 0);
AudioConnection          patchCord117(effectMixerR, 0, usbAudio, 1);
AudioConnection          patchCord118(effectMixerR, 0, i2s, 1);
AudioConnection          patchCord119(effectMixerL, 0, i2s, 0);
AudioConnection          patchCord120(effectMixerL, 0, usbAudio, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=2353,505
// GUItool: end automatically generated code

/*
PatchShared SharedAudio[12] = {
    {
        pitchBend1,
        pitchLfo1,
        oscPitchMixer1,
        pwmLfoA1,
        pwmLfoB1,
        filterLfo1,
        pwa1,
        pwb1,
        noiseMixer1,
        voiceMixer1_1,
        voiceMixer2_1,
        voiceMixer3_1,
        voiceMixerM_1,
        ensemble1
    },
    {
        pitchBend2,
        pitchLfo2,
        oscPitchMixer2,
        pwmLfoA2,
        pwmLfoB2,
        filterLfo2,
        pwa2,
        pwb2,
        noiseMixer2,
        voiceMixer1_2,
        voiceMixer2_2,
        voiceMixer3_2,
        voiceMixerM_2,
        ensemble2
    },
    {
        pitchBend3,
        pitchLfo3,
        oscPitchMixer3,
        pwmLfoA3,
        pwmLfoB3,
        filterLfo3,
        pwa3,
        pwb3,
        noiseMixer3,
        voiceMixer1_3,
        voiceMixer2_3,
        voiceMixer3_3,
        voiceMixerM_3,
        ensemble3
    },
    {
        pitchBend4,
        pitchLfo4,
        oscPitchMixer4,
        pwmLfoA4,
        pwmLfoB4,
        filterLfo4,
        pwa4,
        pwb4,
        noiseMixer4,
        voiceMixer1_4,
        voiceMixer2_4,
        voiceMixer3_4,
        voiceMixerM_4,
        ensemble4
    },
    {
        pitchBend5,
        pitchLfo5,
        oscPitchMixer5,
        pwmLfoA5,
        pwmLfoB5,
        filterLfo5,
        pwa5,
        pwb5,
        noiseMixer5,
        voiceMixer1_5,
        voiceMixer2_5,
        voiceMixer3_5,
        voiceMixerM_5,
        ensemble5
    },
    {
        pitchBend6,
        pitchLfo6,
        oscPitchMixer6,
        pwmLfoA6,
        pwmLfoB6,
        filterLfo6,
        pwa6,
        pwb6,
        noiseMixer6,
        voiceMixer1_6,
        voiceMixer2_6,
        voiceMixer3_6,
        voiceMixerM_6,
        ensemble6
    },
    {
        pitchBend7,
        pitchLfo7,
        oscPitchMixer7,
        pwmLfoA7,
        pwmLfoB7,
        filterLfo7,
        pwa7,
        pwb7,
        noiseMixer7,
        voiceMixer1_7,
        voiceMixer2_7,
        voiceMixer3_7,
        voiceMixerM_7,
        ensemble7
    },
    {
        pitchBend8,
        pitchLfo8,
        oscPitchMixer8,
        pwmLfoA8,
        pwmLfoB8,
        filterLfo8,
        pwa8,
        pwb8,
        noiseMixer8,
        voiceMixer1_8,
        voiceMixer2_8,
        voiceMixer3_8,
        voiceMixerM_8,
        ensemble8
    },
    {
        pitchBend9,
        pitchLfo9,
        oscPitchMixer9,
        pwmLfoA9,
        pwmLfoB9,
        filterLfo9,
        pwa9,
        pwb9,
        noiseMixer9,
        voiceMixer1_9,
        voiceMixer2_9,
        voiceMixer3_9,
        voiceMixerM_9,
        ensemble9
    },
    {
        pitchBend10,
        pitchLfo10,
        oscPitchMixer10,
        pwmLfoA10,
        pwmLfoB10,
        filterLfo10,
        pwa10,
        pwb9,
        noiseMixer10,
        voiceMixer1_10,
        voiceMixer2_10,
        voiceMixer3_10,
        voiceMixerM_10,
        ensemble10
    },
    {
        pitchBend11,
        pitchLfo11,
        oscPitchMixer11,
        pwmLfoA11,
        pwmLfoB11,
        filterLfo11,
        pwa11,
        pwb9,
        noiseMixer11,
        voiceMixer1_11,
        voiceMixer2_11,
        voiceMixer3_11,
        voiceMixerM_11,
        ensemble11
    },
    {
        pitchBend12,
        pitchLfo12,
        oscPitchMixer12,
        pwmLfoA12,
        pwmLfoB12,
        filterLfo12,
        pwa12,
        pwb9,
        noiseMixer12,
        voiceMixer1_12,
        voiceMixer2_12,
        voiceMixer3_12,
        voiceMixerM_12,
        ensemble12
    }
};


//AudioSynthWaveform* filterLfo[12] = {&filterLfo1, &filterLfo2, &filterLfo}
//AudioSynthWaveformDc* pwa[12] = {&pwa1, &pwa2, &pwa3, &pwa4, &pwa5, &pwa6, &pwa7, &pwa8, &pwa9, &pwa10, &pwa11, &pwa12 };
//AudioSynthWaveformDc* pwb[12] = {&pwb1, &pwb2, &pwb3, &pwb4, &pwb5, &pwb6, &pwb7, &pwb8, &pwb9, &pwb10, &pwb11, &pwb12 };
//AudioMixer4* noiseMixer[12] = {&noiseMixer1, &noiseMixer2, &noiseMixer3, &noiseMixer4, &noiseMixer5, &noiseMixer6, &noiseMixer7, &noiseMixer8, &noiseMixer9, &noiseMixer10, &noiseMixer11, &noiseMixer12 };

// The 12 oscillator pairs in one data structure to allow for easier programming.
Patch Oscillators[12] = {
    {
        filterEnvelope1,
        pwMixer1a,
        pwMixer1b,
        glide1,
        keytracking1,
        oscModMixer1a,
        oscModMixer1b,
        filterLfo1,
        waveformMod1a,
        waveformMod1b,
        oscFX1,
        waveformMixer1,
        filterModMixer1,
        filter1,
        filterMixer1,
        ampEnvelope1,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope2,
        pwMixer2a,
        pwMixer2b,
        glide2,
        keytracking2,
        oscModMixer2a,
        oscModMixer2b,
        filterLfo2,
        waveformMod2a,
        waveformMod2b,
        oscFX2,
        waveformMixer2,
        filterModMixer2,
        filter2,
        filterMixer2,
        ampEnvelope2,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope3,
        pwMixer3a,
        pwMixer3b,
        glide3,
        keytracking3,
        oscModMixer3a,
        oscModMixer3b,
        filterLfo3,
        waveformMod3a,
        waveformMod3b,
        oscFX3,
        waveformMixer3,
        filterModMixer3,
        filter3,
        filterMixer3,
        ampEnvelope3,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope4,
        pwMixer4a,
        pwMixer4b,
        glide4,
        keytracking4,
        oscModMixer4a,
        oscModMixer4b,
        filterLfo4,
        waveformMod4a,
        waveformMod4b,
        oscFX4,
        waveformMixer4,
        filterModMixer4,
        filter4,
        filterMixer4,
        ampEnvelope4,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope5,
        pwMixer5a,
        pwMixer5b,
        glide5,
        keytracking5,
        oscModMixer5a,
        oscModMixer5b,
        filterLfo5,
        waveformMod5a,
        waveformMod5b,
        oscFX5,
        waveformMixer5,
        filterModMixer5,
        filter5,
        filterMixer5,
        ampEnvelope5,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope6,
        pwMixer6a,
        pwMixer6b,
        glide6,
        keytracking6,
        oscModMixer6a,
        oscModMixer6b,
        filterLfo6,
        waveformMod6a,
        waveformMod6b,
        oscFX6,
        waveformMixer6,
        filterModMixer6,
        filter6,
        filterMixer6,
        ampEnvelope6,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope7,
        pwMixer7a,
        pwMixer7b,
        glide7,
        keytracking7,
        oscModMixer7a,
        oscModMixer7b,
        filterLfo7,
        waveformMod7a,
        waveformMod7b,
        oscFX7,
        waveformMixer7,
        filterModMixer7,
        filter7,
        filterMixer7,
        ampEnvelope7,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope8,
        pwMixer8a,
        pwMixer8b,
        glide8,
        keytracking8,
        oscModMixer8a,
        oscModMixer8b,
        filterLfo8,
        waveformMod8a,
        waveformMod8b,
        oscFX8,
        waveformMixer8,
        filterModMixer8,
        filter8,
        filterMixer8,
        ampEnvelope8,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope9,
        pwMixer9a,
        pwMixer9b,
        glide9,
        keytracking9,
        oscModMixer9a,
        oscModMixer9b,
        filterLfo9,
        waveformMod9a,
        waveformMod9b,
        oscFX9,
        waveformMixer9,
        filterModMixer9,
        filter9,
        filterMixer9,
        ampEnvelope9,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope10,
        pwMixer10a,
        pwMixer10b,
        glide10,
        keytracking10,
        oscModMixer10a,
        oscModMixer10b,
        filterLfo10,
        waveformMod10a,
        waveformMod10b,
        oscFX10,
        waveformMixer10,
        filterModMixer10,
        filter10,
        filterMixer10,
        ampEnvelope10,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope11,
        pwMixer11a,
        pwMixer11b,
        glide11,
        keytracking11,
        oscModMixer11a,
        oscModMixer11b,
        filterLfo11,
        waveformMod11a,
        waveformMod11b,
        oscFX11,
        waveformMixer11,
        filterModMixer11,
        filter11,
        filterMixer11,
        ampEnvelope11,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    },
    {
        filterEnvelope12,
        pwMixer12a,
        pwMixer12b,
        glide12,
        keytracking12,
        oscModMixer12a,
        oscModMixer12b,
        filterLfo12,
        waveformMod12a,
        waveformMod12b,
        oscFX12,
        waveformMixer12,
        filterModMixer12,
        filter12,
        filterMixer12,
        ampEnvelope12,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    }
};
*/

// Undefine custom classes renaming:
#undef AudioSynthWaveform
#undef AudioSynthWaveformModulated

#endif
